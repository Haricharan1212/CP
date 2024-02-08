#include<bits/stdc++.h>
using namespace std;
#define n {cout<<"NO"<<endl;return 0;}
#define l char
map<l,l>m={{'(',')'},{'{','}'},{'[',']'},{'<','>'}};
int main(){string s;cin>>s;vector<l>a;for(l c:s){if(m[c])a.push_back(c);else{if(!a.size())n l t=a.back();if(c==m[t])a.pop_back();else n}}if(a.size()==0)cout<<"YES";else n}