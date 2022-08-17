# 拡張ユークリッドの互除法

    extgcd(a, b, &x, &y) {
	    if (b == 0) {
		    x = 1;
		    y = 0;
		    return;
	    }

		extgcd(b, a % b, y, x);

		y -= a / b * x;
		
		return
    }

これは何をしているの〜

## モチベーション

$ax + by = gcd(a, b)$ となる $x$ 、 $y$ を求めたい。
* このような等式をベズーの等式という

*  $a$ と $b$ が互いに素である時、 $ax + by = 1$ であるが、この時の $x$ は $ax = 1\ (mod\ b)$ を満たす -> 逆元が求まるので`modint`での除算ができる
* 整数問題でこの方程式を解く必要がある時がある

## コードの原理
`extgcd(a, b, x, y) ->` $ax + by = gcd(a, b)$

について

$a = pb + q$

とすると

$(pb + q)x + by = gcd(a, b)$

$b(px + y) + qx = gcd(a, b)$

となる。この式は新たな変数 $s$ $t$ とでもおいて
$bs + qt = gcd(a, b)$

ユークリッドの互除法で良く使うように

$gcd(a, b) = gcd(b,\ q)$

(で $q$ は $a$ を $b$ で割ったあまり)

なので [(証明(高校数学の美しい物語さん))](https://manabitimes.jp/math/672)

$bs + qt = gcd(b, q)$

となり
`extgcd(b, a%b, y, x)`を再帰的に解けば良いことになる。

`a`か`b`が`0`になった時に自明的に方程式が解けるので。ここから再帰を戻す。

ここで、 $s = (px + y) = (\lfloor\frac{a}{b}\rfloor x + y)$ という式から $y$ を復元する必要がある。

`extgcd(b, a%b, y, x)`は`y`に $s$ が代入されているため、

$y = s - \lfloor\frac{a}{b}\rfloor x$ という式変形があり、`y -= a / b * x`という処理が必要になっている。


## コラム
$c = ax + by$ をみたす整数 $c$ は必ず $gcd(a, b)$ の倍数である。
* $a$ も $b$ も $gcd(a, b)$ の倍数なので、 `右辺 = `$gcd(a, b)(a'x + b'y)$ と変形できる。-> どう考えても左辺が $gcd(a, b)$ の倍数でないといけない

[より詳しく(けんちょんさんのQiita記事)](https://qiita.com/drken/items/b97ff231e43bce50199a)

---

_ラメの定理_

ユークリッドの互除法の計算回数の評価にまつわる定理

> 割って余りを取るという操作を、最悪でも小さいほうの数の十進法での桁数の約 5 倍繰り返せば、最大公約数に達する

毎回桁数の5倍程度に成るわけではなく、大抵はもっと早く終わる模様。

[なかけんの数学ノートさんの記事にわかりやすい解説記事がありました。](https://math.nakaken88.com/textbook/master-euclidean-algorithm-steps/)

## さらなる座学・精進
[Wikipediaさん・・・ユークリッド整域(環論)](https://ja.wikipedia.org/wiki/%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E7%92%B0)

[Wikipediaさん・・・連分数展開](https://ja.wikipedia.org/wiki/%E9%80%A3%E5%88%86%E6%95%B0)

[kirika_compのブログさん・・・整数論テクニック集](https://kirika-comp.hatenablog.com/entry/2018/03/12/210446)

[はまやんはまやんはまやんさん・・・競技プログラミングにおける数学的問題まとめ](https://blog.hamayanhamayan.com/entry/2017/10/14/125941)
