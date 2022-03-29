#include <iostream>
using namespace std;

int map[1000][1000];
int dp[1000][1000][3];

int dy[3] = {-1,0,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            for(int k=0;k<3;k++){
                if(i==0) dp[i][j][k] = map[i][j];
                else dp[i][j][k] = 0xffff;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if (j == 0) {				
                dp[i][j][0] = min(dp[i-1][j][1], dp[i-1][j+1][2]) + map[i][j];
				dp[i][j][1] = dp[i-1][j+1][2] + map[i][j];
			}
            else if (j == m-1) {
				dp[i][j][1] = dp[i-1][j-1][0] + map[i][j];
				dp[i][j][2] = min(dp[i-1][j][1], dp[i-1][j-1][0]) + map[i][j];
			} 
			else {
				dp[i][j][0] = min(dp[i-1][j][1], dp[i-1][j+1][2]) + map[i][j];
				dp[i][j][1] = min(dp[i-1][j-1][0], dp[i-1][j+1][2]) + map[i][j];
				dp[i][j][2] = min(dp[i-1][j][1], dp[i-1][j-1][0]) + map[i][j];
			}
        }
    }

    int res = 0xffff;
    for (int j = 0; j < m; j++){
        for (int k = 0; k < 3; k++){
            res = min(res, dp[n-1][j][k]);
        }
    }
    cout << res;
}