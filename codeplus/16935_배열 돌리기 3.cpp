#include <iostream>
using namespace std;

int arr[101][101];
int tmp[101][101];
int n, m, r, op;

void copy(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=tmp[i][j];
        }
    }
}

void one(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j]=arr[n-1-i][j];
        }
    }
    copy();
}
void two(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j]=arr[i][m-1-j];
        }
    }
    copy();
}
void three(){
    swap(n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j]=arr[m-1-j][i];
        }
    }
    copy();
}
void four(){
    swap(n, m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j]=arr[j][n-1-i];
        }
    }
    copy();
}
void five(){
    int nhalf=n/2;
    int mhalf=m/2;
    for(int i=0;i<nhalf;i++){
        for(int j=0;j<mhalf;j++){
            tmp[i][j+mhalf]=arr[i][j];
        }
        for(int j=mhalf;j<m;j++){
            tmp[i+nhalf][j]=arr[i][j];
        }
    }
    for(int i=nhalf;i<n;i++){
        for(int j=0;j<mhalf;j++){
            tmp[i-nhalf][j]=arr[i][j];
        }
        for(int j=mhalf;j<m;j++){
            tmp[i][j-mhalf]=arr[i][j];
        }
    }
    copy();
}
void six(){
    int nhalf=n/2;
    int mhalf=m/2;
    for(int i=0;i<nhalf;i++){
        for(int j=0;j<mhalf;j++){
            tmp[i+nhalf][j]=arr[i][j];
        }
        for(int j=mhalf;j<m;j++){
            tmp[i][j-mhalf]=arr[i][j];
        }
    }
    for(int i=nhalf;i<n;i++){
        for(int j=0;j<mhalf;j++){
            tmp[i][j+mhalf]=arr[i][j];
        }
        for(int j=mhalf;j<m;j++){
            tmp[i-nhalf][j]=arr[i][j];
        }
    }
    copy();
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

    for(int i=0;i<r;i++){
        cin >> op;
        switch(op){
            case 1: one(); break;
            case 2: two(); break;
            case 3: three(); break;  
            case 4: four(); break;
            case 5: five(); break;
            case 6: six(); break;
            default: break;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}