//
// Created by 修宇航 on 2017/12/4.
//

#include "Sales_data"

double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

int main() {

}