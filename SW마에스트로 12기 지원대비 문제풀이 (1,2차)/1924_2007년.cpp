#include <iostream>
#include <string>
using namespace std;

string week[7]= { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int x, y, days=0;
    cin >> x >> y;
    for(int i=0;i<x-1;i++){
        days+=month[i];
    }
    days+=y;
    days%=7;
    cout << week[days];
}