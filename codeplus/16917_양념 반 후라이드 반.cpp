#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int pivot = min(x, y);
    int whole = x*a + y*b;
    int half = (x-pivot)*a + (y-pivot)*b + 2*pivot*c;
    int extra = 2*max(x, y)*c;

    cout << min(extra, min(whole, half));
}