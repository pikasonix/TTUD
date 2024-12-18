#include<bits/stdc++.h>
using namespace std;
int const MOD = 1e9+7;
int n;
int k;
int res;
int a[1000007];
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        a[k]++;
        res = (res +(a[k]-1)) % MOD;
    }
    cout << res;
}
