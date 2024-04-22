//
#include "option_price_call_european_binomial_multi_period_given_ud.h"
#include <algorithm>
#include <cmath>

using namespace std;

double option_price_call_european_binomial_multi_period_given_ud(
    const double& S,
    const double& K,
    const double& r,
    const double& u,
    const double& d,
    const int& no_periods) {
    double Rinv = exp(-r);                    // inverse of interest rate
    double uu = u * u;
    double p_up = (exp(r) - d) / (u - d);
    double p_down = 1.0 - p_up;
    vector<double> prices(no_periods + 1);      // price of underlying
    prices[0] = S * pow(d, no_periods);       // fill in the endnodes.
    for (int i = 1; i <= no_periods; ++i) prices[i] = uu * prices[i - 1];
    vector<double> call_values(no_periods + 1); // value of corresponding call
    for (int i = 0; i <= no_periods; ++i) call_values[i] = max(0.0, (prices[i] - K)); // call payoffs at maturity
    for (int step = no_periods - 1; step >= 0; --step) { // working backwards
        for (int i = 0; i <= step; ++i) {
            call_values[i] = (p_up * call_values[i + 1] + p_down * call_values[i]) * Rinv;
        }
    };
    return call_values[0];
}

// Explanation:
// The function uses the binomial option pricing model to evaluate the price of a European call option.
// This model involves simulating the different paths the stock price could take until the option's expiration.
// The parameters are:
// S - current stock price, also known as the spot price.
// K - the strike price at which the option can be exercised.
// r - the risk-free interest rate.
// u - the factor by which the stock price increases if the price goes up.
// d - the factor by which the stock price decreases if the price goes down.
// no_periods - the number of discrete time intervals or steps in the binomial tree.

// Example:
// To use the function, you would provide the current stock price, the strike price, the risk-free rate,
// the up and down factors, and the number of periods for the binomial tree.
// For instance:
// double option_price = option_price_call_european_binomial_multi_period_given_ud(100, 100, 0.05, 1.1, 0.9, 3);
// This would calculate the option price for a stock currently priced at $100, with an exercise price of $100,
// a 5% interest rate per period, an up movement of 10%, a down movement of 10%, and 3 periods in the model.
