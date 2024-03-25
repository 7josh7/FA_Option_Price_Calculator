#ifndef BOND_PRICING_H
#define BOND_PRICING_H

#include <vector>

class BondPricing {
public:
    static double bonds_price_discrete(const std::vector<double>& times,
        const std::vector<double>& cashflows,
        const double& r);
};

#endif // BOND_PRICING_H
