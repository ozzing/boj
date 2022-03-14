#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> vec;

bool cmp1(string a, string b){
    if(stoi(a)>stoi(b)) return true;
    else return false;
}

bool cmp2(string a, string b){
    if(a+b>b+a) return true;
    else return false;
}

int main(){
    int k, n;
    string tmp, str="";
    cin >> k >> n;
    for(int i=0;i<k;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), cmp1);

    for(int i=0;i<n-k;i++) vec.push_back(vec[0]);
    sort(vec.begin(), vec.end(), cmp2);
    for(int i=0;i<n;i++) cout << vec[i];    
} 