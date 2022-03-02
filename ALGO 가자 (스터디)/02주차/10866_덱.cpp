#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> dq;

int main(){
    string str;
    int n, num;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        if(!str.compare("push_back")) {
            cin >> num;
            dq.push_back(num);
        }
        if(!str.compare("push_front")){ 
            cin >> num;
            dq.push_front(num);
        }
        if(!str.compare("pop_front")) {
            if(dq.empty()) cout << "-1\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        if(!str.compare("pop_back")) {
            if(dq.empty()) cout << "-1\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        if(!str.compare("size")) cout << dq.size() << "\n";
        if(!str.compare("empty")) {
            if(dq.empty()) cout << "1\n";
            else cout << "0\n";
        }
        if(!str.compare("front")) {
            if(dq.empty()) cout << "-1\n";
            else cout << dq.front() << "\n";
        }
        if(!str.compare("back")) {
            if(dq.empty()) cout << "-1\n";
            else cout << dq.back() << "\n";
        }
    }
}