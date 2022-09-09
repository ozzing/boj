#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];

int main(){
    int sum=0;
    for(int i=0;i<9;i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    int diff=sum-100;

    bool check=false;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(!check && i!=j && arr[i]+arr[j]==diff){
                arr[i]=-1; arr[j]=-1;
                check=true;
            }
        }
    }

    sort(arr, arr+9);

    for(int i=2;i<9;i++){
        cout << arr[i] << "\n";
    }
}