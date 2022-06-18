#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> crane;
vector<int> box;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        crane.push_back(tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp;
        box.push_back(tmp);
    }
    
    sort(crane.begin(), crane.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());
    if(crane[0] < box[0]) {cout << -1; return 0;}

    int cnt=0;
    while(box.size()>0){
        for(int i=0;i<crane.size();i++){
            for(int j=0;j<box.size();j++){
                if(box[j]!=0 && box[j]<=crane[i]) {
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
        cnt++;
    }

    cout << cnt;
}