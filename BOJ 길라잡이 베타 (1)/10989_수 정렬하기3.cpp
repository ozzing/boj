#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, temp;
    int arr[10001]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> temp;
        arr[temp]++;
    }

    for(int i=0;i<10001;i++){
        for(int j=0;j<arr[i];j++){
            if(arr[i]!=0){
                cout << i <<'\n';            
            }
        }
    }
}