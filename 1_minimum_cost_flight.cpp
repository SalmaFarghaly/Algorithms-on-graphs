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

class myComp
{
public:
    bool operator()(pair<int, ll> n1, pair<int, ll> n2) {
        return n1.second > n2.second;
    }
};

long long distance(vii& adj, vii& cost, int s, int t) {
    priority_queue<pair<int,ll>,vector<pair<int,ll>>,myComp> pq;
    vll dist(adj.size(),LLONG_MAX);
    dist[s] = 0;
    vi visted(adj.size(), 0);
    pq.push(pair<int,ll>(s,dist[s]));
    while (!pq.empty()) {
        int cur = pq.top().first;
        if (!visted[cur]) {
            visted[cur] = 1;
            if (cur == t)
                break;
            ll c = pq.top().second;
            rep(i, adj[cur]) {
                if (dist[adj[cur][i]] > c + cost[cur][i]) {
                    dist[adj[cur][i]] = c + cost[cur][i];
                    pq.push(pair<int, ll>(adj[cur][i], dist[adj[cur][i]]));
                }
            }
        }
        pq.pop();
    }
    return (dist[t] != LLONG_MAX) ? dist[t] : -1;
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
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}
