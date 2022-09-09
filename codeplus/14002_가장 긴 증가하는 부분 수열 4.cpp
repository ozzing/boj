#include <iostream>
#include <vector>
using namespace std;

int arr[1001];
int dp[1001];
vector<int> vec[1001];
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    for(int i=1;i<=n;i++){
        dp[i]=1;
        vec[i].push_back(arr[i]);
        for(int j=1;j<i;j++){
            if(arr[i] > arr[j]){
                if(dp[i] < dp[j]+1){
                    vec[i].clear();
                    vec[i]=vec[j];
                    vec[i].push_back(arr[i]);
                    dp[i]=dp[j]+1;
                }
            }
        }
        if(ans.size() < vec[i].size()){
            ans=vec[i];
        }
    }

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}