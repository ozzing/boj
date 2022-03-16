#include <iostream>
#include <string>
using namespace std;

char alpha[3][10]={{'q','w','e','r','t','y','u','i','o','p'},{'a','s','d','f','g','h','j','k','l'},{'z','x','c','v','b','n','m'}};
pair<int,int> idx[25];

int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            int alp = (int)alpha[i][j];
            if(alp>=97)
                idx[alp-97]={i,j};
        }
    }

    char l, r;
    string str;
    cin >> l >> r;
    getchar();
    cin >> str;

    pair<int,int> left, right;
    left = idx[l-97]; right = idx[r-97];
    int x, y, cnt=0;
    for(int i=0;i<str.length();i++){
        int num = (int)str[i]-97;
        x = idx[num].first;
        y = idx[num].second;
        if((x==0||x==1)&&(y>=0&&y<5)||x==2&&(y>=0&&y<4)){
            cnt+=abs(x-left.first); cnt+=abs(y-left.second);
            left.first=x; left.second=y;
        }
        else{
            cnt+=abs(x-right.first); cnt+=abs(y-right.second);
            right.first=x; right.second=y;
        }
    }
    cout << cnt+str.length();
}