#include <bits/stdc++.h>
using namespace std;

int g[9][9];
int rowMask[9], colMask[9], boxMask[9];

bool ok(int r, int c, int v) {
    int bit = 1 << v;
    return !((rowMask[r] | colMask[c] | boxMask[r/3*3 + c/3]) & bit);
}

void place(int r, int c, int v) {
    int bit = 1 << v;
    g[r][c] = v;
    rowMask[r] |= bit;
    colMask[c] |= bit;
    boxMask[r/3*3 + c/3] |= bit;
}

void removeVal(int r, int c, int v) {
    int bit = 1 << v;
    g[r][c] = 0;
    rowMask[r] &= ~bit;
    colMask[c] &= ~bit;
    boxMask[r/3*3 + c/3] &= ~bit;
}

bool solve() {
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            if (g[r][c] == 0) {
                for (int v = 1; v <= 9; v++)
                    if (ok(r, c, v)) {
                        place(r, c, v);
                        if (solve()) return true;
                        removeVal(r, c, v);
                    }
                return false;
            }
    return true;
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            int x;
            cin >> x;
            if (x != 0) place(i, j, x);
        }
    if (solve()) {
        for (auto& row : g) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    } else cout << "No solution\n";
}