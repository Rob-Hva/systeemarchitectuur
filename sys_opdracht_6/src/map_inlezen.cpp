/**
 * @file    map_inlezen.cpp
 * @author  Rob Beaufort
 * @brief   Dit progamma kijkt hoe vaak er een woord voorkomt in het script van "the bee movie".
 *          Het woord waar je op wilt controleren kan je meegeven in de terminal.
 * @version 1.0
 * @date    21-5-2025
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstring>

using namespace std;


int main(){ 

  while(1){
    // Hier kiest de gebruiker het woord waar op gezogd wordt.
    cout << "Welk woord wil je zoeken?" << endl;
    string input;
    cin >> input;

    // Hier wordt het script van de film geopend.
    ifstream mapFile("C:\\school\\ProgameerOmgeving\\gcc-voorbeelden-hva\\systeemarchitectuur\\sys_opdracht_6\\src\\beeMovieScript.txt");
    if (!mapFile){
      throw runtime_error("kon bestand niet openen");
    }


    // Hier wordt een map aangemaakt.
    // In deze map zal aan elk woord een waarde worden gehangen die aangeeft hoe vaak het woord voorkomt.
    map<string, int> beeMovieScript;
    string regel;
    string woord;

    // Hier zal ieder woord worden langsgegaan en de waarde van de frequentie worden opgehoogd.
    while (getline(mapFile, regel)){

      istringstream iss(regel);
      while (iss >> woord){
        beeMovieScript[woord]++;
      }
    }

    // Hier wordt aan de gebruiker teruggegeven hoe vaak het woord voorkomt in de film.
    cout << "Het woord wordt " << beeMovieScript[input] << " keer gezegd in the bee movie" << endl;

    mapFile.close();
  }

  return 0;
}