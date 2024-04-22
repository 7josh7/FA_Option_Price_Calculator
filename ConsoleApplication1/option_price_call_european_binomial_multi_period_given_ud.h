//binomial tree method for European call option pricing.h
#ifndef OPTION_PRICING_H
#define OPTION_PRICING_H

#include <vector>

// This function calculates the European call option price using a binomial tree method.
double option_price_call_european_binomial_multi_period_given_ud(
    const double& S, // spot price
    const double& K, // exercise price
    const double& r, // interest rate (per period)
    const double& u, // up movement
    const double& d, // down movement
    const int& no_periods // no steps in binomial tree
);

#endif // OPTION_PRICING_H
