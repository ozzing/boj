#include <iostream>
using namespace std;

int n, m, r;
int arr[300][300];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void rotate(){
    while(r--){
        int x1=0, x2=n-1, x3=n-1, x4=0;
        int y1=0, y2=0, y3=m-1, y4=m-1;

        while(x1<x2 && y1<y4){
            int tmp=arr[x1][y1];
            for(int i=y1;i<y4;i++){
                arr[x1][i]=arr[x1][i+1];
            }
            for(int i=x4;i<x3;i++){
                arr[i][y4]=arr[i+1][y4];
            }
            for(int i=y3;i>y2;i--){
                arr[x3][i]=arr[x3][i-1];
            }
            for(int i=x2;i>x1;i--){
                arr[i][y2]=arr[i-1][y2];
            }
            arr[x1+1][y1] = tmp;

            x1++; y1++;
            x2--; y2++;
            x3--; y3--;
            x4++; y4--;
        }        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    rotate();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}