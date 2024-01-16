// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

// For ordered Tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

struct Node
{
    int parent;
    vi child;
    int val = -1;
    int s;
    int k;
};

vector<Node> graph;

int func(Node node1, Node node2)
{
    return node1.val > node2.val;
}

void f(int i)
{
    int z = graph[i].child.size();
    for (auto j : graph[i].child)
        graph[j].k += graph[i].k / z;

    for (int j = 0; j < graph[i].k % z; j++)
        graph[graph[i].child[j]].k++;

    for (auto j : graph[i].child)
        f(j);
}

void solve()
{

    int n, k;
    cin >> n >> k;

    graph = vector<Node>(n);
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        graph[i].parent = x;
        graph[x].child.push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> graph[i].s;

    set<int> leafs;
    for (int i = 0; i < n; i++)
    {
        if (graph[i].child.size() == 0)
            leafs.insert(i);
    }

    for (auto i : leafs)
    {
        int sum = 0;
        int num = i;
        while (num != 0)
        {
            sum += graph[num].s;
            num = graph[num].parent;
        }
        graph[i].val = sum;
    }

    for (auto i : leafs)
    {
        int num = i;
        while (num != 0)
        {
            int val = graph[num].val;
            num = graph[num].parent;
            graph[num].val = max(graph[num].val, val);
        }
    }
    for (int i = 0; i < n; i++)
        sort(graph[i].child.begin(), graph[i].child.end(), func);

    graph[0].k = 0;
    f(0);

    ll ans = 0;
    for (auto i : graph)
        ans += i.s * i.k;
    cout << ans << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
