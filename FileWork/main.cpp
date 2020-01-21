#include <iostream>
#include "FileWork.h"

using namespace std;

int main()
{
    while(1){
    cout << "Enter number (1-9): ";
    int n;
    cin >> n;
    cout << "Enter name of your file (or press enter): ";
    string name = "";
    cin.ignore();
    char c = cin.get();
    while(c != '\n'){
        name+=c;
        c = cin.get();
    }
    if(name == "") name = "text.txt";
    if(!open(name)){
        cout << "Open error" << endl;
        return 0;
    }
    switch(n){
    case 1:
        P1();
        break;
    case 2:
        P2();
        break;
    case 3:
        P3();
        break;
    case 4:
        P4();
        break;
    case 5:
        P5();
        break;
    case 6:
        P6();
        break;
    case 7:
        P7();
        break;
    case 8:
        P8();
        break;
    case 9:
        P9();
        break;
    default:
        cout << "Error, try again" << endl;
    }
    cout << endl;
    close();
    }
    return 0;
}
