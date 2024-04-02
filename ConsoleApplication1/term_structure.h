#ifndef TERM_STRUCTURE_H // If HEADER_FILE_NAME_H is not defined
#define TERM_STRUCTURE_H // Define HEADER_FILE_NAME_H

namespace financial_math {

	double term_structure_yield_from_discount_factor(const double& d_t, const double& t);
	double term_structure_discount_factor_from_yield(const double& r, const double& t);
	double term_structure_forward_rate_from_discount_factors(const double& d_t1, const double& d_t2, const double& time);
	double term_structure_forward_rate_from_yields(const double& r_t1, const double& r_t2, const double& t1, const double& t2);

} // namespace financial_math

#endif // TERM_STRUCTURE_H
