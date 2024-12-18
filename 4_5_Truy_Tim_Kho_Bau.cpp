/* Truy tìm kho báu: Cho các điểm vàng (x,y) chứa <gold> lượng vàng
Chỉ được đi theo chiều (x,y không giảm) -> đưa ra giá trị gold max */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tạo 1 node (toạ độ + vàng)
struct Treasure {
    int x, y, gold;
};

int n;
vector<long long> dp; // dp[i] lượng vàng tối đa khi kết thúc tại kho báu thứ i
long long max_gold = 0;  
vector<Treasure> treasures;

// hàm hỗ trợ sort 
bool compare(Treasure a, Treasure b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

void solve(){
	// Sắp xếp Node theo x tăng, x bằng thì y tăng dần (thông qua hàm compare)
    sort(treasures.begin(), treasures.end(), compare);
    
	//--- Quy hoạch động --- 
    dp[0] = treasures[0].gold; 
	// dp[i]=max(dp[i], dp[j]+treasures[i].gold) (với điều kiện j < i và treasures[j].y <= treasures[i].y) do hàm sort chỉ sort theo x chứ không sort theo y)
    for (int i = 1; i < n; i++) {
        dp[i] = treasures[i].gold;
        for (int j = 0; j < i; j++)
            if (treasures[i].y >= treasures[j].y)
                dp[i] = max(dp[i], dp[j] + treasures[i].gold);
    }
	
	// từ mảng dp[i] -> đưa ra max 
    for (int i = 0; i < n; i++) max_gold = max(max_gold, dp[i]);
    cout << max_gold << endl;
}

void input(){
	ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    // resize lại các vector 
    treasures.resize(n);
    dp.resize(n);
	// Nhập các Node vào vector
    for (int i = 0; i < n; i++) 
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;
}
int main() {
	input();
	solve();
}
