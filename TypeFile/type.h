#include <iostream>
#include <string>
#include <vector>
using namespace std;

float convert(string);
float pow(int, int);

class Country{
public:
    float summer;
    float autumn;
    float winter;
    float spring;
    string name;
    Country(string, float,float,float, float);
    float maximum(string &);
    float maximum();
    float minimum(string &);
    float minimum();
    float averenge();
    bool containMore(float);
    bool containLes(float);
    void print();
};
void swap(Country &a, Country &b);
int findByName(vector <Country>, string);
void P1(vector <Country>);
void P2(vector <Country>);
void P3(vector <Country>);
void P4(vector <Country>);
void P5(vector <Country>);
void P61(vector <Country>, string);
void P62(vector <Country>, string, float);
void P63(vector <Country>, string);
