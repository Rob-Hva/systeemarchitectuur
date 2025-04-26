#include <iostream>

using namespace std;

class Complex{
    public:
        Complex(int reeel, int imaginair);
        drukAf();
        telOp(Complex);
    private:
        int re;
        int im;
};

Complex::Complex(int reeel, int imaginair){
    re = reeel;
    im = imaginair;

}

Complex::drukAf(){
    cout << "Het complexe getal is: " << re << " + " << im << "i" << endl;
}

Complex::telOp(Complex c){
    re = re + c.re;
    im = im + c.im;
}

int main(){ 

    int reInput;
    int imInput;

    cout << "het reeele getal 1: ";
    cin >> reInput;
    cout << "het imaginaire getal 1: ";
    cin >> imInput;

    Complex c1 = *new  Complex(reInput, imInput);
    c1.drukAf();

    cout << "het reeele getal 2: ";
    cin >> reInput;
    cout << "het imaginaire getal 2: ";
    cin >> imInput;

    delete &reInput;
    delete &imInput;

    Complex c2 = *new  Complex(reInput, imInput);
    c2.drukAf();

    c1.telOp(c2);
    delete &c2;
    
    c1.drukAf();

    delete &c1;
    return 0;
}