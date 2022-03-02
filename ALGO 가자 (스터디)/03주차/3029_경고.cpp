#include <iostream>
using namespace std;

int main(){
    int start, end, diff;
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    start=h*3600+m*60+s;
    scanf("%d:%d:%d", &h, &m, &s);
    end=h*3600+m*60+s;
    if(end-start<=0) end+=24*3600;

    diff=end-start;
    printf("%02d:%02d:%02d", diff/3600, diff%3600/60, diff%60);
}