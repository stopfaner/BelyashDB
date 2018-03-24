
#include <iostream>
#include "core/server/server.cpp"
#define TRUE   1 
#define FALSE  0 
#define PORT 8888 
    
int main(int argc , char *argv[])  
{  
	Server* server = new Server();
	server->start_accepting();
    
        
    return 0;  
}  
