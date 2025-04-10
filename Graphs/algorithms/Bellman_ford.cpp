#include<bits/stdc++.h>

using namespace std;

using ll=long long int;
const int nmax= 2510;

ll dst[nmax];
vector<vector<ll>>adj; //from, to , cost
ll check[nmax];
bool bell(ll source, ll node, ll vertex)
{
    for(int i=0 ; i<nmax ; i++)
    {
        dst[i]= 1e18+10;

        check[i]=-1;
    }


    dst[source]=0;


    for(int i=1 ; i<node ; i++)
    {

            for(int j=0 ; j<vertex  ; j++)
        {
            ll from= adj[j][0];
            ll to = adj[j][1];
            ll cost = adj[j][2];

             if(dst[from]!=(-1e18+10) && dst[from]+cost < dst[to])
            {
                 dst[to]=dst[from]+cost;
            }



        }
    }

    bool flag = true;
    //iterate one more time to check if there is negative weighted cycle

        for(int i=1 ; i <= 1 ; i++)
    {

            for(int j=0 ; j<vertex  ; j++)
        {
            ll from= adj[j][0];
            ll to = adj[j][1];
            ll cost = adj[j][2];

             if(dst[from]!=(-1e18+10) && dst[from]+cost < dst[to])
            {
                 flag = false;
                 return flag;
            }



        }
    }

    return flag;
}

int main()
{
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

     ll n,m;

     cin>>n>>m;

     for(int i=0 ; i< m ; i++)
     {
         ll u,v,w;
         cin>>u>>v>>w;

         vector<ll>tmp;

         tmp.push_back(u);
         tmp.push_back(v);
         tmp.push_back(w);

         adj.push_back(tmp);

     }

    // sort(adj.begin(),adj.end());

     bool a=bell(1,n,m);

     //cout<<"a: "<<a<<"\n";

     if(!a)
     {
         cout<<-1<<"\n";
     }
     else
     {
         cout<<dst[n]<<"\n";
     }


}

