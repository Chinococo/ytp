#include<bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
   int n1,n2,n3;
   cin>>n1>>n2>>n3;


   if(n1*((n2*n3)/(n1-n2))>=0)
       cout<<n1*((n2*n3)/(n1-n2));
   else
       cout<<"None";
}
