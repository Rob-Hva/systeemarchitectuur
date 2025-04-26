#include <iostream>

using namespace std;

class Vervoersmiddel{
    public:
        Vervoersmiddel(int snelheid);
        void maxSnelheid();
    private:
        int s;
};

void Vervoersmiddel::maxSnelheid(){
    cout << "De maximale snelheid is: " << s << " km/h" << endl;
}

Vervoersmiddel::Vervoersmiddel(int snelheid){
    s = snelheid;
};

class Auto: public Vervoersmiddel{
    public:
        Auto(int snelheid);
    private:
        int s;
};

Auto::Auto(int snelheid): Vervoersmiddel(snelheid){
    s = snelheid;
};

class Fiets: public Vervoersmiddel{
    public:
        Fiets(int snelheid);
    private:
        int s;
};

Fiets::Fiets(int snelheid): Vervoersmiddel(snelheid){
    s = snelheid;
};

int main(){ 

    Auto* a = new Auto(140);
    Fiets* f = new Fiets(20);

    a->maxSnelheid();
    delete a;

    f->maxSnelheid();
    delete f;
    
    return 0;
}