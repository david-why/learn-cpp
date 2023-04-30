#include <bits/stdc++.h>

using namespace std;

#if __cplusplus >= 201103L
#define _constexpr constexpr
#else
#define _constexpr
#endif

typedef long long ll;

const int mod = 1e9 + 7;

template <size_t N, size_t M, ll mod = LLONG_MAX>
class matrix
{
    static_assert(N != 0 && M != 0, "Cannot have 0-sized matrices");
    typedef ll T;
    T arr[N][M];
    struct matrix_row
    {
        matrix &mat;
        size_t row;
        _constexpr matrix_row(matrix &m, size_t i) : mat(m), row(i) {}

    public:
        _constexpr T &operator[](size_t j) { return mat.get(row, j); }
        _constexpr const T &operator[](size_t j) const { return mat.get(row, j); }
    };

public:
    _constexpr matrix() : arr()
    {
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                arr[i][j] = 0;
    }
    _constexpr matrix(initializer_list<initializer_list<T>> lst) : arr()
    {
        const initializer_list<T> *dat = lst.begin();
        for (size_t i = 0; i < N; i++)
        {
            const T *ptr = dat[i].begin();
            for (size_t j = 0; j < M; j++)
                arr[i][j] = ptr[j];
        }
    }
    _constexpr matrix(vector<vector<T>> lst, int) : arr()
    {
        if (lst.size() != N || lst[0].size() != M)
            throw std::domain_error("Dimension mismatch");
        for (size_t i = 0; i < N; i++)
        {
            T *ptr = lst[i].data();
            for (size_t j = 0; j < M; j++)
                arr[i][j] = ptr[j];
        }
    }
    _constexpr static matrix identity()
    {
        static_assert(N == M, "Cannot have non-square identity matrices");
        matrix m;
        for (size_t i = 0; i < N; i++)
            m.get(i, i) = 1;
        return m;
    }
    _constexpr T &get(size_t i, size_t j) { return arr[i][j]; }
    _constexpr const T &get(size_t i, size_t j) const { return arr[i][j]; }
    _constexpr matrix_row operator[](size_t i) { return matrix_row{*this, i}; }
    _constexpr const matrix_row operator[](size_t i) const { return matrix_row{*this, i}; }
    _constexpr matrix operator+(T other) const
    {
        matrix<N, M> ret(*this);
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                (ret.get(i, j) += other) %= mod;
        return ret;
    }
    _constexpr matrix operator+(const matrix &other) const
    {
        matrix<N, M> ret(*this);
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                (ret.get(i, j) += other.get(i, j)) %= mod;
        return ret;
    }
    _constexpr matrix operator-() const
    {
        matrix<N, M> ret(*this);
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
            {
                T &val = ret.get(i, j);
                val = -val;
            }
        return ret;
    }
    _constexpr matrix operator-(T other) const { return *this + -other; }
    _constexpr matrix operator-(const matrix &other) const { return *this + -other; }
    _constexpr matrix operator*(T other) const
    {
        matrix<N, M> ret(*this);
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                (ret.get(i, j) *= other) %= mod;
        return ret;
    }
    template <size_t S>
    _constexpr matrix<N, S> operator*(const matrix<M, S> &other) const
    {
        matrix<N, S> ret;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < S; j++)
                for (size_t k = 0; k < M; k++)
                    (ret.get(i, j) += get(i, k) * other.get(k, j)) %= mod;
        return ret;
    }
    _constexpr matrix<N, M> operator^(size_t k) const
    {
        static_assert(N == M, "Cannot raise non-square matrix to a power");
        matrix ans = identity(), v = *this;
        while (k)
        {
            if (k & 1)
                ans = ans * v;
            v = v * v;
            k >>= 1;
        }
        return ans;
    }
};

int main()
{
    matrix<2, 2> A{{{1, 1}, {1, 0}}};
    ll n;
    while (cin >> n)
        cout << (A ^ n).get(0, 1) << endl;
    return 0;
}
