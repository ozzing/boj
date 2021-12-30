#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, tmp;
    vector<int> div;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        div.push_back(tmp);
    }
    sort(div.begin(), div.end());
    
    cout << div[0] * div[div.size()-1];
}