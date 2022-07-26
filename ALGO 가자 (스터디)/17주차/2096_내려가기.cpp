#include <iostream>
using namespace std;

int input[3];
int maxi[3];
int mini[3];
int temp[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, a, b, c;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> input[j];
            if(i==0){
                for(int j=0;j<3;j++) {
                    maxi[j]=input[j];
                    mini[j]=input[j];
                }
            }
        }
        if(i!=0){
            temp[0]=input[0]+max(maxi[0], maxi[1]);
            temp[1]=input[1]+max(max(maxi[0], maxi[1]), maxi[2]);
            temp[2]=input[2]+max(maxi[1], maxi[2]);
            maxi[0]=temp[0]; maxi[1]=temp[1]; maxi[2]=temp[2];

            temp[0]=input[0]+min(mini[0], mini[1]);
            temp[1]=input[1]+min(min(mini[0], mini[1]), mini[2]);
            temp[2]=input[2]+min(mini[1], mini[2]);
            mini[0]=temp[0]; mini[1]=temp[1]; mini[2]=temp[2];
        }
    }

    cout << max(max(maxi[0], maxi[1]), maxi[2]);
    cout << " ";
    cout << min(min(mini[0], mini[1]), mini[2]);
    cout << "\n";
}