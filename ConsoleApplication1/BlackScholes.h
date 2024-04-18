// BlackScholes.h
#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

#include "DStat.h" // Include the header for statistical functions
#include <cmath> // Include the header for mathematical functions
#include <stdexcept>  // Include standard exceptions


class BlackScholes{
protected:
    double S_;   // spot (underlying) price
    double K_;   // strike (exercise) price
    double r_;   // interest rate
    double sigma_; // volatility
    double time_; // time to maturity
    double time_sqrt; // square root of time to maturity
    double d1; // d1    
    double d2; // d2    
    double n_d1; // standard normal cumulative distribution function
    double n_d2; // standard normal cumulative distribution function
    void validateInputs(double K, double sigma, double time);
public:
    // Constructor
    BlackScholes(const double& S, const double& K, const double& r, const double& sigma, const double& time)
        : S_(S), K_(K), r_(r), sigma_(sigma), time_(time) {
        validateInputs(K, sigma, time);
        time_sqrt = std::sqrt(time_);
        calculate_d1_d2();
    }
    // Copy constructor
    BlackScholes(const BlackScholes& bs)
        : S_(bs.S_), K_(bs.K_), r_(bs.r_), sigma_(bs.sigma_), time_(bs.time_), time_sqrt(bs.time_sqrt), d1(bs.d1), d2(bs.d2), n_d1(bs.n_d1), n_d2(bs.n_d2) {}

    // Destructor
    ~BlackScholes() {}

    // Pure virtual function for option price
    virtual double option_price() = 0;
    virtual void calculate_n_d1_n_d2() = 0;

    // Setter methods
    void calculate_d1_d2();
    void setS(double S);
    void setK(double K);
    void setR(double r);
    void setSigma(double sigma);
    void setTime(double time);
};


class CallOption : public BlackScholes {
public:
    // Constructor for CallOption - initializes base class BlackScholes with passed parameters
    CallOption(const double& S, const double& K, const double& r, const double& sigma, const double& time)
        : BlackScholes(S, K, r, sigma, time) {
        calculate_n_d1_n_d2();
    }

    // Destructor for CallOption - currently does nothing but could handle resource cleanup if needed
    ~CallOption() {}


    void calculate_n_d1_n_d2() override;
    double option_price();
};

class PutOption : public BlackScholes {
public:
    // Constructor for PutOption - initializes base class BlackScholes with passed parameters
    PutOption(const double& S, const double& K, const double& r, const double& sigma, const double& time)
        : BlackScholes(S, K, r, sigma, time) {
        calculate_n_d1_n_d2();
    }

    // Destructor for PutOption - currently does nothing but could handle resource cleanup if needed
    ~PutOption() {}
    void calculate_n_d1_n_d2() override;
    double option_price();
};


#endif // BLACK_SCHOLES_H
