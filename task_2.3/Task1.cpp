/*
* 2.3 Для линейного конгруэнтного генератора чисел (https://ru.wikipedia.org/wiki/Линейный_конгруэнтный_метод)
* реализовать алгоритм вычисления последующего числа по четырем предыдущим. Считать параметр m
* не более 65535. Например, есть 4 числа : 157;  5054; 25789; 13214 Следующим за этими 
* числами будет число 16605.
*/

#include <iostream>
#include <numeric>

#include "functions.h"

int main()
{
    std::cout << "Enter first 4 numbers of your sequence (use spaces as delimeters): ";
    long long numbers[4] = { 0 };
    for (size_t i = 0; i < 4; i++) {
        std::cin >> numbers[i];
    }

    long long t1 = numbers[1] - numbers[0];
    long long t2 = numbers[2] - numbers[1];
    long long t3 = numbers[3] - numbers[2];

    long long z = t1 * t3 - t2 * t2;
    long long upper_bound = 65535;

    long long module = find_max_divisor(z, upper_bound);
    long long a = calculate_a(numbers, module);
    long long b = calculate_b(numbers, module, a);
       
    /*long long X = numbers[0];
    int tests = 1;
    std::cout << "Enter count of generated numbers for test: ";
    std::cin >> tests;
    for (int i = 0; i < tests; i++) {
        std::cout << X << ' ';
        X = generator(a, b, X, module);       
    }*/

    long long fifth_element = generator(a, b, numbers[3], module);
    std::cout << fifth_element << std::endl;
    std::cout << std::endl;

    return 0;
}