#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#define to_string( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

float isNumber(string s)
{
    string all = "1234567890.";
    for(int i = 0; i < s.size(); i++)
        if(!all.find(s[i]))
            return 1;
    return atof(s.c_str());
}

bool F3(string n){
        for(int i = 0; i < n.size(); i++){
            if(i%2==0 && ((int)n[i]-48)%2==0) return false;
            if(i%2 == 1 && ((int)n[i] - 48)%2 == 1) return false;
        }
        return true;
}
bool F2(int n) {
        for(int i = 2; i < n/2+1; i++){
            if(n%i==0) return false;
        }
        return true;
}
bool F1(string n){

bool arr[10];
    for(int i = 0; i < n.size(); i++){
       if(!arr[(int)n[i]-48]) arr[(int)n[i]-48] = true;
       else return false;
    }
    return true;
}
int main()
{
        setlocale(LC_CTYPE, "rus");
        while(true){
    cout << "��� ��� ����� �������(1-3)" << endl;
    string input;
    cin >> input;
    int n = isNumber(input);
    switch (n) {
    case 1: {
        cout << "����� ����� ��� �������� �� ������� ���������� ����"<< endl;
    cin >> input;
    if(F1(input)) cout << "��� ������" << endl;
        else cout << "���� �������" << endl;
    break;
    }
    case 2: {
        cout << "������� ����� ��� �������� ��� �������� �� �������� ����� ����" << endl;
        cin >> input;
        int sum = 0;
        for(int i = 0; i< input.size(); i++) sum += (int)input[i] - 48;
        cout << "����� ���� ����� (" << sum << ") ";
        if(F2(sum)) cout << "������� �����" << endl;
        else cout << "�� ������� �����" << endl;
        break;
        }
    case 3: {
        cout << "������� ����� ��� �������� �� ��������/���������� ����" << endl;
        cin >> input;
        if(F3(input))cout << "�� �������� ������ �������� � �� ������ ������" << endl;
        else cout << "�������������� ��������" << endl;
        break;
        }
    }
    cout << endl;
        }
    return 0;
}
