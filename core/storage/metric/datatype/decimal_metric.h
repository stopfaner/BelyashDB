#include "datatype.h"

class DecimalMetric: public DataType {

    public:

        DecimalMetric() {

        }


        std::string operator()() {
            return "Decimal";
        }
};