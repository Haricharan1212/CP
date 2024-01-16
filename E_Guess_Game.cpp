// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

const int mx = 32;

int check(int a, int b)
{
    string sa = bitset<mx>((unsigned int)a).to_string();
    string sb = bitset<mx>((unsigned int)b).to_string();
    int turn = 1;
    int moves = 0;
    rep(i, 0, mx)
    {
        if (sa[i] == '0' && sb[i] == '0')
        {
            continue;
        }
        else if (sa[i] == '1' && sb[i] == '1')
        {
            if (turn == 1)
            {
                moves += 1;
                turn = 2;
            }
            else
            {
                moves += 1;
                turn = 2;
            }
        }
        else if (sa[i] == '1' && sb[i] == '0')
        {
            if (turn == 1)
            {
                moves += 2;
            }
            else
            {
                moves += 1;
                turn = 1;
            }

            return moves;
        }
        else if (sa[i] == '0' && sb[i] == '1')
        {
            if (turn == 1)
            {
                // a can see a zero, so he can tell in one move
                moves += 1;
                turn = 2;
            }
            else
            {
                moves += 2;
            }

            return moves;
        }
    }

    return moves + 1;
}

int checkvec(vi &a, int b)
{
    string sa = bitset<mx>((unsigned int)b).to_string();

    int moves = 0;

    for (auto i : a)
    {
        moves += check(i, b);
    }

    return moves;
}

const int mod = 998244353;

int modexp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

int modinv(int a)
{
    return modexp(a, mod - 2);
}

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}

template <typename T = int, int LOG = mx>
struct Trie
{

    struct Node
    {

        Node *child[2];
        int freq;

        Node()
        {
            memset(child, 0, sizeof(child));
            freq = 0;
        }
    };

    Node *root;

    Trie()
    {
        root = new Node;
    }

    void insert(const T &x)
    {
        Node *curr = root;
        for (int bit = LOG; bit >= 0; --bit)
        {
            int bit_val = (x >> bit) & 1;
            if (!curr->child[bit_val])
                curr->child[bit_val] = new Node;
            curr = curr->child[bit_val];
            ++curr->freq;
        }
    }

    int search(const T &x)
    {
        int ans = 0;
        int setbits = 0;

        Node *curr = root;

        for (int bit = LOG; bit >= 0; --bit)
        {
            int bit_val = (x >> bit) & 1;

            if (!curr->child[bit_val])
                return ans;

            // 1 0 case
            if (bit_val == 1)
            {
                int zero = curr->child[0] ? curr->child[0]->freq : 0;
                ans += zero * (1 + setbits + (setbits % 2 == 0));

                setbits++;
            }
            else
            {
                int one = curr->child[1] ? curr->child[1]->freq : 0;
                ans += one * (1 + setbits + (setbits % 2 == 1));
            }

            curr = curr->child[bit_val];

        }

        int freq = curr->freq;
        ans = ans + freq * (setbits + 1);
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    Trie<int, 32> t = Trie <int, 32> ();

    rep(i, 0, n)
    {
        t.insert(a[i]);
    }

    int ans = 0;
    rep(i, 0, n)
    {
        ans += t.search(a[i]);
    }

    // int sum = 0;

    // for (auto i : a)
    //     for (auto j : a)
    //     {
    //         cout << check(i, j) << ' ';
    //         sum += check(i, j);
    //     }

    int f = ans;
    int g = n * n;
    int d = __gcd (f, g);
    f /= d;
    g /= d;
    f %= mod;
    g %= mod;

    ans = (f * modinv(g)) % mod;

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}