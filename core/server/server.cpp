#include "server.h"

bool server::Server::_set_up_socket() {

    server_address.sin_family = AF_INET;  
    server_address.sin_addr.s_addr = INADDR_ANY;  
    server_address.sin_port = htons(PORT);  

    //bind the socket to localhost port 8888 
    if (bind(master_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)  
    {
        this->err_flag = true;
        this->err = "Binding failed.";

        perror(this->err);  
        exit(EXIT_FAILURE);  
    }
    printf("Listener on port %d \n", PORT);  
        
    //try to specify maximum of 3 pending connections for the master socket 
    if (listen(master_socket, 3) < 0)  
    {  
        perror("listen");  
        exit(EXIT_FAILURE);  
    }  
        
    //accept the incoming connection 
    address_len = sizeof(server_address);  
    puts("Waiting for connections ...");

    session_manager = new SessionManager(this->max_clients);
}

server::Server::Server(int max_clients) {
                
    if (max_clients != 0) {
        this->max_clients = max_clients;
        
    } else {
        this->max_clients = MAX_CLIENTS_DEFAULT;
    }
    this->client_socket = new int[this->max_clients];

    //initialise all client_socket[] to 0 so not checked 
    for (int i = 0; i < max_clients; i++) {  
        client_socket[i] = 0;  
    }  
        
    //create a master socket 
    if((master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) {  
        perror("socket failed");  
        exit(EXIT_FAILURE);  
    }  
    
    //set master socket to allow multiple connections , 
    //this is just a good habit, it will work without this 
    if(setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0) {  
        perror("setsockopt");  
        exit(EXIT_FAILURE);  
    }  

    this->_set_up_socket();
}

void server::Server::start_accepting() {
    while(TRUE) {  

        //clear the socket set 
        FD_ZERO(&readfds);  
    
        //add master socket to set 
        FD_SET(master_socket, &readfds);  
        max_sd = master_socket;  
            
        //add child sockets to set 
        for (int i = 0; i < max_clients; i++) {  
            //socket descriptor 
            sd = client_socket[i];  
                
            //if valid socket descriptor then add to read list 
            if(sd > 0)  
                FD_SET( sd , &readfds);  
                
            //highest file descriptor number, need it for the select function 
            if(sd > max_sd)  
                max_sd = sd;  
        }  
    
        //wait for an activity on one of the sockets , timeout is NULL , 
        //so wait indefinitely 
        activity = select(max_sd + 1 , &readfds , NULL , NULL , NULL);  
    
        if ((activity < 0) && (errno!=EINTR))  
        {  
            printf("select error");  
        }  
            
        //If something happened on the master socket , 
        //then its an incoming connection 
        this->_incomming_connection();  
            
        this->_io_accept();
    }  
}

void server::Server::_incomming_connection() {
    if (FD_ISSET(master_socket, &readfds))  
    {  
        if ((new_socket = accept(master_socket, (struct sockaddr *) &server_address, (socklen_t*)&address_len)) < 0) {  
            perror("accept");  
            exit(EXIT_FAILURE);  
        }  
        
        //inform user of socket number - used in send and receive commands 
        printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(server_address.sin_addr) , ntohs
            (server_address.sin_port));  
    
        puts("Welcome message sent successfully");  
            
        //add new socket to array of sockets 
        for (int i = 0; i < max_clients; i++) {  
            //if position is empty 
            if(client_socket[i] == 0) {  
                client_socket[i] = new_socket;  
                printf("session socket %d", sizeof(new_socket));

                this->session_manager->create_new_session(new_socket);

                printf("Adding to list of sockets as %d\n" , i);  
                    
                break;  
            }  
        }  
    }
}

void server::Server::_io_accept() {
    //else its some IO operation on some other socket
    for (int i = 0; i < max_clients; i++) {  
        sd = client_socket[i];  
            
        if (FD_ISSET(sd , &readfds)) {  
            //Check if it was for closing , and also read the 
            //incoming message 
            if ((valread = read(sd , buffer, 1024)) == 0) {  
                //Somebody disconnected , get his details and print 
                getpeername(sd , (struct sockaddr*)&server_address, (socklen_t*)&address_len);  
                printf("Host disconnected , ip %s , port %d \n" , 
                    inet_ntoa(server_address.sin_addr) , ntohs(server_address.sin_port));  
                    
                //Close the socket and mark as 0 in list for reuse 
                this->session_manager->remove_session(sd);
                client_socket[i] = 0;  

            } else {  
                //set the string terminating NULL byte on the end 
                //of the data read 
                this->session_manager->push_in_session(buffer, sd, valread);
            }  
        }  
    }  
}