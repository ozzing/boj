#include <iostream>
#include <cstring>
using namespace std;

unsigned int dp[21][2] = { 0, };
pair<int, int> jump[21];

int main() {
    int n, k;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> jump[i].first >> jump[i].second;
    }
    cin >> k;

    memset(dp, 5001, sizeof(dp));
    dp[1][0] = 0;  dp[1][1] = 0;
    for (int i = 1; i < n; i++) {
        if (i + 1 <= n) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + jump[i].first);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + jump[i].first);
        }
        if (i + 2 <= n) {
            dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + jump[i].second);
            dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + jump[i].second);
        }
        if (i + 3 <= n) {
            dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + k);
        }
    }
    cout << min(dp[n][0], dp[n][1]);
}