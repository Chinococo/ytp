#include<bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
    int n;
    cin >> n;
    int data[n + 1];
    set<int> q;

    for (int i = 1; i <= n; i++)
        cin >> data[i], q.insert(i);
    auto now = q.begin();
    int count=1;
    while (q.size() != 1) {
        vector< int > erase;
        for(auto t:q)
        {
            if(count%data[t]==0&&*now!=t)
                erase.push_back(t);
        }
        for(auto t:erase)
            q.erase(t);
        now = next(now);
        if(now==q.end())
            now = q.begin();
        //cout<<q.size()<<endl;
        count++;
    }
    cout<<*q.begin();
}
