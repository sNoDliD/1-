#include <iostream>

using namespace std;
void swap(float&, float&); //����� ��� ������ �������� ����������
int main()
{
    //������ ������� �������������
    cout << "Enter first rectangle: " << endl;
    float a, b, c;
    cin >> a >> b >> c;

    cout << "Enter second rectangle: " << endl;
    float a2, b2, c2;
    cin >> a2 >> b2 >> c2;
    //��������� �� �� �������� � �������� ��� ���������
    if(a>b) swap(a,b);
    if(b>c) swap(c,b);
    if(a>b) swap(a,b);
    if(a2>b2) swap(a2,b2);
    if(b2>c2) swap(c2,b2);
    if(a2>b2) swap(a2,b2);
    //���������� �����������
    if(a/a2==b/b2&&b/b2==c/c2) cout << "rectangles are similar"<<endl;
    else cout << "rectangles are not similar"<<endl;
    return 0;
}
void swap(float& a, float& b){
    float k = a; //�������������� ���������� ��� ������
    a = b;
    b = k;
}
