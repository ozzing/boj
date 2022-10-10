#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> tmp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, x;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        vec.push_back(x);
    }

    for(int i=0;i<m;i++) tmp.push_back(1);
    for(int i=m;i<n;i++) tmp.push_back(0);

    sort(vec.begin(), vec.end());
    do{
        for(int i=0;i<n;i++){
            if(tmp[i]==1) cout << vec[i] << " ";
        }
        cout << endl;
    }while(prev_permutation(tmp.begin(), tmp.end()));
}