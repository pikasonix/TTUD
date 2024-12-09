#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int a[N], S[N];
int n, L1, L2, ans;

void solve(){
    deque<int> d;// luu tru chi so cac ung cu vien j tham gia vao viec xac dinh cac bai toan con S(i)
    ans = 0;
    for(int i = 1; i <= n; i++){
        while(!d.empty() && d.front() < i - L2) d.pop_front();
        int j = i - L1;
        if(j >= 1){
            while(!d.empty() && S[d.back()] < S[j]) d.pop_back();
            d.push_back(j);
        }
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);
        ans = max(ans,S[i]);
    }
    cout << ans;
}
void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
int main(){
	input();
	solve();
}
