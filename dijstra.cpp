#include<bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, pair<int, int>> P;
signed main() {
    int edge[10][10];
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            edge[i][i] = 1e9;

    for (int i = 1; i <= 8; i++)
        edge[i][i] = 0;
    edge[2][1] = 300;
    edge[3][1] = 1000;
    edge[8][1] = 1700;
    edge[3][2] = 800;
    edge[4][3] = 1200;
    edge[5][4] = 1500;
    edge[6][4] = 1000;
    edge[5][6] = 250;
    edge[6][7] = 900;
    edge[6][8] = 1400;
    edge[7][8] = 1000;

    priority_queue<P,P,greater<>> pq;
    set<int> now;
    int dis[10];
    for (int i = 1; i <= 9; i++)
    dis[i]=1e9;
    now.insert(1);
    int  n=1;
    while(now.size()!=8)
    {
        for(int i=1;i<=8;i++)
        {
            if(edge[n][i]!=1e9)
            {
                pq.push({edge[n][i],{n,i}});
            }
        }


    }
}
