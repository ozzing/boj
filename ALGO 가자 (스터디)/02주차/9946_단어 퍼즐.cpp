#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int cs=1;
    string bf, aft;
    while(1){
        cin >> bf >> aft;
        if(!bf.compare("END") && !aft.compare("END")) break;
        sort(bf.begin(), bf.end());
        sort(aft.begin(), aft.end());
        if(!bf.compare(aft)) printf("Case %d: same\n", cs++);
        else printf("Case %d: different\n", cs++);
    }
}