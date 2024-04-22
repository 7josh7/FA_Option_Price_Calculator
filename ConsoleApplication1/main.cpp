#include <iostream>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/form.hpp>
#include <nana/gui/drawing.hpp>
#include <sstream>  
#include <vector>
#include <string>
#include "BlackScholes.h"
#include "date.h"


int main() {
    using namespace nana;

    // Create the form
    form fm;
    fm.size(size(800, 600));  // Ensure enough space for graph and controls
    fm.caption("Option Price Calculator");

    // Create a dropdown list for option type (Call or Put)
    label lblType(fm, rectangle(10, 10, 200, 20));
    lblType.caption("Option Type:");
    combox cmbOptionType(fm, rectangle(220, 10, 100, 20));
    cmbOptionType.push_back("Call");
    cmbOptionType.push_back("Put");
    cmbOptionType.option(0); // Set default selection to "Call"

    label lblS(fm, rectangle(10, 40, 200, 20));
    lblS.caption("Underlying stock price (S):");
    textbox txtS(fm, rectangle(220, 40, 100, 20));
    txtS.caption("100");  // Default stock price
    txtS.multi_lines(false);

    label lblK(fm, rectangle(10, 70, 200, 20));
    lblK.caption("Strike price (K):");
    textbox txtK(fm, rectangle(220, 70, 100, 20));
    txtK.caption("100");  // Default strike price
    txtK.multi_lines(false);

    label lblR(fm, rectangle(10, 100, 200, 20));
    lblR.caption("Risk-free rate (r):");
    textbox txtR(fm, rectangle(220, 100, 100, 20));
    txtR.caption("0.05");  // Default risk-free rate (5%)
    txtR.multi_lines(false);

    label lblDividend(fm, rectangle(10, 130, 200, 20));
    lblDividend.caption("Dividend Yield:");
    textbox txtDividend(fm, rectangle(220, 130, 100, 20));
    txtDividend.caption("0");  // Default dividend yield (0%)
    txtDividend.multi_lines(false);

    label lblSigma(fm, rectangle(10, 160, 200, 20));
    lblSigma.caption("Volatility (sigma):");
    textbox txtSigma(fm, rectangle(220, 160, 100, 20));
    txtSigma.caption("0.2");  // Default volatility (20%)
    txtSigma.multi_lines(false);

    label lblTimeS(fm, rectangle(10, 190, 200, 20));
    lblTimeS.caption("Starting Date(YYYY/MM/DD):");
    textbox txtTimeS(fm, rectangle(220, 190, 100, 20));
    txtTimeS.caption("2024/01/01");  // Default starting date
    txtTimeS.multi_lines(false);

    label lblTimeE(fm, rectangle(10, 220, 200, 20));
    lblTimeE.caption("Expiration Date(YYYY/MM/DD):");
    textbox txtTimeE(fm, rectangle(220, 220, 100, 20));
    txtTimeE.caption("2024/12/31");  // Default expiration date
    txtTimeE.multi_lines(false);

    // Day count convention label moved lower to accommodate new fields
    label lblDayCount(fm, rectangle(10, 250, 200, 20));
    lblDayCount.caption("Day Count Convention:");

    // Create a dropdown list for day count convention
    std::vector<std::string> dayCountConventions = { "Thirty360", "Thirty365", "Actual360", "Actual365", "ActualActual" };
    combox cmbDayCount(fm, rectangle(220, 250, 100, 20));
    for (const auto& dayCount : dayCountConventions) {
        cmbDayCount.push_back(dayCount);
    }
    cmbDayCount.option(0);

    // Create button, now positioned lower
    button btnCalculate(fm, rectangle(10, 280, 230, 30));
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

        // Determine the day count convention based on combox selection
        DayCountConvention dcc;
        switch (cmbDayCount.option()) {
        case 0: dcc = DayCountConvention::Thirty360; break;
        case 1: dcc = DayCountConvention::Thirty365; break;
        case 2: dcc = DayCountConvention::Actual360; break;
        case 3: dcc = DayCountConvention::Actual365; break;
        case 4: dcc = DayCountConvention::ActualActual; break;
        default:
            msgbox mb_error(fm, "Invalid day count convention selected");
            mb_error.show();
            return;
        }

        // Calculate the time to maturity using years_until method
        double timeToMaturity = startingDate.years_until(expirationDate, dcc);

        // Create a CallOption and a PutOption instance with the computed time to maturity
        CallOption call(S, K, r, sigma, timeToMaturity);
        PutOption put(S, K, r, sigma, timeToMaturity);

        // Calculate and display the prices and Greeks
        msgbox mbPrice(fm, "Option Prices and Greeks");
        if (cmbOptionType.option() == 0) { // Call option selected
            mbPrice << "Call Option Price: " << call.option_price() << "\n";
            mbPrice << "Delta: " << call.delta() << "\n";
            mbPrice << "Gamma: " << call.gamma() << "\n";
            mbPrice << "Vega: " << call.vega() << "\n";
            mbPrice << "Theta: " << call.theta() << "\n";
            mbPrice << "Rho: " << call.rho();
        }
        else { // Put option selected
            mbPrice << "Put Option Price: " << put.option_price() << "\n";
            mbPrice << "Delta: " << put.delta() << "\n";
            mbPrice << "Gamma: " << put.gamma() << "\n";
            mbPrice << "Vega: " << put.vega() << "\n";
            mbPrice << "Theta: " << put.theta() << "\n";
            mbPrice << "Rho: " << put.rho();
        }
        mbPrice.show();
        });

    // Show the form
    fm.show();

    // Start the event loop
    exec();
}
