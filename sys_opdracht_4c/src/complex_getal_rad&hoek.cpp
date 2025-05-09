/**
 * @file    complex_getal_radENhoek.cpp
 * @author  Rob Beaufort
 * @brief   Er kan een complex getal aangemaakt worden. Dit getal kan je een radius en een hoek meegeven.
 *          Daarnaast kunnen er complexen met elkaar en met integers vermenigvuldigd worden.
 *          Vervolgens kan de het complexe getal worden afgedrukt met <<.
 * @version 1.0
 * @date    9-5-2025
 */

#include <iostream>
#include <cmath>

using namespace std;

// Dit is de class Complex. hier wordt een complex getal in opgeslagen.
class Complex{
    public:
        Complex(int hoek, int radius);
        void drukAf();
        int radius;
        Complex operator*(Complex& second);
        Complex operator*(int second);
        friend Complex operator*(int scalar, const Complex& complex);
        friend ostream& operator<<(ostream& left, Complex& complex);

    private:
        static int aantalComplexen;

        int cNummer;
        int hoek;
        double reeel;
        double imaginair;
        double hoekRad;
};

// In deze variabele wordt bijgehouden hoeveel complexe getallen er zijn.
int Complex::aantalComplexen = 0;

// Dit is de constructor. Hier worden alle waardes berekend en aan het object toegekend.
Complex::Complex(int hoek, int radius){

    // Hier wordt het aantal complexe getallen verhoogd en wordt er een nummer gegeven aan het object.
    aantalComplexen++;
    cNummer = aantalComplexen;

    // Hier wodr de hoek berekend en de radius meegegeven
    this->hoek = hoek;
    hoekRad = hoek * M_PI / 180.0;
    this->radius = radius;

    // Hier worden het reeele en imaginaire deel berekend.
    reeel = radius * cos(hoekRad);
    imaginair = radius * sin(hoekRad);
}

// Hier kunnen 2 complexe getallen met elkaar worden vermenigvuldigd in de exponentiele vorm.
Complex Complex::operator*(Complex& second){
    double newHoek = this->hoek + second.hoek;
    double newRadius = this->radius * second.radius;
    int newNummer;

    return Complex(newHoek, newRadius);
}

Complex Complex::operator*(int second){
    double newHoek = this->hoek;
    double newRadius = second * this->radius;

    return Complex(newHoek, newRadius);
}

// Hier wordt de operator << overloaded. Dit zorg
ostream& operator<<(ostream& left, Complex& complex){
    complex.drukAf();
}

Complex operator*(int scalar, const Complex& complex){
    // Vermenigvuldig de radius met de scalar
    int newRadius = complex.radius * scalar;

    // Maak een nieuw Complex-object met de nieuwe radius
    return Complex(complex.hoek, newRadius);
}

// Hier worden de waardes van het complexe getal geprint.
void Complex::drukAf(){
    cout << endl;
    cout << "dit is complex getal nummer: " << cNummer << endl;
    cout << "----------------------------------------" << endl;
    cout << "De hoek in graden is: " << hoek << endl;
    cout << "De hoek in PIradialen is: " << hoekRad << endl;
    cout << "De radius is: " << radius << endl;
    cout << "Het complex getal is: " << reeel << " + " << imaginair << "i" << endl;
}

int main(){ 

    int hoekInput;
    int radInput;

    // Hier kiest de gebruiker de waardes voor complex getal 1.
    cout << "De hoek getal 1: ";
    cin >> hoekInput;
    cout << "De radius getal 1: ";
    cin >> radInput;

    Complex c1 = *new  Complex(hoekInput, radInput);
    
    // Hier kiest de gebruiker de waardes voor complex getal 2.
    cout << "De hoek getal 2: ";
    cin >> hoekInput;
    cout << "De radius getal 2: ";
    cin >> radInput;

    Complex c2 = *new  Complex(hoekInput, radInput);
    Complex c3 = c1 * c2;
    Complex c4 = c3 * 3;
    Complex c5 = 3 * c3;

    // Hier worden alle waardes van de complexe getallen afgedrukt.
    cout << c1;
    cout << c2;
    cout << c3;
    cout << c4;
    cout << c5;

    return 0;
}