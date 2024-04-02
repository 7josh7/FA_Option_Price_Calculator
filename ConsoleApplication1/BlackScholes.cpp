// BlackScholes.cpp
#include "BlackScholes.h"
#include <cmath>

DFinMath::DStat myDStat;

double BlackScholes::option_price_call_black_scholes(const double& S,   // spot (underlying) price
    const double& K,   // strike (exercise) price,
    const double& r,   // interest rate
    const double& sigma, // volatility
    const double& time)  // time to maturity
{
    double time_sqrt = std::sqrt(time);
    double d1 = (std::log(S / K) + r * time + 0.5 * sigma * sigma * time) / (sigma * time_sqrt);
    double d2 = d1 - (sigma * time_sqrt);

    // Utilize the DStat class for the cumulative normal distribution function
    return S * myDStat.NormDist(d1) - K * std::exp(-r * time) * myDStat.NormDist(d2);
}

