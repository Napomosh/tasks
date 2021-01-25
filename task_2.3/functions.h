#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H_

long long find_max_divisor(long long number, long long upper_bound);
long long gcdex(long long a, long long b, long long& x, long long& y);
long long find_reverse(long long a, long long m, long long& x, long long& y);
long long calculate_a(const long long* numbers, long long module);
long long calculate_b(const long long* numbers, long long module, long long a);

// Generate next 
long long generator(long long a, long long b, long long Xn, long long module);

#endif //_FUNCTIONS_H_