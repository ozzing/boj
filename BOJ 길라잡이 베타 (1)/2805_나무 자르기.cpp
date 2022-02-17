#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree;

int main() {
    int n, m, tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        tree.push_back(tmp);
    }
    sort(tree.begin(), tree.end());

    int start = 0;
    int end = tree[n - 1];
    int res=0;

    while (start <= end) {
        long long int sum = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < n; i++) {
            int cut = tree[i] - mid;
            if (cut > 0) sum += cut;
        }
        if (sum >= m) {
            res = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << res;
}