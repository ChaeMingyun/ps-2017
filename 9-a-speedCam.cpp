#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
struct vertex;
struct edge;
vector<vertex> v;
struct vertex {
    int num;
    int car;
    int amusementPark;
    vector<edge*> e;
};

struct edge {
    vertex &v;
    vertex &w;
    int cost;
};

int dfs(int index, int visited, int start) {
    int eSize = v[index].e.size();
    int stat = 0;
    for (int i = 0; i < eSize; ++i) {
        if (v[index].e[i]->v.num == v[index].num) {
            //w로 가야함
            if (v[index].e[i]->w.num == visited) {
                continue;
            }
            stat += dfs(v[index].e[i]->w.num, v[index].num, start);
            v[index].e[i]->cost += stat;
        } else {
            //v로 가야함
            if (v[index].e[i]->v.num == visited) {
                continue;
            }
            stat += dfs(v[index].e[i]->v.num, v[index].num, start);
            v[index].e[i]->cost += stat;
        }
    }
    return start * v[index].amusementPark + stat;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<edge*> e;
        int a, b, from, to;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            vertex vtx;
            vtx.num = i;
            vtx.car = a;
            vtx.amusementPark = b;
            v.push_back(vtx);
        }
        for (int i = 0; i < m; ++i) {
            cin >> from >> to;
            edge *edg = new edge;
            edg->v = v[from-1];
            edg->w = v[to-1];
            edg->cost = 0;
            e.push_back(edg);
            v[from - 1].e.push_back(edg);
            v[to - 1].e.push_back(edg);
        }
        for (int i = 0; i < n; ++i) {
            dfs(i, v[i].num, v[i].car);
        }
        int maxi = 0;
        cout << maxi << "\n";
    }
}