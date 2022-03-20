#include <iostream>
using namespace std;

int map[1025][1025];
int dp[1025][1025];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k, x1, x2, y1, y2;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> map[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+map[i][j];
        }
    }

    cin >> k;
    for(int t=0;t<k;t++){
        cin >> x1 >> y1 >> x2 >> y2;
        int res = dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
        cout << res << "\n";
    }
}