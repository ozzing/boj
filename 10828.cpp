#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack <int> st;
    int n, tmp;
    string str;
    cin >> n;

    for(int i=0;i<n;i++){
        cin>>str;
        if(str.compare("push")==0){
            scanf("%d", &tmp);
            st.push(tmp);
        }
        if(str.compare("pop")==0){
            if(!st.empty()){
                cout<< st.top()<<endl;
                st.pop();
            }
            else{
                cout<<"-1"<<endl;
            }
        }
        if(str.compare("size")==0){
            cout <<st.size() << endl;
        }
        if(str.compare("empty")==0){
            if(!st.empty()){
                cout<< "0" <<endl;
            }
            else{
                cout<<"1"<<endl;
            }
        }
        if(str.compare("top")==0){
            if(!st.empty()){
                cout<< st.top() <<endl;
            }
            else{
                cout<<"-1"<<endl;
            }
        }
    }
    return 0;
}