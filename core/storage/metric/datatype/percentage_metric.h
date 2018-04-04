#include "datatype.h"

class PercentageMetric: public DataType {

    public:

        PercentageMetric() {

        }

        std::string operator()() {
            return "Percentage";
        }

};