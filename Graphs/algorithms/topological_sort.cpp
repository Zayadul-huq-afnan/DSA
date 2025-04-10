#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
    vector<int>adj[100000];
vector<int> topologicalSort(map<int,int>&m , int &n)
{
//    vector<vector<int>> adj=j;
//    int n=l;
//
//    map<int,int>mp;
//
//    for(int i=1 ; i<=n ; i++)
//    {
//        mp[i]=0;
//    }

    queue<int>q;

    for(int i=1 ; i<=n ; i++)
    {
        if(m[i]==0)
        {
            q.push(i); //pushing node with 0 in-degree in queue
        }
    }

    vector<int>ans;

    while(!q.empty())
    {
        int x =q.front();
        q.pop();
        ans.push_back(x);
        for(int tre : adj[x])
        {
            m[tre]--;

            if(m[tre]==0)
            {
                q.push(tre);
            }
        }
    }

   return ans;

}




int main()
{
    int n,ver;
    cin>>n>>ver;

    map<int,int>m;

    for(int i=1 ; i<=n ; i++)
    {
        m[i]=0; //initializing in-degree 0
    }

    for(int i=0 ; i<ver ; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        m[v]++;

    }



  vector<int> result= topologicalSort(m,n);

   if(result.size()!=n)
   {
       cout<<"cycle";
   }
   else
   {
       //valid topological ordering
       for(auto x:result)
       {
           cout<<x<<" ";
       }
       cout<<"\n";
   }
}
