#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, tmp, res=0;
    vector <int> a;
    vector <int> b;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin>> tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++) {
        cin>> tmp;
        b.push_back(tmp);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0;i<n;i++){
        res+= a[i] * b[n-1-i];
    }
    cout << res;
}