#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> road;
vector<long long> city;

int main(){
    long long mini=1000000000;
    long long n, temp, sum=0;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> temp;
        road.push_back(temp);
    }
    for(int i=0;i<n;i++){
        cin >> temp;
        city.push_back(temp);
    }

    for(int i=0;i<n-1;i++){
        if(city[i]<mini) mini=city[i];
        sum+=mini*road[i];
    }

    cout << sum;
}