#include <iostream>
using namespace std;

int h, w, x, y;
int arr[605][605];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> h >> w >> x >> y;

    int r=h+x, c=w+y;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=x;i<h;i++){
        for(int j=y;j<w;j++){
            arr[i][j]=arr[i][j]-arr[i-x][j-y];
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}