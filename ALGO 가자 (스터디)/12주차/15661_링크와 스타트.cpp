#include <iostream>
#include <cmath>
using namespace std;
int k;
bool visited[20];
int score[20][20];
int mini = 0xffff;

void dfs(int n){
    int start=0, link=0;
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(visited[i] && visited[j]){
                start+=score[i][j];
                start+=score[j][i];
            }
            else if (!visited[i] && !visited[j]){
                link+=score[i][j];
                link+=score[j][i];
            }
        }
    }
    if(abs(start-link)<mini){
        mini = abs(start-link);
    }

    for(int i=0;i<k;i++){
        if(!visited[i] && i>=n){
            visited[i] = true;
            dfs(i+1);
            visited[i] = false;
        }
    }    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k;
    for(int i=0;i<k;i++){
        for (int j=0;j<k;j++)
            cin>> score[i][j];
    }
    dfs(0);

    cout << mini;
}