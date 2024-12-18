/* TSP - Traveling Salesman Problem */
#include <bits/stdc++.h>
using namespace std;

int** dist, final[1001], minium = -1, n, route[1001];

void tsp(int start) {
    bool visited[1001];
    int cost = 0;

    route[1] = start;
    visited[start] = true;

    for (int i = 2; i <= n; i++){
        int index = 0, min = -1;
        int* temp = dist[route[i - 1]]; 

        for (int j = 1; j <= n; j++){
            if (visited[j] == false && temp[j] < min){
                min = temp[j];
                index = j;
            }
        }

        visited[index] = true;
        route[i] = index;
        cost += min;
        if (cost >= minium) return;
    }

    cost += dist[route[n]][start];
    if (cost < minium){
        minium = cost;
        for (int i = 1; i <= n; i++) final[i] = route[i];
    }
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;

    dist = new int* [n+1];
    for (int i=1; i<=n; i++){
        dist[i] = new int[n + 1];
        for (int j=1; j<=n; j++) cin >> dist[i][j];
    }

    for (int i=1; i<=n; i++) tsp(i);

    cout << n << endl;
    for (int i=1; i<=n; i++) cout <<final[i] << ' ';

}