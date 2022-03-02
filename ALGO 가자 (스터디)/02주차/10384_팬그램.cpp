#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int alpha[26] = {0,};
int mini=10;

int main(){
    string str;
    int n, cs=1;
    cin >> n;
    getchar();
    for(int t=0;t<n;t++){
        getline(cin, str);
        for(int x=0;x<str.size();x++){
            if(str[x]>=65&&str[x]<=90 || str[x]>=97&&str[x]<=122){
                str[x]=tolower(str[x]);
                alpha[str[x]-97]++;
            }
        }
        for(int i=0;i<26;i++){
            if(alpha[i]<mini) mini=alpha[i];
            alpha[i]=0;
        }

        if(mini==0) printf("Case %d: Not a pangram\n", cs++);
        if(mini==1) printf("Case %d: Pangram!\n", cs++);
        if(mini==2) printf("Case %d: Double pangram!!\n", cs++);
        if(mini==3) printf("Case %d: Triple pangram!!!\n", cs++);
        mini=10;
    }
}