Codeforces / c++
------------------

[455 A boredom](http://codeforces.com/contest/455/problem/A)

```
1. dynamic programming
2. 입력을 받으면서 각 숫자별로 긴 배열에 총 값을 계산하여 넣는다.
3. 해당 수를 넣을 때와 안넣을 때를 비교하면서 배열을 채워넣는다.
```

[1279 B verse for santa](http://codeforces.com/contest/1279/problem/B)

```
1. 최대 시간만큼 주어진 배열을 자르고 그 안에서 가장 큰 수를 반환.
2. 예외처리가 많음. 최대 시간이 배열을 넘을 때. 가장 큰 수를 빼도 늘어나는 선물이 없을 때.
3. 범위 지정에 유의하라.
4. 중간에 코드를 추가하다보니 사용되는 변수가 너무 많아졌다.
```

[1281 B Azamon Web Services](http://codeforces.com/contest/1281/problem/B)

```
1. greedy
2. 푸는 방법이 너무 다양하다. 간단하면서 효율적인 방법을 찾아야 한다. 반복을 줄일 방법도 생각하라.
3. swap 함수는 시간이 오래 걸리지 않아서 많이 써도 된다.
4. 두 string의 인자를 하나씩 비교하면서 a가 b보다 작으면 바꾸어 보고 a<b 이면 오케이. 아니면 다시 원래대로.
5. a[i]==a[j]일 때는 비교 안하도록 하여 반복을 줄였다.
```