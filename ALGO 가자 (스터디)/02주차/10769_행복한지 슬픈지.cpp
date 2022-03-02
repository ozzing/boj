#include <iostream>
#include <string>
using namespace std;

int main(){
    int pos=-3, happy=0, sad=0;
    string msg;
    getline(cin, msg);   
    while(1){
        pos = msg.find(":-)", pos+3);
        if(pos==string::npos) break;
        else happy++;
    }
    pos=-3;
    while(1){
        pos = msg.find(":-(", pos+3);
        if(pos==string::npos) break;
        else sad++;
    }
    if(!happy&&!sad) cout << "none";
    else if (happy==sad) cout << "unsure";
    else if (happy>sad) cout << "happy";
    else cout << "sad";
}