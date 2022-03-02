#include <iostream>
#include <vector>
using namespace std;

vector<long long> road;
vector<long long> city;

int main(){
    long long n, tmp, sum=0;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> tmp;
        road.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        cin >> tmp;
        city.push_back(tmp);
    }

    long long min=1000000000;
    for(int i=0;i<n-1;i++){
        if(min>city[i]) min=city[i];
        sum+=min*road[i];
    }
    cout << sum;
}