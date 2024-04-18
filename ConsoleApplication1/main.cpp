#include <iostream>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/button.hpp>
#include "BlackScholes.h"

int main() {
    using namespace nana;

    // Create the form
    form fm;

    // Create labels
    label lblS(fm, rectangle(10, 10, 120, 20));
    lblS.caption("Underlying stock price (S):");

    label lblK(fm, rectangle(10, 40, 120, 20));
    lblK.caption("Strike price (K):");

    label lblR(fm, rectangle(10, 70, 120, 20));
    lblR.caption("Risk-free rate (r):");

    label lblSigma(fm, rectangle(10, 100, 120, 20));
    lblSigma.caption("Volatility (sigma):");

    label lblTime(fm, rectangle(10, 130, 120, 20));
    lblTime.caption("Time to maturity:");

    // Create textboxes
    textbox txtS(fm, rectangle(140, 10, 100, 20));
    txtS.multi_lines(false);

    textbox txtK(fm, rectangle(140, 40, 100, 20));
    txtK.multi_lines(false);

    textbox txtR(fm, rectangle(140, 70, 100, 20));
    txtR.multi_lines(false);

    textbox txtSigma(fm, rectangle(140, 100, 100, 20));
    txtSigma.multi_lines(false);

    textbox txtTime(fm, rectangle(140, 130, 100, 20));
    txtTime.multi_lines(false);

    // Create button
    button btnCalculate(fm, rectangle(10, 160, 230, 30));
    btnCalculate.caption("Calculate Prices");

    // Event handler for the button
    btnCalculate.events().click([&] {
        double S = std::stod(txtS.caption());
        double K = std::stod(txtK.caption());
        double r = std::stod(txtR.caption());
        double sigma = std::stod(txtSigma.caption());
        double time = std::stod(txtTime.caption());

        // Create a CallOption instance
        CallOption call(S, K, r, sigma, time);
        // Create a PutOption instance
        PutOption put(S, K, r, sigma, time);

        // Calculate and show the prices
        msgbox mb(fm, "Option Prices");
        mb << "Call Option Price: " << call.option_price() << "\n";
        mb << "Put Option Price: " << put.option_price();
        mb.show();
        });

    // Show the form
    fm.show();

    // Start the event loop
    exec();
}
