#include <iostream>
using namespace std;

int cash;
int stock[15];

int bnp(){
    int total=cash;
    int cnt=0;
    for(int i=1;i<=14;i++){
        if(total>0){
            int tmp=cnt;
            cnt += total/stock[i];
            total -= (cnt-tmp)*stock[i];
        }
    }
    return total + cnt * stock[14];
}

int timing(){
    int total=cash;
    int cnt=0;
    int up=0, down=0;
    for(int i=2;i<=14;i++){
        if(stock[i-1]==stock[i]){
            up=0;
            down=0;
            continue;
        }
        else if(stock[i-1]<stock[i]){
            up++;
            down=0;
            if(up>=3){
                total += cnt*stock[i];
                cnt = 0;
            }
        }
        else if(stock[i-1]>stock[i]){
            down++;
            up=0;
            if(down>=3){
                int tmp=cnt;
                cnt += total/stock[i];
                total -= (cnt-tmp)*stock[i];
            }
        }
    }
    return total + cnt * stock[14];    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> cash;
    for(int i=1;i<=14;i++){
        cin >> stock[i];
    }
    
    int jh=bnp();
    int sm=timing();

    if(jh>sm) cout << "BNP\n";
    else if(jh<sm) cout << "TIMING\n";
    else cout << "SAMESAME\n";
}