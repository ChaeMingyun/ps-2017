//그리디 알고리즘 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int maxi = 1, m, n, s, f;
    while (t--) {
        cin >> m >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            cin >> s >> f;
            v.push_back(pair<int, int>(f, s));
        }
        sort(v.begin(), v.end());
        int vSize = v.size();
        int fin = v[0].first;
        for (int i = 1; i < vSize; ++i) {
            if(fin <= v[i].second) {
                ++maxi;
                fin = v[i].first;
            }
        }
        cout << maxi << "\n";
        maxi = 1;
    }
}