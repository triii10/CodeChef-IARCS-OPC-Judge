/*
--------------------------------
- AUTHOR : Trilok Bhattacharya -
- EMAIL : triii.10@outlook.com -
- DATE : 04 Oct, 2020          -
--------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// <-- Template code for utility -->
#define watch(x) cout << (#x) << " is " << (x) << endl
#define forl(i, b, e) for (i = b; i < e; i++)
#define fore(i, b, e) for (i = b; i <= e; i++)

void input_arr(vector<int> &arr, int n)
{
    int i;
    forl(i, 0, n)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
}

template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    bool first = true;
    os << "[";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::set<T> &v)
{
    bool first = true;
    os << "[";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}

template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::map<T1, T2> &v)
{
    bool first = true;
    os << "[";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}

// <-- Main funtion -->
// This is where the actual program is

int main(int argc, char *argv[])
{
    // <-- Fast I/O -->
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // <-- Multiple test cases -->
    // cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        vector<int> price;
        input_arr(price, n);

        vector<int> prev(n, 0), curr;
        int i, j;
        fore(i, 1, k) {
            curr.push_back(0);
            int end_here;
            forl(end_here, 1, n) {
                int start_here = end_here-1;
                int previous_profit = curr[end_here-1];
                int current_profit = 0;
                while(start_here >= 0) {
                    current_profit = max(current_profit, (price[end_here]  - price[start_here] > 0 ? price[end_here] - price[start_here] : 0) + (start_here-1 >= 0 ? prev[start_here-1] : 0));
                    start_here--;
                }
                curr.push_back(max(previous_profit, current_profit));
            }
            prev = curr;
            curr.clear();
        }
        cout<<curr[n-1];
        cout<<'\n';
    }
    return 0;
}