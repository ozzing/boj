#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    vector<long long> vec;
    long long n, temp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end(), greater<>());

    long long tip=0;
    for(long long i=0;i<n;i++){
        if(vec[i]-i>0)
        tip+=vec[i]-i;
    }
    cout << tip;
}