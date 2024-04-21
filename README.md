# README for Black-Scholes Option Pricing Model Implementation

## Overview

This repository contains a GUI-based implementation of the Black-Scholes model, a fundamental mathematical model for pricing European-style options. Utilizing this model, users can calculate the prices of call and put options through a graphical interface that simplifies the input of variables such as stock price, strike price, and maturity dates. The model is used extensively in financial markets to estimate the fair value of options, enabling traders to identify potentially undervalued or overvalued options.

## Files

The application comprises several components, structured as follows:

- `main.cpp`: Contains the main function that sets up the GUI and links the computational logic with user inputs.
- `BlackScholes.h`: Header file that declares the `BlackScholes`, `CallOption`, and `PutOption` classes for pricing options.
- `date.h`: Defines the `date` class used for managing date inputs and calculations related to option expiration.
- `date.cpp`: Implements the methods declared in `date.h` for date management and day count conventions.

## Dependencies

This application relies on the Nana GUI library to provide an interactive interface:

- Nana C++ Library: A modern C++ GUI library designed for simplicity and flexibility.
- Standard C++ Libraries: `<iostream>`, `<sstream>`, `<vector>`, `<string>`, used for input/output operations, string manipulations, and handling collections.

## Installation

To run this application, you need to set up the Nana C++ library and configure your development environment to compile C++ code. Steps include:

1. Install the Nana C++ library from its [official repository](https://github.com/cnjinhao/nana) and follow the setup instructions.
2. Compile the source files using a C++ compiler that supports C++14 or later. Integration with an IDE like Visual Studio is recommended for ease of use.

## Usage

Upon launching the application, users will interact with a form where they can:

1. Enter financial parameters (stock price, strike price, risk-free rate, volatility).
2. Set the starting and expiration dates using a YYYY/MM/DD format.
3. Select the appropriate day count convention from a dropdown menu.
4. Calculate the prices of the options by clicking the "Calculate Prices" button.

Results will be displayed in a message box, showing the computed prices for both call and put options based on the Black-Scholes formula.

## Key Classes and Methods

- **date Class**: Manages date calculations, validates correct date entries, and computes time intervals based on various day count conventions.
- **BlackScholes, CallOption, PutOption Classes**: Implement the pricing model calculations, with methods to update parameters and compute the option prices.

## Notes

- The application includes error handling to manage invalid dates and other input errors, ensuring robust application performance.
- The GUI is designed for intuitive use, making it accessible even for those with limited experience in financial modeling.

## License

This project is open-sourced under the MIT License.

## Disclaimer

This software is intended for educational purposes only and should not be used as the sole basis for financial decisions. Users should conduct their own due diligence or consult with a professional advisor before engaging in options trading.
