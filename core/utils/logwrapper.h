#pragma once

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/Priority.hh"
#include <iostream>

#define LOG_FILE_NAME "belyash.log"

class Logger {
    
    private: 
        static Logger *instance;

        log4cpp::Appender *appender;
        log4cpp::Category *category;

        Logger();

    public:
        
        static Logger* getLogger();

        void warn(char *message);
        void info(char *message);
        void error(char *message);
};