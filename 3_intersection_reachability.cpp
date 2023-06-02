#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
#define rep(i, v)		for(int i=0;i<v.size();++i)

// Based on the following conclusions:
// 1) The vertex with largest postOrder in graph G is in source component
// 2) The source SCC in G is sink in reverse G
// 3) G and reverse G has the same SCC
// 4) Exploring v in sink G gives us the SCC of v

void explore(vii & adj, vi & vis,int x,int& st) {
    vis[x] = ++st;
    rep(i, adj[x]) {
        if (vis[adj[x][i]] == 0)
            explore(adj,vis,adj[x][i],st);
    }
    vis[x] = ++st;
}

int number_of_strongly_connected_components(vii& adj,vii& revAdj) {
    int st = 0;
    vi vis(adj.size(),0);
    // Loop over reverse graph to get the postOrder
    rep(i,revAdj) {
        if (vis[i] == 0) {
            explore(revAdj,vis,i,st);
        }
    }
 
    // Run DFS on largest postOrder to find sink SCC of graph
    int result = 0;
    vi vis2(adj.size(), 0);
    while (true) {
        int idx = max_element(vis.begin(), vis.end()) - vis.begin();
        if (vis[idx] == -1) // Means we have explored all the SCC
            break; 
        if (vis2[idx] == 0) {
            explore(adj, vis2, idx, st);
            result++;
        }
        vis[idx] = -1; // To mark its removal from the graph
    }
    return result;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > revAdj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        revAdj[y - 1].push_back(x-1);
    }
    std::cout << number_of_strongly_connected_components(adj,revAdj);
}
