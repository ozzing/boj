#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 2001

int n, m;
bool visited[MAX];

void solve(int s, int num, vector<vector<int>> &vec){
    if(num==5) {cout << 1; exit(0);}

    for(int i=0;i<vec[s].size();i++){
        int next=vec[s][i];
        if(!visited[next]){     
            visited[next]=true;
            solve(next, num+1, vec);
            visited[next]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<vector<int>> vec(n);

    int a, b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        memset(visited, false, sizeof(visited));
        visited[i]=true;
        solve(i, 1, vec);
    }
    
    cout << 0;
}