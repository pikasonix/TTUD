/* VCR - Capacitaed Vehicle Routing [NP-Hard]: đưa ra tổng quãng đường nhỏ nhất sao cho
các xe xuất phát và kết thúc tại điểm 0
mỗi điểm đến đúng 1 lần bởi 1 xe tải
tổng lượng hàng mỗi xe <= Q
 */
#include<bits/stdc++.h>
using namespace std;

int n, K, Q;		            // n: số điểm dừng, K: số xe, Q: trọng tải xe
int d[13];		              	// d[] lượng hàng cần tại mỗi điểm dừng
int c[13][13], cmin = 1e9;  	// c[][]: ma trận khoảng cách, cmin: khoảng cách ngắn nhất giữa 2 điểm		
int x[13], y[13], load[5];		// x[] lưu tuyến đường từng xe, y[] lưu điểm bắt đầu từng xe, load[] tải trọng từng xe 
int visited[13], visited_count = 0;  // visited[] đánh dấu điểm đã đến, visited_count: số điểm đã đi qua
int S = 0, result = 1e9, nbR;        // S: tổng quãng đường hiện tại, result: tổng quãng đường tối ưu, nbR: số điểm đi qua trong 1 giải pháp

/* checkY: kiểm tra điều kiện chọn điểm bắt đầu của xe 
    (điểm 0) hoặc (điểm chưa visited) -> true */
bool checkY(int v, int k){
    if(v == 0) return true;
    if(visited[v]) return false;
    return true;
}

/* checkX: kiểm tra điều kiện chọn đường
    (điểm chưa visited + lượng hàng không vượt quá Q) -> true; */
bool checkX(int v, int k){
    if (v > 0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

/* updateBest: cập nhật giải pháp tối ưu */
void updateBest() {
	if (S < result) result = S;
}

/* TRY_X(s,k): tìm tuyến đường cho xe k bắt đầu từ điểm s */
void TRY_X(int s, int k){
    if(s == 0){
        if(k < K) TRY_X(y[k+1], k + 1);
        return;
    }

    for(int v = 0; v <= n; v++){
        if(checkX(v, k)){
            x[s] = v;
			visited[v] = true;
			S += c[s][v];
			visited_count++;
			load[k] += d[v];
			if (v > 0) {
				if(S+(n+nbR-visited_count)*cmin < result) TRY_X(v, k);
			} else {
				if (k == K) {
					if (visited_count == n + nbR) updateBest();
				} else if(S+(n+nbR-visited_count)*cmin < result) TRY_X(y[k + 1], k + 1);
			}
			visited[v] = false;
			S -= c[s][v];
			visited_count--;
			load[k] -= d[v];
        }
    }
}

/* TRY_Y(k): xây dựng điểm khởi hành y[k] cho xe k */
void TRY_Y(int k){
    
	int s = 0;
    if(y[k-1] > 0) s = y[k-1] + 1;

    for(int v = s; v <= n; v++){
        if(checkY(v,k)){
            y[k]=v;
            if(v > 0) visited_count++;
            S += c[0][v];
            visited[v] = true;
			load[k] += d[v];
			if (k < K) TRY_Y(k + 1);
                else {
                    nbR = visited_count;
                    TRY_X(y[1], 1);
                }
			if (v > 0) visited_count--;
			S -= c[0][v];
			visited[v] = false;
			load[k] -= d[v];
        }
    }
}

void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> K >> Q;
    for(int i=1; i<=n; i++) cin >> d[i];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin >> c[i][j];
            if (i != j) cmin = min(cmin,c[i][j]);
        }
    }
}

int main(){
	input();
	TRY_Y(1);
	cout << result;
}
