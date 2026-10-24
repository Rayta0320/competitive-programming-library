#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(n, i) for (int i = (n-1); i>0; --i)
using ll = long long;
using P = pair<int, int>;
using PLL = pair<ll, ll>;
//using namespace atcoder;
const int INF = 1001001001;
const ll LINF = (1LL << 60);
const ll MOD = 998244353;
//using mint = modint998244353;
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

// Combination<mint> comb(n);
// comb.C(n, r);
template<class Mint>
struct CombMod{
    vector<Mint> fact, ifact;

    CombMod(int n){
        fact.resize(n+1);
        ifact.resize(n+1);
        fact[0] = 1;
        //factorial calculation
        for(int i = 1; i <= n; i++){
            fact[i] = fact[i-1] * i;
        }
        // 1 / n!
        ifact[n] = fact[n].inv();
        // 1 / i!
        for (int i = n; i >= 1; i--){
            ifact[i-1] = ifact[i] * i;
        }
    }
    Mint C(int n, int r){
        if (r < 0 || r > n) return 0;
        // n! / (r!*(n-r)!)
        return fact[n] * ifact[r] * ifact[n-r];
    }
};

//CombinationInt<ll / int> combint;
//combint.C(n, r);
template<class T>
struct CombInt{
    T C(T n, T r){
        if (r < 0 || r > n) return 0;
        r = min(r, n-r);
        T res = 1;
        for (T i = 1; i <= r; i++){
            res *= (n-i+1);
            res /= i;
        }
        return res;
    }
};

//geometry
vector<int> vec(int x1, int y1, int x2, int y2){
    return {x2 - x1, y2-y1};
}

int dot_product(vector<int> v1, vector<int> v2){
    return v1[0] * v2[0] + v1[1] * v2[1];
}

double eucdis(vector<int> v){
    return sqrt(v[0] * v[0] + v[1] * v[1]);
}

int cross_product(vector<int> v1, vector<int> v2){
    return v1[0] * v2[1] - v1[1] * v2[0];
}
