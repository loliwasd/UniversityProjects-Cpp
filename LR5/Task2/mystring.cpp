#include "mystring.h"
#include <cstring>

MyString::MyString(size_t size) : m_data(std::make_unique<char[]>(size)), m_size(size) {
    std::memset(m_data.get(), 0, m_size);
}

MyString::MyString(const char* str) {
    m_size = std::strlen(str) + 1;
    m_data = std::make_unique<char[]>(m_size);
    std::memcpy(m_data.get(), str, m_size);
}

MyString::MyString(const MyString& other) : m_size(other.m_size) {
    m_data = std::make_unique<char[]>(m_size);
    std::memcpy(m_data.get(), other.m_data.get(), m_size);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        m_size = other.m_size;
        m_data = std::make_unique<char[]>(m_size);
        std::memcpy(m_data.get(), other.m_data.get(), m_size);
    }
    return *this;
}

MyString::~MyString() {}

char* MyString::data() {
    return m_data.get();
}

const char* MyString::c_str() const {
    return m_data.get();
}

size_t MyString::length() const {
    return std::strlen(m_data.get());
}
