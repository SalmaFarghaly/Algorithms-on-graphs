#include <iostream>
#include <vector>
#include <queue>
#include<climits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

#define rep(i, v)		for(int i=0;i<v.size();++i)
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;

int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost) {
    vll dist(adj.size(),INT_MAX);
    int changed = false;
    dist[0] = 0;
    for (int i = 0; i <= adj.size();i++) {
        changed = false;
        // loop over edges
        rep(j, adj) {
            rep(k, adj[j]) {
                if (dist[adj[j][k]] > dist[j] + cost[j][k]) {
                    dist[adj[j][k]] = dist[j] + cost[j][k];
                    changed = true;
                }
            }
        }
    }
    return (changed == true);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cout << negative_cycle(adj, cost);
}