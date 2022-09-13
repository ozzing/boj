#include <iostream>
#include <queue>
using namespace std;

#define MAX 2001
int s;
int visited[MAX][MAX]={0,};

void bfs(){
    queue<pair<int,int>> q;
    q.push({1, 0});
    visited[1][0]=1;

    while(!q.empty()){
        int emo = q.front().first;
        int clip = q.front().second;
        q.pop();

        if(emo==s){
            cout << visited[emo][clip]-1;
            break;
        }

        if(emo>=0 && emo<=MAX){
            if(!visited[emo][emo]) {
                q.push({emo, emo});
                visited[emo][emo]=visited[emo][clip]+1;
            }
            if(emo+clip<=s && !visited[emo+clip][clip]){
                q.push({emo+clip, clip});
                visited[emo+clip][clip]=visited[emo][clip]+1;
            }
            if(emo>0 && !visited[emo-1][clip]){
                q.push({emo-1, clip});
                visited[emo-1][clip]=visited[emo][clip]+1;
            }
        }
    }

}

int main(){
    cin >> s;
    bfs();
}