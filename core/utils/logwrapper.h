#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include <iostream>

#define LOG_FILE_NAME "belyash.log"

class Logger {
    
    private: 
        log4cpp::Appender *appender;
        static Logger *instance;
        log4cpp::Category *category;
        char *context;

        Logger();

    public:
        
        static Logger* getLogger();

        void warn(char *message);
        void info(char *message);
        void error(char *message);
};

Logger* Logger::instance = 0;

Logger* Logger::getLogger() {
    
    if (instance == 0) {
        instance = new Logger();
    }

    return instance;
}

Logger::Logger()
{
    if (appender == 0) {
        appender = new log4cpp::FileAppender("default", "test");
        appender->setLayout(new log4cpp::BasicLayout());
    }
    this->category = &log4cpp::Category::getRoot();
    
    this->category->addAppender(appender);
}

void Logger::warn(char *message) {
    
    // Getting category for logger
    category->warn(message);
}

void Logger::info(char *message) {

    // Getting category for logger
    category->info(message);
}

void Logger::error(char *message) {

    // Getting category for logger
    category->error(message);
}
