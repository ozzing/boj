#include <iostream>
#include <algorithm>
using namespace std;

long long arr[500000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, tmp;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);

    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp;
        cout << binary_search(arr, arr+n, tmp) << " ";
    }
}