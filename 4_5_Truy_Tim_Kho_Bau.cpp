#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Treasure {
    int x, y, gold;
};

bool compareTreasures(const Treasure &a, const Treasure &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<Treasure> treasures(n);
    for (int i = 0; i < n; ++i) 
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;


    // Sắp xếp các kho báu theo toạ độ x tăng dần, nếu bằng nhau thì theo toạ độ y tăng dần
    sort(treasures.begin(), treasures.end(), compareTreasures);

    vector<long long> dp(n);
    dp[0] = treasures[0].gold;

    for (int i = 1; i < n; ++i) {
        dp[i] = treasures[i].gold;
        for (int j = 0; j < i; ++j)
            if (treasures[i].x >= treasures[j].x && treasures[i].y >= treasures[j].y)
                dp[i] = max(dp[i], dp[j] + treasures[i].gold);
    }

    long long max_gold = 0;
    for (int i = 0; i < n; ++i) max_gold = max(max_gold, dp[i]);

    cout << max_gold << endl;
}
