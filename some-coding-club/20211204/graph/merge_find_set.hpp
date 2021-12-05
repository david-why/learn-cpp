#ifndef _DISJSET_HPP
#define _DISJSET_HPP
#include <map>
#include <set>
#include <type_traits>

template <typename tp, size_t N>
class mfset
{
    typename std::enable_if<std::is_integral<tp>::value, tp>::type par[N];
    size_t g;

public:
    inline mfset() : g(N)
    {
        for (tp i = 0; i < N; i++)
            par[i] = i;
    }

    inline tp find(tp k) const
    {
        return par[k] == k ? k : (par[k] = find(par[k]));
    }
    inline void merge(tp a, tp b)
    {
        tp x = find(a), y = find(b);
        if (x != y)
        {
            par[x] = y;
            g--;
        }
    }
    inline bool connected(tp a, tp b) const
    {
        return find(a) == find(b);
    }
    inline size_t groups() const
    {
        return g;
    }
};

template <typename tp>
class merge_find_set
{
    std::unordered_map<tp, tp> parent;
    inline void _ensure(const tp &k)
    {
        auto it = parent.find(k);
        if (it == parent.end())
            parent[k] = k;
    }

public:
    inline const tp &find(const tp &k)
    {
        auto it = parent.find(k);
        if (it->second == k)
            return k;
        else
            return (it->second = find(it->second));
    }
    inline void merge(const tp &a, const tp &b)
    {
        parent[find(a)] = find(b);
    }
    inline bool connected(const tp &a, const tp &b)
    {
        return find(a) == find(b);
    }
};
#endif