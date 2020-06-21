AtCoder / c++
------------------

[E - Crested Ibis vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_e)

```
1. dynamic programming
2. greedy로 풀려다가 시간 많이쓰고 못찾았다. 다른사람 풀이를 참고하였다.
3. 각 입력을 받을 때마다 dp[]를 채웠다.
```

[A - αlphabet](https://atcoder.jp/contests/abc171/tasks/abc171_a)

```
1. lev 1, 구현
2. 아스키 코드 활용. A(65) ~ Z(90), a(97) ~ z(122)
```

[B - Mix Juice](https://atcoder.jp/contests/abc171/tasks/abc171_b)

```
1. lev 1, 구현
2. sort로 가장 작은 수 k개를 골라서 더한다.
```

[C - One Quadrillion and One Dalmatians](https://atcoder.jp/contests/abc171/tasks/abc171_c)

```
1. lev 3, 재귀
2. 나머지가 1일 때 a, 2일 때 b... 26(0)일 때 z라고 하면 예외 처리가 굉장히 어려워진다.
3. 수에서 1을 빼서 나머지가 0일 때 a, 1일 때 b... 25일 때 z로 하니 가능하다.
4. 재귀를 먼저 실행시키고 print를 하기 때문에 가장 안쪽에서부터 print를 한다.
```

[D - Replacing](https://atcoder.jp/contests/abc171/tasks/abc171_d)

```
1. lev 1, 구현
2. 각 수마다 가지고 있는 갯수를 가지고 있는 배열을 만들고 바꾸면서 배열과 sum을 수정한다.
3. ll = int * int 는 에러가 난다.
4. ll = ll * ll 로 바꾸니 에러가 사라졌다.
```
