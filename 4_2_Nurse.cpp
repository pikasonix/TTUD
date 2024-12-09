#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 2, MOD = 1e9 + 7;
int n, k1, k2, f[N][2], res;

void inp(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k1 >> k2;
}

void proc(){
    f[0][0] = f[0][1] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = k1; j <= k2; j ++) {
            if(i - j < 0) break;
            f[i][1] += f[i - j][0];
            f[i][1] %= MOD;
        }
        f[i][0] = f[i-1][1];
    }
    res = (f[n][0] + f[n][1]) % MOD;
    cout << res << "\n";
}

int main(){
    inp();
    proc();
}
