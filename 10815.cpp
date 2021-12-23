#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, tmp, m, res;
vector <int> arrN, arrM;


int binary_search(int begin, int end, int key){
    while(begin<=end){
        int mid=(begin+end)/2;
        if(arrN[mid]==key){
            return 1;
        }
        else if(arrN[mid]<key){
            begin=mid+1;
        }
        else if(arrN[mid]>key){
            end=mid-1;
       }
    }
    return 0;
}

int main () {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> tmp;
        arrN.push_back(tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp;
        arrM.push_back(tmp);
    }

    sort(arrN.begin(), arrN.end());

    for(int i=0;i<m;i++){
        res=binary_search(0, n-1, arrM[i]);
        printf("%d ", res);
    }
}