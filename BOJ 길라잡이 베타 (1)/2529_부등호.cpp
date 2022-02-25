#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> num;
vector<char> arr;
vector<int> temp;
vector<string> ans;
int visited[10] = { 0, };
int k;
char c;

bool check() {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == '<') {
            if (temp[i] > temp[i + 1]) {
                return false;
            }
        }
        else if (arr[i] == '>') {
            if (temp[i] < temp[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int depth) {
    if (depth == k + 1) {
        if (check()) {
            string a = "";
            for (int i = 0; i < temp.size(); i++) {
                a += to_string(temp[i]);
            }
            ans.push_back(a);
        }
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            temp.push_back(i);
            visited[i] = 1;
            dfs(depth + 1);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> c;
        arr.push_back(c);
    }
    for (int i = 0; i < 10; i++) num.push_back(i);

    dfs(0);

    cout << ans[ans.size() - 1] << "\n";
    cout << ans[0] << "\n";
}