#include <iostream>
using namespace std;

int s[10001];
int d[10001];
int temp[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }

    for(int j=0;j<k;j++){
        for(int i=1;i<=n;i++){
            temp[d[i]]=s[i];
        }
        for(int i=1;i<=n;i++) s[i]=temp[i];
    }

    for(int i=1;i<=n;i++){
        cout << s[i] << " ";
    }
}
