#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int i, int j) {return j<i;}

int main(){
    int n, tmp, val;
    cin >> n;
    vector<int> rope;
    for(int i=0;i<n;i++) {
        cin >> tmp;
        rope.push_back(tmp);
    }
    
    sort(rope.begin(), rope.end(), compare);
    
    val=rope[0];
    for(int i=2;i<=n;i++){
        if(rope[i-1]*i > val){
            val=rope[i-1]*i;
        }
    }
 
    cout << val;
}