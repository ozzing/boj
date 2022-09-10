#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int> vec;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        vec.push_back(arr[i]);
    }
    
    bool check=false;
    do {
        if(check==true){
            for(int i=0;i<n;i++){
                cout << vec[i] << " ";
            }
            return 0;
        }
        check=true;
        for(int i=0;i<n;i++){
            if(arr[i]!=vec[i]) {
                check=false;
                break;
            }
        }
    } while(prev_permutation(vec.begin(), vec.end()));
    
    cout << -1;
}