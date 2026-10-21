#include <bits/stdc++.h>
using namespace std;

int g[9][9];

bool ok(int r, int c, int v) {
    for (int i = 0; i < 9; i++) {
        if (g[r][i] == v || g[i][c] == v) return false;
        if (g[r/3*3 + i/3][c/3*3 + i%3] == v) return false;
    }
    return true;
}

bool solve() {
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            if (g[r][c] == 0) {
                for (int v = 1; v <= 9; v++)
                    if (ok(r, c, v)) {
                        g[r][c] = v;
                        if (solve()) return true;
                        g[r][c] = 0;
                    }
                return false;
            }
    return true;
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) cin >> g[i][j];
    if (solve()) {
        for (auto& row : g) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    } else cout << "No solution\n";
}
