#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

void init(){
    int i=1;
    while((i*(i+1))/2<1000){
        vec.push_back((i*(i+1))/2);
        i++;
    }
}

int main(){
    init();
    int t, k;
    cin >> t;
    for(int x=0;x<t;x++){
        bool check=false;
        cin >> k;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec.size();j++){
                for(int l=0;l<vec.size();l++){
                    if(vec[i]+vec[j]+vec[l]==k){
                        check=true;
                        break;    
                    }
                }
            }
        }
        if(check) cout << "1\n";
        else cout << "0\n";
    }
}