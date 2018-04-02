#include "logwrapper.h"

Logger* Logger::instance = 0;

Logger* Logger::getLogger() {
    
    if (instance == 0) {
        instance = new Logger();
    }

    return instance;
}

Logger::Logger()
{
    appender = new log4cpp::FileAppender("default", LOG_FILE_NAME);

    log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
    layout->setConversionPattern("%d [%p][%t] : %m%n");
    appender->setLayout(layout);

    this->category = &log4cpp::Category::getRoot();
    this->category->setAppender(appender);    
}

void Logger::warn(char *message) {
    category->warn(message);
}

void Logger::info(char *message) {
    category->info(message);
}

void Logger::error(char *message) {
    category->error(message);
}
