/**
 * @file    complex_getal_radENhoek.cpp
 * @author  Rob Beaufort
 * @brief   Er kan een complex getal aangemaakt worden. Dit getal kan je een radius en een hoek meegeven.
 * @version 1.0
 * @date    7-5-2025
 */

#include <iostream>
#include <cmath>

using namespace std;

// Dit is de class Complex. hier wordt een complex getal in opgeslagen.
class Complex{
    public:
        Complex(int hoek, int radius);
        void drukAf();

    private:
        int hoe;
        int rad;
        double argument;
};

Complex::Complex(int hoek, int radius){
    hoe = hoek;
    rad = radius;

}

// Hier worden de waardes van het complexe getal geprint.
void Complex::drukAf(){
    cout << "De hoek is: " << hoe << endl;
    cout << "De radius is: " << rad << endl;
}

int main(){ 

    int hoeInput;
    int radInput;

    // Hier kiest de gebruiker de waardes voor complex getal 1.
    cout << "De hoek getal 1: ";
    cin >> hoeInput;
    cout << "De radius getal 1: ";
    cin >> radInput;

    Complex c1 = *new  Complex(hoeInput, radInput);
    
    // Hier kiest de gebruiker de waardes voor complex getal 2.
    cout << "De hoek getal 2: ";
    cin >> hoeInput;
    cout << "De radius getal 2: ";
    cin >> radInput;

    Complex c2 = *new  Complex(hoeInput, radInput);

    c1.drukAf();
    c2.drukAf();
    
    return 0;
}