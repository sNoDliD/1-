#include <iostream>
#include <fstream>
#include <vector>
#include "type.h"
using namespace std;

int main()
{
    vector <Country> countrys;
    string fileName = "countries.txt";
    ifstream fin(fileName.c_str());
    if(!fin.is_open()) return 1;
    while(!fin.eof()){
        string a, s, d, f, g;
        fin >> a >> s >> d >> f >> g;
        if(a == "") break;
        countrys.push_back(Country(a,convert(s),convert(d),convert(f), convert(g)));
    }
    while(1){
        cout << "Enter number of problem(1-6)" << endl;
        int k;
        cin >> k;
        switch(k){
            case 1:
                P1(countrys);
            break;
            case 2:
                P2(countrys);
            break;
            case 3:
                P3(countrys);
            break;
            case 4:
                P4(countrys);
            break;
            case 5:
                P5(countrys);
            break;
            case 6:
                {
                string name;
                do{
                cout << "Enter name of coutry: ";
                cin >> name;
                }
                while(findByName(countrys, name)== -1);
                cout << "Enter number of problem: ";
                cin >> k;
                switch(k){
                    case 1:
                        P61(countrys, name);
                    break;
                    case 2:
                        {
                            float temp;
                            cout << "enter temperature for compare: ";
                            cin >> temp;
                        P62(countrys, name, temp);
                    break;
                    }
                    case 3:
                        P63(countrys, name);
                    break;
                }
            break;}
            default:
                cout << "Try again" << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}

