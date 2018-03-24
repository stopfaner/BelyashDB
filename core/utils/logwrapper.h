#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include <iostream>

#define LOG_FILE_NAME "belyash.log"

class Logger {
    
    private: 
        static log4cpp::Appender *appender;
        static log4cpp::Category& category;
        static Logger *instance;

        Logger();

    public:
        
        static Logger* getLogger(const char *context);

        void warn(char *message);
        void info(char *message);
        void error(char *message);
};

Logger* Logger::instance = 0;

Logger* Logger::getLogger(const char *context) {
    
    if (instance == NULL) {
        instance = new Logger();
    }

    return instance;
}

Logger::Logger()
{
    // if (appender == 0) {
    //     appender = new log4cpp::FileAppender("default", LOG_FILE_NAME);
    //     appender->setLayout(new log4cpp::BasicLayout());
    // } 
    // category = log4cpp::Category::getInstance(std::string("test  "));

}

void Logger::warn(char *message) {
    std::cout << message << std::endl;
}