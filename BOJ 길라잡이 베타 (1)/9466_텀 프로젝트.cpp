#include <iostream>
#include <cstring>
using namespace std;

int test, n;
int sel[100001] = { 0, };
int visited[100001] = { 0, };
int check[100001] = { 0, };
int sum = 0;

void dfs(int pre, int cur) {
    visited[cur] = visited[pre];

    int next = sel[cur];
    if (!visited[next]) {
        dfs(cur, next);
    }
    else if (!check[next]){
        for (int i = next; i != cur; i = sel[i]) {
            sum++;
        }
        sum++;
    }
    check[cur] = 1;
}

int main() {
    cin >> test;
    for (int t = 0; t < test; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> sel[i];
        }
        sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = i;
                dfs(i, i);
            }
        }
        cout << n - sum << endl;
        memset(visited, 0, sizeof(visited));
        memset(check, 0, sizeof(check));
    }
}