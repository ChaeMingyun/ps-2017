//일반 구현 문제였지만 dp로 풀었음

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<int> v;
    for (int j = 1; j < 500; j *= 2) {
        v.push_back(j);
    }
    while (t--) {
        int dp[305] = {0,};
        int m, n;
        cin >> m >> n;
        dp[0] = 1;
        for (int i = 0; i < 9; i++){
            for (int j = n - v[i]; j >= 0; j--){
                if (!dp[j]) continue;
                for (int k = 1, add = v[i]; k <= m; k++, add += v[i]){
                    int next = j + add;
                    if (next > n) break;
                    dp[next] += dp[j];
                }
                for (int l = 0; l < 20; ++l) {
                    cout << dp[l] << " ";
                }
                cout << "\n";
            }
        }
//        cout << dp[n] << "\n";
    }
    return 0;
}