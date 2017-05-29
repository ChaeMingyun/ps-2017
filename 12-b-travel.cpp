#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct edge {
    int weight, v, w;
};

class cmp {
public:
    bool operator()(edge a, edge b) {
        return a.weight > b.weight;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int status[10001];
    int t;
    cin >> t;
    while (t--) {
        //[START] 초기입력
        int n, m;//n 여행지역(정점) 수, m 버스노선(간선) 수
        cin >> n >> m;
        memset(status, 0, sizeof(int) * (n));// 0 => unseen, 1 => end
        vector<vector<pair<int, int>>> info(n);
        for (int i = 0; i < m; ++i) {
            int v, w, weight;
            cin >> v >> w >> weight;
            info[v].push_back(pair<int, int>(w, weight));
            info[w].push_back(pair<int, int>(v, weight));
        }
        //[END] 초기입력
        int answer = 0;
        status[0] = 1;
        int sizeInit = info[0].size();
        priority_queue<edge, vector<edge>, cmp> pq;
        for (int i = 0; i < sizeInit; ++i) {
            edge e{info[0][i].second, 0, info[0][i].first};
            pq.push(e);
        }
        while (!pq.empty()) {
            edge e = pq.top();
            pq.pop();
            if (status[e.w] != 1) {
                status[e.w] = 1;
                answer += e.weight;
                int size = info[e.w].size();
                for (int i = 0; i < size; ++i) {
                    int check = info[e.w][i].first;
                    int weight = info[e.w][i].second;
                    if (status[check] == 0) {
                        edge newE{weight, e.w, check};
                        pq.push(newE);
                    }
                }
            }
        }
        cout << answer << "\n";
    }
}