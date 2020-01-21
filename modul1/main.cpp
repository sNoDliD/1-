#include <bits/stdc++.h>

using namespace std;
string ToString(int a){
    string result = "";
    while(a>0){
        char temp = a%10 + '0';
        result = temp + result;
        a /= 10;
    }
    return result;
}

string num1(string str){
string conmpare = "fat";
string temp;
deque <int> arr;
int n = str.size();
for(int i = 0; i < n - 2; i++){
        for(int k = 0; k < 3; k++)
        temp += str[i + k];
    if(temp == conmpare) arr.push_back(i+1);
    temp = "";
}
    string answer = arr.size() > 0 ? "YES (" + ToString(arr.size()) + ")" : "NO";
    for(int i = 0; i< arr.size(); i++) answer += ", " + ToString(arr[i]);
    return answer;
}

float Fac(int a){
    float res = 1;
    for(int i = 2; i<= a; i++) res*= i;
    return res;
}
float num2(float e){
int x = 5;
float res = 0;
int i = 0;
while(abs(res - cos(x))>e){
    res += pow(-1,i)* pow(x,2*i) / Fac(2*i);
    i++;
}
return res;
}

float num3(int m, int n){
int arr[m][n];
for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        arr[i][j] = -50 + rand() % 100;
        cout << arr[i][j] << "\t";
    }
        cout << endl;
}
float sum = 0;
for(int i = 0; i < n; i++){
    int ma = arr[0][i];
    for(int j = 1; j < m; j++){
        if(arr[j][i]>ma) ma = arr[j][i];
    }
    sum += ma;
}
return sum;
}

int Fin(string s, char el){
int n = s.size();
    for(int i = 0; i < n; i++) if(s[i] == el) return i;
    return -1;
}
int num4(string str){
int arrN[7] = {1, 5, 10, 50, 100, 500, 1000};
string arrR = "IVXLCDM";
int n = str.size();
int res = 0;
for(int i = 0; i < n; i++){
    int first = arrN[Fin(arrR,str[i])];
    int second = i+1<n? arrN[Fin(arrR,str[i + 1])] : 0;
    if(first < second) {
            first = second - first;
            i++;
    }
    res += first;
}
return res;
}

string num5(int a){
string b = ToString(a);
int n = b.size();
int res = 0;
for(int i = 0; i < n/2; i++){
    if(b[i] == b[n-1-i]) res++;
    else break;
}
if(res == 0) return "Not a poli";
if(res == n/2) return "Poli";
return "Chasticni poli poradka " + ToString(res);
}
int main()
{
    cout << num1("Luke, I'm your fat father")<< endl<< endl;
    cout << num2(0.0001) << endl <<endl;
    cout << num3(5,6) << endl<<endl;
    cout << num4("CLXIV") << endl<<endl;
    cout << num5(1254321) << endl<<endl;
    return 0;
}
