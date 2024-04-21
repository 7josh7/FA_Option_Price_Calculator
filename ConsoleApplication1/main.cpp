#include <iostream>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/button.hpp>
#include <sstream>  
#include <vector>
#include <string>
#include "BlackScholes.h"
#include "date.h"


int main() {
    using namespace nana;

    // Create the form
    form fm;

    // Create labels
    label lblS(fm, rectangle(10, 10, 200, 20));
    lblS.caption("Underlying stock price (S):");

    label lblK(fm, rectangle(10, 40, 200, 20));
    lblK.caption("Strike price (K):");

    label lblR(fm, rectangle(10, 70, 200, 20));
    lblR.caption("Risk-free rate (r):");

    label lblSigma(fm, rectangle(10, 100, 200, 20));
    lblSigma.caption("Volatility (sigma):");

    label lblTimeS(fm, rectangle(10, 130, 200, 20));
    lblTimeS.caption("Starting Date(YYYY/MM/DD):");

    label lblTimeE(fm, rectangle(10, 160, 200, 20));
    lblTimeE.caption("Expiration Date(YYYY/MM/DD):");

    // Create textboxes
    textbox txtS(fm, rectangle(220, 10, 100, 20));
    txtS.multi_lines(false);

    textbox txtK(fm, rectangle(220, 40, 100, 20));
    txtK.multi_lines(false);

    textbox txtR(fm, rectangle(220, 70, 100, 20));
    txtR.multi_lines(false);

    textbox txtSigma(fm, rectangle(220, 100, 100, 20));
    txtSigma.multi_lines(false);

    textbox txtTimeS(fm, rectangle(220, 130, 100, 20));
    txtTimeS.multi_lines(false);

    textbox txtTimeE(fm, rectangle(220, 160, 100, 20));
    txtTimeE.multi_lines(false);

    // Create button
    button btnCalculate(fm, rectangle(10, 190, 230, 30));
    btnCalculate.caption("Calculate Prices");

    // Event handler for the button
    btnCalculate.events().click([&] {
        double S = std::stod(txtS.caption());
        double K = std::stod(txtK.caption());
        double r = std::stod(txtR.caption());
        double sigma = std::stod(txtSigma.caption());

        // Parse starting date
        std::istringstream startStream(txtTimeS.caption());
        int sYear, sMonth, sDay;
        char delim;
        startStream >> sYear >> delim >> sMonth >> delim >> sDay;
        date startingDate(sDay, sMonth, sYear);

        // Parse expiration date
        std::istringstream endStream(txtTimeE.caption());
        int eYear, eMonth, eDay;
        endStream >> eYear >> delim >> eMonth >> delim >> eDay;
        date expirationDate(eDay, eMonth, eYear);

        if (!startingDate.valid() || !expirationDate.valid()) {
            msgbox mb(fm, "Error");
            mb << "Invalid date(s) entered.";
            mb.show();
            return;
        }

        // Calculate the time to maturity using years_until method
        double timeToMaturity = startingDate.years_until(expirationDate, DayCountConvention::ActualActual);

        // Create a CallOption and a PutOption instance with the computed time to maturity
        CallOption call(S, K, r, sigma, timeToMaturity);
        PutOption put(S, K, r, sigma, timeToMaturity);

        // Calculate and display the prices
        msgbox mbPrice(fm, "Option Prices");
        mbPrice << "Call Option Price: " << call.option_price() << "\n";
        mbPrice << "Put Option Price: " << put.option_price();
        mbPrice.show();
        });

    // Show the form
    fm.show();

    // Start the event loop
    exec();
}
