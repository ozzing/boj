#include <iostream>
#include <algorithm>
using namespace std;

int rgb[3];
int home[1001][3] = {0,};


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin >> rgb[j];
        }
        home[i][0] = min(home[i-1][1], home[i-1][2]) + rgb[0];
        home[i][1] = min(home[i-1][0], home[i-1][2]) + rgb[1];
        home[i][2] = min(home[i-1][0], home[i-1][1]) + rgb[2];
    }

    cout<< min(min(home[n][0], home[n][1]), home[n][2]);
}  