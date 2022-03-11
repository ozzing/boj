#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
vector<pair<int, int>> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, s, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        vec.push_back({ s, t });
    }
    sort(vec.begin(), vec.end(), less<pair<int,int>>());

    int end = vec[0].second;
    q.push(end);
    for(int i=1;i<n;i++){
        s = vec[i].first;
        t = vec[i].second;

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