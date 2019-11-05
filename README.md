Coding Pratice / c++
------------------

1. 스터디를 통해 일주일에 4~5개의 코딩 문제를 풀어본다.
2. 실력이 오른다.

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

**2** - [백준 11726](https://www.acmicpc.net/problem/11726)
```
1. dynamic programming
2. 처음에 반복문으로 풀려다가 동적 계획법인걸 늦게 알고난 후 금방 풀었다. 어떤 알고리즘을 적용할지 빠르게 결정하는 것이 중요하다.
3. 피보나찌 수열과 같다.
4. 계속 숫자를 더하다보면 자료형의 크기를 넘을 수 있기 때문에 연산할 때마다 10007로 나누어 주어야 런타임 에러를 방지할 수 있다.
```

>leeheejoon / soongsil univ.
