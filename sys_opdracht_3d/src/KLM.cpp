/**
 * @file    KLM.cpp
 * @author  Rob Beaufort
 * @brief   Dit is opdracht 3d van systeemarchitectuur. Hier wordt er geoefend met classes. 
 *          Deze classes maken onderdeel uit van een vliegtuigmaatschappij.
 * @version 1.0
 * @date    27-4-2025
 */
#include <iostream>

using namespace std;

class vliegtuigen{
    public:

    private:

};

// Boieng737 is een vliegtuig.
class boieng737: public vliegtuigen{
    public:

    private:

};

// AirbusA320 is een vliegtuig.
class airbusA320: public vliegtuigen{
    public:

    private:

};

class personeel{
    public:

    private:

};

// Piloten zijn personeel.
class piloten: public personeel{
    public:

    private:

};

// Crew is personeel.
class crew: public personeel{
    public:

    private:

};

class passagiers{
    public:

    private:

};

// Vluchten hebben passagiers, piloten, viliegtuigen en een crew.
class vluchten{
    public:

    private:
    passagiers* pas;
    vliegtuigen* vli;
    crew* cre;
    piloten* pil;

};

int main(){ 

    return 0;
}