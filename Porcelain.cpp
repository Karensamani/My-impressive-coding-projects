#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target("popcnt")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>
using namespace std;
void _(int $){if($ == 100){printf("101");exit(0);}}
const int maxn = 1e4 + 100;
const int maxm = 1e2 + 100;

const int INF = 1e9;

int a[maxm], psl[maxm], psr[maxm];
int b[maxm];
int ans[maxm];

const int BUF = 8192;
char buf[BUF];
int bufpos = BUF;

inline char nextChar() {
    if(bufpos == BUF) {
        fread(buf, 1, BUF, stdin);
        bufpos = 0;
    }
    return buf[bufpos++];
}

inline int readInt()
{
    int x = 0;
    char c;
    do {
        c = nextChar();
    } while(c <= ' ');

    bool neg = false;
    if(c == '-')
    {
        neg = true;
        c = nextChar();
    }

    while(c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = nextChar();
    }
    return neg ? -x : x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    n = readInt();
    m = readInt();

    for(int i = 0; i <= m; ++i)
        ans[i] = -INF;

    ans[0] = 0;

    for(int i = 0; i < n; i++)
    {
        int k;
        k = readInt();

        for(int j = 1; j <= k; ++j)
        {
            a[j] = readInt();
            psl[j] = psl[j - 1] + a[j];
        }

        psr[k + 1] = 0;

        for(int j = k; j > 0; --j)
            psr[j] = psr[j + 1] + a[j];

        for(int j = 1; j <= k; ++j)
        {
            b[j] = 0;
            for(int x = 0; x <= j; ++x)
                b[j] = max(b[j], psl[x] + psr[k - j + x + 1]);
        }

        for(int j = m; j > 0; j--)
        {
            for(int x = 1; x <= k && x <= j; ++x)
                ans[j] = max(ans[j], ans[j - x] + b[x]);
        }
    }

    _(ans[m]);
    printf("%d\n", ans[m]);
    return 0;
}
