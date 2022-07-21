#include <iostream>
using namespace std;

int sum[1025][1025] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k, x1, y1, x2, y2;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> k;
            sum[i][j]=k+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    for(int i=0;i<m;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
        cout << ans << "\n";
    }
}