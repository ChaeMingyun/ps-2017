//BFS 알고리즘 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//도시 구조체, r,s,x 는 문제에 나와있는 변수. ppl은 도시의 인구수.
struct capital {
    int r = 0;
    int s = 0;
    int x;
    int ppl;
};
//index는 도시의 번호 depth는 bfs를 돌리기 시작한 시점으로 부터의 거리
struct qType {
    int index;
    int depth;
};

int main() {
    std::ios::sync_with_stdio(false);
    //[start] 초기 입력
    int t;
    cin >> t;
    //[start] 테스트
    for (int i = 0; i < t; i++) {
        vector<capital> v;
        int n, m;
        int mini = 999999999;
        int findAnswer = 1;
        cin >> n >> m;
        vector<vector<int> > mtrx(n + 1);
        capital c1;
        v.push_back(c1);
        int people;
        for (int j = 1; j <= n; j++) {
            cin >> people;
            capital c;
            c.ppl = people;
            v.push_back(c);
        }
        int a, b;
        for (int j = 0; j < m; j++) {
            cin >> a >> b;
            mtrx[a].push_back(b);
            mtrx[b].push_back(a);
        }
        //[end] 초기 입력
        //[start] bfs
        for (int j = 1; j <= n; j++) {
            queue<qType> que;
            //처리한 도시들을 알려주는 배열
            int arr[505] = {0,};
            arr[j] = 1;
            qType q;
            q.index = j;
            q.depth = 0;
            que.push(q);
            while (!que.empty()) {
                qType q2 = que.front();
                int num = q2.index;
                int depth = q2.depth;
                que.pop();
                int mtrx_size = mtrx[num].size();
                for (int k = 0; k < mtrx_size; k++) {
                    if (arr[mtrx[num][k]] != 1) {
                        //k도시에 한번도 간 적이 없으면
                        qType q3;
                        q3.index = mtrx[num][k];
                        q3.depth = depth + 1;
                        que.push(q3);
                        //k도시에 갔음을 체크
                        arr[mtrx[num][k]] = 1;
                        if (v[j].r < q3.depth) {
                            v[j].r = q3.depth;
                        }
                        v[j].s += q3.depth;
                    }
                }
            }
        }
        //[end] bfs
        //[start] x = (n-1)r + s
        for (int j = 1; j <= n; j++) {
            v[j].x = (n - 1) * v[j].r + v[j].s;
            if (mini >= v[j].x) {
                if (mini == v[j].x) {
                    if (v[findAnswer].ppl < v[j].ppl) {
                        mini = v[j].x;
                        findAnswer = j;
                    }
                } else {
                    mini = v[j].x;
                    findAnswer = j;
                }
            }
        }
        //[end] bfs
        //[start] 정답 출력
        cout << findAnswer << endl;
        //[end] 정답 출력
    }
    //[end] 초기 입력
    return 0;
}