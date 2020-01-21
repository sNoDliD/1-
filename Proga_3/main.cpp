#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
    Point(){

    }
Point(int a, int b){
        x = a;
        y = b;
    }
void Random(int a = 500){
        x = rand()%a - a/2;
        y = rand()%a - a/2;
    }
void Print(){
    cout << "(" <<x << ";" << y<< ")";
    }
float Dictanse(Point point){
    return sqrt(pow(x - point.x,2) + pow(y - point.y,2));
}
};
void Swap(Point &a, Point &b){
    swap(a.x,b.x);
    swap(a.y,b.y);
}
int main()
{
    srand( time(0) );
    int n;
    cin >> n;
    Point arr[n];
    for(int i = 0; i < n; i++){
        arr[i].Random();
        arr[i].Print();
    }
    bool next = true;
    for(int i = 0; i < n && next; i++){
        next = false;
        for(int i2 = 1; i2 < n; i2++){
            if(arr[i2].x<arr[i2-1].x) {
                Swap(arr[i2],arr[i2-1]);
                next = true;
            }
        }
        if(!next) break;
    }
    for(int i = 0, next = true; i < n && next; i++){
        next = false;
        for(int i2 = 1; i2 < n; i2++){
            if(arr[i2].x == arr[i2-1].x && arr[i2].y < arr[i2-1].y) {
                Swap(arr[i2],arr[i2-1]);
                next = true;
            }
        }
        if(!next) break;
    }
    cout << endl << endl;
    for(int i = 0; i < n; i++){
            arr[i].Print();
            if(i != n - 1) cout << " -> ";
    }
    int minY = 0, maxY = 0;
    for(int i = 1; i < n; i++){
        if(arr[i].y>arr[maxY].y) maxY = i;
        if(arr[i].y<arr[minY].y) minY = i;
    }
    cout << endl << endl;
    Point fir(arr[0].x,arr[minY].y);
    Point sec(arr[n - 1].x,arr[maxY].y);
    cout << "O = {" << ((float)fir.x + sec.x)/2 << ";" << ((float)fir.y + sec.y)/2 << "}" << endl;
    cout << "R = " << fir.Dictanse(sec)/2 << endl;
    return 0;
}
