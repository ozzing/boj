#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, tmp;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for(int i=0;i<n;i++)
        cout<<vec[i]<<'\n';
}