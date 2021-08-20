#include<bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    string s1,s2;

    getline(cin,s1);
    getline(cin,s2);
    int lcs[s1.size()][s2.size()];
    memset(lcs,0, sizeof(lcs));
    for(int i=0;i<s1.size();i++)
        for(int k=0;k<s2.size();k++)
        {
            if(i==0||k==0)
                lcs[i][k]=0;
            else if(s1[i]==s2[k])
                lcs[i][k] = max({lcs[i-1][k-1]+1,lcs[i-1][k],lcs[i][k-1]});
            else
                lcs[i][k] = max({lcs[i-1][k],lcs[i][k-1]});
        }
    s1+='-';
    s2+='-';
    int ma = lcs[s1.size()-1][s2.size()-1];
    int ans=0;
    int x = s1.size()-1,y=s2.size()-1;
    string t="";
    vector<pair<int,int>> e;
    cout<<s1<<endl<<s2<<endl;
    while(!(x==0&&y==0))
    {
        if(x>=0&&y>=0&&s1[x]==s2[y])
        {
            t+=s1[x];
            e.push_back({x,y});
            //cout<<x-1<<" "<<y-1<<" "<<s1[x-1]<<""<<s2[y-1]<<endl;
            x--;y--;
        }else
        {
            if(x>0&&lcs[x-1][y]>lcs[x][y-1])
                x--;
            else
                y--;
        }
        if(x==-1||y==-1)
            break;
    }
    sort(e.begin(),e.end());
    reverse(t.begin(),t.end());

    cout<<t<<endl;
    int now1=0,now2=0;
    int a=0,b=0,c=0;
    for(auto i:e)
    {
        //cout<<now1<<" "<<i.first-1<<endl;
        //cout<<now2<<" "<<i.second-1<<endl;
        //now1~i.first-1
        //now2~i.second-1;
        int t=abs((i.second-now2)-(i.first-now1));
        if(i.first-now1<i.second-now2)
        {
            //cout<<"y1"<<endl;
            b+=t;
            c+=(i.first-now1);
            ans+=t*4+(i.first-now1)*5;
        }else if(i.first-now1>i.second-now2)
        {
            //cout<<"y2"<<endl;
            a+=t;
            c+=(i.second-now2);
            ans+=t*3+(i.second-now2)*5;
        }else
        {
            //cout<<"y3"<<endl;
            c+=(i.second-now2);
            ans+=(i.second-now2)*5;
        }
        //cout<<ans<<endl<<endl;

        now1=i.first+1;
        now2=i.second+1;
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<ans;





}
