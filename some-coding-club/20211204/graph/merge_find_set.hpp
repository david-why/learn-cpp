#ifndef _DISJSET_HPP
#define _DISJSET_HPP
#include <map>
#include <set>
#include <type_traits>

template <typename KeyType, size_t N>
class sized_merge_find_set
{
    typedef typename std::enable_if<std::is_integral<KeyType>::value>::type _IsIntegral;
    KeyType par[N];
};

template <typename KeyType>
class merge_find_set
{
    std::map<KeyType, KeyType> parent;
    inline void _ensure(const KeyType &k)
    {
        auto it = parent.find(k);
        if (it == parent.end())
            parent[k] = k;
    }

    inline const KeyType &_find(const KeyType &k)
    {
        auto it = parent.find(k);
        if (it->second == k)
            return k;
        else
            return (it->second = _find(it->second));
    }

public:
    inline void connect(const KeyType &a, const KeyType &b)
    {
        parent[_find(a)] = _find(b);
    }

    inline bool connected(const KeyType &a, const KeyType &b)
    {
        return _find(a) == _find(b);
    }
};
#endif