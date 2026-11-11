#pragma once

#include <cstddef>
#include <cstdint>

class MyVector {
public:
    MyVector() = default;
    MyVector(std::size_t size);
    MyVector(std::size_t size, std::int32_t val);
    ~MyVector();

    std::size_t GetSize() const {return size_;}
    std::int32_t* Begin() const {return begin_;}
    std::int32_t* End() const {return end_;}

    void PushBack(std::int32_t val);
    void PopBack();
    void Resize(std::size_t size);
    void Assign(std::size_t size, std::int32_t val);
    void Clear() { size_ = 0; }
    void InsertSort();
    std::int32_t* LowerBound(std::int32_t val);

    std::int32_t operator[](std::size_t ind);

private:
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
    std::int32_t* begin_ = nullptr;
    std::int32_t* end_ = nullptr;
};