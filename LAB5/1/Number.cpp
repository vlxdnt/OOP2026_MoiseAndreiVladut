#include "Number.h"
#include <stdio.h>

// metode helper

int Number::strlen(const char* string) const {
    int index = 0;
    while (string[index] != '\0')
        index++;
    return index;
}

void Number::strcpy(char* dest, const char* src) const {
    int index = 0;
    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
}

int Number::GetBase10Value() const {
    int value = 0;
    for (int i = 0; number[i] != '\0'; i++) {
        char c = number[i];
        int digit = (c >= 'A') ? (c >= 'a' ? c - 'a' + 10 : c - 'A' + 10) : (c - '0');
        value = value * base + digit;
    }
    return isNegative ? -value : value;
}

void Number::SetFromBase10Value(int value, int newBase) {
    char buffer[64];
    int index = 0;
    base = newBase;
    isNegative = (value < 0);
    int absValue = isNegative ? -value : value;

    if (absValue == 0)
        buffer[index++] = '0';
    else {
        while (absValue > 0) {
            int remainder = absValue % newBase;
            buffer[index++] = (remainder < 10) ? ('0' + remainder) : ('A' + remainder - 10);
            absValue /= newBase; 
        }
    }

    buffer[index] = '\0';

    for (int i = 0; i < index / 2; i++) {
        char t = buffer[i];
        buffer[i] = buffer[index - i - 1];
        buffer[index - i - 1] = t;
    }

    delete[] number;
    number = new char[index + 1];
    strcpy(number, buffer);
}

// constructori & destructor

Number::Number(const char* number, int base) {
    this->base = base;
    
    int startIndex = 0;
    if (number[0] == '-') {
        startIndex++;
        isNegative = true;
    }
    else
        isNegative = false;

    this->number = new char[strlen(number + startIndex) + 1];
    strcpy(this->number, number + startIndex);

    if (this->number[0] == '0' && this->number[1] == '\0')
        isNegative = false;
}

Number::Number(const Number& other) {
    this->base = other.base;
    isNegative = other.isNegative;

    this->number = new char[strlen(other.number) + 1];
    strcpy(this->number, other.number);
}

Number::Number(Number&& other) {
    this->base = other.base;
    isNegative = other.isNegative;
    this->number = other.number;

    other.number = nullptr; 
    other.isNegative = false;
}

Number::Number(int value) {
    this->number = nullptr;
    SetFromBase10Value(value, 10);
}

Number::~Number() {
    delete[] number;
}

// metode membre

void Number::Print() const {
    if (isNegative)
        printf("Number: -%s, Base: %d\n", number, base);
    else
        printf("Number: %s, Base: %d\n", number, base);
}

int Number::GetBase() const {
    return this->base;
}

int Number::GetDigitsCount() const {
    if (isNegative)
        return strlen(this->number) - 1;
    else
        return strlen(this->number);
}

void Number::SwitchBase(int newBase) {
    if (this->base == newBase) 
        return;

    int value = GetBase10Value();
    SetFromBase10Value(value, newBase);
}

// operator overloading

Number& Number::operator=(const Number&& other) {
    if (this != &other) {
        delete[] number; 

        this->base = other.base;
        isNegative = other.isNegative;

        number = new char[strlen(other.number) + 1];
        strcpy(this->number, other.number);
    }
    return *this;
}

Number& Number::operator=(Number&& other) {
    if (this != &other) {
        delete[] number; 

        this->base = other.base;
        isNegative = other.isNegative;
        this->number = other.number;

        other.number = nullptr; 
    }
    return *this;
}

Number& Number::operator=(const char* str) {
    delete[] number; 

    int startIndex = 0;
    if (str[0] == '-') {
        isNegative = true;
        startIndex++;
    }
    else
        isNegative = false;

    this->number = new char[strlen(str + startIndex) + 1];
    strcpy(this->number, str + startIndex);

    if (this->number[0] == '0' && this->number[1] == '\0')
        isNegative = false;

    return *this;
}

Number& Number::operator=(int value) {
    SetFromBase10Value(value, this->base);
    return *this;
}

bool Number::operator==(const Number& other) const {
    return this->GetBase10Value() == other.GetBase10Value();
}

bool Number::operator!=(const Number& other) const {
    return !(*this == other);
}

bool Number::operator<(const Number& other) const {
    return this->GetBase10Value() < other.GetBase10Value();
}

bool Number::operator>(const Number& other) const {
    return other < *this;
}

bool Number::operator<=(const Number& other) const {
    return !(*this > other);
}

bool Number::operator>=(const Number& other) const {
    return !(*this < other);
}

char Number::operator[](int index) const {
    if (index < 0 || index >= GetDigitsCount()) 
        return false; // index invalid
    return number[index];
}

Number operator+(const Number& a, const Number& b) {
    int maxBase = (a.GetBase() > b.GetBase()) ? a.GetBase() : b.GetBase();
    Number result(0);

    result.SetFromBase10Value(a.GetBase10Value() + b.GetBase10Value(), maxBase);
    return result;
}

Number operator-(const Number& a, const Number& b) {
    int maxBase = (a.GetBase() > b.GetBase()) ? a.GetBase() : b.GetBase();
    Number result(0);

    result.SetFromBase10Value(a.GetBase10Value() - b.GetBase10Value(), maxBase);
    return result;
}

Number& Number::operator+=(const Number& b) {
    int maxBase = (this->GetBase() > b.GetBase()) ? this->GetBase() : b.GetBase();
    SetFromBase10Value(this->GetBase10Value() + b.GetBase10Value(), maxBase);
    return *this;
}

Number& Number::operator-=(const Number& b) {
    int maxBase = (this->GetBase() > b.GetBase()) ? this->GetBase() : b.GetBase();
    SetFromBase10Value(this->GetBase10Value() - b.GetBase10Value(), maxBase);
    return *this;
}

Number& Number::operator--() {
    if (number != nullptr && number[0] != '\0') {
        int len = strlen(number);
        for (int i = 0; i < len; i++)
            number[i] = number[i+1];
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);

    if (number != nullptr && number[0] != '\0')
        number[strlen(number) - 1] = '\0';

    return temp;
}