#include <iostream>
#include <algorithm>
using namespace std;



int main(){
    int a;
    scanf("%d", &a);
    int *arr = (int*)malloc(sizeof(int)*a);
    for(int i=0;i<a;i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+a);

    int b, key, res;
    scanf("%d", &b);
    for(int i=0;i<b;i++){
        scanf("%d", &key);
        res=0;
        // binary search
        int start=0, end=a-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]==key){
                res=1;
                break;
            } 
            else if (arr[mid]>key){
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        printf("%d\n", res);
    }

}