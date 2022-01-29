#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAX 2000000
long long a, b, sum;
bool check[MAX+1];
vector<int> prime;

void get_prime(){
    for (int i = 2; i * i < MAX; i++) {
        if (!check[i]){
            for (int j = i * i; j < MAX; j += i){
                check[j] = true;
            }
        }
    }

    for (int i = 2; i <= MAX; i++){
        if (!check[i]){
            prime.push_back(i);
        }
    }
}

int main(void){
    get_prime();
    int n;
    cin>> n;
    for(int t=0;t<n;t++) {
        bool check = false;
        cin >> a >> b;
        sum = a + b;

        if (sum <= 3) {
            check=false;
        }
        else if (sum % 2 == 0) {
            check=true;
        }
        else{
            sum -= 2;
            bool isprime = false;
            for (int i = 0; i < prime.size() && (long long)prime[i] * prime[i] <= sum; i++)
                if (sum % prime[i] == 0){
                    check=false;
                    isprime = true;
                    break;
                }
            if (!isprime) check=true;
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
}