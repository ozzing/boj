#include <iostream>
using namespace std;

int sw[101];
int n, m;

void boy(int num){
    int tmp=num;
    while(tmp<=n){
        sw[tmp]=!sw[tmp];
        tmp+=num;
    }
}

void girl(int num){
    int start=num;
    int end=num;
    while(start>=1&&end<=n){
        if(start==num){
            sw[start]=!sw[start];
        }
        else if(sw[start]==sw[end]){
            sw[start]=!sw[start];
            sw[end]=!sw[end];
        }
        else break;        
        start--; end++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int gen, num;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> sw[i];
    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> gen >> num;
        if(gen==1) boy(num);
        else if(gen==2) girl(num);
    }

    for(int i=1;i<=n;i++) {
        cout << sw[i] << " ";
        if(i%20==0) cout << "\n";
    }
}