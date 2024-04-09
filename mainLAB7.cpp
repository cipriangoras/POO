#include <iostream>
using namespace std;


float operator"" _Kelvin(long double kelvin) {
    return kelvin - 273.15;
}
float operator"" _Fahrenheit(long double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9; 
}


int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    cout << a<<endl;
    cout << b << endl;
    return 0;
}
