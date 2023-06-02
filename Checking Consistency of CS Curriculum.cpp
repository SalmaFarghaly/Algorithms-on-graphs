#include <iostream>
#include <vector>
using namespace std;

using std::vector;
using std::pair;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
#define rep(i, v)		for(int i=0;i<v.size();++i)

int explore(vii &adj,vi & vis,int x){
    vis[x] = 1;
    rep(i, adj[x]) {
        if (vis[adj[x][i]] == 0) {
            int res = explore(adj, vis, adj[x][i]);
            if (res) return 1;
        }
        else if (vis[adj[x][i]] == 1)
            return 1;
    }
    vis[x] = 2;
    return 0;
}

int acyclic(vector<vector<int> >& adj) {
    vi vis(adj.size(), 0);
    rep(i, adj) {
        if (!vis[i]) {
            int ans = explore(adj,vis,i);
            if (ans) return 1;
        }
    }
    return 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << acyclic(adj);
}
