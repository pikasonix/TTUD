/* Warehouse: Cho N nhà kho (a:lượng hàng, t:thời gian tiêu tốn)
	tìm đường cho tổng hàng a lớn nhất (điều kiện: tổng thời gian < T, khoảng cách |i-j|<D) */

#include <bits/stdc++.h>
using namespace std;

int n, S[1007][102], T, D, a[1007], t[1007], result;
// S[][]: lượng hàng tối đa tại trạm i, tổng thời gian k
// a[]: lượng hàng mỗi trạm, t[]: thời gian tốn tại mỗi trạm

// Quy hoạch động: S[i][k] = max(S[i][k], S[j][k−t[i]] + a[i]) (điều kiện: tổng thời gian < T, khoảng cách |i-j|<D) 
void solve(){
    for(int i=1; i<=n; i++){
        for(int k = t[i]; k<=T; k++){ 
            for(int j = max(0,i-D); j <=i-1; j++){ // duyệt các trạm thoả mãn (i-D <= j <= i) và (k nằm trong T cho phép)
                S[i][k] = max(S[i][k], S[j][k-t[i]] + a[i]);
            }
            result = max(result, S[i][k]);
        }
    }
    cout << result;
}

void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    
    cin >> n >> T >> D;
    for(int i = 1 ; i <= n; i ++) cin >> a[i];
    for(int i = 1 ; i <= n; i ++) cin >> t[i];
}

int main(){
    input();
    solve();
}

