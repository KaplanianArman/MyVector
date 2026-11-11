#include <cstdint>
#include <cstddef>
#include <iostream>

#include "lib/my_vector.h"

int main() {
    std::size_t n1;
    std::cin >> n1;
    MyVector vec1{};

    for (std::size_t i = 0; i < n1; ++i) {
        std::int32_t cur;
        std::cin >> cur;
        vec1.PushBack(cur);
    }

    for (std::size_t i = 0; i < n1; ++i) {
        std::cout << vec1[i] << ' ';
    }
    std::cout << '\n';

    vec1.InsertSort();

    for (std::size_t i = 0; i < n1; ++i) {
        std::cout << vec1[i] << ' ';
    }
    std::cout << '\n';

    std::int32_t val;
    std::cin >> val;

    std::int32_t* lb = vec1.LowerBound(val);
    if (lb == vec1.End()) {
        std::cout << "All elements are smaller than val\n";
    } else {
        std::cout << *lb << '\n';
    }

    return 0;
}