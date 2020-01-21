#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
std::ostream& operator <<(std::ostream & out, vector <int> & a);
vector <int> sort1(vector <int>);
vector <int> sort2(vector <int>);
void sort3(vector <int>&, int left = -1, int right = -1);
vector <int> sort4(vector <int>);

int main()
{
    srand( time(0) );
    int n = 20;
    vector <int> arr;
    for(int i = 0; i < n; i++) arr.push_back(rand()%100 - 50);
    cout << "start array: "<<endl;
    cout << arr;
    vector <int> arr1 = sort1(arr);
    vector <int> arr2 = sort2(arr);
    sort3(arr);
    cout << "sorts" <<endl;
    cout <<arr1<<arr2<< arr;
    return 0;
}
std::ostream& operator <<(std::ostream & out, vector <int> & a){
    for(int i = 0; i < a.size(); i++){
        out << a[i] << "   ";
    }
    out<<endl;
    return out;
}

vector <int> sort1(vector <int> arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else break;
        }
    }
    return arr;
}

vector <int> sort2(vector <int> arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j]< arr[min]) min = j;
        }
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }

    }
    return arr;
}

void sort3(vector <int>& arr, int left, int right){
    if(left < 0) left = 0;
    if(right < 0) right = arr.size()-1;
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    };
    if (left < j) sort3(arr, left, j);
    if (i < right) sort3(arr, i, right);

}
