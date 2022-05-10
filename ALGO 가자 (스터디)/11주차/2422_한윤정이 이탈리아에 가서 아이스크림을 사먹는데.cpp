#include <iostream>
using namespace std;

int type[201][201];
int n, m, cnt;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        type[a][b]=1;
        type[b][a]=1;
    }

    cnt=0;
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                if(type[i][j]||type[i][k]||type[j][k]) continue;
                cnt++;
            }
        }
    }
    cout << cnt;
}