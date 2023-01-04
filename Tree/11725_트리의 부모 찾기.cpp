#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

vector<int> tree[MAX];
int parent[MAX];
bool visited[MAX];
int n, a, b;

void dfs(int x){
    for(int i=0;i<tree[x].size();i++){
        int cand=tree[x][i];
        if(!visited[cand]){
            parent[cand]=x;
            visited[cand]=true;
            dfs(cand);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    visited[1]=true;
    dfs(1);

    for(int i=2;i<=n;i++){
        cout << parent[i] << "\n";
    }
}