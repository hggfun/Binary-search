#include <iostream>
#include <vector>

int leftBinarySearch(const std::vector<int>& vec, int num) {
    size_t left = 0, right = vec.size(), mid = right / 2;
    while (left < right - 1) {
        if (vec[mid] < num) {
            left = mid;
            mid = left + (right - left) / 2;
        } else {
            right = mid;
            mid = left + (right - left) / 2;
        }
    }
    if (vec[mid] != num) {
        ++mid;
    }
    if (mid >= vec.size() || vec[mid] != num) {
        mid = -1;
    }
    return static_cast<int>(mid);
}

int rightBinarySearch(const std::vector<int>& vec, int num) {
    size_t left = 0, right = vec.size(), mid = right / 2;
    while (left < right - 1) {
        if (vec[mid] > num) {
            right = mid;
            mid = left + (right - left) / 2;
        } else {
            left = mid;
            mid = left + (right - left) / 2;
        }
    }
    if (vec[mid] != num) {
        --mid;
    }
    if (mid < 0 || vec[mid] != num) {
        mid = -1;
    }
    return static_cast<int>(mid);
}

int main() {
    int t1, t2, inp, index, index2;
    std::cin >> t1 >> t2;
    std::vector<int> numbers;
    for (int i = 0; i < t1; ++i) {
        std::cin >> inp;
        numbers.push_back(inp);
    }
    for (int i = 0; i < t2; ++i) {
        std::cin >> inp;
        index = leftBinarySearch(numbers, inp) + 1;
        if (index == 0) {
            std::cout << 0 << std::endl;
            continue;
        } else {
            index2 = rightBinarySearch(numbers, inp) + 1;
            std::cout << index << " " << index2 << std::endl;
        }
    }
    return 0;
}
