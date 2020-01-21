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
void Print(){
    cout << "(" <<x << ";" << y<< ")";
    }
float Dictanse(Point point){
    return sqrt(pow(x - point.x,2) + pow(y - point.y,2));
}
};

int main()
{
    while(true){
    cout << "enter number 1-3"<< endl;
    char num;
    cin >> num;
    switch(num){
case '1':{
    cout << "enter r, a, b: ";
    float r, a, b;
    cin >> r >> a >> b;
    if(r>=sqrt(a*a + b*b)/2) cout << "YES";
    else cout << "NO";
    cout << endl << endl;
    break;
}
case '2':{
    cout << "enter a, b, x, y, z: ";
    float a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    if(x > y) swap(x,y);
    if(y > z) swap(y, z);
    if(x > y) swap(x, y);
    if(a > b) swap(a, b);
    if(a >= x && b >= y) cout << "YES";
    else cout << "NO";
    cout << endl << endl;
    break;
}
case '3':{
    cout << "enter n, x, y and n pair of (x,y): ";
    int n, x, y;
    cin >> n >> x >> y;
    Point arr[n];
    int corx, cory;
    for(int i = 0; i < n; i++){
        cin >> corx >> cory;
        arr[i] = Point(corx, cory);
    }
    for(int i = 0; i < n; i++){
        arr[i].Print();
    }
    bool result = false;
    for(int i = 0; i < n - 1; i++){
        if(arr[i].x == arr[i+1].x && x <= arr[i].x && y > min(arr[i].y, arr[i + 1].y) && y < max(arr[i].y, arr[i + 1].y)) result = !result;
        else if(y > min(arr[i].y, arr[i + 1].y) && y < max(arr[i].y, arr[i + 1].y)
           && x <= (float)(y - arr[i].y)*(arr[i+1].x - arr[i].x)/(arr[i+1].y - arr[i].y) + arr[i].x)
            result = !result;
    }
    if(result) cout << "YES" << endl;
    else cout << "NO" << endl;
    break;
}
    }
    }
    return 0;
}
