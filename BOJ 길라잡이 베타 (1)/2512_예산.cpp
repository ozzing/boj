#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> budget;
int n, m, sum, tmp;

void binary_search() {
    int start = 0;
    int end = budget[n-1];
    int res;

    while (start <= end) {
        sum = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < n; i++) {
            sum += min(budget[i], mid);
        }
        if (sum > m) {
            end = mid - 1;
        }
        else {
            res = mid;
            start = mid + 1;
        }
    }

    cout << res;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
        budget.push_back(tmp);
    }
    cin >> m;
    sort(budget.begin(), budget.end());

    binary_search();
}