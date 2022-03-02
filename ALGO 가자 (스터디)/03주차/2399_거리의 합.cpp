#include <iostream>
using namespace std;

long long p[10000];

int main(){
    long long n, sum=0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                sum+=abs(p[i]-p[j]);
            }
        }
    }
    
    cout << sum;
}