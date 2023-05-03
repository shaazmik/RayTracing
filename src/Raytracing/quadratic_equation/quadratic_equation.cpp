#include <assert.h>
#include <math.h>


#include "./quadratic_equation.hpp"

#define EPSILON 1e-6

static bool isequal(const double num1, const double num2) {
    if (fabs(num1 - num2) <= EPSILON) return 1;
    else return 0;
}

//=====================================================

static double zerofix(double value) {
    
    return (isequal(value, 0)) ? fabs(value) : value;
}

//=====================================================

void solve_equation(struct Equation* equation) {
    assert(equation != NULL);

    if (isequal(equation->a, 0))
        solve_linear(equation);
    else
        solve_quadratic(equation);
}

//=====================================================

void equation_init(struct Equation* equation){
    equation->a = NAN;
    equation->b = NAN;
    equation->c = NAN;
    equation->root1 = NAN;
    equation->root2 = NAN;
    equation->roots_ct = NOT_STATED_CASE;
}

//=====================================================

void solve_linear(struct Equation* equation) {
    assert(equation != NULL);

    double c = equation->c;
    double b = equation->b;

    if (isequal(c, 0) && isequal(b, 0)) equation->roots_ct = INF_ROOTS;
    
    else if (!isequal(c, 0) && isequal(b, 0)) 
        equation->roots_ct = NO_ROOTS;

    else if (!isequal(b, 0)) {
        equation->roots_ct = ONE_ROOT;
        equation->root1 = (-c) / b;
        
        equation->root1 = zerofix(equation->root1);                        
    }
}

//=====================================================

void solve_quadratic(struct Equation* equation) {
    assert(equation != NULL);

    double a = equation->a;
    double b = equation->b;
    double c = equation->c;
    double discr = NAN;



    discr = b * b - 4 * a * c;

    if (isequal(discr, 0)) {

        equation->roots_ct = ONE_ROOT;
        equation->root1 = (-b) / (2 * a);

        equation->root1 = zerofix(equation->root1);
    }
    else if (discr > 0) {
        double discr_sqrt = sqrt(discr);
        a *= 2;

        equation->root1 = (-b - discr_sqrt) / a;                          
        equation->root2 = (-b + discr_sqrt) / a;

        equation->roots_ct = TWO_ROOTS;
    }
    else equation->roots_ct = NO_ROOTS;
}

//=====================================================
