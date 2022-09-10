#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    queue <int> qu;
    int n, tmp;
    string str;
    cin >> n;

    for(int i=0;i<n;i++){
        cin>>str;
        if(str.compare("push")==0){
            scanf("%d", &tmp);
            qu.push(tmp);
        }
        if(str.compare("pop")==0){
            if(!qu.empty()){
                cout<< qu.front()<<"\n";
                qu.pop();
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
        if(str.compare("size")==0){
            cout <<qu.size() << "\n";
        }
        if(str.compare("empty")==0){
            if(!qu.empty()){
                cout<< "0" <<"\n";
            }
            else{
                cout<<"1"<<"\n";
            }
        }
        if(str.compare("front")==0){
            if(!qu.empty()){
                cout<< qu.front() <<"\n";
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
        if(str.compare("back")==0){
            if(!qu.empty()){
                cout<< qu.back() <<"\n";
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
    }
    return 0;
}