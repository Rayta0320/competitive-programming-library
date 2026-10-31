#include <bits/stdc++.h>
using namespace std;
//https://github.com/atcoder/ac-library
#include <atcoder/all>
using namespace atcoder;

//https://github.com/Rayta0320/competitive-programming-library
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(n, i) for (int i = (n-1); i>=0; --i)
#define reps(i, n, s) for (int i = s; i<n; ++i)
using ll = long long;
using P = pair<int, int>;
using PLL = pair<ll, ll>;
using PL = pair<ll, int>;
const int INF = 1001001001;
const ll LINF = (1LL << 60);
const ll MOD = 998244353;
using mint = modint998244353;
using mint2 = modint1000000007;
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

// CombMod<mint> combmod;
// combmod.C(n, r);
template<class Mint>
struct CombMod{
    vector<Mint> fact, ifact;

    CombMod(){
        fact = {1};
        ifact = {1};
    }
    
    void ensure(int n){
        int old = (int)fact.size() - 1;
        if (old >= n) return;

        fact.resize(n+1);
        //factorial calculation
        for (int i = old + 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;

        }

        ifact.resize(n+1);
        // 1 / n!
        ifact[n] = fact[n].inv();
        // 1 / i!
        for (int i = n; i > old; i--) {
            ifact[i - 1] = ifact[i] * i;
        }
    }
    Mint C(int n, int r){
        if (n < 0 || r < 0 || r > n) return 0;
        ensure(n);
        // n! / (r!*(n-r)!)
        return fact[n] * ifact[r] * ifact[n-r];
    }
};

//CombInt<ll / int> combint;
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


//Mod
//using mint = modint<998244353>;
//using Mint = modint<1000000007>;
template<int MOD>
struct modint {
    long long v;

    modint(long long x = 0) {
        v = x % MOD;
        if (v < 0) v += MOD;
    }

    modint& operator+=(const modint& other) {
        v += other.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }

    modint& operator-=(const modint& other) {
        v -= other.v;
        if (v < 0) v += MOD;
        return *this;
    }

    modint& operator*=(const modint& other) {
        v = v * other.v % MOD;
        return *this;
    }

    modint pow(long long n) const {
        modint res = 1, x = *this;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    modint inv() const {
        return pow(MOD - 2);
    }

    modint& operator/=(const modint& other) {
        return *this *= other.inv();
    }

    friend modint operator+(modint a, const modint& b) { return a += b; }
    friend modint operator-(modint a, const modint& b) { return a -= b; }
    friend modint operator*(modint a, const modint& b) { return a *= b; }
    friend modint operator/(modint a, const modint& b) { return a /= b; }

    int val() const { return (int)v; }
};


//累積和
//PrefixSum<ll/int> ps(vector_name);
//ps.query(l, r) -> sum from [l, r)
template<class T>
class PrefixSum {
private:
    vector<T> sum;
public:
    PrefixSum(const vector<T>& a){
        //a.size()+1の長さ。T型の0で初期化
        sum.resize(a.size()+1, T(0));
        for (int i = 0; i < (int)a.size(); i++) {
            sum[i + 1] = sum[i] + a[i];
        }
    }

    T query(int l, int r){
        return sum[r]-sum[l];
    }
    //累積和のベクトルを取得
    const vector<T>& get() const{
        return sum;
    }
};