백준 / c++
------------------


**벚꽃이 정보섬에 피어난 이유** - [백준 17127](https://www.acmicpc.net/problem/17127)
```
1. 숭실대학교 출제 문제. 각 펫말의 경계선을 for문으로 정하여 계산.
2. leechanwoo 코드 참고할 것.
```

**로또** - [백준 6603](https://www.acmicpc.net/problem/6603)
```
1. 6중 for문 방법과 그 for문을 recursive를 이용하여 코딩.
2. 구현 방식은 for문이 매우 간단하다. 시간은 recursive가 조금 덜 걸렸다.
3. recursive 이용의 연습이 필요하다.
```

**정수 상각형** - [백준 1932](https://www.acmicpc.net/problem/1932)
```
1. bottom-up 방법과 top-down 방법 모두 코딩.
2. bottom-up 일 때 필요한 예외처리가 적고, 마지막에 for문을 통한 최댓값 비교가 필요없어서 더 효율적이다.
```

**1로 만들기** - [백준 1463](https://www.acmicpc.net/problem/1463)
```
1. recursive로 풀려다가 10번 넘게 틀렸다. 결국 for문으로 코딩.
2. 나중에 꼭 다시 한 번 풀어보기.
```

**포도주 시식** - [백준 2156](https://www.acmicpc.net/problem/2156)
```
1. dynamic programming
2. bottom부터 top으로 올라가며 하나씩 직접 계산해보니 규칙을 찾아 쉽게 알고리즘을 작성하였다.
```

**회의실배정** - [백준 1931](https://www.acmicpc.net/problem/1931)
```
1. greedy algorithm
2. 처음에는 회의의 시작시간으로 sort하여서 시간 초과가 나왔다.
3. 구조체를 정렬하기 위해 bool 함수를 조건식으로 하는 sort를 이용하였다. sort( , , 조건식)
```

**궁금한 민호** - [백준 1507](https://www.acmicpc.net/problem/1507)
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

**좋은 수열** - [백준 2661](https://www.acmicpc.net/problem/2661)
```
1. backtracking
2. 재귀 함수를 만들고 탈출조건을 만든다. promising 함수를 구현한다.
3. 배열 크기를 80으로 하면 런타임 에러가 나고 81로 했을 때 에러가 안난다. 배열의 크기 주의할 것.
```

**스도쿠** - [백준 2580](https://www.acmicpc.net/problem/2580)
```
1. backtracking
2. 사람이 직접 푸는 것처럼 row, col, box의 빈칸이 적은 칸부터 숫자를 넣으며 풀고 싶었으나 실패. (나중에 도전해볼것)
3. 자식이 유망하지 않아 올라오게 되면 내려가면서 수정한 것들을 원래대로 돌려놓는다.
```

**후보 추천하기** - [백준 1713](https://www.acmicpc.net/problem/1713)
```
1. array
2. 연산의 순서를 잘못하면 값이 달라질 수 있다.
```

**양 구출 작전** - [백준 16437](https://www.acmicpc.net/problem/16437)
```
1. recursive
2. int 자료형으로 담을 수 있는 크기를 벗어난다. long long을 사용해야함.
3. top에서 bottom을 불러서 진행하는 recursive가 아닌 각 leaf node에서 top으로 가는 방식으로 하니 시간초과.
4. recursive의 연습이 더 필요하다.
```

**초콜릿 자르기** - [백준 2163](https://www.acmicpc.net/problem/2163)
```
1. math / dynamic programing
2. dp로 풀었지만 사실 수학문제. 수학문제로는 3줄로 끝날 거 dp로 풀면 70줄 정도.
3. 2차원 배열이 대칭이고 풀기 위한 순서를 위해서는 switching 함수가 필요했다.
```

**최솟값 찾기** - [백준 11003](https://www.acmicpc.net/problem/11003)
```
1. sliding window
2. priority queue에 pair<int,int>를 넣어 최소값을 뽑았다. 그 최소값이 오래된 최소값이면 삭제했다.
3. 최소값을 뽑기 위해 greater로 compare했고 최소값을 벡터에 하나씩 넣었다.
```

**졸려** - [백준 9519](https://www.acmicpc.net/problem/9519)
```
1. string. 반복문
2. 반복을 줄일 방법을 생각해야 시간초과를 하지 않을 수 있다.
3. 반복에 규칙이 없을 수도 있다.
```

**5차 전직** - [백준 16112](https://www.acmicpc.net/problem/16112)
```
1. 반복문.
2. sort 후 가장 작은 퀘스트부터 진행. 경험치에 min(index, k)를 곱하면서 더한다.
```

**설탕 배달** - [백준 2839](https://www.acmicpc.net/problem/2839)
```
1. 쉬운 코드라도 모두의 구현 방식이 다르다. 시간을 줄이는 법을 생각하라.
2. 5로 나눌 수 있을 때까지 3을 빼준다. 3의 배수의 1의 자리는 1~9까지 모두 존재 하고 5의 배수가 될 때까지 5번 이하만 빼준다.
```

**계단 오르기** - [백준 2579](https://www.acmicpc.net/problem/2579)
```
1. dynamic programming
2. 포도주 시식과 비슷하다. 전형적인 dp 문제.
```

**알고스팟** - [백준 1261](https://www.acmicpc.net/problem/1261)
```
1. Dijkstra Algorithm
2. 벽을 부수는 길을 갈 때 weight를 1이라고 하고 map을 만든다.
3. 네 방향으로 이동하며 dist[][]를 최신화 시킨다.
4. visited[][]를 만들었다가 늦게 가더라도 더 적은 distance가 있을 수 있으므로 없앴다.
5. queue가 아닌 priority_queue or structure를 사용하여 distance 순으로 뽑아냈다면 고려하는 경우의 수가 많이 줄어들 것이다.
6. memset()은 다차원 배열도 1차원 배열과 동일하게 초기화 할 수 있지만 0, -1만 가능하다.
```

**소가 정보섬에 올라온 이유** - [백준 17128](https://www.acmicpc.net/problem/17128)
```
1. 구현
2. endl은 시간이 오래 걸린다. '\n' 쓰자.
3. mul[]의 합을 ans에 저장하고 장난을 칠때마다 mul과 ans를 바꿨다.
```

**Stop Using Money** - [백준 14974](https://www.acmicpc.net/problem/14674)
```
1. sort 비교문
2. struct를 만들고 변수들을 비교하여 오름차순 내림차순으로 정렬하도록 cmp 정의했다.
3. double형은 비교함수 ==를 쓰지 않는다.
4. 소수 비교를 최대한 하지 말아라.
```

**영우는 사기꾼?** - [백준 14676](https://www.acmicpc.net/problem/14676)
```
1. 시간초과 해결 (구현)
2. 처음 방식 : 건물을 지을 때 필요한 건물들이 모두 지어졌는 지 확인
3. 해결 방식 : degree는 해당 건물을 짓기 위해서 앞서 지어야 하는 건물의 수.
              짓게 되면 degree는 하나씩 줄고 0이 되면 조건 만족.
              중복되서 지을수도 있으니 0->1, 1->0이 될 때만 degree를 최신화 함.
4. for(int next : arr) ... : arr에 있는 값들을 next에 넣으면서 for문이 반복됨
```

**창용이의 시계** - [백준 12840](https://www.acmicpc.net/problem/12840)
```
1. 시간 응용 문제
2. 시간, 분, 초를 전부 합쳐서 초로 표현
3. 하루가 넘어가면 크기를 줄이기 위해 %DAY 사용
```

**정보대 등산** - [백준 12841](https://www.acmicpc.net/problem/12841)
```
1. 구현
2. 누적으로 벡터를 쌓음
3. way1 = cross1 + left1 - right1 + rightAll 이런 느낌으로 계산
4. 배열로 하면 틀리지만 vector로 하면 맞음
```

**튀김 소보루** - [백준 12842](https://www.acmicpc.net/problem/12842)
```
1. lev 3, 구현, 효율
2. 첫 번째 방법 : i를 증가시키면서 time[i]이 나눠지면 해당 사람이 먹은 것으로 처리
3. 두 번째 방법 : i를 1부터 너무 큰 수까지 증가시켜야 하므로 이를 줄이자.
                 sol()함수는 해당 시간까지 사람들이 먹을 수 있는 빵의 수이다.
                 0부터 INT_MAX까지 binary search 방식으로 mid값을 찾는다.
                 mid는 해당 시간 쯤 나오는 사람이 범인임을 알려준다.
4. 세 번째 방법 : pq를 사용한다. 사람을 번호와 함께 pq에 넣는다.
                 하나씩 꺼내면서 다 먹을 시간과 함께 pq에 다시 넣는다.
                 꺼내는 것이 하나 먹는 것
5. 다른 사람의 풀이를 참고할 필요가 있다.                 
```

**복수전공** - [백준 12843](https://www.acmicpc.net/problem/12843)
```
1. lev 3, 이분매칭
2. 이분매칭은 두 집단이 최대로 연결 가능한 수를 찾는 법이다. 중복된 수업의 수를 찾아내어 전체에서 뺀다.
3. 알고리즘
  - 한쪽에 컴공, 한쪽에 소프트웨어 수업이 몰려있다고 생각
  - 컴공 수업을 하나씩 확인
  - 연결되어 있는 edge들을 하나씩 확인하며 연결 가능한지 확인하고 연결되면 match에 저장.
  - 연결이 될 때마다 하나씩 저장. 
```

**XOR** - [백준 12844](https://www.acmicpc.net/problem/12844)
```
1. lev 4, Segment tree with lazy propagation
2. segment tree : 구간의 합(또는 어떠한 연산)을 쉽게 구하기 위해서 구성한 트리. 
   lazy propagation : tree의 update를 나중에 필요할 때 함으로 더 효율적으로 update하는 방법. 
3. 알고리즘
  - 입력을 받고 만든 array로 tree를 만든다.
  - propagation : lazy값이 있으면 tree 값을 갱신하고 아래로 lazy 값을 전파
                  같은 값을 2번 ^ 하면 0이므로 이를 활용하여 계산한다.
  - 1번 쿼리 : propagation을 한 후 범위에 해당하는 tree의 값들을 xor(^) 한다.
  - 2번 쿼리 : propagation을 한 후 tree를 갱신, 아래로 lazy 값을 전파한다. 마지막 return 문장을 통해 위로도 전파가 된다.
4. 항상 a<b는 아니기 때문에 체크해야한다.
```
[segment tree 참고 링크](https://bowbowbow.tistory.com/4)

[lazy propagation 참고 링크](https://wkdtjsgur100.github.io/segment-tree)

**모두의 마블** - [백준 12845](https://www.acmicpc.net/problem/12845)
```
1. lev 1, 구현
2. 가장 level이 큰 카드와 계속 합성을 하는 것이 가장 큰 gold를 얻을 수 있다.
```
