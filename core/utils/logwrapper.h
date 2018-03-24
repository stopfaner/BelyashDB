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
        log4cpp::Appender *appender;
        static Logger *instance;

        char *context;

        Logger(const char *context);

    public:
        
        static Logger* getLogger(const char *context);

        void warn(char *message, char *context);
        void info(char *message, char *context);
        void error(char *message, char *context);
};

Logger* Logger::instance = 0;

Logger* Logger::getLogger(const char *context) {
    
    if (instance == 0) {
        instance = new Logger(context);
    }

    return instance;
}

Logger::Logger(const char *context)
{
    if (appender == 0) {
        appender = new log4cpp::FileAppender("default", LOG_FILE_NAME);
        appender->setLayout(new log4cpp::BasicLayout());
    }
    this->context = (char*) context;
}

void Logger::warn(char *message, char *context = 0) {
    
    char *temp_context;
    if (context != 0)
        temp_context = this->context;

    // Getting category for logger
    log4cpp::Appender* appender = new log4cpp::FileAppender("default", LOG_FILE_NAME);
    log4cpp::Category& category = log4cpp::Category::getInstance(temp_context);
    category.setAppender(appender);

    category.warn(message);
}

void Logger::info(char *message, char *context = 0) {

    char *temp_context;
    if (context != 0)
        temp_context = this->context;

    // Getting category for logger
    log4cpp::Appender* appender = new log4cpp::FileAppender("default", LOG_FILE_NAME);
    log4cpp::Category& category = log4cpp::Category::getInstance(temp_context);
    category.setAppender(appender);

    category.info(message);
}

void Logger::error(char *message, char *context = 0) {
    // Getting category for logger
    
}
