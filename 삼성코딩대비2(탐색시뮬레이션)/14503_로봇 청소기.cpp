#include <iostream>
using namespace std;

int map[51][51];
int n, m;
int cnt=0;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void clean(int x, int y){
    map[x][y]=2;
    cnt++;
}

void search(int x, int y, int dir){
    if(!map[x][y]) clean(x, y);
    for(int i=0;i<4;i++){
        int nd=(dir+3-i)%4;
        int nx=x+dx[nd];
        int ny=y+dy[nd];

        if(map[nx][ny] || nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        search(nx, ny, nd);
    }
    int nd = (dir + 2) % 4;
	int nx = x + dx[nd];
	int ny = y + dy[nd];

	if(map[nx][ny] != 1)
    	search(nx, ny, dir);    
	else{
    	cout << cnt;
		exit(0);
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }

    search(r, c, d);
}