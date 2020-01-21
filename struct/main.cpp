#include <iostream>
#include <cmath>
using namespace std;
struct equaition{
    public:
    float a, b ,c;
    equaition(float a2, float b2, float c2){
        a = a2;
        b = b2;
        c = c2;
    }
    void print(){
     if(a!=0) cout << a <<"x^2";
     if(b!=0) {
        if(a==0)
            cout << b <<"x";
        else
        {
            if(b>0) cout <<"+"<< b <<"x";
            if(b<0) cout << b <<"x";
        }
     }
     if(c!=0){
        if(b==0&&a==0) cout << c;
        else{
            if(c>0) cout <<"+"<< c;
            if(c<0) cout << c;
        }
     }
     cout << endl;
    }
    void roots(){
        if(a==0){
            if(b==0){
            cout << "no roots" <<endl;
            return;
            }
            cout <<"x = " << -c/b<< endl;
            return;
        }
        float d = sqrt(b*b - 4*a*c);
        if(d<0){
            cout << "no roots" <<endl;
            return;
        }
        float x1 = (-b + d)/(2*a);
        float x2 = (-b - d)/(2*a);
        if(x1 == x2) cout << "x = "<<x1 << endl;
        else cout << "x1 = "<<x1 << endl <<"x2= "<<x2 << endl;;
    }

};
equaition sum(equaition fir, equaition sec){
        float q = fir.a + sec.a;
        float w = fir.b + sec.b;
        float e = fir.c + sec.c;
        return equaition(q, w, e);
    }
int main()
{
    equaition a(0,3,4);
    equaition b(2,3,-4);
    equaition c = sum(a,b);
    c.print();
    c.roots();
    return 0;
}
