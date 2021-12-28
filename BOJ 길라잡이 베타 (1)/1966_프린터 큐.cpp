#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int t, n, m, tmp, count;
    cin >> t;
    for(int i=0;i<t;i++){
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        count = 0;
        cin >> n >> m;
        for(int j=0;j<n;j++){
            cin >> tmp;
            q.push({tmp, j});
            pq.push(tmp);
        }

        while(!q.empty()){
            int val = q.front().first;
			int index = q.front().second;
			q.pop();

            if(pq.top()==val){
                pq.pop();
                count++;
                if(index == m){
                    printf("%d\n", count);
                    break;
                }
            }
            else{
                q.push({val, index});
            }
        }
    }
}