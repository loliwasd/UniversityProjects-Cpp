#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include "iterator.h"

template<typename T>
class Vector : public Iterator<T>
{
private:
    T* data;
    size_t sz;
    size_t cap;

    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < sz; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        cap = new_cap;
    }

public:
    Vector() : data(nullptr), sz(0), cap(0) {}

    ~Vector() {
        delete[] data;
    }

    size_t size() const { return sz; }

    size_t capacity() const { return cap; }

    bool empty() const { return sz == 0; }

    void push_back(const T& value) {
        if (sz == cap) {
            reallocate(cap == 0 ? 1 : cap * 2);
        }
        data[sz++] = value;
    }

    void pop_back() {
        if (empty()) throw std::out_of_range("Vector is empty");
        --sz;
    }

    T& front() {
        if (empty()) throw std::out_of_range("Vector is empty");
        return data[0];
    }

    const T& front() const {
        if (empty()) throw std::out_of_range("Vector is empty");
        return data[0];
    }

    T& back() {
        if (empty()) throw std::out_of_range("Vector is empty");
        return data[sz - 1];
    }

    const T& back() const {
        if (empty()) throw std::out_of_range("Vector is empty");
        return data[sz - 1]; //overwriting back()? same arguments, different return
    }

    T& at(size_t index) {
        if (index >= sz) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& at(size_t index) const {
        if (index >= sz) throw std::out_of_range("Index out of range");
        return data[index];
    }

    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    void clear() {
        sz = 0;
    }

    T* get_data() {
        return data;
    }

    const T* get_data() const {
        return data;
    }

    void assign(const T* arr, size_t count) {
        clear();
        if (count > cap) {
            reallocate(count);
        }
        for (size_t i = 0; i < count; ++i) {
            data[i] = arr[i];
        }
        sz = count;
    }

    void reserve(size_t new_cap) {
        if (new_cap > cap) {
            reallocate(new_cap);
        }
    }

    void resize(size_t new_size) {
        if (new_size > cap) {
            reallocate(new_size);
        }
        if (new_size > sz) {
            for (size_t i = sz; i < new_size; ++i) {
                data[i] = T();
            }
        }
        sz = new_size;
    }

    void insert(size_t index, const T& value) {
        if (index > sz) throw std::out_of_range("Index out of range");
        if (sz == cap) reallocate(cap == 0 ? 1 : cap * 2);

        for (size_t i = sz; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++sz;
    }

    void erase(size_t begin_index, size_t end_index) {
        if (begin_index >= sz || end_index > sz || begin_index > end_index) {
            throw std::out_of_range("Index out of range");
        }
        size_t delta = end_index - begin_index;
        for (size_t i = begin_index; i + delta < sz; ++i) {
            data[i] = data[i + delta];
        }
        sz -= delta;
    }

    void swap(Vector<T>& other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
        std::swap(cap, other.cap);
    }

    size_t max_size() const {
        return static_cast<size_t>(-1) / sizeof(T);
    }

    T* begin() { return data; }
    const T* begin() const { return data; }

    T* end() { return data + sz; }
    const T* end() const { return data + sz; }

    const T* cbegin() const { return data; }

    T* rbegin() { return data + sz - 1; }
    const T* rbegin() const { return data + sz - 1; }

    T* rend() { return data - 1; }
    const T* rend() const { return data - 1; }

    template<typename... Args>
    void emplace(size_t index, Args&&... args) {
        if (index > sz) throw std::out_of_range("Index out of range");
        if (sz == cap) reallocate(cap == 0 ? 1 : cap * 2);

        for (size_t i = sz; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = T(std::forward<Args>(args)...);
        ++sz;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
        if (sz == cap) reallocate(cap == 0 ? 1 : cap * 2);
        data[sz++] = T(std::forward<Args>(args)...);
    }
};
