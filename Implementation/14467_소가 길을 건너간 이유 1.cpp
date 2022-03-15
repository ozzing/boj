#include <iostream>
using namespace std;

pair<int,int> cow[11];

int main(){
    int n, num, loc, sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num >> loc;
        if((cow[num].second!=loc && cow[num].first!=0) || cow[num].first==0){
            cow[num].first++;
            cow[num].second=loc;
         }
    }
    for(int i=1;i<=10;i++){
        if(cow[i].first>0){
            sum+=cow[i].first-1;
        }
    }
    cout << sum;
}