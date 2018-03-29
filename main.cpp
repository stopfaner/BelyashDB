
#include <iostream>
#include "core/server/server.cpp"
// #include "log4cpp/Category.hh"
// #include "log4cpp/Appender.hh"
// #include "log4cpp/FileAppender.hh"
// #include "log4cpp/OstreamAppender.hh"
// #include "log4cpp/Layout.hh"
// #include "log4cpp/BasicLayout.hh"
// #include "log4cpp/Priority.hh"
//#include "core/utils/logwrapper.h"


int main(int argc , char *argv[])  
{  

     server::Server* server = new server::Server(10);
     server->start_accepting();

	return 0;
}  
