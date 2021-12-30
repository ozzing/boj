#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt = 0;

void prime(int num){
    for(int i=3;i<num;i+=2){
        if(num%i==0) return;
    }
    cnt++;
}

int main(){
    int n, tmp;
    vector<int> num;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> tmp;
        num.push_back(tmp);
    }

    for(int i=0;i<num.size();i++){
        if(num[i]==2) cnt++;
        else if(num[i]!=1 && num[i]%2 != 0){
            prime(num[i]);
        }
    }
    cout << cnt;
}