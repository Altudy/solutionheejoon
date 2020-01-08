백준 / c++
------------------


**jungbosum** - [백준 17127](https://www.acmicpc.net/problem/17127)
```
1. 숭실대학교 출제 문제. 각 펫말의 경계선을 for문으로 정하여 계산.
2. leechanwoo 코드 참고할 것.
```

**lotto** - [백준 6603](https://www.acmicpc.net/problem/6603)
```
1. 6중 for문 방법과 그 for문을 recursive를 이용하여 코딩.
2. 구현 방식은 for문이 매우 간단하다. 시간은 recursive가 조금 덜 걸렸다.
3. recursive 이용의 연습이 필요하다.
```

**integerTriangle** - [백준 1932](https://www.acmicpc.net/problem/1932)
```
1. bottom-up 방법과 top-down 방법 모두 코딩.
2. bottom-up 일 때 필요한 예외처리가 적고, 마지막에 for문을 통한 최댓값 비교가 필요없어서 더 효율적이다.
```

**makeToOne** - [백준 1463](https://www.acmicpc.net/problem/1463)
```
1. recursive로 풀려다가 10번 넘게 틀렸다. 결국 for문으로 코딩.
2. 나중에 꼭 다시 한 번 풀어보기.
```

**wine** - [백준 2156](https://www.acmicpc.net/problem/2156)
```
1. dynamic programming
2. bottom부터 top으로 올라가며 하나씩 직접 계산해보니 규칙을 찾아 쉽게 알고리즘을 작성하였다.
```

**meetingTimeTable** - [백준 1931](https://www.acmicpc.net/problem/1931)
```
1. greedy algorithm
2. 처음에는 회의의 시작시간으로 sort하여서 시간 초과가 나왔다.
3. 구조체를 정렬하기 위해 bool 함수를 조건식으로 하는 sort를 이용하였다. sort( , , 조건식)
```

**backFloyd** - [백준 1507](https://www.acmicpc.net/problem/1507)
```
1. greedy algorithm
2. 주어진 값에서 직접 가지 않고 다른 길을 통해서 갈 때 최소라면 연결된 선을 지워가며 진행한다.
3. floyd 알고리즘을 거꾸로 진행한다.
```

**2xn** - [백준 11726](https://www.acmicpc.net/problem/11726)
```
1. dynamic programming
2. 처음에 반복문으로 풀려다가 동적 계획법인걸 늦게 알고난 후 금방 풀었다. 어떤 알고리즘을 적용할지 빠르게 결정하는 것이 중요하다.
3. 피보나찌 수열과 같다.
4. 계속 숫자를 더하다보면 자료형의 크기를 넘을 수 있기 때문에 연산할 때마다 10007로 나누어 주어야 런타임 에러를 방지할 수 있다.
```

**niceSequence** - [백준 2661](https://www.acmicpc.net/problem/2661)
```
1. backtracking
2. 재귀 함수를 만들고 탈출조건을 만든다. promising 함수를 구현한다.
3. 배열 크기를 80으로 하면 런타임 에러가 나고 81로 했을 때 에러가 안난다. 배열의 크기 주의할 것.
```

**sudoku** - [백준 2580](https://www.acmicpc.net/problem/2580)
```
1. backtracking
2. 사람이 직접 푸는 것처럼 row, col, box의 빈칸이 적은 칸부터 숫자를 넣으며 풀고 싶었으나 실패. (나중에 도전해볼것)
3. 자식이 유망하지 않아 올라오게 되면 내려가면서 수정한 것들을 원래대로 돌려놓는다.
```

**candidate** - [백준 1713](https://www.acmicpc.net/problem/1713)
```
1. array
2. 연산의 순서를 잘못하면 값이 달라질 수 있다.
```

**sheep** - [백준 16437](https://www.acmicpc.net/problem/16437)
```
1. recursive
2. int 자료형으로 담을 수 있는 크기를 벗어난다. long long을 사용해야함.
3. top에서 bottom을 불러서 진행하는 recursive가 아닌 각 leaf node에서 top으로 가는 방식으로 하니 시간초과.
4. recursive의 연습이 더 필요하다.
```

**chocolate** - [백준 2163](https://www.acmicpc.net/problem/2163)
```
1. math / dynamic programing
2. dp로 풀었지만 사실 수학문제. 수학문제로는 3줄로 끝날 거 dp로 풀면 70줄 정도.
3. 2차원 배열이 대칭이고 풀기 위한 순서를 위해서는 switching 함수가 필요했다.
```

**findmin** - [백준 11003](https://www.acmicpc.net/problem/11003)
```
1. sliding window
2. priority queue에 pair<int,int>를 넣어 최소값을 뽑았다. 그 최소값이 오래된 최소값이면 삭제했다.
3. 최소값을 뽑기 위해 greater로 compare했고 최소값을 벡터에 하나씩 넣었다.
```

**sleepy** - [백준 9519](https://www.acmicpc.net/problem/9519)
```
1. string. 반복문
2. 반복을 줄일 방법을 생각해야 시간초과를 하지 않을 수 있다.
3. 반복에 규칙이 없을 수도 있다.
```

**Arcane Stone** - [백준 16112](https://www.acmicpc.net/problem/16112)
```
1. 반복문.
2. sort 후 가장 작은 퀘스트부터 진행. 경험치에 min(index, k)를 곱하면서 더한다.
```
