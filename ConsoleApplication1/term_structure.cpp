// term_structure.cpp
#include "term_structure.h"
#include <cmath>

namespace financial_math {

    double term_structure_yield_from_discount_factor(const double& d_t, const double& t) {
        return (-std::log(d_t) / t);
    }

    double term_structure_discount_factor_from_yield(const double& r, const double& t) {
        return std::exp(-r * t);
    }

    double term_structure_forward_rate_from_discount_factors(const double& d_t1, const double& d_t2, const double& time) {
        return (std::log(d_t1 / d_t2)) / time;
    }

    double term_structure_forward_rate_from_yields(const double& r_t1, const double& r_t2, const double& t1, const double& t2) {
        return r_t2 * t2 / (t2 - t1) - r_t1 * t1 / (t2 - t1);
    }

} // namespace financial_math
