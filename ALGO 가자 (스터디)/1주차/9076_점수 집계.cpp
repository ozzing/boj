#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int score[5];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin >> score[j];
        }
        sort(score, score+5);
        if(score[3]-score[1]>=4){
            cout << "KIN\n"; 
        }
        else{
            int res=0;
            for(int i=1;i<4;i++) res += score[i];
            cout << res << "\n";
        }
        memset(score, 0, sizeof(score));
    }
}