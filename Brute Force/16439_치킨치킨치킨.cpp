#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int val[30][30];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> val[i][j];
        }
    }

    vector<int> vec;
    for(int i=0;i<3;i++){vec.push_back(1);}
    for(int i=3;i<m;i++){vec.push_back(0);}
    sort(vec.begin(), vec.end());

    int mx=0;
    do{
        int total=0;
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=0;j<m;j++){
                if(vec[j]) p=max(p, val[i][j]);
            }
            total+=p;
        }
        mx=max(mx, total);

    }while(next_permutation(vec.begin(), vec.end()));

    cout << mx;
}