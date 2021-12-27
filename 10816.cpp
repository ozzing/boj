#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, tmp, num;
    vector<int> a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());

    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp;
        num = upper_bound(a.begin(), a.end(), tmp) - lower_bound(a.begin(), a.end(), tmp);
        cout << num << ' ';
    }
}