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


void shortest_paths(vector<vector<int> >& adj, vector<vector<int> >& cost, int s, vector<long long>& distance, 
                    vector<int>& reachable, vector<int>& shortest) {
    distance[s] = 0, reachable[s] = 1;
    for (int i = 0; i <= adj.size(); i++) {
        // loop over edges
        rep(j, adj) {
            rep(k, adj[j]) {
                if (reachable[j] && distance[adj[j][k]] > distance[j] + cost[j][k]) {
                    distance[adj[j][k]] = distance[j] + cost[j][k];
                    reachable[adj[j][k]] = 1;
                    if (i == adj.size()) {
                        // Some node has changed (i.e There is negative cycle)
                        // And we need to find the nodes that are reachable from it
                        shortest[adj[j][k]] = 0;
                    }
                }
            }
        }
    }
    queue<int> qu;
    rep(i, shortest) {
        if(!shortest[i])
            qu.push(i);
    }
    while (!qu.empty()) {
        int top = qu.front();
        shortest[top] = 0;
        rep(i, adj[top]) {
            if (shortest[adj[top][i]])
                qu.push(adj[top][i]);
        }
        qu.pop();
    }
}

int main() {
    int n, m, s;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cin >> s;
    s--;
    vector<long long> distance(n, INT_MAX);
    vector<int> reachable(n, 0);
    vector<int> shortest(n, 1);
    shortest_paths(adj, cost, s, distance, reachable, shortest);
    for (int i = 0; i < n; i++) {
        if (!reachable[i]) {
            std::cout << "*\n";
        }
        else if (!shortest[i]) {
            std::cout << "-\n";
        }
        else {
            std::cout << distance[i] << "\n";
        }
    }
}