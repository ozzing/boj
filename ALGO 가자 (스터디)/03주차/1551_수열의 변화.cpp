#include <iostream>
#include <algorithm>
using namespace std;

int num[20];

int main(){
    int n, k;
    char tr;
    cin >> n >> k;
    cin >> num[0];
    for(int i=1;i<n;i++){
        cin >> tr >> num[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n-i;j++){
            num[j-1] = num[j]-num[j-1];
        }
    }
    cout << num[0];
    for(int i=1;i<n-k;i++){
        cout << "," << num[i];
    }
}