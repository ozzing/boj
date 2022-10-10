#include <iostream>
using namespace std;

int main(){
    int e, s, m;
    cin >> e >> s >> m;

    long long pivot=s;
    while(1){
        if((pivot-e)%15==0 && (pivot-m)%19==0){
            cout << pivot;
            break;
        }
        pivot+=28;
    }
}