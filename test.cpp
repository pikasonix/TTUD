#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<vector<int>> dist;
vector<pair<int, int>> constraints;
int min_dist = INT_MAX;
vector<int> best_path;

bool is_valid(const vector<int>& path) {
    for (const auto& constraint : constraints) {
        int pos_p = -1, pos_q = -1;
        for (int i = 0; i < n; ++i) {
            if (path[i] == constraint.first) {
                pos_p = i;
            }
            if (path[i] == constraint.second) {
                pos_q = i;
            }
        }
        if (pos_p > pos_q) {
            return false;
        }
    }
    return true;
}

void solve(int u, vector<int>& path, vector<bool>& visited, int current_dist) {
    if (path.size() == n) {
        current_dist += dist[path.back() - 1][path[0] - 1];
        if (is_valid(path) && current_dist < min_dist) {
            min_dist = current_dist;
            best_path = path;
        }
        return;
    }

    for (int v = 1; v <= n; ++v) {
        if (!visited[v]) {
            visited[v] = true;
            path.push_back(v);
            solve(v, path, visited, current_dist + dist[u - 1][v - 1]);
            path.pop_back();
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n;
    dist.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    cin >> m;
    constraints.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> constraints[i].first >> constraints[i].second;
    }

    vector<int> path;
    vector<bool> visited(n + 1, false);

    for (int start_node = 1; start_node <=n; ++start_node)
    {
        path.push_back(start_node);
        visited[start_node] = true;
        solve(start_node, path, visited, 0);
        path.pop_back();
        visited[start_node] = false;
    }

    if (min_dist == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_dist << endl;
        for (int node : best_path) {
            cout << node << " ";
        }
        cout << best_path[0] << endl;
    }

    return 0;
}
