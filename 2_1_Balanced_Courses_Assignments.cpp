/* BCA - Balance Course Asignment: phân công teacher sao cho
không có 2 course trùng 1 teacher tại 1 thời điểm
course được tối ưu theo độ ưu tiên của teacher */
#include <bits/stdc++.h>
using namespace std;

#define N 50
vector<int> T[N];   // T[k]: lưu danh sách teacher có thể dạy course k
int m,n;            // m: số teacher; n: số course 
bool visited[N][N]; // visited[i][j] == true -> course i và j trùng teacher
int x[N];           // x[k]: lưu teacher dạy course k
int load[N];        // load[t]: lưu số khoá học mà teacher t đã dạy
int result = 1e9;  

/* check: kiểm tra teacher t có thể dạy course k không 
    t không dạy course nào trùng với course k -> true */
bool check(int t, int k){
    for(int i=1; i<=k-1; i++)
        if(visited[i][k] && x[i] == t) return false;
    return true;
}

/* solution: cập nhật result (số course tối đa mà 1 teacher phải dạy) */
void solution(){
    int maxLoad = 0;
    for(int t=1; t<=m; t++)
        maxLoad = max(maxLoad, load[t]);
    if(maxLoad < result) result = maxLoad;
}

void Try(int k){
    for(int i=0; i < T[k].size(); i++){
        int t = T[k][i];            // temp (các teacher có thể dạy course k)
        if(check(t,k)){
            x[k] = t;               // gán thử
            load[t] += 1;           // update
            if(k == n) solution();              // -> hoàn thành
            else if(load[t] < result) Try(k+1); // -> cắt nhánh (load[t] >= result)
            load[t] -= 1;           // remove update
        }
    }
}

void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    int c, k; 
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){   
            cin >> c;  
            T[c].push_back(i);
        }
    }

    int K; 
    cin >> K;
    int i,j;
    for(int k=1; k <= K; k++){
        cin >> i >> j;
        visited[i][j] = true;   
        visited[j][i] = true;
    }
}

int main(){
    input();
    Try(1);
    cout << result;
}

