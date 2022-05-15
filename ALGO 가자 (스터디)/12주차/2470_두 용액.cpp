#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define SWAP(a,b) {int t; t=a; a=b; b=t;}

int n, tmp, res, cnt, sum;
int num[2];
int ans[2];
vector<int> sol;
vector<int> permu;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        sol.push_back(tmp);
    }
    for(int i=0;i<2;i++) permu.push_back(1);
    for(int i=2;i<n;i++) permu.push_back(0);
    sort(permu.begin(), permu.end());

    res=0xffff;
    do{
        sum=0;
        cnt=0;
        for(int i=0;i<n;i++){
            if(permu[i]==1){
                sum+=sol[i];
                num[cnt++]=sol[i];
            }
        }

        if(abs(res)>abs(sum)){
            res=sum;
            for(int i=0;i<2;i++){
                ans[i]=num[i];
            }
        }
        memset(num, 0, sizeof(num));

    } while(next_permutation(permu.begin(), permu.end()));
    
    if(ans[0]>ans[1]) SWAP(ans[0], ans[1]);
    cout << ans[0] << " " << ans[1];
}