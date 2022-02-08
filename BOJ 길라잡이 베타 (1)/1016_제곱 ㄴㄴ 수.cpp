#include <iostream>
#include <cmath>
using namespace std;

long long arr[1000001];

int main() {
    int count = 0;
    long long min, max;
    cin >> min >> max;

    for (long long i = 2; i <= sqrt(max); i++) {
        long long n = min / (i * i);
        if (min % (i * i)) n++;

        for(long long j=n*i*i; j<=max; j+=i*i) {
            arr[j - min] = 1;
        }
    }

    for (long long i = 0; i <= max - min; i++) {
          if (arr[i] == 0) count++;
    }
    cout << count;
}