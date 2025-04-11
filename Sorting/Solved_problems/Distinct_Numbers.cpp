#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
/// adj list
 
 
using ll= long long int;
 
 
int main(){
 
    ll n;
    cin>>n;
 
    map<ll,bool>m;
    vector<ll>v;
    for(int i=0 ; i<n ; i++)
    {
        int x;
        cin>>x;
        v.pb(x);
        m[x]=false;
    }
    ll ans=0;
    for(ll i=0 ; i<n; i++)
    {
        ll x = v[i];
 
        if(m[x]==false)
        {
            m[x]=true;
            ans++;
        }
    }
 
    cout<<ans<<"\n";
 
    return 0;
}
Share code to others
Test details
Test 1
Verdict: ACCEPTED

