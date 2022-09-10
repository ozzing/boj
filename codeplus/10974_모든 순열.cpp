#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int> vec;

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        vec.push_back(i);
    }
    
    do {
        for(int i=0;i<n;i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(vec.begin(), vec.end()));
}