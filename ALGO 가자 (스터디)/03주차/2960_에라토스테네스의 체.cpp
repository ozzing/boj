#include <iostream>
using namespace std;

int num[1000] = { 0, };

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (num[j] != 0) continue;
            num[j]++;
            k--;
            if (k == 0) {
                cout << j;
                return 0;
            }
        }
    }
}