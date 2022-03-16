#include <iostream>
using namespace std;

int map[400][400];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, size=1;
    cin >> n;
    for(int i=2;i<=n;i++){
        size+=4;
    }

    int start=0, end=size;

    for(int k=0;k<n;k++){
        for(int i=start;i<end;i++){
            for(int j=start;j<end;j++){
                if(i==start||j==start||i==end-1||j==end-1)
                    map[i][j]=1;     
            }
        }
        start+=2; end-=2;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(map[i][j]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}