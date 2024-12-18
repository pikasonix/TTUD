/* Linear Equation: a1X1 + a2X2 + ... + anXn = M -> đếm số nghiệm X(X1,X2,...,Xn) thoả mãn */
#include <bits/stdc++.h>
using namespace std;

int n, M;           
int a[1000], x[1000];
long long S = 0;        // tổng tạm thời của ai*Xi
long long t[1000];  // tổng t[i] = tổng a0 -> ai
int result = 0;         // đếm số nghiệm thoả mãn

// (M-S-(t[n]-t[k])) / a[k] : giá trị tối đa của x[k] (M - tổng ai*xi - tổng ai còn lại*1)/a[k] = x[k]
void Try(int k){
        for(int v=1; v <= (M-S-(t[n]-t[k]))/a[k]; v++){
            x[k] = v;           // gán thử
            S += a[k]*x[k];     // update
            if(k == n) {         // -> hoàn thành
                if(S == M) result++;
        	} else Try(k+1);
            S -= a[k]*x[k];     // remove update
        }
}

void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    
	cin >> n >> M;
	t[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        t[i] = t[i-1] + a[i]; // tổng t[i] = tổng a0 -> ai
    }
}

int main() {
    input();
    Try(1);
    cout << result;
}
