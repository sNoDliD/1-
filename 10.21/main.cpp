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
string copyStart(string, int);
string copyBefore(string, int);

static int now = 0;
vector <param> arr;

int main()
{
    while(true){
        string str;
        getline(cin, str);
        delSpace(str);
        now = 0;
        int equ = Find(str, '=');
        if(equ ==-1)
        cout <<str << " = " << analize(str) << endl;
        else if(Find(copyBefore(str,equ))==-1)arr.push_back(param(copyBefore(str,equ),analize(copyStart(str, equ))));
        else arr[Find(copyBefore(str,equ))].value = analize(copyStart(str, equ));
    }
    return 0;
}

float peram(string s){
    string rez = "";
    string rules = "0123456789+-*/.()";
    while(rules.find(s[now])==string::npos){
            if(now>=s.size()) break;
            rez+=s[now++];
    }
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
string copyBefore(string s, int k){
    string rez = "";
    for(int i = 0; i< k; ++i) rez += s[i];
    return rez;
}
string copyStart(string s, int k){
    string rez = "";
    int n = s.size();
    for(int i = k+1; i< n; ++i) rez += s[i];
    return rez;
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
