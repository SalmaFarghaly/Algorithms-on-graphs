#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
#define rep(i, v)		for(int i=0;i<v.size();++i)

int distance(vector<vector<int> >& adj, int s, int t) {
    vi dist(adj.size(), -1);
    dist[s] = 0;
    queue<int> qu;
    qu.push(s);
    int found = false;
    while (!qu.empty() && !found) {
        int cur = qu.front();
        qu.pop();
        rep(i, adj[cur]) {
            if (dist[adj[cur][i]] == -1) {
                dist[adj[cur][i]] = dist[cur] + 1;
                if (adj[cur][i] == t) {
                    found = true;
                    break;
                }
                qu.push(adj[cur][i]);
            }
        }
    }
    return dist[t];
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
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
