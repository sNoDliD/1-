#include <iostream>
#include <vector>

using namespace std;

class LongNumber{
public:
    unsigned int lengthInteger = 0, lengthFractional = 0;
    bool positive = true;
    vector<short> arrInteger, arrFractional;
    LongNumber(){

    }
    LongNumber(string str){
        if(str[0] == '-') {
            positive = false;
            str.erase(0,1);
        }
        if(str.find(".")==string::npos)lengthInteger = str.size();
        else {
                lengthInteger = str.find(".");
                lengthFractional = str.size() - lengthInteger - 1;
        }
        for(int i = 0; i < str.size(); i++){
                if(i < lengthInteger) arrInteger.insert(arrInteger.begin(),str[i]-48);
                if(i > lengthInteger) arrFractional.push_back(str[i] - 48);
    }
    }
    string get(){
        string rez = "";
        if(!positive) rez += "-";
        for(int i = lengthInteger - 1; i >= 0; i--) rez += arrInteger[i] + 48;
        for(int i = 0; i < lengthFractional; i++) {
                if(i == 0)  rez += ".";
                rez += arrFractional[i] + 48;
        }
        return rez;
    }
};
    LongNumber operator + (LongNumber a, LongNumber b){
        LongNumber f;
        int extra = 0;
        int maxLength = max(a.lengthFractional, b.lengthFractional);
        if(maxLength!=0){
        while(a.lengthFractional != maxLength){a.arrFractional.push_back(0); a.lengthFractional++;}
        while(b.lengthFractional != maxLength){b.arrFractional.push_back(0); b.lengthFractional++;}
        for(int i = maxLength - 1; i >= 0; i--){
            int temp = a.arrFractional[i]+b.arrFractional[i] + extra;
            f.arrFractional.insert(f.arrFractional.begin(), temp%10);
            extra = temp/10;
        }
        while(f.arrFractional[f.arrFractional.size()-1] == 0) f.arrFractional.erase(f.arrFractional.begin() + f.arrFractional.size()-1);
        f.lengthFractional = f.arrFractional.size();
        }
        maxLength = max(a.lengthInteger, b.lengthInteger);
        while(a.lengthInteger != maxLength){a.arrInteger.push_back(0); a.lengthInteger++;}
        while(b.lengthInteger != maxLength){b.arrInteger.push_back(0); b.lengthInteger++;}
        for(int i = 0; i < maxLength; i++){
            int temp = a.arrInteger[i]+b.arrInteger[i]+ extra;
            f.arrInteger.push_back(temp%10 );
            extra = temp/10;
        }
        f.lengthInteger = maxLength;
        if(extra != 0) { f.arrInteger.push_back(extra);  f.lengthInteger ++;}
        while(f.arrInteger[f.arrInteger.size()-1] == 0) {
            f.arrInteger.erase(f.arrInteger.begin() + f.arrInteger.size()-1);
            f.lengthInteger--;
        }
        return f;
    }


bool isIntegen(string s){
    string all = "1234567890";
    for(int i = 0; i < s.size(); i++){
        if(s[0]=='-'&&i==0) continue;
        if(all.find(s[i])==string::npos)
            return false;
        }
    return true;
}
float Pow(int n, int f){
    float rez = 1;
    for(int i = 0; i < f; i++) rez *= n;
    return rez;
}
float StringToFloat(string s){
 float rez = 0;
 float sign = 1;
 for(int i = s.size() - 1; i >= 0; i--){
        if(s[0]=='-'&&i==0){
            sign = -1;
            continue;
        }
        rez += ((int)s[i]-48)* Pow(10, s.size()-i-1);
}
return rez*sign;
}
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
    string str;
    cin >> str;
    LongNumber a1(str);
    cin >> str;
    LongNumber a2(str);
    LongNumber a3 = a1 + a2;
    cout << a3.get();
    return 0;
}

