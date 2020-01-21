#include <iostream>
#include <vector>
using namespace std;
void P1();
void P2();
void P3();
void P4();
void P5();
int Fn(int, int);
void f5(string, int);
bool isCorect(string str, string patt);
vector <string> permutation(string);
string SCopy(string , int ,int);
string IntToString(int a){
    string rez = "";
    string rez2 = a>0?"":"-";
    if(a<0)a*=-1;
        while(a>0){
            rez += a%10 + 48;
            a /= 10;
        }
    for(int i = rez.size() - 1; i >=0; i--) rez2 += rez[i];
    return rez2;
}
int main()
{
    while(1){
        cout << "enter number of problem(1-5): ";
        int n;
        cin >> n;
        switch(n){
        case 1: P1(); break;
        case 2: P2(); break;
        case 3: P3(); break;
        case 4: P4(); break;
        case 5: P5();
             break;
        }
        cout << endl;
    }
    return 0;
}
int Fn(int a, int b){
    if(a>=b) return 0;
    int res = 0;
    while(a<b){
        a++;
        res+= Fn(a,b---a) + 1;
    }
    return res;
}
bool isCorect(string str, string patt){

    if(str==patt) return true;
    for(int n = patt.size(); n > 0;){
        if(patt[0]=='?'||patt[0]==str[0]) {
            patt.erase(0,1);
            str.erase(0,1);
            n--;
            if(str==patt) return true;
            if(str==""&&patt!="*") return false;
            if(patt==""&&patt!="") return false;
            continue;
        }
        if(patt[0]=='*'){
            if(n==1) return true;
            for(int i = 0, n2 = str.size(); i < n2; i++){
                if(patt[1]==str[i]||patt[1]=='?'){
                    string temp = str;
                    temp.erase(0,i);
                    string patt2= patt;
                    patt2.erase(0,1);
                    if(isCorect(temp, patt2)) {
                            return true;
                    }
                }

            }
        }
        return false;

    }
    //return false;
}
void P5(){
    cout << "Enter code and length" << endl;
    string code;
    int n;
    cin >> code >> n;
    string key = "";
    f5(code,n);
    return;
    for(int i = 0, k = n; i < code.size(); ++i){


    }
}
void P4(){
            cout << "enter string: ";
            string str, patt;
            cin >> str;
            cout << "enter your pattern: ";
            cin >> patt;
            for(int i = 0; i < patt.size(); i++) {
                if(patt[i]=='*')
                    while(i<patt.size()-1&&patt[i+1]=='*')//||patt[i+1]=='?'))
                        patt.erase(i+1,1);
            }
            if(isCorect(str, patt)) cout << "YES" << endl;
            else cout << "NO" << endl;
}
void P1(){
    cout << "enter n: ";
    int n;
    cin >> n;
    cout << Fn(1,n-1) + 1 <<endl;
}
void P2(){
    cout << "enter your string: ";
    string s;
    cin >> s;
    vector <string> ss = permutation(s);
    for(int i = 0, n1 = ss.size(); i < n1; ++i) cout << ss[i] << endl;
}
void P3(){
    int sum = 0;
    int last;
    string mon = "";
    vector <int> nominals;
    while(1){
        cin >> last;
        if(last <= 0) break;
        sum += last;
        nominals.push_back(last);
    }
    last = nominals.back();
    nominals.pop_back();
    sum -= last;
    if(sum*2 < last) {
        cout << -1;
        return;
    }
    bool arr[2*nominals.size()];
    int n = sizeof(arr)/sizeof(bool);
    for(int i = 0; i < n; i++) arr[i] = false;
    arr[0] = true;
    int res = n+1;
    while(1){
        // chek on 0
        bool ok = false;
        for(int i = 0; i < n; i++){
            if(arr[i]) {
                ok = true;
                break;
            }
        }
        if(!ok) break;
        // chek on mon
        int coutn=0;
        int sum2=0;
        string qmon = "";
        for(int i = 0; i < n; i++){
            if(arr[i]) {
                   coutn++;
                   if(qmon == "") qmon = IntToString(nominals[i/2])+" ";
                   else qmon += "+ " + IntToString(nominals[i/2]) + " ";
                   sum2+=nominals[i/2];
            }
        }
        if(sum2 == last){
            if(res > coutn) {
                    res = coutn;
                mon = qmon;
            }
        }
        // +1
        for(int i = 0; i < n; i++){
            if(arr[i]) {
                arr[i] = false;
            }
            else{
                arr[i] = true;
                break;
            }
        }
    }
    if(res == n +1) cout << "0" << endl;
    else {
            cout << res << endl;
            cout << last << " = " << mon << endl;
    }

}
vector <string> permutation(string s){
    vector <string> res;
    if(s.size()==1){
        res.push_back(s);
        return res;
    }
    for(int i = 0, n = s.size(); i < n; ++i){
        string t = s;
        vector <string> temp = permutation(t.erase(i,1));
        for(int j = 0, n2 = temp.size(); j < n2; j++){
            res.push_back(s[i] + temp[j]);
        }
    }
    return res;
}
string SCopy(string str, int start, int n){

}
int num(vector <string> a){
  int res = 0;
  for (int i = 0; i < a.size(); i++)
  {
    res += a[i].size();
  }
  return res;
}

void f5(string str, int n){
  //5 555251212164
  vector <string> code;
  string part="";
  bool flag = 0;
  int i, j;
  for (i = 0; i < str.size(); i++){
    flag = 0;
    part = "";
    for (j = i + 1; j < str.size();){
      if (str[i] == str[j]){
        part += str[i];
        i++;
        j++;
        flag = 1;
        if (num(code) + part.size() >= n) break;
      }
      else if (flag) break;
      else j++;
    }
    if (j - i <= part.size()) code.push_back(part);
    else if (part.size() != 0) i--;
  }

  if (num(code) == n) {
    for (int i = 0; i<code.size(); i++) cout << code[i];
    cout << endl;
  }
  else cout << "NO" << endl;
}


