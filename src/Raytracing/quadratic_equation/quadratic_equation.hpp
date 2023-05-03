/// @file equation.h header file contains function declarations, structures, enumerations used for solving equation
#pragma once

//=========================================================

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//=========================================================

enum root_cases {
    INF_ROOTS = 3,
    NO_ROOTS=4,
    ONE_ROOT=5, 
    TWO_ROOTS=6,
    NOT_STATED_CASE = 7 
};


enum answers { NOT_STATED = 0, YES = 1, NO = 2 };

struct Equation {
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double root1 = NAN;
    double root2 = NAN;
    enum root_cases roots_ct = NOT_STATED_CASE;
};


void solve_linear(struct Equation* equation);


void solve_quadratic(struct Equation* equation);


void solve_equation(struct Equation* equation);


void equation_init(struct Equation* equation);

