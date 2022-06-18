#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool visited[17][51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string t;
    int n, tlen;
    cin >> t;
    cin >> n;
    tlen=t.length();

    vector<pair<int,string>> vec(n);
    vector<string> check(n);
    for(int i=0;i<n;i++){
        cin >> vec[i].first >> vec[i].second;
    }

    int mn=0xffffff;
    for(int i=1;i<=n;i++){
        vector<int> tmp;
        for(int t=0;t<i;t++) tmp.push_back(1);
        for(int t=i;t<n;t++) tmp.push_back(0);
        sort(tmp.begin(), tmp.end());

        do{
            memset(visited, false, sizeof(visited));
            vector<int> find(tlen);
            int price=0;
            for(int v=0;v<n;v++){
                if(tmp[v]){
                    price+=vec[v].first;
                    for(int j=0;j<tlen;j++){
                        for(int s=0;s<vec[v].second.length();s++){
                            if(!find[j] && !visited[v][s] && vec[v].second[s]==t[j]){
                                find[j]=1;
                                visited[v][s]=true;
                            }
                        }
                    }
                }
            }
            bool tf = true;
            for(int t=0;t<tlen;t++){
                if(find[t]!=1) tf=false;
            }
            if(tf) mn=min(mn, price);
        } while(next_permutation(tmp.begin(), tmp.end()));
    }    

    if(mn!=0xffffff) cout << mn;
    else cout << -1;
}