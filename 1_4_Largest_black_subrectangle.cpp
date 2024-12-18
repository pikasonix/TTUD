/*Largest black subrectangle: tìm hình chữ nhật con có diện tích lớn nhất */
#include <bits/stdc++.h>
using namespace std;

int n, m;           // kích thước hcn lớn
int A[1000][1000];  // ma trận A[][] = 1 -> đen, A[][] = 0 -> trắng
int result;         // diện tích hcn đen lớn nhất

/* solve: Tìm diện tích lớn nhất trong 1 histogram */
void solve(int row[]) {
    stack<int> st;
    int top_value, S;
    int j;
    while (j < n) {
        if (st.empty() || row[st.top()] <= row[j]) st.push(j++); // nếu phần tử hiện tại >= st.top() -> push vào stack
            else {                                               // nếu nhỏ hơn thì tính S = top*(khoảng cách j -> top)
                top_value = row[st.top()];
                st.pop();
                if (!st.empty()) S = top_value*(j-st.top()-1);
                    else S = top_value * j;
                result = max(S, result);
            }
    }
    // Sau khi duyệt xong -> tính S cho các phần tử còn lại trong stack
    while (!st.empty()) {
        top_value = row[st.top()];
        st.pop();
        if (!st.empty()) S = top_value*(j-st.top()-1);
            else S = top_value * j;
        result = max(S, result);
    }
}

void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++){
            cin >> A[i][j];
            if (A[i][j] && i>0) A[i][j] = A[i-1][j] + 1; // nếu A[i][j] = 1 thì tăng chiều cao lên 1
        }
            
}

int main(){
    input();   
    for (int i=0;i<m;i++) solve(A[i]);
    cout << result;
}
