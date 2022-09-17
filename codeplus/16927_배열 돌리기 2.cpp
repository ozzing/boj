#include <iostream>
using namespace std;

int arr[301][301];
int n, m, r;

void turn(){
    int x1=1, y1=1;
    int x2=1, y2=m;
    int x3=n, y3=1;
    int x4=n, y4=m;

    while((x1<x3) && (y1<y2)){
        int times = r % ((x3-x1)*2 + (y2-y1)*2);

        while(times--){
            int tmp = arr[x1][y1];
            
            for(int j=y1;j<y4;j++){
                arr[x1][j]=arr[x1][j+1];
            }
            for(int i=x2;i<x4;i++){
                arr[i][y2]=arr[i+1][y2];
            }
            for(int j=y4;j>y3;j--){
                arr[x3][j]=arr[x3][j-1];
            }
            for(int i=x3;i>x1;i--){
                arr[i][y3]=arr[i-1][y3];
            }
            
            arr[x1+1][y1]=tmp;
        }

        x1++; y1++;
        x2++; y2--;
        x3--; y3++;
        x4--; y4--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> r;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }

    turn();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}