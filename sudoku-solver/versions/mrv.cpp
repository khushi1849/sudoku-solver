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
    int bestR = -1, bestC = -1, bestCnt = 10;
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            if (g[r][c] == 0) {
                int used = rowMask[r] | colMask[c] | boxMask[r/3*3 + c/3];
                int cnt = 0;
                for (int v = 1; v <= 9; v++)
                    if (!(used & (1 << v))) cnt++;
                if (cnt < bestCnt) {
                    bestCnt = cnt;
                    bestR = r;
                    bestC = c;
                }
            }
    if (bestR == -1) return true;
    if (bestCnt == 0) return false;
    for (int v = 1; v <= 9; v++)
        if (ok(bestR, bestC, v)) {
            place(bestR, bestC, v);
            if (solve()) return true;
            removeVal(bestR, bestC, v);
        }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            int x;
            cin >> x;
            if (x != 0) place(i, j, x);
        }
    auto t1 = chrono::steady_clock::now();
    bool solved = solve();
    auto t2 = chrono::steady_clock::now();
    if (solved) {
        for (auto& row : g) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    } else cout << "No solution\n";
    cerr << "Time: " << chrono::duration<double, milli>(t2 - t1).count() << " ms\n";
}