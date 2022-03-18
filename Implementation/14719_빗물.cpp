#include <iostream>
using namespace std;

int block[501];

int main(){
    int h, w;  
    cin >> h >> w;
    for(int i=0;i<w;i++){
        cin >> block[i];
    } 

    int sum=0;
    for(int i=1;i<w-1;i++){
        int left=0, right=0;
        for(int j=0;j<i;j++) left=max(left, block[j]);
        for(int j=w-1;j>i;j--) right=max(right, block[j]);
        sum+= max(0, min(left, right) - block[i]);
    }
    cout << sum;
}