// BlackScholes.h
#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

#include "DStat.h" // Include the header for statistical functions

class BlackScholes
{
public:
    static double option_price_call_black_scholes(const double& S,   // spot (underlying) price
        const double& K,   // strike (exercise) price,
        const double& r,   // interest rate
        const double& sigma, // volatility
        const double& time); // time to maturity
};

#endif // BLACK_SCHOLES_H
