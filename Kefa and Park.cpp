/*

Kefa decided to celebrate his first big salary by going to the restaurant.

He lives by an unusual park. The park is a rooted tree consisting of n vertices with the root at vertex 1. Vertex 1 also contains Kefa's house. Unfortunaely for our hero, the park also contains cats. Kefa has already found out what are the vertices with cats in them.

The leaf vertices of the park contain restaurants. Kefa wants to choose a restaurant where he will go, but unfortunately he is very afraid of cats, so there is no way he will go to the restaurant if the path from the restaurant to his house contains more than m consecutive vertices with cats.

Your task is to help Kefa count the number of restaurants where he can go.


Input

The first line contains two integers, n and m (2 ≤ n ≤ 105, 1 ≤ m ≤ n) — the number of vertices of the tree and the maximum number of consecutive vertices with cats that is still ok for Kefa.

The second line contains n integers a 1, a 2, ..., a n, where each a i either equals to 0 (then vertex i has no cat), or equals to 1 (then vertex i has a cat).

Next n - 1 lines contains the edges of the tree in the format " x i y i" (without the quotes) (1 ≤ x i, y i ≤ n, x i ≠ y i), where x i and y i are the vertices of the tree, connected by an edge.

It is guaranteed that the given set of edges specifies a tree.


Output

A single integer — the number of distinct leaves of a tree the path to which from Kefa's home contains at most m consecutive vertices with cats.

INPUT
4 1
1 1 0 0
1 2
1 3
1 4

OUTPUT
2
*/

    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define Size 100010
    vector<ll> adj[Size];
    bool vis[Size];
    ll n,m,total=0;
    ll cc[Size];
     
    void dfs(ll s,ll sum)
    {
        if(vis[s])
            return;
     
        vis[s]=1;
     
        if(cc[s])
            sum++;
        else
            sum=0;
     
        if(sum>m)
            return;
     
        if(s!=1 && adj[s].size()==1)
        {
            total++;
        }
     
        for(int i=0;i<adj[s].size();i++)
        {
            dfs(adj[s][i],sum);
        }
    }
     
    int main()
    {
     
        ll i,j,k;
        ll u,v;
     
        memset(vis,0,sizeof(vis));
     
        cin>>n>>m;
     
        for(i=1;i<=n;i++)
            cin>>cc[i];
     
        for(i=0;i<n-1;i++)
        {
            cin>>u>>v;
     
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
     
        dfs(1,0);
     
        cout<<total;
     
        return 0;
    }