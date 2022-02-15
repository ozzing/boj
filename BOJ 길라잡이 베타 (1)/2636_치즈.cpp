#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue<pair<int, int>> q;
vector<int> vec;
int x, y, z, w;
int n, m, k;
int cnt=0;
int map[100][100];
bool visited[100][100];

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void dfs(int x, int y){
    visited[x][y]=true;
    cnt++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx >= 0 && nx < n && ny>=0 && ny < m && map[nx][ny] == 0 && !visited[nx][ny]) {
			dfs(nx, ny);
		}
    }
}

int main(){
    cin >> m >> n >> k;
    for(int c=0;c<k;c++){
        cin >> x >> y >> z >> w;
        for(int i=x;i<z;i++){
            for(int j=y;j<w;j++){
                map[i][j]=1;
                visited[i][j]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0&&!visited[i][j]){
                cnt=0;
                dfs(i, j);
                vec.push_back(cnt);
            }
        }
    }

    sort(vec.begin(), vec.end());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
}