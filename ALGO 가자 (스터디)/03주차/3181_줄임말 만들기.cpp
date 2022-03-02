#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter);
vector<string> vec;

int main(){
    string word[10] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
    string str, ans="";
    getline(cin, str);
    istringstream ss(str);
    string stringBuffer;
    while (getline(ss, stringBuffer, ' ')){
        vec.push_back(stringBuffer);
    }
 
    for(int i=0;i<vec.size();i++){
        bool check=false;
        if(i!=0){
            for(int j=0;j<10;j++){
                if(!word[j].compare(vec[i])) check=true;
            }
        }
        if(!check){
            char c = vec[i][0] - 32;
            ans+=c;
        }
    }

    cout << ans;
}