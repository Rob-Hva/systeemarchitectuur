#include <iostream>

using namespace std;

class Complex{
    public:
        Complex(int reel, int imaginair);
        drukAf();
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

int main(){ 

    int reInput;
    int imInput;

    cout << "het reeele getal: ";
    cin >> reInput;
    cout << "het imaginaire getal: ";
    cin >> imInput;

    Complex c1 = *new  Complex(reInput, imInput);
    c1.drukAf();

    delete &c1;
    return 0;
}