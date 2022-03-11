#include <iostream>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    int n, tmp, sum=0;
    cin >> n;
    if(n==0) {
        cout << 0;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin >> tmp;
        pq.push(tmp);
    }
    
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
        sum+=a+b;
    }
    cout << sum;
}