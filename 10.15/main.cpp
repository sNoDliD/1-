#include <iostream>
#include <deque>
#include <iomanip>
using namespace std;

class Point{
public:
    int x, y;
    Point () {}
    Point(int a, int b){
    x = a;
    y = b;
    }
    void Print(){
    cout << "(" << x << "," << y << ")";
    }
};
class Circle{
    const float PI = 3.141592;
public:
    deque <int> arr;
    int sum = 0;
    float radius;
    Circle(int r){
        radius = r;
    }
    void add(int a){
    arr.push_back(a);
    sum += a;
    }
    float get(int n){
    if(n > arr.size()) return 0;
    return (float)arr[n]*PI * radius * radius / sum;
    }
};
int abs(int a){
    if(a<0) return -a;
    return a;
}
int main()
{
    int n;
    float r;
    cin >> n >> r;
    Circle kolo(r);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        kolo.add(temp);
    }
    for(int i = 0; i < n; i++)cout << i + 1 << ": " <<setprecision(7)<< kolo.get(i) << endl;
    /*
    cout << "enter n and n pair of cordinate" << endl;
    int n;
    cin >> n;
    Point arr[n];
    for(int i = 0; i < n; i++)
    {
        int cx, cy;
        cin >> cx >> cy;
        arr[i] = Point(cx, cy);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if((arr[i].x - arr[j].x)*(arr[i].y - arr[j].y) == 0 || abs(arr[i].x - arr[j].x) == abs(arr[i].y - arr[j].y)){
                cout << i + 1 << " vs " << j+1 << "\t";
                arr[i].Print();
                arr[j].Print();
                cout << endl;
                }
        }

    }*/
    return 0;
}
