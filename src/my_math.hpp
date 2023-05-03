#ifndef VECTOR_MATH_hpp
#define VECTOR_MATH_hpp

#include <math.h>

const size_t Poison  = 747385748;
const double Epsylon = 0.0000001;


inline bool double_is_equal(const double a, const double b){return (fabs(a - b) < Epsylon);}


#endif