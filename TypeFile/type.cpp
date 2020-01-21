#include "type.h"

void P1(vector <Country> countrys){
    cout << "max tempetatyre in summer:" << endl;
    vector <Country> rez;
    rez.push_back(countrys[0]);
    for(int i = 1, n = countrys.size(); i < n; ++i){
        if(rez[0].summer == countrys[i].summer) rez.push_back(countrys[i]);
        else if(rez[0].summer < countrys[i].summer) {
            while(rez.size()>0)
                rez.erase(rez.begin()+1);
            rez.push_back(countrys[i]);
        }
    }
    for(int i = 0, n = rez.size(); i < n; ++i){
        cout << rez[i].name << " - " << rez[i].summer << endl;
    }
    cout << "min tempetatyre in averange:" << endl;
    while(rez.size()>0) rez.erase(rez.begin()+1);
    rez.push_back(countrys[0]);
    for(int i = 1, n = countrys.size(); i < n; ++i){
        if(rez[0].averenge() == countrys[i].averenge()) rez.push_back(countrys[i]);
        else if(rez[0].averenge() > countrys[i].averenge()) {
            while(rez.size()>0)
                rez.erase(rez.begin()+1);
            rez.push_back(countrys[i]);
        }
    }
    for(int i = 0, n = rez.size(); i < n; ++i){
        cout << rez[i].name << " - " << rez[i].averenge() << endl;
    }
}
void P2(vector <Country> countrys){
    float ma, mi;
    string maSeson, miSeson;
    string maName, miName;
    cout << "Max and Min temperature in all countrys:" << endl;
    mi = countrys[0].minimum(miSeson);
    ma = countrys[0].maximum(maSeson);
    for(int i = 1, n = countrys.size(); i < n; ++i){
        string s;
        int t = countrys[i].minimum(s);
        if(t < mi){
            miName = countrys[i].name;
            miSeson = s;
            mi = t;
        }
        t = countrys[i].maximum(s);
        if(t > ma){
            maName = countrys[i].name;
            maSeson = s;
            ma = t;
        }
    }
        cout <<"Min at " << miName<< " in " << miSeson << " - "<< mi << endl;
        cout <<"Max at " <<maName<< " in " << maSeson << " - "<< ma << endl;
}
void P3(vector <Country> countrys){
    cout << "Sort by MAX:" << endl;
    for(int i = 0, n = countrys.size(); i < n - 1; ++i){
        for(int j = 0; j < n - 1; ++j){
            if(countrys[j].summer < countrys[j+1].summer) swap(countrys[j],countrys[j+1]);
        }
    }
    for(int i = 0, n = countrys.size(); i < n; ++i){
        countrys[i].print();
    }
}
void P4(vector <Country> countrys){
    cout << "countrys with t > 30 in summer:" << endl;
    for(int i = 0, n = countrys.size(); i < n; ++i){
        if(countrys[i].summer>30 )cout << countrys[i].name << endl;
    }
}
void P5(vector <Country> countrys){
    cout << "countrys with t < 0 in winter:" << endl;
    for(int i = 0, n = countrys.size(); i < n; ++i){
        if(countrys[i].winter < 0)cout << countrys[i].name << endl;
    }
}
void P61(vector <Country> countrys, string name){
    Country country = countrys[findByName(countrys,name)];
    cout << "min temperature in " << name << " - " << country.minimum() << endl;
    cout << "max temperature in " << name << " - " << country.maximum() << endl;
    cout << "averenge temperature in " << name << " - " << country.averenge() << endl;

}
void P62(vector <Country> countrys, string name, float temp){
    Country country = countrys[findByName(countrys,name)];
    if(country.containLes(temp))cout << "In " << name << " was les"<< endl;
    if(country.containMore(temp))cout << "In " << name << " was more"<< endl;
}
void P63(vector <Country> countrys, string name){
    Country country = countrys[findByName(countrys,name)];
    cout << "Delta between max and min temperature in " << name << " - " <<country.maximum() - country.minimum() << endl;
}
void Country::print(){
    string tab = "";
    if(name.size() < 8) tab = "\t\t";
    else if(name.size() < 16) tab = "\t";
    cout << name << tab << summer << "\t" << autumn << "\t" << winter << "\t" << spring << endl;
}
void swap(Country &a, Country &b){
    Country c = a;
    a = b;
    b = c;
}
int findByName(vector <Country> countrys, string name){
    for(int i = 0, n = countrys.size(); i < n; ++i){
        if(countrys[i].name == name) return i;
    }
    return -1;
}
float convert(string str){
    float rez = 0;
    int i = str[0] == '-'? 1 : 0;
    bool isPositive = i == 0;
    bool isFloat = false;
    for(int n = str.size(), i2 = 1; i < n; ++i){
        if(str[i]=='.') {
            isFloat = true;
            continue;
        }
        if(!isFloat)rez = rez * 10 + (str[i]-'0');
        else rez += (str[i]-'0')/pow(10,i2++);
    }
    return isPositive? rez : -rez;

}
float pow(int a, int b){
    float rez = 1;
    if(b > 0){
        for(int i = 0; i < b; ++i) rez*=a;
    }
    else if(b < 0){
        for(int i = 0; i > b; --i) rez/=a;
    }
    return rez;
}
float Country::maximum(string &seson){
    float m = summer;
    seson = "summer";
    if(autumn > m){
        m = autumn;
        seson = "summer";
    }
    if(winter > m){
        m = winter;
        seson = "winter";
    }
    if(spring > m){
        m = spring;
        seson = "spring";
    }
    return m;
}
float Country::maximum(){
    float m = summer;
    if(autumn > m) m = autumn;
    if(winter > m) m = winter;
    if(spring > m) m = spring;
    return m;
}
float Country::minimum(string &seson){
    float m = summer;
    seson = "summer";
    if(autumn < m){
        m = autumn;
        seson = "summer";
    }
    if(winter < m){
        m = winter;
        seson = "winter";
    }
    if(spring < m){
        m = spring;
        seson = "spring";
    }
    return m;
}
float Country::minimum(){
    float m = summer;
    if(autumn < m) m = autumn;
    if(winter < m) m = winter;
    if(spring < m) m = spring;
    return m;
}
float Country::averenge(){
    return (summer + autumn + winter + spring)/4;
}
bool Country::containLes(float temp){
    if(summer < temp) return true;
    if(spring < temp) return true;
    if(winter < temp) return true;
    if(autumn < temp) return true;
    return false;
}
bool Country::containMore(float temp){
    if(summer > temp) return true;
    if(spring > temp) return true;
    if(winter > temp) return true;
    if(autumn > temp) return true;
    return false;
}
Country::Country(string s, float a, float b, float c, float d){
    name = s;
    summer = a;
    autumn = b;
    winter = c;
    spring = d;
}
