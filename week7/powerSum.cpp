#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll x, int n){
    ll xPower = 1;
    for (int i = 1; i <= n; i++){
        xPower *= x;
    }
    return xPower;
}

void powerSum(int& cnt, ll X, int N, int j){
    if (X == 0) {
        cnt++;
        return;
    }
    if (X < 0){
        return;
    }

    for (int i = j + 1; power(i, N) <= X; i++){
        powerSum(cnt, X - power(i, N), N, i);
    }
}

int main() {
    ll X;
    int N;
    cin >> X >> N;
    int cnt = 0;
    powerSum(cnt, X, N, 0);
    cout << cnt << endl;
    return 0;
}
