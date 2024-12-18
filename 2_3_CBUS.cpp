/* CBUS: tính khoảng cách ngắn nhất để phục vụ n khách và quay về điểm 0 (mỗi điểm thăm 1 lần)
có n khách hàng cần đi từ điểm i -> i+n, BUS xuất phát từ điểm 0 (max <cap> hành khách)
cho ma trận c[i][j] khoảng cách di chuyển từ i -> j */

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int n, cap, load;           // n: số khách, cap: tổng sức chứa xe, load: số khách trên xe hiện tại
int A[2*MAX+1][2*MAX+1];    // ma trận khoảng cách
int x[MAX], visited[MAX];   // x[]: lưu lộ trình hiện tại, visited[] đánh dấu điểm đã qua 
int S, S_opt = 1e9;         // S: tổng quãng đường hiện tại, S_opt: quãng đường tối ưu
//int x_opt[MAX];             // mảng lưu lộ trình tối ưu
int cmin = 1e9;             // khoảng cách ngắn nhất giữa 2 điểm

/* solution: cập nhật best option */
void solution(){
    if(S + A[x[2*n]][0] < S_opt){ // S: quãng đường hiện tại + quãng đường quay về 0
        S_opt = S + A[x[2*n]][0];
        //for(int i = 0; i <= 2*n; i++) x_opt[i] = x[i];
        //printf("update best %d\n",S_opt);
    }
}

/* check: kiểm tra điểm tiếp theo 
		điểm v chưa visited
		(v>n)  v là điểm trả khách -> v-n đã visited
		(v<=n) v là điểm đón khách -> xe đủ chỗ  */
bool check(int v, int k) {
    if (visited[v]) return false;
    if (v > n) {
        if (!visited[v-n]) return false;
    } else {
        if (load+1 > cap) return false;
    }
    return true;
}

void TRY(int k){
    for(int v=1; v<=2*n; v++){
        if(check(v,k)){
            x[k] = v;						// gán thử
            S += A[x[k-1]][x[k]];			// update 
            if(v <= n) load++; else load--; //
            visited[v] = 1;					//
            if(k == 2*n) solution();  							// -> hoàn thành
            	else if(S + (2*n+1-k)*cmin < S_opt) TRY(k+1);   // -> cắt nhánh (nếu 2n+1-k điểm còn lại theo cmin còn xa hơn S_opt thì thôi)
            if(v <= n) load--; else load++;	// remove update
            visited[v] = 0;					//
            S -= A[x[k-1]][x[k]];			//
        }
    }
}

//void print(){
//    for(int i = 0; i <= 2*n; i++) printf("%d ",x_opt[i]);
//}

void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    
    cin >> n >> cap;
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin >> A[i][j];
            if (i != j) cmin = min(cmin,A[i][j]);
        }
    }
}

int main(){
    input();
    TRY(1);
    cout << S_opt;
}
