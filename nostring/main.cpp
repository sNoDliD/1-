#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void check(char* a, char* b, void (*f)(char* c,char* d));
void cInt(char*, char*);
void cChar(char*, char*);
int NSD(int, int);
void P3();
void P4();
int Find(string,char);
bool isVowels(char);
bool contains(vector <char[]> , char*);
int Size(char*);
int main()
{
    while(1){
        cout << "Enter number of problem(1-4): ";
        int n;
        cin >> n;
        switch(n){
        case 1: {
            void (*f)(char*,char*);
            char str1[51];
            cin.ignore();
            cin.getline(str1, 51, ' ');
            char str2[51];
            cin.getline(str2, 51, '\n');
            if(Size(str1)!=Size(str2)){
                cout << "NO";
                break;
            }
            if(str1[0]>='0'&&str1[0]<='9') f = cInt;
            else f = cChar;
            check(str1,str2,f);
            break;
        }
        case 2: {
            int a,b;
            cin >> a >> b;
            cout << NSD(a,b)<< endl;
            break;
        }
        case 3: P3();
        case 4: P4();
    }
    cout << endl;
    }
    return 0;
}
void cInt(char* c,char* d){
    for(int i = 0; i < Size(c); i++){
        if(c[i]!=d[i]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}
void cChar(char* c,char* d){
    for(int i = 0; i < Size(c); i++){
        if(c[i]!=d[i]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}
void check(char* a, char* b, void (*f)(char* c,char* d)){
    f(a,b);
}
int Size(char* a){
    int res = 0;
    while(a[res]!='\0')res++;
    return res;
}
int NSD(int a, int b){
    if(a < b){
        int c = a;
        a = b;
        b = c;
    }
    if(b==0) return a;
    else return NSD(b,a%b);
}
int VowCount(string s){
    int res = 0;
    for(int i = 0; i < s.size(); i++) if(isVowels(s[i])) res++;
    return res;
}
void P3(){
    string out1 = "", out2 = "";
    char c;
    string temp = "";
    string sp1 = ".,:-!? ";
    fstream fin;
    fin.open("eng_in.txt");
    while(fin.get(c)){
        if(Find(sp1,c)!=-1){
            if(temp == "") continue;
            if(VowCount(temp)>=2) out1 += temp + " ";
            if(!isVowels(temp[0])&&isVowels(temp[temp.size()-1])) out2 += temp + " ";
            temp = "";
            continue;
        }
        temp += c;
    }
    if(VowCount(temp)>=2) out1 += temp + " ";
    if(!isVowels(temp[0])&&isVowels(temp[temp.size()-1])) out2 += temp + " ";
    ofstream fout("eng_out.txt");
    fout << out1<< "\n" << out2;
    fout.close();
    fin.close();

}
void P4(){
    //vector <char*> A;
    char **A;
    for(int i = 0; i < 30; i++){
        A[i][0] = '\0';
    }
    vector <char*> B;
    bool inA = true;
    char c;
    int now = 0;
    int now2 = 0;
    char temp[30];
    fstream fin;
    fin.open("names.txt");
    while(fin.get(c)){
        if(c==' '||c=='\n'){
                //cout << temp << endl;
            if(inA) {
                    A[now2++]=temp;
            }
            else B.push_back(temp);
            if(c=='\n') inA = false;
            now = 0;
            temp[0] = '\0';
        }
        else {
                temp[now] =c;
                temp[now+1] = '\0';
                now++;
        }

    }
    if(temp[0] != '\0') B.push_back(temp);
    cout << "peretin: ";
    for(int i = 0; A[i][0]!='\0'; i++) cout << A[i];
    //if(contains(A,B[i]))cout << B[i] << " ";
    /*cout << endl;
    cout << "simytrichna rizica: ";
    for(int i = 0; i < B.size(); i++)
    if(!contains(A,B[i]))cout << B[i] << " ";
    for(int i = 0; i < A.size(); i++)
    if(!contains(B,A[i]))cout << A[i] << " ";
    cout << endl;*/
    fin.close();
}
/*bool contains(vector <char[]> A, char* elB){
    for(int i = 0; i < A.size(); i++)
    if(A[i]==elB) return true;
    return false;
}*/
int Find(string str,char c){
    for(int i = 0, len = str.size(); i < len; ++i)
        if(str[i]==c) return i;
    return -1;
}
bool isVowels(char c){
    string s = "AEIOUYaeiouy";
    if(Find(s,c)==-1) return false;
    else true;
}
bool contains(string str, string s){
    return str.find(s)!=string::npos;
}
