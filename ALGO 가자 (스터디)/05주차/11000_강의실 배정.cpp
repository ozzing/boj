#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, s, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        vec.push_back({ t, s });
    }
    sort(vec.begin(), vec.end(), cmp);

    int end = vec[0].first;
    q.push(end);
    for(int i=1;i<n;i++){
        t = vec[i].first;
        s = vec[i].second;

        if (q.top() > s) {
            q.push(t);
        }
        else {
            q.pop();
            q.push(t);
        }
    }
    cout << q.size();
}