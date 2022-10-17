#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int arr[10];

int main(){
    long long a, b;
    cin >> a >> b;

    string str=to_string(a);
    
    for(int i=0;i<str.length();i++){
        arr[i]=str[i] - '0';
    }

    sort(arr, arr+str.length(), greater<>());

    do{
        if(arr[0]==0) continue;
        string tmp="";
        for(int i=0;i<str.length();i++){
            tmp+=arr[i] + '0';
        }

        long long res = stoi(tmp);
        if(res<b){
            cout << res;
            return 0;    
        }
    }while(prev_permutation(arr, arr+str.length()));

    cout << -1;
}