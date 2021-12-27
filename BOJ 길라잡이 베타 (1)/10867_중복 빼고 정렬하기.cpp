#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>> tmp;
        vec.push_back(tmp);
    }
    
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << ' ';
    }
}