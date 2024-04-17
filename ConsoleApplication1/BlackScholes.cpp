// BlackScholes.cpp
#include "BlackScholes.h"
#include <cmath>

DFinMath::DStat myDStat;

// Setter methods
void BlackScholes::calculate_d1_d2() {
    d1 = (std::log(S_ / K_) + r_ * time_ + 0.5 * sigma_ * sigma_ * time_) / (sigma_ * time_sqrt);
    d2 = d1 - (sigma_ * time_sqrt);
}

void BlackScholes::setS(double S) {
    S_ = S;
    calculate_d1_d2();
    calculate_n_d1_n_d2();
}

void BlackScholes::setK(double K) {
    K_ = K;
    calculate_d1_d2();
    calculate_n_d1_n_d2();
}

void BlackScholes::setR(double r) {
    r_ = r;
    calculate_d1_d2();
    calculate_n_d1_n_d2();
}

void BlackScholes::setSigma(double sigma) {
    sigma_ = sigma;
    calculate_d1_d2();
    calculate_n_d1_n_d2();
}

void BlackScholes::setTime(double time) {
    time_ = time;
    time_sqrt = std::sqrt(time_);
    calculate_d1_d2();
    calculate_n_d1_n_d2();
}

double CallOption::option_price() {
    return S_ * n_d1 - K_ * std::exp(-r_ * time_) * n_d2;
}

void CallOption::calculate_n_d1_n_d2(){
    n_d1 = myDStat.NormDist(d1);
    n_d2 = myDStat.NormDist(d2);
}


double PutOption::option_price() {
    return K_ * std::exp(-r_ * time_) * n_d2 - S_ * n_d1;
}

void PutOption::calculate_n_d1_n_d2(){
    n_d1 = myDStat.NormDist(-d1);
    n_d2 = myDStat.NormDist(-d2);
}

