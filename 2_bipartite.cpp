#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
#define rep(i, v)		for(int i=0;i<v.size();++i)

int bipartite(vector<vector<int> > &adj) {
    vi bi(adj.size(),-1);
    rep(j, adj) {
        if (bi[j] != -1)
            continue;
        int src = j;
        queue<int> qu;
        qu.push(src);
        bi[src] = 0;
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            rep(i, adj[cur]) {
                if (bi[cur] == bi[adj[cur][i]])
                    return 0;
                if (bi[adj[cur][i]] == -1) {
                    bi[adj[cur][i]] = 1 - bi[cur];
                    qu.push(adj[cur][i]);
                }
            }
        }
    }
    return 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << bipartite(adj);
}
