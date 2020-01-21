#include <iostream>
#include <vector>

using namespace std;

class LongNumber{
public:
    unsigned int length = 0;
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
        for(int i = 0; i < length; i++)
            arr.insert(arr.begin(),str[i]-48);
    }
    string get(){
        string rez = "";
        if(!positive) rez += "-";
        for(int i = length - 1; i >= 0; i--) rez += arr[i] + 48;
        return rez;
    }
};

bool operator >= (LongNumber a, LongNumber b);
bool operator <= (LongNumber a, LongNumber b);
bool operator == (LongNumber a, LongNumber b);
LongNumber operator - (LongNumber a, LongNumber b);
LongNumber operator + (LongNumber a, LongNumber b);
LongNumber operator * (LongNumber a, LongNumber b);
LongNumber operator / (LongNumber a, LongNumber b);
LongNumber operator % (LongNumber a, LongNumber b);
struct Fraction{
    bool positive = true;
    LongNumber numerator;
    LongNumber denominator;
    Fraction(string a, string b){
        numerator = LongNumber(a);
        denominator = LongNumber(b);
        positive = numerator.positive == denominator.positive;
        numerator.positive = denominator.positive = true;
        Cut();
    }
    void Print(){
        string sign = "";
        if(!positive)sign = "-";
        cout << sign;
        if(denominator == LongNumber("1")){  cout << numerator.get(); return;}
        if(numerator == LongNumber("0")){  cout << "0"; return; }
        if(numerator >= denominator) cout << (numerator/denominator).get() << " ";
        cout << (numerator % denominator).get() << "/" << denominator.get();
    }
    short Sign(){
    if(positive) return 1;
    else return -1;
    }
    void Cut(){
        /*int gcf = GCF(numerator,denominator);
        if(gcf != 1) {
            numerator/=gcf;
            denominator/=gcf;
        }*/
    }
private:
    int Mod(int a){
        if(a<0)a*= -1;
        return a;
    }
    int GCF(int a, int b){
        if(a<b){
            int k = a;
            a = b;
            b = k;
        }
        if(b == 0) return a;
        return GCF(b, a%b);
    }
};
Fraction operator+ (Fraction a, Fraction b){
    //return Fraction(a.Sign()*a.numerator*b.denominator + b.Sign()*a.denominator*b.numerator,a.denominator*b.denominator);
}
Fraction operator- (Fraction a, Fraction b){
    b.positive = !b.positive;
    return a + b;
}
Fraction operator* (Fraction a, Fraction b){
//return Fraction(a.Sign()*a.numerator*b.Sign()*b.numerator, a.denominator*b.denominator);
}
Fraction operator/ (Fraction a, Fraction b){
//return Fraction(a.Sign()*a.numerator*b.Sign()*b.denominator, a.denominator*b.numerator);
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
int Convert(string str){
    int i = 0;
    int rez = 0;
    if(str[0] == '-') i++;
    for(int j = str.size() - 1; j >= i; j--){
        int pow = 1;
        for(int i2 = 0; i2 < str.size()-j-1; i2++) pow *= 10;
        rez += pow * (str[j] - 48);
    }
    if(i == 1) rez *= -1;
    return rez;
}

int main()
{
    string op;
    LongNumber a("12344");
    cout << a.length;
    LongNumber b("23533");
    //cout << (a+b).get();
    while(true){
        getline(cin, op);
        string temp = "";
        vector <string> arrNum;
        vector <char> arrOp;
        string operations = "+-*:/";
        string numbers = "1234567890";
        for(int i = 0; i < op.size(); i++){
            if(op[i] == '-' && numbers.find(op[i+1]) != string :: npos) temp += '-';
            else if(numbers.find(op[i]) != string :: npos) temp += op[i];
            else {
                if(operations.find(op[i]) == string :: npos) continue;
                arrOp.push_back(op[i]);
                arrNum.push_back(temp);
                temp = "";
            }
        }
        arrNum.push_back(temp);
        for(int i = 0; i<arrNum.size(); i++)
        cout << arrNum[i] << endl;
        for(int i = 0; i< arrOp.size(); i++)
            cout << arrOp[i] << endl;
        Fraction d1(arrNum[0], arrNum[1]);
        Fraction d2(arrNum[2], arrNum[3]);
        d1.Print();
        cout << " " << arrOp[1] << " ";
        d2.Print();
        cout << " = ";
        switch(arrOp[1]){
            case '+': (d1 + d2).Print(); break; //43
            case '-': (d1 - d2).Print(); break; //45
            case '*': (d1 * d2).Print(); break; //42
            case '/': (d1 / d2).Print();break; //47
        }
        cout << endl << endl;
    }
    return 0;
}

bool operator <= (LongNumber a, LongNumber b){
        if(a.length > b.length) return false;
        if(a.length < b.length) return true;
        for(int i = a.length - 1; i >= 0 ; i--){
            if(a.arr[i] < b.arr[i]) return true;
            else if(a.arr[i] > b.arr[i]) return false;
        }
        return true;
    }
bool operator == (LongNumber a, LongNumber b){
        if(a.length != b.length) return false;
        for(int i = 0; i < a.length; i++){
            if(a.arr[i] != b.arr[i]) return false;
        }
        return true;
    }
bool operator >= (LongNumber a, LongNumber b){
        if(a.length < b.length) return false;
        if(a.length > b.length) return true;
        for(int i = a.length - 1; i >= 0 ; i--){
            if(a.arr[i] < b.arr[i]) return false;
            else if(a.arr[i] > b.arr[i]) return true;
        }
        return true;
    }
LongNumber operator - (LongNumber a, LongNumber b){
    if(a == b && a.positive == b.positive) return LongNumber("0");
    if(a <= b) {
            b.positive = !b.positive;
            a.positive = !a.positive;
            return b - a;
    }
    LongNumber f;
    if(a.positive == false && b.positive == false) f.positive = false;
    else if(b.positive == false) {
            b.positive = true;
            return a + b;
    }
    else if(a.positive == false){
        b.positive = false;
        return a + b;
    }
    int maxLength = max(a.length, b.length);
    while(a.length != maxLength){a.arr.push_back(0); a.length++;}
    while(b.length != maxLength){b.arr.push_back(0); b.length++;}
    for(int i = 0; i < maxLength; i++){
        if(a.arr[i]==-1) {
            a.arr[i] = 9;
            a.arr[i+1]--;
        }
        int temp = a.arr[i];
        if(temp < b.arr[i]){
            temp += 10;
            a.arr[i+1]--;
        }
        f.arr.push_back(temp - b.arr[i]);
        }
        f.length = maxLength;
        while(f.arr[f.length-1] == 0) {
            f.arr.erase(f.arr.begin() + f.length-1);
            f.length--;
        }

    return f;
    }
LongNumber operator + (LongNumber a, LongNumber b){
        LongNumber f;
        if(a.positive == false && b.positive == false) f.positive = false;
        else if(a.positive == false){
                a.positive = true;
                return b - a;
        }
        else if(b.positive == false){
                b.positive = true;
                return a - b;
        }
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
        while(f.arr[f.length-1] == 0) {
            f.arr.erase(f.arr.begin() + f.length-1);
            f.length--;
        }
        return f;
    }
LongNumber operator * (LongNumber a, LongNumber b){
    LongNumber mass[b.length];
    for(int i = 0, extra = 0; i < b.length; i++){
        for(int i2 = 0; i2 < a.length; i2++) {
            int temp = a.arr[i2]*b.arr[i] + extra;
            mass[i].arr.push_back(temp%10);
            mass[i].length++;
            extra = temp/10;
        }
        if(extra != 0) {
            mass[i].arr.push_back(extra);
            extra = 0;
            mass[i].length++;
          }
        for(int i3 = 0; i3 < i; i3++){
        mass[i].arr.insert(mass[i].arr.begin(), 0);
        mass[i].length++;
        }
    }
    LongNumber f("0");
    for(int i = 0; i < b.length; i++)
            f = f + mass[i];
    f.positive = a.positive == b.positive;
    return f;
}
LongNumber operator / (LongNumber a, LongNumber b){
    LongNumber f("0");
    while (a>= b){
        a = a - b;
        f = f + LongNumber("1");
    }
    f.positive = a.positive == b.positive;
    return f;
}
LongNumber operator % (LongNumber a, LongNumber b){
    return a - a / b * b;
}

