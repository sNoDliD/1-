#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Matrix
{
public:
    float* arr;
    int n,m;
    Matrix(int a, int b);
    ~Matrix();
    float* operator[](int row){
        if(row >= n) throw 0;
        return arr+row*m;
    }
    friend std::ostream& operator<< (std::ostream &out, Matrix & a);
    bool isSym();
    void Fill(int max = 10);
    void E();
    void Input();
    void swap(int, int);
    float Det();
    Matrix T();
    Matrix Revers();
    bool operator ==(Matrix& a);
};
    Matrix operator +(Matrix& a, Matrix& b);
    Matrix operator -(Matrix& a, Matrix& b);
    Matrix operator *(Matrix& a, Matrix& b);
    Matrix AxB(Matrix& a, Matrix& b);
int main()
{
    srand(time(0));
    Matrix a(2,2);
    Matrix b(2,2);
    a.Input();
    b.Fill();
    cout <<"Matrix 1"<<endl<< a;
    cout << "Matrix 2" <<endl<<b;
    cout << "Ax = B:"<<endl;
    Matrix c = AxB(a,b);
    cout << c;
    cout << "Matrix1*Matrix2"<<endl;
    Matrix c2 = a*b;
    cout << c2;
    cout << "Matrix1+Matrix2"<<endl;
    Matrix c3 = a+b;
    cout << c3;
    cout << "Matrix1 revedsed"<<endl;
    Matrix c4 = a.Revers();
    cout << c4;
    cout << "Matrix1 trans"<<endl;
    Matrix c5 = a.T();
    cout << c5;


    if(a.isSym()) cout << "a is symitrichna" << endl;
    else cout << "a is not symitrichna" << endl;
    return 0;
}

Matrix AxB(Matrix& a, Matrix& b){
    Matrix c = a.Revers();
    Matrix q = c*b;
    return q;
}

bool Matrix::isSym(){
    Matrix trans = this->T();
    if(trans == *this) return true;
    return false;

}

bool Matrix::operator==(Matrix& a){
    if(n!=m||a.n!=a.m||n!=a.n) return false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != arr[i*m+j]) return false;
    return true;
}

Matrix Matrix::T(){
    Matrix res(m,n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            res[j][i] = arr[i*m + j];
    }
    return res;
}

Matrix operator +(Matrix& a, Matrix& b){
    if(a.n != b.n || a.m != b.m) throw "difetent size!";
    Matrix c(a.n, a.m);
    for(int i = 0; i < c.n; i++)
        for(int j = 0; j < c.m; j++)
            c[i][j]=a[i][j] + b[i][j];
    return c;
}

Matrix operator -(Matrix& a, Matrix& b){
    if(a.n != b.n || a.m != b.m) throw "difetent size!";
    Matrix c(a.n, a.m);
    for(int i = 0; i < c.n; i++)
        for(int j = 0; j < c.m; j++)
            c[i][j]=a[i][j] - b[i][j];
    return c;
}

Matrix operator *(Matrix& a, Matrix& b){
    if(a.m != b.n) throw "difetent size!";
    Matrix c(a.n, b.m);
    for(int i = 0; i < c.n; i++)
        for(int j = 0; j < c.m; j++){
            float sum = 0;
            for(int t = 0; t < a.m; t++){
                sum += a[i][t]*b[t][j];
            }
            c[i][j] = sum;
        }
    return c;
}

void Matrix::Input(){
    cout << "enter "<<n*m<< " elements: ";
    int i = 0;
    while(i<n*m){
        cin >> arr[i++];
    }
}

Matrix::Matrix(int a, int b){
        n = a;
        m = b;
        arr=new float[a*b];
}

void Matrix::E(){
        if(n==m)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i==j)arr[i*m+j]=1;
                else arr[i*m+j]=0;
        }
        }
}

Matrix::~Matrix(){
        delete[] arr;
    }

void Matrix::Fill(int max){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr[i*m+j]=rand()%(max*2)-max;
        }
    }
}

Matrix Matrix::Revers(){
        if(n!=m) throw "Has no revers";
        Matrix temp(n,n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                temp[i][j] = arr[i*m+j];
        Matrix res(n,n);
        res.E();
        for(int i = 0; i < n; i++){
                if(temp[i][i]==0){
                    for(int z = n-1; ; z--){
                        if(temp[z][0]!=0){
                            this->swap(z,i);
                            res.swap(z,i);
                            break;
                        }
                        if(z==i) {
                                cout << "Det = 0"<< endl;
                                throw "Has no revers";
                        }
                    }
                }
                float div = temp[i][i];
                for(int z = 0; z < n; z++) {
                        temp[i][z]/=div;
                    res[i][z]/= div;
                }
                for(int z = i+1; z < n; z++){
                    float delta = temp[z][i];
                    for(int y = 0; y < n; y++){
                        temp[z][y]-=delta*temp[i][y];
                        res[z][y]-=delta*res[i][y];
                    }
                }
                for(int z = i-1; z >= 0; z--){
                    float delta = temp[z][i];
                    for(int y = 0; y < n; y++){
                        temp[z][y]-=delta*temp[i][y];
                        res[z][y]-=delta*res[i][y];
                    }
                }

        }
        return res;
}

float Matrix::Det(){
        if(n!=m) throw "Has no determinant";
        float res = 1;
        for(int i = 0; i < n; i++){
                if(arr[i*m+i]==0){
                    for(int z = n-1; ; z--){
                        if(arr[z*m]!=0){
                            this->swap(z,i);
                            res*=-1;
                            break;
                        }
                        if(z==i) return 0;
                    }
                }
                float div = arr[i*m+i];
                for(int z = i; z < n; z++) arr[i*m+z]/=div;
                for(int z = i+1; z < n; z++){
                    float delta = arr[z*m+i];
                    for(int y = i; y < n; y++){
                        arr[z*m+y]-=delta*arr[i*m+y];
                    }
                }
                res*=div;

        }
        return res;
}

void Matrix::swap(int row1, int row2){
    for(int i = 0; i < m; i++){
        float temp = arr[row1*m + i];
        arr[row1*m + i]= arr[row2*m + i];
        arr[row2*m + i] = temp;
    }
}

std::ostream& operator <<(std::ostream & out, Matrix & a){
    for(int i = 0; i < a.n; i++){
        for(int j = 0; j < a.m; j++){
            out << a[i][j]<< "\t";
        }
        out << endl;
    }
    out<<endl;
    return out;
}
