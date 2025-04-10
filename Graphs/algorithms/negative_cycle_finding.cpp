#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

vector<vector<ll>>adj;

ll track[5000][1];

bool check[5000];

ll bellman(ll src , ll node , ll vertex)
{
    ll dst[node+1];
    for(ll i=0 ; i<=node ; i++ )
    {
        dst[i]=1e17+10;
    }

    dst[src]=0;

    //cout<<track[1][0]<<endl;

    for(ll i=1 ; i<node ; i++)
    {
        for(ll j=0 ; j<vertex ; j++)
        {
            ll from = adj[j][0];
            ll to = adj[j][1];
            ll cst = adj[j][2];

            if((dst[from]+cst)<dst[to])
            {
                dst[to]=dst[from]+cst;
                track[to][0]=from;
            }
        }
    }

    for(ll i=1 ; i<2 ; i++)
    {
        for(ll j=0 ; j<vertex ; j++)
        {
            ll from = adj[j][0];
            ll to = adj[j][1];
            ll cst = adj[j][2];

            if(dst[from]+cst<dst[to])
            {
                track[to][0]=from;
               return from;
            }
        }
    }

    return -1;


}



int main()
{
    ll n,m;
     cin>>n>>m;
    for(ll i=0 ; i<m ; i++)
    {
        ll src,dst, cost;

        cin>>src>>dst>>cost;

        vector<ll>tmp;
        tmp.push_back(src);
        tmp.push_back(dst);
        tmp.push_back(cost);

        adj.push_back(tmp);
    }

    ll x= bellman(1,n,m);

//    for(int i=1 ; i<=n ; i++)
//    {
//        cout<<i<<" : "<<track[i][0]<<"\n";
//    }
//
//    cout<<x<<"\n";

    if(x==-1)
    {
        cout<<"NO"<<"\n";
    }
    else
    {

        vector<ll>ans;
        ll curr = x;

        ans.push_back(curr);

        check[curr]=1;

        ll nxt = track[curr][0];



        while(nxt!=curr)
        {
           // cout<<"x"<<"\n";
            ans.push_back(nxt);
            check[nxt]=1;
            ll y=track[nxt][0];
            nxt= y;

            if(check[nxt]==1)
            {
                curr=nxt;
                break;
            }


        }

        ans.push_back(curr);

        //sort(ans.begin() , ans.end());

        cout<<"YES"<<"\n";

        for(ll i= ans.size()-1 ; i>=0 ; i--)
        {
            cout<<ans[i]<<" ";

            if(ans[i]==ans[ans.size()-1] && i!=ans.size()-1)
            {
                break;
            }
        }
        cout<<"\n";
    }
}
