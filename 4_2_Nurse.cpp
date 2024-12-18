/* Nurse: lập lịch trong N ngày. Y tá có thể làm việc x ngày liên tiếp (K1 <= x <= K2). 
	Chỉ được nghỉ 1 ngày giữa 2 đợt.
	Tính số cách có thể lập lịch cho y tá  */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, k1, k2, S[1007][2], result;

/* Quy hoạch động: 
	S[i][0] = S[i-1][1] 							-> số cách lập lịch đến ngày i (i là ngày nghỉ)
	S[i][1] = tổng S[i-j][0] (với j chạy từ k1->k2) -> số cách lập lịch đến ngày i (i là ngày cuối của chuỗi)
	-> Tổng có: S[n][0] + S[n][1] cách
*/
void solve(){
    S[0][0] = S[0][1] = 1;
    
    for(int i=1; i<=n; i++) {
    	// tính S[i][1]
        for(int j=k1; j<=k2; j++) {  
            if(i-j < 0) break;
            S[i][1] += S[i-j][0];
            S[i][1] %= MOD;
        }
        // tính S[i][0]
        S[i][0] = S[i-1][1];
    }
    
    result = (S[n][0] + S[n][1]) % MOD;
    cout << result;
}

void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k1 >> k2;
}

int main(){
    input();
    solve();
}
  