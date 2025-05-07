#include <iostream>
#include <cmath>

using namespace std;

class Complex{
    public:
        Complex(int reeel, int imaginair);
        void drukAf();
        void telOp(Complex);
        void DrukAfRadiaal();
        void DrukAfLengte();
    private:
        int re;
        int im;
        double argument;
};

Complex::Complex(int reeel, int imaginair){
    re = reeel;
    im = imaginair;

}

void Complex::drukAf(){
    cout << "Het complexe getal is: " << re << " + " << im << "i" << endl;
}

void Complex::telOp(Complex c){
    re = re + c.re;
    im = im + c.im;
}

void Complex::DrukAfRadiaal(){
    argument = atan2(im, re) / M_PI;
    cout << "Het argument is: " << argument << " PIrad" << endl;
}

void Complex::DrukAfLengte(){
    float lengte = sqrt(re * re + im * im);
    cout << "De lengte is: " << lengte << endl;
}

int main(){ 

    int reInput;
    int imInput;

    cout << "het reeele getal 1: ";
    cin >> reInput;
    cout << "het imaginaire getal 1: ";
    cin >> imInput;

    Complex c1 = *new  Complex(reInput, imInput);

    cout << "het reeele getal 2: ";
    cin >> reInput;
    cout << "het imaginaire getal 2: ";
    cin >> imInput;

    Complex c2 = *new  Complex(reInput, imInput);

    delete &reInput;
    delete &imInput;

    c1.DrukAfRadiaal();
    c1.DrukAfLengte();
    delete &c1;

    c2.DrukAfRadiaal();
    c2.DrukAfLengte();
    delete &c2;

    return 0;
}