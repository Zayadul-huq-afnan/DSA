#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> adj[N];

bool visited[N];

void bfs(int node){

    queue<int>q;
    visited[node] = true;
    q.push(node);

    while(!q.empty()){

        int curr_node = q.front();
        q.pop();

        for(int v : adj[curr_node]){

            if(visited[v])continue;

            visited[v] = true;
            q.push(v);
        }
    }

}

