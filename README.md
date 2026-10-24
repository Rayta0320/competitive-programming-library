# Competitive Programming Library

AtCoder・Codeforces で使用する、自分用の C++ ヘッダー集です。
ループマクロ、型エイリアス、組合せ計算、幾何計算などをまとめています。

## ファイル

| ファイル | 用途・内容 | 依存関係 |
| --- | --- | --- |
| [atcoder_cpp_setting.hpp](./atcoder_cpp_setting.hpp) | AtCoder 用。基本マクロ、組合せ計算、幾何計算、modint、累積和 | GNU C++ の標準ライブラリ、AtCoder Library |
| [codeforces_cpp_setting.hpp](./codeforces_cpp_setting.hpp) | Codeforces 用。基本マクロ、組合せ計算、幾何計算 | GNU C++ の標準ライブラリ |

どちらも `<bits/stdc++.h>` を使用するため、GCC / libstdc++ の環境を想定しています。
共通の名前を定義しているので、1つのプログラムでは用途に応じて片方を使ってください。

## ローカルでの使い方

```sh
git clone https://github.com/Rayta0320/competitive-programming-library.git
cd competitive-programming-library
```

使用するヘッダーと同じディレクトリに `main.cpp` を置きます。

### AtCoder

[AtCoder Library](https://github.com/atcoder/ac-library) を別途用意し、
`atcoder/` ディレクトリの親をコンパイラのインクルードパスに指定します。

```cpp
#include "atcoder_cpp_setting.hpp"

int main() {
    CombMod<mint> comb(10);
    cout << comb.C(5, 2).val() << '\n'; // 10

    vector<ll> a = {1, 2, 3, 4};
    PrefixSum<ll> ps(a);
    cout << ps.query(1, 3) << '\n'; // 5: a[1] + a[2]
}
```

```sh
g++ -std=c++17 -O2 -I /path/to/ac-library main.cpp -o main
./main
```

`/path/to/ac-library` は実際の配置先に置き換えてください。

### Codeforces

```cpp
#include "codeforces_cpp_setting.hpp"

int main() {
    CombInt<ll> comb;
    cout << comb.C(5, 2) << '\n'; // 10

    vector<int> a = {1, 2, 3};
    ll sum = 0;
    rep(i, (int)a.size()) sum += a[i];
    cout << sum << '\n'; // 6
}
```

```sh
g++ -std=c++17 -O2 main.cpp -o main
./main
```

macOS で Homebrew の GCC を使う場合は、`g++` をインストール済みのコマンド名
（例: `g++-14`）に置き換えてください。

## 主な API と使用上の注意

- `rep(i, n)`: `0` から `n - 1` までのループ。
- `rrep(n, i)`: 現在の AtCoder 版は `n - 1` から `0` まで、Codeforces 版は `n - 1` から `1` までです。
- `CombMod<Mint>(n).C(a, b)`: 前計算した範囲 `0 <= a <= n` の組合せを計算します。
  法を素数とする通常の使い方では `n` を法より小さくしてください。
  AtCoder 版では `mint`（法 `998244353`）を使えます。
  Codeforces 版には modint 型が含まれていないため、利用する場合は対応する型を別途用意します。
- `CombInt<T>().C(n, r)`: 整数で組合せを計算します。途中の乗算も `T` に収まる範囲で使用してください。
- `vec`, `dot_product`, `cross_product`, `eucdis`: 2次元ベクトルの生成・内積・外積・長さ。
  座標や積は `int` で計算するため、大きい値ではオーバーフローに注意してください。
- `PrefixSum<T>`（AtCoder 版のみ）: `query(l, r)` で半開区間 `[l, r)` の和を返します。
  `0 <= l <= r <= 配列の長さ` の範囲で使用してください。
- AtCoder 版の `mint` は ACL の型です。独自の `modint` を明示的に使う場合は
  `::modint<998244353>` のように書くと、ACL の同名の型との曖昧さを避けられます。

## 提出用ソースへの組み込み

自作ヘッダーの内容を提出する `.cpp` に展開し、
`#include "atcoder_cpp_setting.hpp"` または `#include "codeforces_cpp_setting.hpp"` を置き換えてください。
GitHub に公開するだけでは、提出先から自作ヘッダーを読み込めるようにはなりません。
AtCoder 版の `<atcoder/all>` は、提出先の選択した言語環境で利用できることを確認してください。

## 参照リンク

リポジトリ全体を紹介する場合:

```markdown
[競技プログラミング用 C++ ライブラリ](https://github.com/Rayta0320/competitive-programming-library)
```

使用した特定の版を示す場合は、GitHub 上で対象のヘッダーを開き、`y` キーを押して
コミット ID を含む固定リンクに切り替えてからコピーしてください。
通常の `main` のリンクは更新に追従し、固定リンクはその時点の内容を指します。
詳細: [GitHub の固定リンクの説明](https://docs.github.com/en/repositories/working-with-files/using-files/getting-permanent-links-to-files)。

提出コードや解説のコメントには、次の形で記載できます。

```cpp
// Library: https://github.com/Rayta0320/competitive-programming-library
// 使用した版: ここに対象ヘッダーの固定リンクを貼る
```

## 外部ライブラリ

AtCoder 版は [AtCoder Library (ACL)](https://github.com/atcoder/ac-library) を利用しています。
ACL 本体はこのリポジトリには含めていません。
