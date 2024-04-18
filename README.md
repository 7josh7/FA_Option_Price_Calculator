# README for Black-Scholes Option Pricing Model Implementation

## Overview

This repository contains the implementation of the Black-Scholes model, a mathematical model for pricing an options contract. Specifically, it calculates the price of European call and put options. The Black-Scholes formula is widely used by option traders who buy options that are priced under the formula calculated value and sell options that are priced higher than the Black-Schole calculated value.

## Files

The implementation consists of two primary files:

- `BlackScholes.h`: This header file declares the `BlackScholes` class, along with its derived classes `CallOption` and `PutOption`.
- `BlackScholes.cpp`: This source file contains the definitions of the functions declared in `BlackScholes.h`.

## Dependencies

- `DStat.h`: A header file for statistical functions (not provided in this code snippet). It must define a class `DStat` with a method `NormDist` which computes the standard normal cumulative distribution.
- `<cmath>`: A header file from the standard library providing access to mathematical functions.
- `<stdexcept>`: A header file for standard exceptions, used to handle invalid arguments in the class methods.

## Usage

1. **Creating an Option Object**: 
   - To price a call option, create an instance of `CallOption` by passing the spot price, strike price, risk-free interest rate, volatility, and time to maturity.
   - Similarly, to price a put option, create an instance of `PutOption`.

2. **Pricing an Option**: 
   - Call the `option_price()` method on an instance of `CallOption` or `PutOption` to calculate the price of the option.

3. **Updating Option Parameters**: 
   - Setters are provided to update the spot price (`setS`), strike price (`setK`), risk-free rate (`setR`), volatility (`setSigma`), and time to maturity (`setTime`).

## Classes

- `BlackScholes`: An abstract base class for the pricing model, which contains common data members and methods for the derived classes.
- `CallOption`: A derived class from `BlackScholes` for calculating the price of call options.
- `PutOption`: A derived class from `BlackScholes` for calculating the price of put options.

## Key Methods

- `validateInputs()`: Validates that the strike price, volatility, and time to maturity are positive.
- `calculate_d1_d2()`: Calculates the d1 and d2 parameters used in the Black-Scholes formula.
- `calculate_n_d1_n_d2()`: Calculates the values of the standard normal cumulative distribution function for d1 and d2.
- `option_price()`: A pure virtual function implemented in derived classes to calculate the price of the option.

## Notes

- Exception handling is used to ensure that invalid inputs are managed appropriately.

## License

This code is released under the [MIT License].
## Disclaimer

This code is for educational purposes and should not be used for financial advice or trading without proper risk management and due diligence.

---

Please replace `LICENSE.md` with the path to your actual license file, if available.
