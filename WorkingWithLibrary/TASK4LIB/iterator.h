#ifndef ITERATOR_H
#define ITERATOR_H


template<typename T>
class Iterator
{
protected:
    T* ptr;

public:
    Iterator(T* p = nullptr) : ptr(p) {}

    T& operator*() {return *ptr;}
    Iterator& operator++() {++ptr; return *this;}
    Iterator& operator--() {--ptr; return *this;}
    Iterator operator+(int value) const { return Iterator(ptr + value);}
    Iterator operator-(int value) const { return Iterator(ptr - value);}
    bool operator==(const Iterator& other) const { return ptr == other.ptr;}
    bool operator!=(const Iterator& other) const { return ptr != other.ptr;}
    T& operator[](int index) {return *(ptr + index*sizeof(T));}
};

#endif // ITERATOR_H
