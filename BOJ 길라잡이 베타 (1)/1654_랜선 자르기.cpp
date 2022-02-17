#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lan;

int main(){
    int k, n;
    long long tmp;
    cin >> k >> n;
    for(int i=0;i<k;i++){
        cin >> tmp;
        lan.push_back(tmp);
    }
    sort(lan.begin(), lan.end());

    long long start=1;
    long long end=lan[k-1];
    int res=0;

    while(start<=end){
        long long sum=0;
        long long mid = (start + end) / 2;
        for(int i=0;i<k;i++){
            sum+=lan[i]/mid;
        }
        if(sum>=n){
            res = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout << res;
}