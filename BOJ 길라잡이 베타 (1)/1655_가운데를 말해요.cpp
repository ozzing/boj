#include <iostream>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int> low;
priority_queue<int, vector<int>, greater<int>> high;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(low.size()<=high.size()){
            low.push(tmp);
        }
        else{
            high.push(tmp);
        }
        if(low.size()&&high.size()&&low.top()>high.top()){
            int ltemp = low.top();
            int htemp = high.top();
            low.pop();
            high.pop();
            low.push(htemp);
            high.push(ltemp);
        }
        cout << low.top() << "\n";
    }
}