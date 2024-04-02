//// main.cpp
//#include <iostream>
//#include "term_structure.h"
//
//int main() {
//    double discount_factor = 0.95;
//    double yield = 0.05;
//    double t1 = 1;
//    double t2 = 2;
//    double d_t1 = financial_math::term_structure_discount_factor_from_yield(yield, t1);
//    double d_t2 = financial_math::term_structure_discount_factor_from_yield(yield, t2);
//
//    // Test the functions
//    double computed_yield = financial_math::term_structure_yield_from_discount_factor(discount_factor, t1);
//    double computed_discount = financial_math::term_structure_discount_factor_from_yield(yield, t1);
//    double forward_rate_from_discount = financial_math::term_structure_forward_rate_from_discount_factors(d_t1, d_t2, t1);
//    double forward_rate_from_yield = financial_math::term_structure_forward_rate_from_yields(yield, yield, t1, t2);
//
//    // Print the results
//    std::cout << "Computed Yield: " << computed_yield << std::endl;
//    std::cout << "Computed Discount Factor: " << computed_discount << std::endl;
//    std::cout << "Forward Rate from Discount Factors: " << forward_rate_from_discount << std::endl;
//    std::cout << "Forward Rate from Yields: " << forward_rate_from_yield << std::endl;
//
//    t1 = 1;
//    double r_t1 = 0.05;
//    d_t1 = financial_math::term_structure_discount_factor_from_yield(r_t1, t1);
//
//    std::cout << "a " << t1 << " period spot rate of " << r_t1
//        << " corresponds to a discount factor of " << d_t1 << std::endl;
//
//    t2 = 2;
//    d_t2 = 0.9;
//    double r_t2 = financial_math::term_structure_yield_from_discount_factor(d_t2, t2);
//
//    std::cout << "a " << t2 << " period discount factor of " << d_t2
//        << " corresponds to a spot rate of " << r_t2 << std::endl;
//
//    std::cout << "the forward rate between " << t1 << " and " << t2
//        << " is " << financial_math::term_structure_forward_rate_from_discount_factors(d_t1, d_t2, t2 - t1)
//        << " using discount factors " << std::endl;
//
//    std::cout << "and is " << financial_math::term_structure_forward_rate_from_yields(r_t1, r_t2, t1, t2)
//        << " using yields " << std::endl;
//
//
//    return 0;
//}
