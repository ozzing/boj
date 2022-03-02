#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main(){
    int n, tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for(int i=0;i<vec.size();i++) cout << vec[i] << " ";
}