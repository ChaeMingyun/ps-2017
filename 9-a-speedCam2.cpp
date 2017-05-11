//
// Created by 채민균 on 2017. 5. 9..
//
#include <iostream>
#include <string.h>
using namespace std;

long long cities, people, c, p, cost[5001];
int cityArr[5001][5001], adjacencyMatrix[5001][5001], visit[5001], cn, rn;

void dfs(int from, int to) {
    visit[from] = 1;
    for (int i = 1; i <= to; i++) {
        if (adjacencyMatrix[from][i] == 1 && visit[i] == 0) {
            people += cityArr[i][1];
            cities += cityArr[i][2];
            dfs(i, to);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        c = p = 0;
        cin >> cn >> rn;
        for (int i = 1; i <= cn; i++) {
            memset(adjacencyMatrix[i], 0, sizeof(int) * 5001);
            memset(cityArr[i], 0, sizeof(int) * 5001);
        }
        memset(cost, 0, sizeof(long long) * 5001);
        memset(visit, 0, sizeof(int) * 5001);
        for (int i = 1; i <= cn; i++) {
            cin >> cityArr[i][1] >> cityArr[i][2];
            p += cityArr[i][1];
            c += cityArr[i][2];
        }
        int s, e;
        for (int i = 1; i <= rn; i++) {
            cin >> s >> e;
            adjacencyMatrix[s][e] = 1;
        }
        long long ans = 0;
        for (int i = 1; i <= cn; i++) {
            memset(visit, 0, sizeof(int) * (cn + 1));
            cities = people = 0;
            people += cityArr[i][1];
            cities += cityArr[i][2];
            dfs(i, cn);
            cost[i] = (people * (c - cities)) + ((p - people) * cities);
            if (ans < cost[i]) {
                ans = cost[i];
            }
        }
        cout << ans << "\n";
    }
}
