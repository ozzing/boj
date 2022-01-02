#include <iostream>
#include <vector>
using namespace std;

int get_gcd(int a, int b){
    if(a % b) return get_gcd(b, a % b);
    return b; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, tmp, gcd=0;
    vector<int> tree;
    cin >> n;
    tree.resize(n);
    for(int i=0;i<n;i++){
        cin >> tree[i];
        if(i) gcd = get_gcd(gcd, tree[i] - tree[i-1]);
    }

    int res = (tree[n-1] - tree[0])/gcd - n + 1;
    cout << res;
}