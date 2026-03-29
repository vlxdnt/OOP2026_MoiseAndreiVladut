#include <stdio.h>

float operator"" _Kelvin(unsigned long long k) {
    return static_cast<float>(k - 273.15);
}

float operator"" _Fahrenheit(unsigned long long f) {
    return static_cast<float>((f - 32.0) * 5.0 / 9.0);
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    
    printf("300 Kelvin in Celsius: %.2f\n", a);
    printf("120 Fahrenheit in Celsius: %.2f\n", b);
    return 0;
}