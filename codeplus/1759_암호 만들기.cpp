#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<char> vec;
int l, c;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

bool check(string str){
    int vow=0, con=0;
    for(int i=0;i<str.length();i++){
        bool flag=false;
        for(int v=0;v<5;v++){
            if(str[i]==vowel[v]) flag=true;
        }
        if(flag) vow++;
        else con++;
    }

    if(vow>=1 && con>=2) return true;
    else return false;
}

void solve(int loc, int dep, string str){
    if(dep==l && check(str)){
        cout << str << '\n';
        return;
    }

    for(int i=loc+1;i<c;i++){
        solve(i, dep+1, str+vec[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> l >> c;

    char tmp;
    for(int i=0;i<c;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    for(int i=0;i<=c-l;i++){
        string str="";
        str.append(1, vec[i]);
        solve(i, 1, str);
    }
}