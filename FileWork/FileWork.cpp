#include "FileWork.h"

fstream fin;
string name;
bool open(string n){
    name = n;
    fin.open(name.c_str());
    return fin.is_open();
}
void Fclear(){
    close();
    fin.open(name.c_str(), ios::out);
}
void close(){
    fin.close();
}

int Find(string str,char c){
    for(int i = 0, len = str.size(); i < len; ++i)
        if(str[i]==c) return i;
    return -1;
}
bool isLater(string str){
    if(str.size()==0) return false;
    for(int i = 0, len = str.size(); i < len; ++i){
        char c = str[i];
        if((c>=65&&c<=90)||(c>=97&&c<=122))
            continue;
        else return false;
    }
    return true;
}
bool isLater(char c){
    if((c>=65&&c<=90)||(c>=97&&c<=122))
        return true;
    return false;
}
bool isVowels(char c){
    string s = "AEIOUaeiou";
    if(Find(s,c)==-1) return false;
    else true;
}
bool contains(string str, string s){
    return str.find(s)!=string::npos;
}
void P1(){
    int later = 0, symbols = 0, spacial =0;
    char c;
    string sp = ".,-!?:\"():;";
    while(fin.get(c)){
        ++symbols;
        if(isLater(c)){
        ++later;
        }
        else if(Find(sp,c)!=-1){
        ++spacial;
        }
    }
        cout << "Laters: " << later << endl;
        cout << "Symbols: " << symbols << endl;
        cout << "Spacial: " << spacial << endl;
}
void P2(){
    int word = 0, sent = 0;
    char c;
    string temp = "";
    string sp1 = ".!?\n\t, ()\"";
    string sp2 = ".!?";
    while(fin.get(c)) {
        if(Find(sp1,c)!=-1){
            if(Find(sp2,c)!=-1)
                ++sent;
            if(isLater(temp)) ++word;
            temp = "";
            continue;
        }
        temp += c;
    }
    cout << "Words: " << word << endl;
    cout << "Sentences: " << sent << endl;
}
void P3(){
    int vowels = 0, consonants = 0;
    char c;
    string temp = "";
    string sp1 = ".!?\n\t, ()\"";
    while(fin.get(c)){
        if(Find(sp1,c)!=-1){
            if(isLater(temp)) {
                if(isVowels(temp[0])&&isVowels(temp[temp.size()-1])) ++vowels;
                if(!isVowels(temp[0])&&!isVowels(temp[temp.size()-1])) ++consonants;
            }
            temp = "";
            continue;
        }
        temp += c;
    }
    cout << "Words Vowels: " << vowels << endl;
    cout << "Words Consonants: " << consonants << endl;
}
void P4(){

}
void P5(){
    string les="", big="";
    char c;
    string temp = "";
    string sp1 = ".!?\n\t, ()\"";
    while(fin.get(c)){
        if(Find(sp1,c)!=-1){
            if(isLater(temp)) {
                if(big==""){
                    big = temp;
                    les = temp;
                }
                if(temp.size()>big.size()) big = temp;
                if(temp.size()<les.size()) les = temp;
            }
            temp = "";
            continue;
        }
        temp += c;
    }
    cout << "Min word: " << les << " length: " << les.size()<< endl;
    cout << "Max word: " << big << " length: " << big.size()<< endl;
}
void P6(){
    string word;
    bool con = false;
    cout << "Enter your word for serch: ";
    cin >> word;
    char c;
    string temp = "";
    string sp1 = ".!?\n\t, ()\"";
    while(fin.get(c)){
        if(Find(sp1,c)!=-1){
            if(isLater(temp)) {
                if(contains(temp, word)){
                    con = true;
                    break;
                }
            }
            temp = "";
            continue;
        }
        temp += c;
    }
    if(con) cout << word << " contains in file " << endl;
    else cout << word << " NOT contains in file " << endl;
}
void P7(){
    string temp = "";
    char c;
    while(fin.get(c)){
        if(!isVowels(c))
            temp +=c;
        else temp += '*';
    }
    Fclear();
    fin << temp;
    cout << "Success" << endl;
}
void P8(){
    string temp = "";
    char c;
    while(fin.get(c)){
        if(!isVowels(c))
            temp +=c;
    }
    Fclear();
    fin << temp;
    cout << "Success" << endl;
}
void P9(){
    string temp = "";
    char c;
    while(fin.get(c)){
        if(c=='k')
            temp += "math";
        else temp += c;
    }
    Fclear();
    fin << temp;
    cout << "Success" << endl;
}

