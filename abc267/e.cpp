#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y; --x, --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    set<pair<long long, int>> st;
    vector<long long> cost(N);
    for (int i = 0; i < N; i++) {
        long long cur = 0;
        for (int j : G[i]) {
            cur += A[j];
        }
        cost[i] = cur;
        st.insert({cur, i});
    }
    vector<int> done(N);
    long long ans = 0;
    while (!st.empty()) {
        int v = st.begin()->second;
        ans = max(ans, st.begin()->first);
        st.erase(st.begin());
        done[v] = 1;
        for (int u : G[v]) {
            if (!done[u]) {
                st.erase({cost[u], u});
                cost[u] -= A[v];
                st.insert({cost[u], u});
            }
        }
    }
    cout << ans << "\n";
	return 0;
}
