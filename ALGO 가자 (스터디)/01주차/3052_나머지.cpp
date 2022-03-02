#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;

int main(){
    int tmp;
    for(int i=0;i<10;i++){
        cin >> tmp;
        num.push_back(tmp%42);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    cout << num.size();
}