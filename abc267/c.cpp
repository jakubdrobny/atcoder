#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<long long> P(N + 1);
    for (int i = 0; i < N; i++) P[i + 1] = P[i] + A[i];
    long long cur = 0;
    for (int i = 0; i < M; i++) cur += A[i] * (long long) (i + 1);
    long long ans = cur;
    for (int i = M; i < N; i++) {
        cur += M * A[i];
        cur -= P[i] - P[i - M];
        ans = max(ans, cur);
    }
    cout << ans << "\n";
	return 0;
}
