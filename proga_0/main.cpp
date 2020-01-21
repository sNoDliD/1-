#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

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

int F7(int n, int m){
        if(n<m){
            int k = n;
            n = m;
            m = k;
        }
        if(m==0) return n;
        else return F7(m,n%m);
        }

string F6(int n){
for(int i = 2; i < n/2+1; i++){
    if(n%i==0) return "";
}
return IntToString(n) + "  ";
}

int F4(int n){
 if(n == 0) return 0;
 if(n == 1) return 1;
 return F4(n-1) + F4(n-2);
}

string F1(float x, float y){
    return "a=1 b="+ IntToString(-(x+y)) +" c="+IntToString(x*y);
}

int main()
{
        srand( time( 0 ) );
        string input;
        setlocale(LC_CTYPE, "rus");
        while(true){
        cout << "Введите номер задания (1-8)"<< endl;
        cin >> input;
        int n = isIntegen(input)? StringToFloat(input): 0;
        switch(n)
        {
            case 1:{
                cout << "Введите корни квадратного уравнения" << endl;
                cin >> input;
                float x = isIntegen(input)? StringToFloat(input): 0;
                cin >> input;
                float y = isIntegen(input)? StringToFloat(input): 0;
                cout << F1(x,y) << endl;
                break;
            }
            case 2:{
                cout << "Введите стороны треугольника" << endl;
                cin >> input;
                float a = isIntegen(input)? StringToFloat(input): 0;
                cin >> input;
                float b = isIntegen(input)? StringToFloat(input): 0;
                cin >> input;
                float c = isIntegen(input)? StringToFloat(input): 0;
                float delta = a-b;
                if(delta<0) delta *= -1;
                if(delta<c&&c<a+b){
                    if(a<b) swap( a, b );
                    if(a<c) swap(a,c);
                    if(b*b + c*c - a*a>0) cout << "Треугольник остроугольный" << endl;
                    else cout << "Треугольник не остроугольный" << endl;
                }
                else cout << "Увы, но такого треугольника не существует" << endl;
                break;
                }
            case 3:{
                    cout<< "Введите 4-х значное число" <<endl;
                    cin >> input;
                    if(input.size()!=4) cout<< "Хорошая попытка, но нет" <<endl;
                    else {
                        int sumFirst = 0, sumSecond = 0;
                        for(int i = 0; i < 2; i++) sumFirst += (int)input[i] - 48;
                        for(int i = 0; i < 2; i++) sumSecond += (int)input[input.size() - 1 - i] - 48;
                        if(sumFirst==sumSecond) cout << "Сумма первых двух чисел равна сумме последних"<< endl;
                        else cout << "Сумма первых двух чисел не равна сумме последних"<< endl;
                    }
                break;
                }
            case 4:{
                cout << "Введите n для получения элемента последовательности a(n+2) = a(n+1) + a(n)" << endl;
                cin >> input;
                int n = isIntegen(input)? StringToFloat(input): 0;
                cout << F4(n) << endl;
            break;
            }
            case 5:{
                cout << "Введи размер массива" << endl;
                cin >> input;
                int arrSize = isIntegen(input) ? StringToFloat(input) : 0;
                if(arrSize<=0) arrSize = 10;
                int arr[arrSize];
                cout << "Заполни массив целыми числами или напишите AUTO" << endl;
                bool autoFill = false;
                for(int i = 0; i < arrSize; i++){
                    if(!autoFill) cin >> input;
                    if(isIntegen(input)) {
                            arr[i] = StringToFloat(input);
                    }
                    else {
                        autoFill = true;
                        arr[i] = rand()%100 + 1;
                    }
                }
                for(int i = 0; i < arrSize; i++) cout << arr[i] << "\t";
                cout << endl << "Введите число для поиска" << endl;
                cin >> input;
                int finder = isIntegen(input)? StringToFloat(input) : 0;
                autoFill = false;
                for(int i = 0; i < arrSize; i++)
                        if(arr[i]==finder) {
                            autoFill = true;
                            break;
                        }
                if(autoFill) cout << "Число есть в массиве" << endl;
                else cout << "Числа нет в массиве" << endl;
                break;
            }
            case 6:{
            cout << "Все простые числа до 1000"<< endl;
            for(int i = 1; i<= 1000; i++){
                    cout << F6(i);
            }
            cout << endl;
            break;
            }
            case 7:{
                cout << "Введите n и m для нахождения их НСК" << endl;
                cin >> input;
                float n = isIntegen(input)? StringToFloat(input): 0;
                cin >> input;
                float m = isIntegen(input)? StringToFloat(input): 0;
                cout << m*n / F7(n, m) << endl;
                break;
                }
            case 8:{
                cout << "Введи размер массива" << endl;
                cin >> input;
                int arrSize = isIntegen(input) ? StringToFloat(input) : 0;
                if(arrSize<=0) arrSize = 10;
                int arr[arrSize];
                cout << "Заполни массив целыми числами или напишите AUTO" << endl;
                bool autoFill = false;
                for(int i = 0; i < arrSize; i++){
                    if(!autoFill) cin >> input;
                    if(isIntegen(input)) {
                            arr[i] = StringToFloat(input);
                    }
                    else {
                        autoFill = true;
                        arr[i] = rand()%100 + 1;
                    }
                }
                for(int i = 0; i < arrSize; i++) cout << arr[i] << "\t";
                cout << endl;
                int arr2[101];
                for(int i = 0; i < 100; i++) arr2[i] = 0;
                for(int i = 0; i < arrSize; i++) arr2[arr[i]]++;
                for(int i = 0; i < 100; i++) if(arr2[i]!=0) cout<<i<<": " << arr2[i] << ",\t";
                cout << endl;
            break;
            }
        }
        cout<< endl;
        }
    return 0;
}
