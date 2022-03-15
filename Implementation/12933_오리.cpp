#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
char quack[5] = {'q', 'u', 'a', 'c', 'k'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        for(int j=0;j<5;j++){
            if(str[i]==quack[j]){
                bool check=false;
                for(int v=0;v<vec.size();v++){
                    if((vec[v]==j-1&&j!=0) || (vec[v]==4&&j==0)) {
                        vec[v]=j;
                        check=true;
                        break;
                    }

                }
                if(!check) {
                    if(j==0) vec.push_back(j);
                    else {
                        cout << -1; return 0;
                    }
                }
            }
        }
    }

    sort(vec.begin(), vec.end());
    if(vec.size()){
        if(vec.front()==4&&vec.back()==4){
            cout << vec.size();
        }
        else cout << -1;
    } 
    else cout << -1;
}