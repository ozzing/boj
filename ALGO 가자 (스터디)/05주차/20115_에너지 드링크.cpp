#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long double> drink;

int main(){
    int n, x;
    long double sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        drink.push_back(x);
    }
    sort(drink.begin(), drink.end());
    sum+=drink[drink.size()-1];
    for(int i=0;i<n-1;i++){
        sum+=(long double)(drink[i]/2);
    }
    cout << sum;
}