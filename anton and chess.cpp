#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2, typename T3>
struct triple
{
    T1 first;
    T2 second;
    T3 third;
    triple(T1 f, T2 s, T3 t) : first(f), second(s), third(t) {}

    bool operator <(const triple& o) const
    {
        if(first != o.first)
            return first < o.first;
        if(second != o.second)
            return second < o.second;
        return third < o.third;
    }
};

template <typename T1, typename T2, typename T3>
triple<T1, T2, T3> make_triple(T1 a, T2 b, T3 c)
{
    return triple<T1, T2, T3> (a, b, c);
}

int main()
{
    int n;
    int king_x, king_y;
    cin >> n >> king_x >> king_y;

    vector<triple<char, int, int>> Black_pieces;

    for(int i = 0; i < n; ++i)
    {
        char s;
        int x, y;
        cin >> s >> x >> y;
        Black_pieces.push_back(make_triple(s, x, y));
    }

    vector<pair <char, long long>> closest(8, {' ', LLONG_MAX});
    //ino LLONG_MAX o to internet didam doctor ha

    for(int i = 0; i < n; ++i)
    {
        char piece = Black_pieces[i].first;
        int x = Black_pieces[i].second;
        int y = Black_pieces[i].third;

        if(x == king_x)
        {
            if(y > king_y)
            {
                long long dist = abs(y - king_y);
                if(dist < closest[0].second)
                    closest[0] = {piece, dist};
            }
            else if(y < king_y)
            {
                long long dist = abs(y - king_y);
                if(dist < closest[1].second)
                    closest[1] = {piece, dist};
            }
        }
        else if(y == king_y)
        {
            if(x > king_x)
            {
                long long dist = abs(x - king_x);
                if(dist < closest[3].second)
                    closest[3] = {piece, dist};
            }

            else if(x < king_x)
            {
                long long dist = abs(x - king_x);
                if(dist < closest[2].second)
                    closest[2] = {piece, dist};
            }
        }
        else if(abs(x - king_x) == abs(y - king_y))
        {
            long long dist = abs(x - king_x);

            if(x > king_x && y > king_y)
            {
                if(dist < closest[4].second)
                    closest[4] = {piece, dist};
            }
            else if(x < king_x && y > king_y)
            {
                if(dist < closest[5].second)
                    closest[5] = {piece, dist};
            }
            else if(x > king_x && y < king_y)
            {
                if(dist < closest[6].second)
                    closest[6] = {piece, dist};
            }
            else if(x < king_x && y < king_y)
            {
                if(dist < closest[7].second)
                    closest[7] = {piece, dist};
            }
        }
    }


    bool valid = false;
    for(int i = 0; i < 8; ++i)
    {
        char piece = closest[i].first;
        if(piece == ' ') continue;

        if(i < 4)
        {
            if(piece == 'R' || piece == 'Q')
                valid = true;
        }
        else
        {
            if(piece == 'B' || piece == 'Q')
                valid = true;
        }
    }

    if(valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
