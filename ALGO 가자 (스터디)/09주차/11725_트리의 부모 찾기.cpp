#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

vector<int> node[MAX];
int parent[MAX];
bool visited[MAX];
int n;

void dfs(int point){
    for(int i=0;i<node[point].size();i++){
        int tmp = node[point][i];
        if(!visited[tmp]){
            parent[tmp]=point;
            visited[tmp]=true;
            dfs(tmp);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    visited[1]=true;
    dfs(1);

    for(int i=2;i<=n;i++){
        cout << parent[i] << "\n";
    }
}