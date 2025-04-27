/**
 * @file    vervoersmiddel_keuze.cpp
 * @author  Rob Beaufort
 * @brief   Dit is opdracht 3c van systeemarchitectuur. Hier wordt er geoefend met classes. 
 *          De gebruiker moet hierbij kiezen tussen een auto en een fiets. Het progamma zal dan de maximale snelheid van het voertuig teruggeven.
 * @version 1.0
 * @date    27-4-2025
 */
#include <iostream>

using namespace std;

// Dit is de class Vervoersmiddel. Deze zal gebruikt worden om vervoersmiddelen aan te maken.
class Vervoersmiddel{
    public:
        Vervoersmiddel(int snelheid);
        void maxSnelheid();
    private:
        int s;
};

// Deze functie geeft de maximale snelheid van een vervoersmiddel terug.
void Vervoersmiddel::maxSnelheid(){
    cout << "De maximale snelheid is: " << s << " km/h" << endl;
}

// Dit is de constructor van de class Vervoersmiddel. Hier wordt de snelheid van het vervoersmiddel ingesteld.
Vervoersmiddel::Vervoersmiddel(int snelheid){
    s = snelheid;
};

// Dit is het vervoersmiddel Auto.
class Auto: public Vervoersmiddel{
    public:
        Auto(int snelheid);
    private:
        int s;
};

Auto::Auto(int snelheid): Vervoersmiddel(snelheid){
    s = snelheid;
};

// Dit is het vervoersmiddel Fiets.
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

    string keuze;

    // Kies een vervoersmiddel.
    cout << "wil je een foets of een auto?" << endl;
    cin >> keuze;

    // Maak vervoersmiddel en geef maximales snelheid terug.
    if (keuze == "auto"){
        Auto* a = new Auto(140);
        a->maxSnelheid();
        delete a;

    } else if (keuze == "fiets"){
        Fiets* f = new Fiets(20);
        f->maxSnelheid();
        delete f;

    } else {
        cout << "Voer alleen auto of fiets in!" << endl;
    }

    return 0;
}