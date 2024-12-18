/* Gold mining: Tìm tổng lớn nhất dãy số mà cách nhau [L1,L2] đơn vị
	solve(): [tối ưu] [O(n)] sử dụng deque
	solve2(): [O(n^2)] chỉ dùng quy hoạch động */

#include <bits/stdc++.h>
using namespace std;

int a[1000007], S[1000007]; // a[] chứa mảng số nhập vào, S[i] tổng lớn nhất khi kết thúc tại a[i] 
int n, L1, L2, result;		// result = max(S[])

// Quy hoạch động: S[i] = a[i]+max(S[j]) (với j nằm trong khoảng [L1,L2] so với i)
void solve(){
    deque<int> d; // lưu các j thoả mãn i (i-L2 <= j <= i-L1)
    			  // sắp xếp theo thứ tự giảm dần của S[j] (luôn đảm bảo S[d.front()] là max)
    result = 0;
    for(int i=1; i<=n; i++){
    	//xoá các phần tử không hợp lệ khỏi d(không thoả mãn i-L2 <= j) (#)
        while(!d.empty() && d.front() < i-L2) d.pop_front(); 
        
		//thêm các phần tử hợp lệ vào d(thoả mãn j <= i-L1)
        int j = i-L1; 
        if(j >= 1){
            while(!d.empty() && S[d.back()] < S[j]) d.pop_back(); // loại bỏ các j' còn tồn từ (#) mà S[j'] < S[j] (đã xa lại còn bé)
            d.push_back(j);										  // lúc này S[j] là bé nhất nên thêm cuối
        }
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]); // S[i] = a[i] + max(S[j])
        result = max(result,S[i]);
    }
    cout << result;
}

// Quy hoạch động theo công thức: S[i] = a[i]+max(S[j]) (với j nằm trong khoảng [L1,L2] so với i)
void solve2(){
	S[1] = a[1];
	result = S[1];
	for(int i=2; i<=n; i++){
		S[i] = a[i];
		//  S[i] = a[i] + max(S[j])
		for(int k=L1; k<=L2; k++){                    
			int j = i-k;
			if(j>=1 && S[i]<S[j]+a[i]) S[i] = S[j]+a[i];
		}
		result = max(result,S[i]);
	}
	cout << result;
}
// Đọc dữ liệu
void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> L1 >> L2;
    for(int i=1; i<=n; i++) cin >> a[i];
}
int main(){
	input();
	solve();
	//solve2();
}
