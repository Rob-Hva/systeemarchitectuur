#include <iostream>

using namespace std;

struct breuk{
    int teller;
    int noemer;
    
};

breuk& telop(breuk& b1, breuk& b2, breuk& b3){
    b3.teller = b1.teller * b2.noemer + b2.teller * b1.noemer;
    b3.noemer = b1.noemer * b2.noemer;

}

void drukaf(breuk& b3){
    cout << "De nieuwe breuk = " << b3.teller << " / " << b3.noemer << "\n";

}

int main(){ 

    breuk b1;   
    cout << "Geef de teller 1: ";
    cin >> b1.teller;
    cout << "Geef de noemer 1: ";
    cin >> b1.noemer;

    breuk b2;  
    cout << "Geef de teller 2: ";
    cin >> b2.teller;
    cout << "Geef de noemer 2: ";
    cin >> b2.noemer;

    breuk b3;
    telop(b1, b2, b3);
    drukaf(b3);

    return 0;
}