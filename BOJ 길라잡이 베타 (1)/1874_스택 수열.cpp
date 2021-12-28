#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int n, tmp, val=1;
    queue<char> res;
    stack<int> base;
    cin >>n;
    for(int i=0;i<n;i++){
        cin>> tmp;
        if(val<=tmp){
            while(val<=tmp){
                base.push(val++);
                res.push('+');
            }
            base.pop();
            res.push('-');
        }
        else{
            if(!base.empty() && tmp==base.top()){
                base.pop();
                res.push('-');
            }
        }
    }
    if(base.empty()){        
        int size= res.size();
        for(int x=0;x<size;x++) {
            printf("%c\n", res.front());
            res.pop();
        }
    }
    else{
        printf("NO");
    }
}