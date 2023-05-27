#include <iostream>
#include <vector>

using std::vector;
using std::pair;

#define rep(i, v)		for(int i=0;i<v.size();++i)

bool explore(vector<vector<int> >& adj,vector<int> vis, int x,int y) {
    vis[x] = 1;
    rep(i, adj[x]) {
        if (adj[x][i] == y)
            return true;
        if (vis[adj[x][i]] == 0 && explore(adj, vis, adj[x][i], y)) {
            return true;
        }
    }
    return false;
}

int reach(vector<vector<int> >& adj, int x, int y) {
    vector<int> vis(adj.size(),0);
    return explore(adj,vis,x,y);
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1);
}
