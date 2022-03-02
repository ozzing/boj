#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, tmp;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        card.push_back(tmp);
    } 
    sort(card.begin(), card.end(), greater<int>());

    int sum=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int tmp = card[i]+card[j]+card[k];
                if(tmp<=m && sum<tmp) sum=tmp;
            }
        }
    }
    cout << sum;
}