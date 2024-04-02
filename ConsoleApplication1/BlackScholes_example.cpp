#include <iostream>
#include "BlackScholes.h"

int main() {
    // Define test parameters
    double S = 50;     // Spot price
    double K = 50;     // Strike price
    double r = 0.10;      // Risk-free rate
    double sigma = 0.3;   // Volatility
    double time = 0.5;    // Time to maturity in years

    // Calculate the call option price
    double call_price = BlackScholes::option_price_call_black_scholes(S, K, r, sigma, time);

    // Output the result
    std::cout << "The Black-Scholes call option price is: " << call_price << std::endl;

    // Here you would compare the output to the expected value
    // For example, if you know the expected price is approximately $10.45 for these inputs
    double expected_price = 5.45325; // Example expected price
    std::cout << "The expected call option price should be around: " << expected_price << std::endl;

    // Check if the calculated price is within an acceptable range
    double tolerance = 0.01; // Define an acceptable error tolerance
    if (std::abs(call_price - expected_price) <= tolerance) {
        std::cout << "Test passed: Price is within the acceptable tolerance." << std::endl;
    }
    else {
        std::cout << "Test failed: Price is outside the acceptable tolerance." << std::endl;
    }

    return 0;
}
