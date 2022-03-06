#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> muscle;

int main(){
    long long n, t, max=0, start=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        muscle.push_back(t);
    }

    sort(muscle.begin(), muscle.end());

    if(n%2==0){
        max=muscle[n-1]+muscle[0];
        start=1;
    }
    else{
        max=muscle[n-1];
        start=0;
    }
    for(int i=start;i<(n-1+start)/2;i++){
        long long tmp=muscle[i]+muscle[n-2+start-i];
        if(tmp>max) max=tmp;
    }
    cout << max;
}