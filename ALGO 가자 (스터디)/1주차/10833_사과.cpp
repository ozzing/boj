#include <iostream>
using namespace std;

int main(){
    int n, stu, app;
    int sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> stu >> app;
        sum+=(app%stu);
    }
    cout << sum;
}