#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());
       
    int ans=0;
    do {
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=abs(vec[i]-vec[i+1]);
        }
        ans=max(ans, sum);
    } while(next_permutation(vec.begin(), vec.end()));

    cout << ans;
}