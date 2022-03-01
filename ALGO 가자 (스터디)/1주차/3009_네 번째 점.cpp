#include <iostream>
#include <vector>
using namespace std;

int main(){
    int x, y;
    vector<pair<int, int>> point;
    
    for(int i=0;i<3;i++){
        cin >> x >> y;
        point.push_back({x, y});
    }
    if(point[2].first==point[0].first){
        cout << point[1].first << " ";
    }
    else if(point[2].first==point[1].first){
        cout << point[0].first << " ";
    }
    else{
        cout << point[2].first << " ";      
    }

    if(point[2].second==point[0].second){
        cout << point[1].second;
    }
    else if(point[2].second==point[1].second){
        cout << point[0].second;
    }
    else{
        cout << point[2].second;      
    }
}