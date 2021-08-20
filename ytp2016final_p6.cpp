#include<bits/stdc++.h>

#define int long long
using namespace std;

vector<string> ans;
int n;
int check[10];
void s(string data)
{
    if(data.size()==n)
    {
        ans.push_back(data);
        return;
    }
    for(int i=0;i<n;i++)
        if(!check[i])
        {
            check[i]=1;
            s(data+(char )('A'+i));
            check[i]=0;
        }

}
signed main() {
    cin>>n;
   s("");
   for(auto  t:ans)
       cout<<t<<endl;
}
