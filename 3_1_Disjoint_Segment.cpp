/* Disjoint Segment: Tìm tập lớn nhất các đoạn thẳng không giao nhau 
ĐK giao nhau: (ai,bi) (aj,bj) giao nhau nếu (aj < bi) và (ai < bj) */

#include <bits/stdc++.h>
using namespace std;

int n;
int result = 0;     	// số đoạn được chọn    
int last = -1;      	// điểm kết thúc của đoạn cuối được chọn
pair<int,int> a[100007];// các đoạn

// hàm hỗ trợ sort (sort theo b - pair.second)
bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

void solve() {
    // sort theo tăng dần của b -> chọn đoạn kết thúc sớm nhất (tăng số lượng đoạn thoả mãn)
    sort(a+1, a+n+1,compare);
    // duyệt lần lượt, nếu không giao đoạn cuối đã chọn -> đưa vào tập kết quả
	for (int i=1; i<=n; i++){
        if(a[i].first > last){   
            result++;
            last = a[i].second;
        }
	}
    cout << result;
}

void input() {
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i].first >> a[i].second;
}

int main() {
    input();
    solve();
}
