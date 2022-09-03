#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    const long long INFI = 1e18;
    int N, M; cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<long long>> dp(N + 1, vector<long long>(M + 1, -INFI));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j == 0) {
                dp[i][j] = 0;
            } else if (j <= i) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + j * A[i-1]);
            }
        }
    }
    long long ans = -INFI;
    for (int i = 0; i <= N; i++) {
        ans = max(ans, dp[i][M]);
    }
    cout << ans << "\n";
	return 0;
}
