/**
 * @file    complex_bestand.cpp
 * @author  Rob Beaufort
 * @brief   In dit progamma wordt er een complex getal uit het bestand complex.txt gelezen. 
 *          De waardes die het progamma uitleest zijn de radius en de hoek in graden.
 *          Dez waardes komen in het volgende format uit het bestand:
 *          R:x H:y
 *          Deze waardes worden vervolgens omgerekend naar een reeel en imaginair deel.
 *          Tot slot worden alle waardes in een vector van objecten opgeslagen van de class Complex.
 * @version 1.0
 * @date    14-5-2025
 */

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

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
    hoekRad = hoek / 180.0;
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
    return left;
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

// Hier wordt er een bestand met complexe getallen uitgelezen.
void readComplexFile(vector<int>& radInput, vector<int>& hoekInput, int& aantalRegelsInput){
    ifstream complexFile("C:\\school\\ProgameerOmgeving\\gcc-voorbeelden-hva\\systeemarchitectuur\\sys_opdracht_4d\\src\\complex.txt");

    string inputBuffer;
    int R;
    int H;

    if (!complexFile){
        throw runtime_error("kon bestand niet openen");
    }

    while (getline(complexFile, inputBuffer)){
        aantalRegelsInput++;
        cout << inputBuffer << endl;
        sscanf(inputBuffer.c_str(), "R:%d H:%d", &R, &H);
        radInput.push_back(R);
        hoekInput.push_back(H);
    }

    complexFile.close();
}

int main(){ 

    // Hier worden alle vectoren en variabelen aangemaakt.
    vector<int> hoekInput;
    vector<int> radInput;
    int aantalRegelsInput = 0;

    // Hier wordt er een bestand met complexe getallen uitgelezen.
    readComplexFile(radInput, hoekInput, aantalRegelsInput);

    // Hier worden alle waardes aan de objecten toegekend.
    vector<Complex> complexen;
    for (int i = 0; i < aantalRegelsInput; i++){
        complexen.emplace_back(hoekInput[i], radInput[i]);
    }

    // Hier worden alle waardes van de complexe getallen afgedrukt.
    for (int i = 0; i < aantalRegelsInput; i++){
        cout << complexen[i];
    }
    
    return 0;
}