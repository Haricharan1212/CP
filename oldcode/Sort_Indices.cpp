#include <bits/stdc++.h>
using namespace std;
int main(){int t,n;cin>>t;while(t--){cin>>n;vector<pair<int,int>>a(n);for(int i=0;i<n;i++)cin>>a[i].first,a[i].second=i;sort(a.begin(),a.end());for(auto i:a)cout<<i.second<<'\n';}}