#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char arr[500001];

    char c;
    int n, k, tmp, cnt, temp=1;
    cin >> n >> k;

    cnt=k;
    cin >> arr[0];
    for(int i=1;i<n;i++){
        cin >> c;
        while(cnt && temp && arr[temp-1]<c){
            temp--;
            cnt--;
        }
        arr[temp++]=c;
    }

    for(int i=0;i<n-k;i++){
        cout << arr[i];
    }
}