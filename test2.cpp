#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra số chẵn
bool isEven(int num) {
    return num % 2 == 0;
}

// Hàm tìm chiều dài chuỗi con tăng dần dài nhất
int longestIncreasingSubsequence(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // Khởi tạo mảng dp

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// Hàm tìm chiều dài chuỗi con chẵn lẻ tăng dần dài nhất
int longestEvenOddSubsequence(const vector<int>& arr) {
    int maxLength = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        vector<int> newArr = arr; // Tạo chuỗi mới
        newArr.erase(newArr.begin() + i); // Bỏ phần tử arr[i]

        // Tạo các mảng chứa số chẵn và số lẻ
        vector<int> evens, odds;
        for (int num : newArr) {
            if (isEven(num)) {
                evens.push_back(num);
            } else {
                odds.push_back(num);
            }
        }

        // Tìm chiều dài chuỗi con tăng dần
        maxLength = max(maxLength, longestIncreasingSubsequence(evens));
        maxLength = max(maxLength, longestIncreasingSubsequence(odds));
    }

    return maxLength;
}

int main() {
    vector<int> array = {1, 3, 4, 5, 8, 7, 5, 2, 1, 2, 4, 5};
    int result = longestEvenOddSubsequence(array);
    cout << "Chiều dài chuỗi con chẵn lẻ tăng dần dài nhất: " << result << endl;
    return 0;
}
