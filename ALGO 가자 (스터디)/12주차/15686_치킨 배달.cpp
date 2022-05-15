#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int arr[50][50];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<pair<int,int>> chicken;
    vector<int> permu;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2) chicken.push_back({i,j});
        }
    }
    for(int i=0;i<chicken.size()-m;i++) permu.push_back(0);
    for(int i=0;i<m;i++) permu.push_back(1);

    int mindis=0xffff;
    do{
        int dis=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    int mind=0xffff;
                    for(int k=0;k<permu.size();k++){
                        if(permu[k]==1){
                            mind=min(mind, abs(i-chicken[k].first)+abs(j-chicken[k].second));
                        }
                    }
                    dis+=mind;
                }
            }
        }        
        mindis=min(mindis, dis);

    } while(next_permutation(permu.begin(), permu.end()));

    cout << mindis;
}