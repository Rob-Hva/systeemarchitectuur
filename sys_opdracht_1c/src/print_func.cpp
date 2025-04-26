#include <iostream>

using namespace std;

void print_input(){
    cout << "Voer een getal in: ";
    int x;
    cin >> x;
    cout << x;
}

int main(){
    print_input();
    return 0;
}