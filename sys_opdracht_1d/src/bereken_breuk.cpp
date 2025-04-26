#include <iostream>

using namespace std;

struct breuk{
    int teller;
    int noemer;
    float antwoord;
};

void bereken_breuk(breuk& b){
    b.antwoord = (float)b.teller / b.noemer;
}

void drukaf(breuk& b){
    cout << "teller = " << b.teller << "\n";
    cout << "noemer = " << b.noemer << "\n";
    cout << "antwoord = " << b.antwoord << "\n";
}

int main(){ 
    breuk b;   
    cout << "geef de teller: ";
    cin >> b.teller;
    cout << "geef de noemer: ";
    cin >> b.noemer;

    bereken_breuk(b);
    drukaf(b);

    return 0;
}