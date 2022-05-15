#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, tmp;
long long mini, sum;
vector<long long> sol;
int fir, sec;

void binary_search(){
    int start=0;
    int end=n-1;

    while(start<end){
        sum=sol[start]+sol[end];
        if(llabs(sum)<mini){
            mini=llabs(sum);
            fir=start;
            sec=end;
        }
        if(sum<0) start++;
        else end--;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        sol.push_back(tmp);
    }
    sort(sol.begin(), sol.end());

    mini=__LONG_LONG_MAX__;
    binary_search();

    cout << sol[fir] << " " << sol[sec];
}