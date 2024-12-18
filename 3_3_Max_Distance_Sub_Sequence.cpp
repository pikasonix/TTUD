/* Max Distance SubSequence: Cho dãy a. và tham số C
 Chọn C phần tử từ a[] sao cho khoảng cách nhỏ nhất giữa 2 phần tử bất kì là lớn nhất*/

#include<bits/stdc++.h>
using namespace std;

int T;
int n,c;
int a[100007];

bool check(int distance) {
    int sl = 1;			// sô lượng phần tử đã chọn (từ phần tử đầu tiên)
    int point = a[1];   // giá trị phần tử đầu tiên

    while(1){
    	// tìm phần tử nhỏ nhất trong a[] >= point+distance (thông qua tìm kiếm nhị phân)
        point += distance; 
        auto it = lower_bound(a+1, a+1+n, point); 
  
        if (it == a+1+n) return false; // Không còn phần tử >= point+distance -> FALSE
        
        sl++; // Tìm được thì tăng sl
        if (sl>=c) return true;  // Chọn đủ C rồi -> TRUE 

        point = *it; // Cập nhật lại point và tiếp tục lặp
    }
}

void solve(){
	// Sắp xếp a[]
    sort(a+1, a+1+n);
    // Tìm giá trị mid lớn nhất thoả mãn (tìm kiếm nhị phân)
	int l = 0;
    int r = a[n]-a[1];
    while(l<=r){
        int m = l + (r-l)/2;
        if(check(m)) l = m+1; else r = m-1;
    }
    cout << r << endl;
}

void input(){
	cin >> n >> c;
    for(int i=1; i<=n; i++) cin >> a[i];
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> T;
    while(T--){
        input();
        solve();
    }
}
