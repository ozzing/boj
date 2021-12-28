#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    queue<int> qu;
    for(int i=0;i<n;i++){
        qu.push(i+1);
    }
    cout<<"<";

    while(qu.size()>1){
        for(int i=0;i<k-1;i++){
            qu.push(qu.front());
            qu.pop();
        }
        cout<< qu.front() <<", ";
        qu.pop();
    }

    cout<< qu.front() << ">";
}


/* 시간초과
int main(){
    int n, k, in;
    vector<int> arr;
    queue<int> qu;
    cin >> n >> k;
    for(int i=0;i<=n;i++){
        arr.push_back(i);
    }

    in=k;
    while(qu.size()<n){
        qu.push(arr[in]);
        arr[in]=0;

        for(int i=0;i<k;i++){
            in++;
            while(arr[in]==0) in++;
            if(in>n) in-=n;
        }
    }

    int size=qu.size();
    printf("<");
    for(int i=0;i<size-1;i++){
        printf("%d, ", qu.front());
        qu.pop();
    }
    printf("%d>", qu.front());
}
*/