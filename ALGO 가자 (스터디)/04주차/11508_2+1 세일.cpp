#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> dairy;

int main(){
    int n, c;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c;
        dairy.push_back(c);
    }
    sort(dairy.begin(), dairy.end(), greater<int>());

    int sum=0;
    for(int i=0;i<n;i++){
        if((i+1)%3!=0) sum+=dairy[i];
    }

    cout << sum;
}