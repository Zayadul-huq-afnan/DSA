#problem link : https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5+10;
 
using ll = long long int;
 
char arr[1010][1010];
int visited[1010][1010];
 
int n,m;
 
void dfs(int i, int j)
{
    if(visited[i][j]==1)return;
    visited[i][j]=1;
 
    if(i-1>=0 && arr[i-1][j]!='#' && visited[i-1][j]!=1)
    {
        dfs(i-1,j);
    }
    if(i+1<n && arr[i+1][j]!='#' && visited[i+1][j]!=1)
    {
        dfs(i+1,j);
    }
 
    if(j-1>=0 && arr[i][j-1]!='#' && visited[i][j-1]!=1)
    {
        dfs(i,j-1);
    }
 
    if(j+1<m && arr[i][j+1]!='#' && visited[i][j+1]!=1)
    {
        dfs(i,j+1);
    }
}
 
int main()
{
 
    cin>>n>>m;
 
    for(int i=0; i<1010 ; i++)
    {
        for(int j=0 ; j<1010 ; j++)
        {
            visited[i][j]=0;
        }
    }
 
    for(int i=0; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cin>>arr[i][j];
        }
    }
 
    int ans=0;
 
    for(int i=0; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(arr[i][j]!='#' && visited[i][j]!=1)
            {
                dfs(i,j);
                ans++;
            }
        }
    }
 
 
   cout<<ans<<"\n";
 
}
