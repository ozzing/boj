#include <iostream>
#include <cmath>
using namespace std;

int rgb[1001][3];
int dp0[1001][3];
int dp1[1001][3];
int dp2[1001][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin >> rgb[i][j];
        }
        if(i==1){
            dp0[i][0]=rgb[i][0];
            dp1[i][1]=rgb[i][1];
            dp2[i][2]=rgb[i][2];

            dp0[i][1]=1001; dp0[i][2]=1001;
            dp1[i][0]=1001; dp1[i][2]=1001;
            dp2[i][0]=1001; dp2[i][1]=1001;
        }
        else{
            dp0[i][0]=min(dp0[i-1][1],dp0[i-1][2])+rgb[i][0];
            dp0[i][1]=min(dp0[i-1][0],dp0[i-1][2])+rgb[i][1];
            dp0[i][2]=min(dp0[i-1][0],dp0[i-1][1])+rgb[i][2];
           
            dp1[i][0]=min(dp1[i-1][1],dp1[i-1][2])+rgb[i][0];
            dp1[i][1]=min(dp1[i-1][0],dp1[i-1][2])+rgb[i][1];
            dp1[i][2]=min(dp1[i-1][0],dp1[i-1][1])+rgb[i][2];
        
            dp2[i][0]=min(dp2[i-1][1],dp2[i-1][2])+rgb[i][0];
            dp2[i][1]=min(dp2[i-1][0],dp2[i-1][2])+rgb[i][1];
            dp2[i][2]=min(dp2[i-1][0],dp2[i-1][1])+rgb[i][2];
        }
    }

    int min0 = min(dp0[n][1], dp0[n][2]);
    int min1 = min(dp1[n][0], dp1[n][2]);
    int min2 = min(dp2[n][0], dp2[n][1]);

    cout << min(min0, min(min1, min2));
}