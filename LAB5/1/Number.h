class Number {
    private:
        char* number;
        int base;

        int GetBase10Value() const;
        void SetFromBase10Value(int value, int newBase);;
        int strlen(const char* string) const;
        void strcpy(char* dest, const char* src) const;

    public:
        Number(const char* number, int base);
        Number(const Number& other);
        Number(int value);
        Number(Number&& other);
        ~Number();

        Number& operator=(const Number&& other);
        Number& operator=(Number&& other);
        Number& operator=(const char* str);
        Number& operator=(int value);

        friend Number operator+(const Number& a, const Number& b);
        friend Number operator-(const Number& a, const Number& b);

        Number& operator+=(const Number& b);
        Number& operator-=(const Number& b);
        
        Number& operator--(); // prefix
        Number operator--(int); // postfix

        bool operator==(const Number& other) const;
        bool operator!=(const Number& other) const;
        bool operator<(const Number& other) const;
        bool operator>(const Number& other) const;
        bool operator<=(const Number& other) const;
        bool operator>=(const Number& other) const;
        char operator[](int index) const;

        void SwitchBase(int newBase);
        void Print() const;
        int GetDigitsCount() const;
        int GetBase() const;
};