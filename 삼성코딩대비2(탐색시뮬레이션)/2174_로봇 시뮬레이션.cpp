#include <iostream>
using namespace std;
   
int a, b, n, m, x, y;
char cmd, d;
int map[101][101] = {0,};

struct node{
    int x;
    int y;
    int dir;
};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1 ,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    cin >> n >> m;
    node* robot = new node[n+1];
    for(int i=1;i<=n;i++){
        cin >> robot[i].x >> robot[i].y >> d;
        if(d=='N') robot[i].dir=0;
        else if(d=='E') robot[i].dir=1;
        else if(d=='S') robot[i].dir=2;
        else robot[i].dir=3;
        map[robot[i].x][robot[i].y]=i;
    }
    for(int i=0;i<m;i++){
        cin >> x >> cmd >> y;
        for(int t=0;t<y;t++){
            if(cmd=='L')
                robot[x].dir=(robot[x].dir-1+4)%4;
            else if(cmd=='R')
                robot[x].dir=(robot[x].dir+1+4)%4;
            else {
                int d=robot[x].dir;
                map[robot[x].x][robot[x].y]=0;
                robot[x].x=robot[x].x+dx[d];
                robot[x].y=robot[x].y+dy[d];
                if(robot[x].x<=0 || robot[x].x>a || robot[x].y<=0 || robot[x].y>b){
                    cout << "Robot " << x << " crashes into the wall\n";
                    return 0;
                }
                if(map[robot[x].x][robot[x].y]!=0){
                    cout << "Robot " << x << " crashes into robot " << map[robot[x].x][robot[x].y] << "\n";
                    return 0;
                }
                map[robot[x].x][robot[x].y]=x;
            }
        }
    }
    cout << "OK\n";
}