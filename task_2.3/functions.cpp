#include <iostream>

#include "functions.h"

// Find max divisor of our number. In our task it will be module.
long long find_max_divisor(long long number, long long upper_bound) {
    // We know upper bound of module and we shouldn't consider all divisors, it is enough
    // from the upper bound to one
    for (long long i = upper_bound; i > 0; i--) {
        if (number % i == 0) {
            return i;
        }
    }
    return 1;
}

//  Extend Euqlid algorithm 
//  ax + by = g mod m   Our goal is x
long long gcdex(long long a, long long b, long long& x, long long& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

long long find_reverse(long long number_for_reverse, long long module, long long& reverse_number, long long& y) {
    long long gcd = gcdex(number_for_reverse, module, reverse_number, y);

    // Check necessary condition for the existence of the reverse number
    if (gcd != 1) {
        std::cout << "X1 - X2 has not reverse with module " << module << std::endl;
        return -1;
    }
    else {
        reverse_number = (reverse_number % module + module) % module;
    }
    return reverse_number;
}

// a = (X2 - X3) / (X1 - X2)
long long calculate_a(const long long* numbers, long long module) {
    long long numerator = numbers[1] - numbers[2];
    if (numerator < 0) {
        numerator += module;
    }
    long long denominator = numbers[0] - numbers[1];

    // x and y are numbers for Euclid algorithm
    long long x = 1;
    long long y = 1;
    long long a = numerator * find_reverse(denominator, module, x, y) % module;

    return a;
}


// b = X2 - a*X1
long long calculate_b(const long long* numbers, long long module, long long a) {
    return (numbers[1] - a * numbers[0]) % module;
}

// Generate the next number according to the law of Linear congruential generator. This generator
// needs module, coeffecients 'a' and 'b' and previous number
// Xn+1 = (a*Xn + b) mod m
long long generator(long long a, long long b, long long Xn, long long module) {
    return (a * Xn + b) % module;
}

