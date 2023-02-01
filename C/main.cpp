#include <iostream>
#include <cmath>
#include <iomanip>

double function(double num) {
    return (num * num + sqrt(num));
}

double realBinarySearch(double num) {
    double left = sqrt(num) / 2, right = sqrt(num), mid;
    while (right - left > 0.000001) {
        mid = left + (right - left) / 2;
        if (function(mid) > num) {
            right = mid;
        } else {
            left = mid;
        }
    }
    mid = left + (right - left) / 2;
    return mid;
}

int main() {
    double num;
    std::cin >> num;
    std::cout << std::fixed << std::setprecision(6) << realBinarySearch(num) << std::endl;
    return 0;
}
