#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int day=1;
    int a, b, v;
    cin >> a >> b >> v;
    if(v>a){
        day += (v-a)/(a-b);
    }
    if((v-a)%(a-b)!=0) day++;

    cout<< day;
}