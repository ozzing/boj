#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int map[100001];
int visited[100001];
int cnt[100001];

int main() {
    int n, k;
    cin >> n >> k;

    q.push(n);
    visited[n] = true;
    cnt[n] = 0;
    while (!q.empty()) {
        int pre = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int now = pre;
            if (i == 0) now -= 1;
            if (i == 1) now += 1;
            if (i == 2) now *= 2;

            if (now >= 0 && now <= 100000 && !visited[now]) {
                visited[now] = true;
                cnt[now] = cnt[pre] + 1;
                if (now != k) q.push(now);
            }
        }
    }

    cout << cnt[k];
}