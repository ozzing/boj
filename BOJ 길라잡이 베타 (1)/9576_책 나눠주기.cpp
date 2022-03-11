#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, m;
    cin >> t;
    for (int x = 0; x < t; x++) {
        pair<int, int> vec[1001];
        int visited[1001] = { 0, };

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> vec[i].second >> vec[i].first;
        }
        sort(vec, vec + m);
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = vec[i].second; j <= vec[i].first; j++) {
                if (!visited[j]) {
                    visited[j] = 1;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) { if (visited[i]) cnt++; }
        cout << cnt << "\n";
    }
}