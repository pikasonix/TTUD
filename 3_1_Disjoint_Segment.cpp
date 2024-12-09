#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
pair<int,int> a[maxn];
// sort the segments by second element of pairs
bool cmp (pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}
void input() {
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i].first >> a[i].second;
}
void solve() {
    int res = 0;        // result
    int last = -1;      // the end point of last chosen segment
    sort(a+1, a+n+1, cmp);
    for (int i=1; i<=n; i++)
        if(a[i].first > last) {   // not overlap
            res ++;
            last = a[i].second;
        }
    cout << res << endl;
}

int main() {
    input();
    solve();
}
