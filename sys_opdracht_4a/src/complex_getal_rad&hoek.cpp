#include <iostream>
#include <cmath>

using namespace std;

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

void Complex::drukAf(){
    cout << "De hoek is: " << hoe << endl;
    cout << "De radius is: " << rad << endl;
}

int main(){ 

    int hoeInput;
    int radInput;

    cout << "De hoek getal 1: ";
    cin >> hoeInput;
    cout << "De radius getal 1: ";
    cin >> radInput;

    Complex c1 = *new  Complex(hoeInput, radInput);

    cout << "De hoek getal 2: ";
    cin >> hoeInput;
    cout << "De radius getal 2: ";
    cin >> radInput;

    Complex c2 = *new  Complex(hoeInput, radInput);

    c1.drukAf();
    c2.drukAf();
    
    return 0;
}