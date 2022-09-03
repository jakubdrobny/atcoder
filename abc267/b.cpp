#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	vector<int> cnt(7);
    vector<int> fall = {1, 1, 2, 2, 2, 1, 1};
    string s; cin >> s;
    for (int i = 0; i < 10; i++) {
        char c = s[i];
        if (c == '0') {
            if (i == 0 || i == 4) cnt[3]++;
            else if (i == 1 || i == 7) cnt[2]++;
            else if (i == 3) cnt[1]++;
            else if (i == 6) cnt[0]++;
            else if (i == 2 || i == 8) cnt[4]++;
            else if (i == 5) cnt[5]++;
            else cnt[6]++;
        }
    }
    // for (auto x : cnt) cout << x << " ";
    // cout << " cnt\n";
    if (s[0] == '0') {
        int i = 0;
        while (i < 7 && cnt[i] == fall[i]) i++;
        int j = i + 1;
        while (j < 7 && cnt[j] != fall[j]) j++;
        int k = j + 1;
        while (k < 7 && cnt[k] == fall[k]) k++;
        // cout << i << " " << j << " " << k << "\n";
        if (i < 7 && j < 7 && k < 7) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }
	return 0;
}