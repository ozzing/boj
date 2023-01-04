#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 10001

struct edge{
    int vertex;
    int weight;
};

vector<edge> tree[MAX];
bool visited[MAX];
int answer=0;
int farthest=0;

void dfs(int x, int length){
    if(visited[x]) return;
    visited[x]=true;

    if(answer<length){
        answer=length;
        farthest=x;
    }

    for(int i=0;i<tree[x].size();i++){
        edge temp=tree[x][i];
        dfs(temp.vertex, length+temp.weight);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x, y, z;
    cin >> n;

    for(int i=0;i<n-1;i++){
        cin >> x >> y >> z;
        tree[x].push_back({y,z});
        tree[y].push_back({x,z});
    }

    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(farthest, 0);
    cout << answer;
}