#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> home;
int n, c, tmp;

void binary_search(){
    int start=0;
    int end=home[n-1];
    int res=0, cnt=0, tmp=0;

    while(start<=end){
        cnt=1;
        tmp=0;
        int mid=(start+end)/2;
        for(int i=1;i<n;i++){
            if(home[i]-home[tmp]>=mid){
                tmp=i;
                cnt++;
            }
        }
        if(cnt>=c){
            res = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    } 
    cout << res;
}

int main(){
    cin >> n >> c;
    for(int i=0;i<n;i++){
        cin >> tmp;
        home.push_back(tmp);
    }
    sort(home.begin(), home.end());

    binary_search();
}