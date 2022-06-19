#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 25
int n;
int stu[MAX*MAX];
int like[MAX*MAX][4];
int seat[MAX][MAX];

int dx[4]={-1, 0, 0, 1};
int dy[4]={0, -1, 1, 0};

struct ST{
    int x;
    int y;
    int cnt;
    int likes;
};

bool compare(ST A, ST B)
{
    if (A.likes >= B.likes){
        if (A.likes == B.likes){
            if (A.cnt >= B.cnt){
                if (A.cnt == B.cnt){
                    if (A.x <= B.x){
                        if (A.x == B.x){
                            if (A.y < B.y){
                                return true;
                            }
                            return false;
                        }
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void sit(){
    for(int s=0;s<n*n;s++){
        int likes, cnt;
        vector<ST> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                likes=0; cnt=0;
                if(seat[i][j]==0){
                    for(int d=0;d<4;d++){
                        int nx=i+dx[d];
                        int ny=j+dy[d];
                        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                        for(int k=0;k<4;k++){
                            if(seat[nx][ny]==like[stu[s]][k]) likes++;
                            else if(!seat[nx][ny]) cnt++;
                        }
                    }
                    vec.push_back({i, j, cnt, likes});
                }
            }
        }

        sort(vec.begin(), vec.end(), compare);
        int fx=vec[0].x;
        int fy=vec[0].y;
        seat[fx][fy]=stu[s];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0;i<n*n;i++){
        cin >> stu[i];
        for(int j=0;j<4;j++){
            cin >> like[stu[i]][j];
        }
    }

    sit();
    
    int total=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int s = seat[i][j];
            int likes=0;
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                for(int k=0;k<4;k++){
                    if(seat[nx][ny]==like[s][k]){
                        likes++;
                    }
                }
            }
            if(likes==0) total+=0;
            else if (likes==1) total+=1;
            else if (likes==2) total+=10;
            else if (likes==3) total+=100;
            else if (likes==4) total+=1000;
        }
    }
    cout << total;
}