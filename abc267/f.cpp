#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5+1;
int N, L[mxn], R[mxn], D[mxn];
int timer = 0;
vector<int> G[mxn];

void dfs(int v, int p, int d) {
    L[v] = timer++;
    D[v] = d;
    for (int u : G[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }
    R[v] = timer++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y; --x, --y;
        G[x].push_back(y), G[y].push_back(x);
    }
    dfs(0, -1, 0);
    int q; cin >> q;
    while (q--) {
        int u, k; cin >> u >> k; --u;
        int ans = 
    }
	return 0;
}
