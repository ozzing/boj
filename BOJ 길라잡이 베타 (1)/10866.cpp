#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    deque <int> qu;
    int n, tmp;
    string str;
    cin >> n;

    for(int i=0;i<n;i++){
        cin>>str;
        if(str.compare("push_front")==0){
            scanf("%d", &tmp);
            qu.push_front(tmp);
        }
        if(str.compare("push_back")==0){
            scanf("%d", &tmp);
            qu.push_back(tmp);
        }
        if(str.compare("pop_front")==0){
            if(!qu.empty()){
                cout<< qu.front()<<endl;
                qu.pop_front();
            }
            else{
                cout<<"-1"<<endl;
            }
        }
        if(str.compare("pop_back")==0){
            if(!qu.empty()){
                cout<< qu.back()<<endl;
                qu.pop_back();
            }
            else{
                cout<<"-1"<<endl;
            }
        }
        if(str.compare("size")==0){
            cout <<qu.size() << endl;
        }
        if(str.compare("empty")==0){
            if(!qu.empty()){
                cout<< "0" <<endl;
            }
            else{
                cout<<"1"<<endl;
            }
        }
        if(str.compare("front")==0){
            if(!qu.empty()){
                cout<< qu.front() <<endl;
            }
            else{
                cout<<"-1"<<endl;
            }
        }
        if(str.compare("back")==0){
            if(!qu.empty()){
                cout<< qu.back() <<endl;
            }
            else{
                cout<<"-1"<<endl;
            }
        }
    }
    return 0;

}