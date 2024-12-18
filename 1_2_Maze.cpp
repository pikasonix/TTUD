/* Maze: tìm đường mê cung */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;       // cặp toạ độ (x,y)
int a[2000][2000], m, n, r, c;  // a[] ma trận; m,n: kích thước ma trận; r,c: điểm khởi đầu
int d[2000][2000];              // quãng đường đã đi
int dx[] = {1,0,-1,0} ,  dy[] = {0,1,0,-1}; // hướng di chuyển 1 lên,trái; 2 xuống, phải
queue<ii> qe;

int solve(){
    qe.push(ii(r,c));               // đưa ô xuất phát vào queue
    d[r][c] = 0;   a[r][c] = 1;     // update: a[][] = 1 -> đã visited
    while(!qe.empty()){
        ii u = qe.front(); qe.pop();
        for(int i=0; i<4; i++){     // duyệt các ô lân cận
            int x = dx[i] + u.first;         
            int y = dy[i] + u.second;
            // kiểm tra thoát khỏi mê cung
            if(x < 1 || x > m || y < 1 || y > n) return d[u.first][u.second] + 1;
            // kiểm tra điều kiện di chuyển
            if(a[x][y] != 1){
                    d[x][y] = d[u.first][u.second] + 1;
                    qe.push(ii(x,y));
                    a[x][y] = 1;
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> m >> n >> r >> c;
    for(int i=1; i<=m; i++) 
        for(int j=1; j<=n; j++) 
            cin >> a[i][j];
    cout << solve();
}