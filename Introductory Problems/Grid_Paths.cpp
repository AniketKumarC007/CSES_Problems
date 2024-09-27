#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define I_am_speed()                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vec vector<ll>
#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;
#define loop(x, start, end) for (int x = start; x < end; ++x)
#define all(v) v.begin(), v.end()
#define here(i) cout << " here " << i << endl;

class DSU
{
    vector<int> parent;
    vector<int> subtree_size;
    int N;

public:
    DSU(int n)
    {
        N = n;
        parent = vector<int>(n + 1, 0);
        subtree_size = vector<int>(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int findRoot(int u)
    {
        while (u != parent[u])
        {
            parent[u] = parent[parent[u]]; // Path compression
            u = parent[u];
        }
        return u;
    }
    void combine(int u, int v)
    {
        int ru = findRoot(u);
        int rv = findRoot(v);
        if (ru == rv)
            return;
        if (subtree_size[ru] > subtree_size[rv])
        {
            parent[rv] = ru;
            subtree_size[ru] += subtree_size[rv];
        }
        else
        {
            parent[ru] = rv;
            subtree_size[rv] += subtree_size[ru];
        }
    }
};
void print(vi &v)
{
    int n = v.size();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}
void print(vvi &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
bool check(int i, int j, vvi &vis)
{
    if (i >= 0 && i < 7 && j >= 0 && j < 7 && (vis[i][j]) )
        return true;
    return false;
}
void f(int i, int j, int index, vvi &vis, string &s, int &count)
{
    // cout << "HERE" << endl ;

    if (index == s.length() && i == 6 && j == 0)
    {
        count++;
    }
    else if (index == s.length())
    {
        return;
    }
    vis[i][j] = 1;

    if (s[index] == '?')
    {

    
        if (check(i + 1, j, vis) )
        {
            f(i + 1, j, index + 1, vis, s, count);
        }
        if (check(i - 1, j, vis) )
        {
            f(i - 1, j, index + 1, vis, s, count);
        }
        if (check(i, j + 1, vis) )
        {
            f(i, j + 1, index + 1, vis, s, count);
        }
        if (check(i, j - 1, vis) )
        {
            f(i, j - 1, index + 1, vis, s, count);
        }
    }
    else if (s[index] == 'D')
    {
        if (check(i + 1, j, vis) )
        {
            f(i + 1, j, index + 1, vis, s, count);
        }

    }
    else if (s[index] == 'U')
    {
        if (check(i - 1, j, vis) )
        {
            f(i - 1, j, index + 1, vis, s, count);
        }
    }
    else if (s[index] == 'R')
    {
        if (check(i, j + 1, vis) )
        {
            f(i, j + 1, index + 1, vis, s, count);
        }
    }
    else if (s[index] == 'L')
    {
         if (check(i, j - 1, vis) )
        {
            f(i, j - 1, index + 1, vis, s, count);
        }
    }

    vis[i][j] = -1;

    return;
}
void solve()
{
    string s;
    cin >> s;
    vvi vis(7, vi(7, -1));
    int i = 0, j = 0;
    int index = 0;
    int count  = 0 ;
    f(0,0,0, vis ,s, count) ;
    cout <<count <<endl;
}
int32_t main()
{
    I_am_speed();

    solve();

    return 0;
}