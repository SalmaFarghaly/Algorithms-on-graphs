#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> >& adj, vector<int>& vis, int x) {
    vis[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        if (vis[adj[x][i]] == 0) {
            explore(adj,vis,adj[x][i]);
        }
    }
}

int number_of_components(vector<vector<int> >& adj) {
    int res = 0;
    vector<int> vis(adj.size(),0);
    for (int i = 0; i < adj.size(); i++) {
        if (vis[i] == 0) {
            explore(adj,vis,i);
            res++;
        }
    }
    return res;
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
    std::cout << number_of_components(adj);
}
