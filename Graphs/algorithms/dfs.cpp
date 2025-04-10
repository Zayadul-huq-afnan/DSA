#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> adj[N];

bool visited[N];


void dfs(int node){

    visited[node] = true;

    for(int x : adj[node]){

        if(visited[x]) continue;

        dfs(x);
    }

}

