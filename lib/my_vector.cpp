#include <cassert>
#include <cstddef>
#include <cstdint>
#include <utility>

#include "my_vector.h"

MyVector::MyVector(std::size_t size) {
    size_ = size;
    capacity_ = size;

    begin_ = new std::int32_t[size_];
    end_ = begin_ + size_;
}

MyVector::MyVector(std::size_t size, std::int32_t val) {
    size_ = size;
    capacity_ = size;

    begin_ = new std::int32_t[size_];
    end_ = begin_ + size_;

    for (std::size_t i = 0; i < size_; ++i) {
        begin_[i] = val;
    }
}

MyVector::~MyVector() {
    delete[] begin_;
}

void MyVector::PushBack(std::int32_t val) {
    if (size_ == capacity_) {
        capacity_ = (capacity_ == 0 ? 1 : capacity_) * 2;
        std::int32_t* tmp = new std::int32_t[capacity_];

        for (std::size_t i = 0; i < size_; ++i) {
            tmp[i] = begin_[i];
        }

        delete[] begin_;
        begin_ = tmp;
    }

    begin_[size_] = val;
    ++size_;
    end_ = begin_ + size_;
}

void MyVector::PopBack() {
    --size_;
    --end_;
}

void MyVector::Resize(std::size_t size) {
    if (size > capacity_) {
        capacity_ = (capacity_ == 0 ? 1 : capacity_) * 2;
        std::int32_t* tmp = new std::int32_t[capacity_];

        for (std::size_t i = 0; i < size_; ++i) {
            tmp[i] = begin_[i];
        }

        delete[] begin_;
        begin_ = tmp;
    }

    size_ = size;
    end_ = begin_ + size_;
}

void MyVector::Assign(std::size_t size, std::int32_t val) {
    if (size > capacity_) {
        capacity_ = (capacity_ == 0 ? 1 : capacity_) * 2;
        std::int32_t* tmp = new std::int32_t[capacity_];

        delete[] begin_;
        begin_ = tmp;
    }

    size_ = size;
    end_ = begin_ + size_;

    for (std::size_t i = 0; i < size_; ++i) {
        begin_[i] = val;
    }
}

std::int32_t MyVector::operator[](std::size_t ind) {
    assert(ind < size_);
    return begin_[ind];
}

void MyVector::InsertSort() {
    for (std::size_t i = 1; i < size_; ++i) {
        std::int32_t j = i - 1;
        while (j >= 0 && begin_[j] > begin_[j + 1]) {
            std::swap(begin_[j], begin_[j + 1]);
            --j;
        }
    }
}

std::int32_t* MyVector::LowerBound(std::int32_t val) {
    int left = -1;
    int right = size_;

    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (begin_[mid] >= val) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (right == size_) {
        return end_;
    }

    return begin_ + right;
}