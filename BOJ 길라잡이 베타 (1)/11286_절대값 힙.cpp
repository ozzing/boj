#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct cmp{
    bool operator()(int x, int y){
        if(abs(x)==abs(y)){
            return x>y;
        }
        else{
            return abs(x) > abs(y);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    priority_queue<int, vector<int>, cmp> pq;
    int n, x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x == 0){
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else cout << 0 << "\n";
        }
        else{
            pq.push(x);
        }
    }
}