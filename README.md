# #-010verSCP-EEE
コンパイラー

仮想マシンベースのアセンブラへと変換するコンパイラ

仮想マシン自体も実装
## 命令一覧
1. push
　値（全ての型と全てのＳ式）を押し込む。
2. pop
　値を取り出す。
3. exch
　値の交換である。
4. match
　指定した値までpopする。なければ全てをpopした後、#fを返す。
5. add
　足し算である。
6. sub
　引き算である。
7. mul
　掛け算である。
8. dev
　割り算である。
9. sort
　現在位置を最小値とする順列へと並び変える。
10. elt
　指定した順番の値を読み取る。
11. convert
  万能型変換システムである。文字を数字に直すだけでなくリストからオブジェクトへ、数値から絵、文字列からプログラムまで変換する。変換対象が宣言されていない場合宣言も担う。
12. call-with-current-continuation
 継続である。
## 仮想マシンスペック
1. レジスター一本

明確に操作できる空間は一つしかない。しかしリストを一つの値として押し込めるので、実質無限階層レジスター。

2. 全S式構造

全ては自身で構成されている。

3. 強制型変換

変換エラーはない。

4. 半自動型決定

手動で変数を宣言しない場合(プログラムによるプログラム操作)は推論による静的型宣言が、手動で変数を宣言する場合はその変数のみ動的型宣言がなされる。

5. 基本遅延評価性

全ての式は取り出すまで計算されない。
