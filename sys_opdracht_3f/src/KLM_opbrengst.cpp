/**
 * @file    KLM_vluchten.cpp
 * @author  Rob Beaufort
 * @brief   Dit is opdracht 3f van systeemarchitectuur. Hier wordt verder gebouwd op opdracht 3e. 
 *          Het doel van dit progamma is om de opbrengst van een vlucht te berekenen.
 *          Dit worddt gedaan door de afstand van de vlucht te vermeningvuldigen met het aantal passagiers.
 *          Deze afstanden zijn geen ecte afstanden. Ik heb deze namelijk zelf bedacht.
 * @version 1.0
 * @date    6-5-2025
 */
#include <iostream>
#include <string>

#define AANTAL_PILOTEN 2
#define AANTAL_CREWLEDEN 5
#define AANTAL_PASSAGIERS 100
#define AFSTAND_AMSTERDAM 69
#define AFSTAND_PARIJS 420

using namespace std;

// Hier wordt de meegegeven array gevult met objecten van de meegegeven class.
template <typename ClassType>
void fillClassArray(ClassType *array[], int AantalObjecten){
    for (int i = 0; i < AantalObjecten; i++){    
        array[i] = new ClassType(i);
    }
}

// Hier wordt de meegegeven array gevult met objecten van de meegegeven class.
template <typename ClassType>
void deleteClassArray(ClassType *array[], int AantalObjecten){
    for (int i = 0; i < AantalObjecten; i++){    
        delete array[i];
    }
}

// Deze functie laat alle objecten in de array hallo zeggen.
template <typename ClassType>
void allHallo(ClassType array[], int AantalObjecten){
    for (int i = 0; i < AantalObjecten; i++){
        array[i]->hallo();
    }
}

class vliegtuigen{
    public:
        virtual void hallo();
    private:

};

void vliegtuigen::hallo(){
    cout << "Hallo ik ben een vliegtuig." << endl;
}

// Boieng737 is een vliegtuig.
class boieng737: public vliegtuigen{
    public:
        void hallo();
    private:

};

void boieng737::hallo(){
    cout << "Hallo ik ben een Boieng 737." << endl;
}

// AirbusA320 is een vliegtuig.
class airbusA320: public vliegtuigen{
    public:
        void hallo();
    private:

};

void airbusA320::hallo(){
    cout << "Hallo ik ben een airbusA320." << endl;
}

class personeel{
    public:

    private:

};

// Piloten zijn personeel.
class piloot: public personeel{
    public:
        piloot(int nummer);
        void hallo();
    private:
        int n;
};

// Geef de piloot een nummer.
piloot::piloot(int nummer){
    n = nummer;
}

// De piloot zegt hallo.
void piloot::hallo(){
    cout << "Hallo ik ben piloot nummer " << n << "." << endl;
}

// Crew is personeel.
class crew: public personeel{
    public:
        crew(int nummer);
        void hallo();
    private:
        int n;

};

// Geef het crewlid een nummer.
crew::crew(int nummer){
    n = nummer;
}

// Het crewlid zegt hallo.
void crew::hallo(){
    cout << "Hallo ik ben crewlid nummer " << n << "." << endl;
}

class passagier{
    public:
        passagier(int nummer);
        void hallo();
    private:
        int n;
};

passagier::passagier(int nummer){
    n = nummer;
}

void passagier::hallo(){
    cout << "Hallo ik ben passagier nummer " << n << "." << endl;
}

// Vluchten hebben passagiers, piloten, viliegtuigen en een crew.
class Vlucht{
    public:
        Vlucht(string vliegtuig, piloot *Piloten[], crew *crewlid[], string bestemming, passagier *passagiers[]);
        ~Vlucht();
        int opbrengst();
        void hallo();
    private:
        passagier *pas[AANTAL_PASSAGIERS];
        vliegtuigen* vli;
        crew *cre[AANTAL_CREWLEDEN];
        piloot *pil[AANTAL_PILOTEN];
        string bes;
};

Vlucht::Vlucht(string vliegtuig, piloot *Piloten[], crew *crewlid[], string bestemming, passagier *passagiers[]){

    // Kies een vliegtuig.
    if (vliegtuig == "boieng737"){
        vli = new boieng737;
    } else if (vliegtuig == "airbusA320"){
        vli = new airbusA320;
    } else {
        cout << "Dit vliegtuig bestaat nog niet." << endl;
    }


    // Hier wordt een copy constructor gebruikt om de meegegeven array van piloten in het niewe object te kopieeren.
    for (int i = 0; i < AANTAL_PILOTEN; i++){
        pil[i] = new piloot(*Piloten[i]);;
    }

    // Hier wordt een copy constructor gebruikt om de meegegeven array van crewleden in het niewe object te kopieeren.
    for (int i = 0; i < AANTAL_CREWLEDEN; i++){
        cre[i] = new crew(*crewlid[i]);;
    }

    // Kies een bestemming.
    bes = bestemming;

    // Hier wordt een copy constructor gebruikt om de meegegeven array van passagiers in het niewe object te kopieeren.
    for (int i = 0; i < AANTAL_PASSAGIERS; i++){
        pas[i] = new passagier(*passagiers[i]);;
    }
    
}

Vlucht::~Vlucht(){

    delete vli;

    // hier worden alle piloten verwijderd.
    for (int i = 0; i < AANTAL_PILOTEN; i++){
        delete pil[i];
    }

    // Hier worden alle crewleden verwijderd.
    for (int i = 0; i < AANTAL_CREWLEDEN; i++){
        delete cre[i];
    }

    // Hier wordten alle piloten verwijderd.
    for (int i = 0; i < AANTAL_PASSAGIERS; i++){
        delete pas[i];
    }
    
}

int Vlucht::opbrengst(){
    int afstand;
    if (bes == "Amsterdam"){
        afstand = AFSTAND_AMSTERDAM;
    } else if (bes == "Parijs"){
        afstand = AFSTAND_PARIJS;
    }
    return AANTAL_PASSAGIERS * afstand;
}

void Vlucht::hallo(){
    cout << "Hallo ik ben een vlucht naar " << bes << "." << endl;
    vli->hallo();
    allHallo(pil, AANTAL_PILOTEN);
    allHallo(cre, AANTAL_CREWLEDEN);
    allHallo(pas, AANTAL_PASSAGIERS);
}

int main(){

    piloot *Piloten[AANTAL_PILOTEN];
    crew *crewlid[AANTAL_CREWLEDEN];
    passagier *passagiers[AANTAL_PASSAGIERS];

    fillClassArray(Piloten, AANTAL_PILOTEN);
    fillClassArray(crewlid,  AANTAL_CREWLEDEN);
    fillClassArray(passagiers, AANTAL_PASSAGIERS);

    Vlucht& v1 = *new Vlucht("boieng737", Piloten, crewlid, "Amsterdam", passagiers);
    Vlucht& v2 = *new Vlucht("airbusA320", Piloten, crewlid, "Parijs", passagiers);
    
    // Hier worden de arrays verwijderd omdat ze nu naar het object v1 zijn gekopieerd.
    deleteClassArray(Piloten, AANTAL_PILOTEN);
    deleteClassArray(crewlid, AANTAL_CREWLEDEN);
    deleteClassArray(passagiers, AANTAL_PASSAGIERS);

    v1.hallo();
    v2.hallo();

    cout << "de opbrengst voor vlucht 1 = " << v1.opbrengst() << endl;
    delete &v1;
    cout << "de opbrengst voor vlucht 1 = " << v2.opbrengst() << endl;
    delete &v2;

    return 0;
}