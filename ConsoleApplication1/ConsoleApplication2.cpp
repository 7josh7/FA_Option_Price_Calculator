#include <iostream>
#include "BondPricing.h"

int main() {
    std::vector<double> times = { 1, 2, 3 };  // Example time periods
    std::vector<double> cashflows = { 100, 100, 1000 };  // Example cash flows, including principal at the end
    double r = 0.05;  // Discount rate of 5%

    double bond_price = BondPricing::bonds_price_discrete(times, cashflows, r);

    std::cout << "The price of the bond is: " << bond_price << std::endl;

    return 0;
}
