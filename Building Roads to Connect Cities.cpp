#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>

using namespace std;

#define rep(i, v)		for(int i=0;i<v.size();++i)
#define repStart(i, st ,v)		for(int j=st;i<v.size();++i)
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;

bool sortByVal(const pair<pair<int,int>, double> &a,
    const pair<pair<int, int>, double> &b)
{
    return (a.second < b.second);
}

class DisjointSet { //to represent disjoint set
    unordered_map<int, int> parent;
public:
    void makeSet(vector<int> const& wholeset) {
        //perform makeset operation
        for (int i : wholeset) // create n disjoint sets
            parent[i] = i;
    }
    int Find(int l) { // Find the root of the set in which element l belongs
        if (parent[l] == l) // if l is root
            return l;
        return Find(parent[l]); // recurs for parent till we find root
    }
    void Union(int m, int n) { // perform Union of two subsets m and n  
        int x = Find(m);
        int y = Find(n);
        parent[x] = y;
    }
};

double minimum_distance(vector<int> x, vector<int> y) {
    double result = 0.;
    vector<pair<pair<int, int>, double>> cost;
    vector<double> edges;
    rep(i, x) {
        repStart(j, i+1 ,x) {
            double dist = pow(x[i] - x[j], 2.0) + pow(y[i] - y[j], 2.0);
            cost.push_back(make_pair(make_pair(i,j), sqrt(dist)));
        }
    }
    sort(cost.begin(), cost.end(), sortByVal);
    DisjointSet set;
    vi vertcies(x.size(), 0);
    rep(i, vertcies) {
        vertcies[i] = i;
    }
    set.makeSet(vertcies);
    for (auto i : cost){
        int f1 = set.Find(i.first.first);
        int f2 = set.Find(i.first.second);
        if (set.Find(i.first.first) != set.Find(i.first.second)) {
            set.Union(i.first.first,i.first.second);
            result += i.second;
        }
    }
    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
