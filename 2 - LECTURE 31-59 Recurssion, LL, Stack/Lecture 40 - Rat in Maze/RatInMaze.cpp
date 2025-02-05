#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
bool isSafe(int x, int y, int n, const vector<vector<int>>& visited, const vector<vector<int>>& m) {
    return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
}

void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
    // Base case: Reached the destination
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[x][y] = 1;

    // 4 choices: D, L, R, U
    // Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back(); // Backtrack
    }

    // Left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back(); // Backtrack
    }

    // Right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back(); // Backtrack
    }

    // Up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back(); // Backtrack
    }

    // Unmark the cell (backtrack)
    visited[x][y] = 0;
}

// Function to find all paths from top-left to bottom-right
vector<string> findPath(vector<vector<int>>& m) {
    vector<string> ans;
    int n = m.size(); // Assuming the matrix is square

    if (m[0][0] == 0) {
        return ans; // No path if the start is blocked
    }
int x=0,y=0;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(m, n, ans, x,y, visited, path);
    sort(ans.begin(), ans.end()); // Sort paths lexicographically
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    vector<string> paths = findPath(m);
    for (const string& path : paths) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}

int main()
{

    return 0;
}