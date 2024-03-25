#include "BondPricing.h"
#include <cmath>

double BondPricing::bonds_price_discrete(const std::vector<double>& times,
    const std::vector<double>& cashflows,
    const double& r) {
    double p = 0;
    for (size_t i = 0; i < times.size(); i++) {
        p += cashflows[i] / (std::pow((1 + r), times[i]));
    }
    return p;
}
