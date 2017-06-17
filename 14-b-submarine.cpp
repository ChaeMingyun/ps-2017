#include <iostream>
#include <string.h>

using namespace std;
//arr[][] = 지도크기
//maxi[0,1,2,3] = 위, 아래, 오른쪽, 왼쪽으로 먼저 출발했을 때의 dfs 호출 최댓값
//isEnd[][] = 방문한 적이 있는지 체크하기 위한 2차원배열
int maxi[4], arr[6][6], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, n, m, isEnd[6][6];

void func(int x, int y, int index, int count) {
    if (maxi[index] < count) maxi[index] = count;
    isEnd[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int goX = x + dx[i];
        int goY = y + dy[i];
        if (arr[goX][goY] == 0)
            if (isEnd[goX][goY] == 0)
                if (0 <= goX && goX < n && 0 <= goY && goY < n) func(goX, goY, index, count + 1);
    }
    isEnd[x][y] = 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    //[START] 테스트
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int num;
                cin >> num;
                arr[i][j] = num;
            }
            memset(isEnd, 0, sizeof(int) * n);
        }
        //for (int k = 0; k < 6; ++k) {
        //    memset(isEnd[k], 0, sizeof(int) * 6);
        //}
        while (m--) {
            int x, y;
            cin >> x >> y;
            for (int i = 0; i < 4; ++i) {
                maxi[i] = 1;
                int goX = x + dx[i];
                int goY = y + dy[i];
                if (arr[goX][goY] == 0) {
                    isEnd[x][y] = 1;
                    if (0 <= goX && goX < n && 0 <= goY && goY < n) func(goX, goY, i, 2);
                }
            }
            isEnd[x][y] = 0;
            int ans = 0;
            for (int i = 0; i < 4; ++i)
                if (ans < maxi[i]) ans = maxi[i];
            cout << ans << "\n";
        }
    }
    //[END] 테스트
    return 0;
}