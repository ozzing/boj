#include <iostream>
using namespace std;

int main(){
    int n, a, b, ascore=0, bscore=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(a>b) ascore++;
        else if(b>a) bscore++;
    }   
    cout << ascore << " " << bscore;
}