//Yago Fernandez Rego
//Alejandro Fernandez Vazquez

#include <stdlib.h>
#include "rational_pointer.h"

//operation to create a rational number
Rational createRational(int n, int d){
    Rational temp;

    temp = malloc(sizeof(*temp));
    temp -> num = n;
    temp -> den = d;
    return temp;
}

//operation that returns the denominator of a rational number
int denominator(Rational r){
    return r -> den;
}

//operation that returns the numerator of a rational number
int numerator(Rational r){
    return r -> num;
}

//operation that returns the sum of two rational
Rational sum(Rational r1, Rational r2){
    Rational s;

    s = malloc(sizeof(*s));
    s -> num = r1 -> num * r2 -> den + r2 -> num * r1 -> den;
    s -> den = r1 -> den * r2 -> den;
    return s;
}
