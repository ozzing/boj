#include <iostream>
#include <vector>
using namespace std;

int map[21][21];
vector<int> num;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int i=1;i<=n;i++) num.push_back(i);

    do{

    } while(next_permutation(num.begin(), num.end()));
}