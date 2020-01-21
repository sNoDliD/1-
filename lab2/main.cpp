#include <iostream>
#include <vector>

using namespace std;

class LongNumber{
public:
    unsigned int length=0;
    bool positive = true;
    vector<short> arr;
    LongNumber(){
    }
    LongNumber(string str){
        if(str[0] == '-') {
            positive = false;
            str.erase(0,1);
        }
        length = str.size();

        for(int i = 0; i < str.size(); i++)
                arr.insert(arr.begin(),str[i]-48);
    }
    string get(){
        string rez = "";
        if(!positive) rez += "-";
        for(int i = length - 1; i >= 0; i--) rez += arr[i] + 48;
        return rez;
    }
};

    LongNumber operator + (LongNumber a, LongNumber b);
    LongNumber operator - (LongNumber a, LongNumber b);
    LongNumber operator * (LongNumber a, LongNumber b);


/*bool isIntegen(string s){
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
}*/

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

LongNumber operator + (LongNumber a, LongNumber b){
        LongNumber f;
        int extra = 0;
        int maxLength = max(a.length, b.length);
        while(a.length != maxLength){a.arr.push_back(0); a.length++;}
        while(b.length != maxLength){b.arr.push_back(0); b.length++;}
        for(int i = 0; i < maxLength; i++){
            int temp = a.arr[i]+b.arr[i]+ extra;
            f.arr.push_back(temp%10 );
            extra = temp/10;
        }
        f.length = maxLength;
        if(extra != 0) { f.arr.push_back(extra);  f.length ++;}
        while(f.arr[f.arr.size()-1] == 0) {
            f.arr.erase(f.arr.begin() + f.arr.size()-1);
            f.length--;
        }
        return f;
    }
    LongNumber operator - (LongNumber a, LongNumber b){
        LongNumber f;
        int extra = 0;
        int maxLength = max(a.length, b.length);
        while(a.length != maxLength){a.arr.push_back(0); a.length++;}
        while(b.length != maxLength){b.arr.push_back(0); b.length++;}
        for(int i = 0; i < maxLength; i++){
                if(i+1<maxLength&&a.arr[i]<0){
                    a.arr[i+1]--;
                    a.arr[i]+=10;
                }
            int temp = a.arr[i]-b.arr[i];
            if(temp<0){
                a.arr[i+1]--;
                temp += 10;
            }
            f.arr.push_back(temp%10 );
            extra = temp/10;
        }
        f.length = maxLength;
        if(extra != 0) { f.arr.push_back(extra);  f.length ++;}
        while(f.arr[f.arr.size()-1] == 0) {
            f.arr.erase(f.arr.begin() + f.arr.size()-1);
            f.length--;
        }
        return f;
    }
