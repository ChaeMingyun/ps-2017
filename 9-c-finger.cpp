#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int t, n, m, x, y, dx, dy;
    cin >> t;
    //[start] 테스트
    set<pair<int, int>> finger, comp;
    while (t--) {
        //[start] 초기입력
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            finger.insert(pair<int, int>(x, y));
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            comp.insert(pair<int, int>(x, y));
        }
        //[end] 초기입력
        set<pair<int, int>>::iterator fingerIter = finger.begin();
        int fingerCount = 0;
        for (; fingerIter != finger.end(); ++fingerIter) {
            ++fingerCount;
            if (fingerCount * 15 > n)break;
            int compCount = 0;
            set<pair<int, int>>::iterator compIter = comp.begin();
            for (; compIter != comp.end(); ++compIter) {
                int count = 0;
                ++compCount;
                if (compCount * 10 > m)break;
                dx = compIter->first - fingerIter->first;
                dy = compIter->second - fingerIter->second;
                set<pair<int, int>>::iterator newIter = comp.begin();
                for (; newIter != comp.end(); ++newIter) {
                    if (finger.find(pair<int, int>(newIter->first - dx, newIter->second - dy)) != finger.end()) {
                        ++count;
                    }
                }
                //10*비교대상 지문 중 일치하는 좌표 수(count) >= 9*등록지문의 좌표 수
                if (10 * count >= 9 * n) {
                    //일치하면 1 출력
                    cout << "1\n";
                    goto isEnd;
                }
            }
        }
        //일치한다고 출력하지 않았으면 불일치이므로 0 출력
        cout << "0\n";
        isEnd:;
        finger.clear();
        comp.clear();
    }
    //[end] 테스트
    return 0;
}