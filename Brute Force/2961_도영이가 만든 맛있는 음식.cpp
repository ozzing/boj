#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<long long,long long>> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i].first >> vec[i].second;
    }

    long long mn=0xffffff;
    for(int i=1;i<=n;i++){
        vector<int> tmp;
        for(int t=0;t<i;t++) tmp.push_back(1);
        for(int t=i;t<n;t++) tmp.push_back(0);
        sort(tmp.begin(), tmp.end());

        do{
            long long s=1, b=0;
            for(int v=0;v<n;v++){
                if(tmp[v]){
                    s*=vec[v].first;
                    b+=vec[v].second;
                }
            }
            if(s&&b) mn=min(mn, abs(s-b));
        } while(next_permutation(tmp.begin(), tmp.end()));
    }

    cout << mn;
}