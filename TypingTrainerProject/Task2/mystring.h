#ifndef MYSTRING_H
#define MYSTRING_H

#include <memory>
#include <cstddef>

class MyString {
public:
    MyString(size_t size);
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    char* data();
    const char* c_str() const;
    size_t length() const;

private:
    std::unique_ptr<char[]> m_data;
    size_t m_size;
};

#endif // MYSTRING_H
