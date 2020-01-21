#include <bits/stdc++.h>

using namespace std;

float number(string);
float skobki(string);
float priority(string);
float analize(string);
void delSpace(string&);
struct param{
    string name;
    float value;
    param(string a, float b){
    name = a;
    value = b;
    }
};
int Find(string);
int Find(string, char);
int NewP(string);
static int now = 0;
vector <param> arr;

string Copy(string, int,int);
string Take(vector <string>,int,int);
int main()
{
    setlocale(LC_ALL, "rus");

    vector <string> commands;
    string buff;
    ifstream f("EatForCom.txt");
    if (!f.is_open())
        cout << "Файл не может быть открыт!\n";
    else{
    while(f >> buff){
        int len = buff.size();
        if(len!=1&&(buff[len-1]==';'||buff[len-1]=='{')){
            commands.push_back(Copy(buff,0,len-2));
            commands.push_back(Copy(buff,len-1,len-1));
            continue;
        }
        commands.push_back(buff);
    }
    int len = commands.size();
    if(Take(commands,0,8)!="#include<iostream>usingnamespacestd;intmain(){"||
       Take(commands,len-5,len-1)!=";return0;}"){
        cout << "Не верная запись" <<endl;
        return 0;
    }
    int inDeque = 9, endDeque = len-4;
    string temp = "";
    while(inDeque<endDeque){
        string com = commands[inDeque];
        if(com == "float" ||com == "double"){
            if(commands[++inDeque]==";"){
                cout << "Неверно поставлена ;"<< endl;
                return 0;
            }
            while(com!=";"){
                com = commands[inDeque];
                if(com != ";") {temp += com;
                inDeque++;}
            }
            if(NewP(temp)==1) {
                cout << "Ошибка инициализации переменной"<< endl;
                return 0;
            }
            if(now == -1){
                cout << "Переменной не существует"<< endl;
                return 0;
            }
            temp = "";
        }
        else if (com == "cout"){
            if(commands[++inDeque]==";"){
                cout << "Неверно поставлена ;"<< endl;
                return 0;
            }
            if(commands[inDeque++]!="<<"){
                cout << "Неверно поставлен оператор"<< endl;
                return 0;
            }
            while(com!=";"){
                com = commands[inDeque];
                if(com == "<<"){
                    now = 0;
                    if(temp != "") cout << analize(temp);
                    if(now == -1){
                        cout << "Переменной не существует"<< endl;
                        return 0;
                    }
                    temp = "";
                    ++inDeque;
                    continue;
                }
                if(com == "endl"){
                    temp = "";
                    cout << endl;
                    ++inDeque;
                    continue;
                }
                if(com != ";") {
                        temp += com;
                        inDeque++;
                }
            }
            now = 0;
            if(temp!="")cout << analize(temp);
            if(now == -1){
                cout << "Переменной не существует"<< endl;
                return 0;
            }
            temp = "";
        }
        else if (com == "cin"){}
        else if (com == "string"){}
        ++inDeque;
    }

    f.close();
    }
    return 0;
}

int NewP(string str){
        delSpace(str);
        now = 0;
        int equ = Find(str, '=');
        if(equ ==-1){
            if(Find(str)==-1)arr.push_back(param(str,0));
            else return 1;
        }
        else if(Find(Copy(str,0,equ-1))==-1)arr.push_back(param(Copy(str,0,equ-1),analize(Copy(str, equ+1,str.size()-1))));
        else return 1;
        return 0;
}
string Take(vector <string> s,int start,int fin){
    string res = "";
for(int i=start; i <=fin; ++i) res += s[i];
return res;

}
string Copy(string s, int start, int fin){
string res = "";
for(int i = start; i <= fin; ++i) res += s[i];
return res;
}

float peram(string s){
    string rez = "";
    string rules = "0123456789+-*/.()";
    while(rules.find(s[now])==string::npos){
            if(now>=s.size()) break;
            rez+=s[now++];
    }
    if(Find(rez)==-1) now = -1;
    return arr[Find(rez)].value;
}
float number(string s)
{
  float res = 0;
  bool fl = false;
  int i = 1;
  string rules = "0123456789+-*/().\n";
  while(true)
  {
    if(now >= s.size())return res;
    char c = s[now];
    now++;
    if(c == '.'){
        fl = true;
        continue;
    }
    if (c >= '0' && c <= '9'){
            if(fl) res += (c - '0')*pow(10,-i++);
            else res = res * 10 + c - '0';
    }
    else if(rules.find(c)==string::npos){
        --now;
        if(res==0) return peram(s);
        else return res*peram(s);
    }
    else
    {
        now--;
      return res;
    }
  }
}

float skobki(string s)
{
    char c = s[now];
    now++;
  if (c == '(')
  {
    float x = analize(s);
    now++;
    //cin.get(); выкидываем )
    return x;
  }
  else
  {
      --now;
    return number(s);
  }
}

float priority(string s)
{
  float x = skobki(s);
  if(now==-1) return 0;
  while(true)
  {
    char c = s[now];
    now++;
    switch (c)
    {
    case '*':
      x *= skobki(s);
      break;
    case '/':
      x /= skobki(s);
      break;
    default:
        --now;
      return x;
    }
  }
}

float analize(string s){
  float x = priority(s);
  if(now==-1) return 0;
  while(true){
    char c = s[now];
    now++;
    switch (c)
    {
    case '+':
      x += priority(s);
      break;
    case '-':
      x -= priority(s);
      break;
    default:
        --now;
      return x;
    }
  }
}
int Find(string s, char c){
    int n = s.size();
    for(int i = 0; i <n; ++i){
        if(s[i]==c)return i;
    }
    return -1;
}
void delSpace(string& s){
    string rez = "";
    int n = s.size();
    for(int i = 0; i<n; i++) if(s[i]!=' ') rez+=s[i];
    s = rez;
}
int Find(string str){
    int length = arr.size();
    for(int i = 0; i< length; i++){
        if(arr[i].name == str) return i;
    }
    return -1;
}
