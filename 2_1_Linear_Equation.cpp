#include <bits/stdc++.h>
using namespace std;
long long f = 0;
long long t[1000];
int dem = 0;
int n, M;
int a[1000], x[1000];

void Try(int k){
        for(int v = 1; v <= (M-f-(t[n]-t[k]))/a[k]; v++){
            x[k] = v;
            f += a[k]*x[k];
            if(k == n)
                if(f == M) dem++;
            else Try(k+1);
            f -= a[k]*x[k];
        }

}
int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> M;
    for(int i = 1; i <= n; i++) cin >> a[i];
    t[1] = a[1];
    for(int i = 2; i <= n; i++) t[i] = t[i-1]+a[i];
    Try(1);
    cout << dem;
}
