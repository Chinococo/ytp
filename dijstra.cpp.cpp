#include<bits/stdc++.h>

using namespace std;
int dir[10001][10001];
int ans[10001];
#define INF 1e9
#define pi pair<int,int>

void build() {
    for (int i = 0; i < 10001; i++)
        for (int k = 0; k < 10001; k++)
            dir[i][k] = INF;
    for (int i = 1; i < 10001; i++)
        ans[i] = INF;
    dir[1][2] = 5;
    dir[2][1] = 5;
    dir[1][3] = 8;
    dir[3][1] = 8;
    dir[2][3] = 1;
    dir[3][2] = 1;
    dir[2][5] = 2;
    dir[5][2] = 2;
    dir[2][4] = 3;
    dir[4][2] = 3;
    dir[5][4] = 7;
    dir[4][5] = 7;
}

int main() {
    build();
    set<int> now = {1};
    int start = 1;
    ans[1] = 0;
    priority_queue<pi, vector<pi >, greater<pi>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if(t.first > ans[t.second])
            continue;
        for (int i = 1; i <= 5; i++) {
            if ( t.first + dir[t.second][i] < ans[i]) {
                ans[i] = t.first + dir[t.second][i];
                pq.push({ans[i], i});
            }
        }


    }
    for (int i = 1; i <= 5; i++) {
        cout << 1 << " to " << i << " distan " << ans[i] << endl;
    }
}
