#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> p;

int main(){
    int n, tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        p.push_back(tmp);
    }
    sort(p.begin(), p.end());
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=p[i]*(n-i);
    }

    cout << sum;
}