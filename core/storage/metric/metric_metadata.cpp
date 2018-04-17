#include "metric_metadata.h"

storage::MetricMetadata::MetricMetadata() {
    
}

storage::MetricMetadata::MetricMetadata(char *metric_name, char *filename, char *tag_name) {
    strcpy(this->metric_name, metric_name);
    strcpy(this->filename, filename);

    if (tag_name != 0) {
        strcpy(this->tag_name, tag_name);
    }
}

bool storage::MetricMetadata::operator==(const MetricMetadata &other) const {
    if (strcmp(this->metric_name, other.get_metric_name()) != 0) {
        return false;
    }

    if (strcmp(this->filename, other.get_filename()) != 0) {
        return false;
    }
    if (this->tag_name != 0 && other.get_tag_name() != NULL) {
        if (strcmp(this->tag_name, other.get_tag_name()) != 0) {
            return false;
        }
    } else {
        if (this->tag_name == 0 && other.get_tag_name() == NULL)
            return true;
        else
            return false;
    }

    return true;
}

char* storage::MetricMetadata::get_metric_name() const {
    char *name = new char[MAX_METRIC_NAME_SIZE];

    strcpy(name, this->metric_name);

    return name;
}

char* storage::MetricMetadata::get_filename() const {
    char *name = new char[MAX_FILENAME_SIZE];

    strcpy(name, this->filename);

    return name;
}

char* storage::MetricMetadata::get_tag_name() const {
    if (this->tag_name != 0) {
        char *name = new char[MAX_TAG_NAME_SIZE];

        strcpy(name, this->tag_name);

        return name;
    } 

    return NULL;
}