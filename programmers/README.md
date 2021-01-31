programmers / c++
------------------

[[2020 카카오 공채] 문자열 압축](https://programmers.co.kr/learn/courses/30/lessons/60057#)

```
1. lev2
2. 어려운 문법을 쓰지 않지만 구현과 깊은 생각이 요구된다.
3. 단위를 1 ~ 문자열길이/2 반복한다. 각 단위별 시작을 각각 반복한다. 단위 안에서 다음 것과 같은 지 비교한다.
4. 압축하는 숫자가 9->10, 99->100 넘어갈 때 자리수가 하나 늘어난다.
```

[[2020 카카오 공채] 문자열 압축](https://programmers.co.kr/learn/courses/30/lessons/60057#)

```
1. lev2, stack, recursive, string
2. 문제에서 나온 그대로 재귀를 이용한 구현을 하면 된다.
3. 처음부터 문자열을 살펴서 '('와 ')'의 개수를 보고 균형잡힌 괄호 문자열을 찾는다.
4. 동시에 stack을 이용하여 올바른 괄호 문자열인지 확인한다.
5. 균형잡힌 괄호 문자열을 찾으면 u에 넣고 나머지를 v에 넣는다.
6. 올바른 괄호 문자열이라면 u + solution(v)를 반환한다.
7. 올바른 괄호 문자열이 아니라면 u의 처음과 마지막을 뺀 문자열을 반대로 뒤집는다.
8. 그리고 '(' + solution(v) + ')' + u 를 반환한다.
```

[[2020 카카오 공채] 가사 검색](https://programmers.co.kr/learn/courses/30/lessons/60060)

```
1. lev4, trie
2. 트라이(trie) 자료구조를 사용한다.
3. 노드에 map을 추가해서 길이가 L인 문자열이 몇 개인지 표시한다.
4. 아직 완전히 습득하지 못했으니 나중에 꼭 재검.
```
- [참고 링크](https://yomyom0824.tistory.com/m/58?category=1040570)



[[2018 카카오 공채] 비밀 지도](https://programmers.co.kr/learn/courses/30/lessons/17681)

```
1. lev1
2. 2진수를 사용하기 위해 <bitset> 라이브러리 사용.
3. bitset<n>(a) : int형 a를 n길이의 2진수로 나타낸다. or 연산자 | 를 사용한다.
4. .to_string()함수로 스트링 변환 후 값을 수정한다.
```

[[2018 Summer/Winter Coding] 스티커 모으기(2)](https://programmers.co.kr/learn/courses/30/lessons/12971)

```
1. lev4, dynamic programming
2. 포도주 시식과 비슷하다. 처음과 끝을 이엇다는 조건만 추가해주면 된다.
3. 처음 것을 제외하고 보았을 때 + 마지막 것을 제외하고 보았을 때 경우를 나누어 계산한다.
```

[[2020 카카오 인턴십] 키패드 누르기](https://programmers.co.kr/learn/courses/30/lessons/67256)

```
1. lev1, 구현
2. my solution
  1) 키패드별 좌표를 미리 저장한다.
  2) 왼손 위치를 ll, 오른손 위치를 rr에 저장한다.
  3) 눌러야할 숫자가 1, 4, 7이라면 왼손을 이동시키고 L을 추가한다.
  4) 눌러야할 숫자가 3, 6, 9 라면 오른손을 이동시키고 R을 추가한다.
  5) 나머지는 손과의 거리를 비교하여 가까운 쪽을 이동시키고 해당 문자를 추가한다.
```

[[2020 카카오 인턴십] 수식 최대화](https://programmers.co.kr/learn/courses/30/lessons/67257)

```
1. lev2, Array
2. my solution
  1) 가장 먼저 check() 함수 실행
    a) 숫자와 연산자를 분리하여 벡터에 저장한다.
    b) 연산자가 있는 지 체크한다.
  2) 있는 연산자 별로 조합을 확인하여 가장 큰 answer 값을 구한다.
  3) do_연산자는 받은 벡터에 해당하는 연산자의 연산만 수행한다.
  4) 연산의 결과를 두 값 중 왼쪽에 저장하고 오른쪽에는 INT_MAX를 저장한다.
  5) 연산하려는 값에 INT_MAX가 들어있으면 왼쪽으로 가면서 피연산자를 찾는다.
  6) 연산을 마치고 인자로 받은 add, sub, mul을 보고 다음 명령어를 수행하기 위해 함수를 실행한다.
3. best solution
  1) 숫자와 연산자를 분리하여 벡터에 넣는 것은 동일하다.
  2) exp에 연산자의 종류를 모두 넣는다.
  3) exp를 정렬한다.
  4) next_permutation을 활용하여 exp의 모든 조합을 반복한다.
    a) 조합에 맞는 연산자 순서대로 연산을 수행한다.
    b) 연산을 수행한 숫자와 연산자는 벡터에서 erase 한다.
4. next_permutation은 <algorithm> 안에 있는 함수이다.
  1) 인자로 넘긴 범위에 해당하는 배열의 다음 순열로 정렬하고 true를 반환한다.
  2) 더이상의 다은 순열이 없다면 false를 반환한다.
```

[[2020 카카오 인턴십] 보석 쇼핑](https://programmers.co.kr/learn/courses/30/lessons/67258)

```
1. lev3, Hash map, Two pointers
2. my solution
  1) 먼저 gems를 훑어보며 보석 종류의 개수를 구한다.
  2) start와 end를 시작에 위치시키며 모든 보석을 포함할 때까지 end를 증가시킨다.
  3) end를 증가시킬 때마다 map의 해당 보석의 개수를 하나씩 증가시킨다.
  4) 모든 보석을 포함하게 되면, 그 조건이 유지되도록 start도 증가시킨다.
  5) 조건이 깨지게 되는 start 지점에서의 범위를 answer에 저장한다.
  6) 이 과정을 end가 끝에 다다를 때까지 한다.
3. map을 처음에 clear한 후 map의 크기로 보석 종류의 개수를 계산할 수 있다.
4. 즉, 보석의 개수가 0개가 되면 map에서 제거하는 방법을 사용하여 변수k를 대체한다.
```

[[2020 카카오 인턴십] 경주로 건설](https://programmers.co.kr/learn/courses/30/lessons/67259)

```
1. lev3, queue, Breadth First Search, Struct
2. my solution
  1) 좌표, 비용, 방향을 갖는 struct를 정의한다.
  2) up, right, down, left로 움직이기 위한 배열을 만든다.
  3) queue를 만들고 살펴볼만한 좌표의 자동차만 넣는다.
  4) queue가 비어있을 때까지 while문
    a) 차의 좌표가 마지막까지 왔다면 ans를 최신화
    b) 움직이기 위한 배열을 이용하여 4번의 for문을 돈다.
    c) 좌표를 이동시키고 범위를 벗어났는지, 벽으로 왔는지 확인한다.
    d) 이동한 방향과 이전의 방향을 고려하여 cost와 변경된 방향을 최신화한다.
    e) 새로운 곳이거나, 더 저렴하거나 같은 비용이라면 살펴볼 필요가 있으므로 queue에 넣는다.
```

[[2020 카카오 인턴십] 동굴 탐험](https://programmers.co.kr/learn/courses/30/lessons/67260)

```
1. lev4, queue, Breadth First Search
2. my solution
  1) 필요한 전역 변수들을 선언한다.
    a) edge : 해당 노드와 연결된 노드들을 저장한다.
    b) need : 해당 노드를 가기 위해서 꼭 들려야하는 노드를 저장한다.
    c) save : need의 노드를 들리게 되면, 이전에 저장한 위치에서 다시 시작하기 위해서 저장된 노드들.
    d) visited : 방문한 노드를 체크
  2) path를 보고 edge를 채운다.
  3) order를 보고 need를 채운다.
  4) bfs() 함수 실행
  5) queue에 0을 넣고, 혹여나 0의 need가 있으면 함수를 종료한다.
  6) queue가 비어있을 때까지 while
    a) queue에서 하나를 뽑아 이미 방문한 곳이라면 다음 것을 뽑는다.
    b) 처음 0은 이 이후로 true여야 하므로 visited[0] =true
    c) need를 보고 들려야만 하는 노드에 들리지 않았다면 해당 노드를 일단 save에 저장한다.
    d) 통과한다면 node를 들렸다고 visited에 표시한다.
    e) 만약 자신때문에 진행을 멈춘 노드가 있는지 need를 보고, 있으면 queue에 넣는다.
    f) 연결된 edge들을 모두 queue에 넣는다.
```

[단어 변환](https://programmers.co.kr/learn/courses/30/lessons/43163)

```
1. lev3, String, DFS, Backtracking
2. my solution
  1) words에 target이 있는지 검사하고 없으면 0 반환
  2) 3중 for문으로 graph에 자신과 한글자 차이가 나는 word를 찾아 넣어준다.
  3) dfs 함수로 begin을 root로 하여 진행한다.
    a) 방문했던 곳이면 return
    b) target에 도착하면 depth를 ans와 비교하며 저장
    c) 현재 string을 visit에 표시하고 연결된 모든 string 노드로 들어가보며 확인한다.
    d) 다 찾아본 후 visit을 false로 수정
  4) ans이 여전히 51이면 0을 return
```

[여행경로](https://programmers.co.kr/learn/courses/30/lessons/43164)

```
1. lev3, DFS, Backtracking, Hash Table
2. my solution
  1) 비행기 티켓들을 보고 map을 만든다. key:출발지 value:갈 수 있는 목적지
  2) 각 value를 sort한다.
  3) ICN을 출발지로 dfs를 시작한다.
  4) dfs의 t_num 인자는 사용한 티켓의 수이다.
  5) 사용한 티켓의 수가 전체 티켓의 수가 되면 true를 반환한다.
  6) 인자로 받은 현재 위치 cur에서 갈 수 있는 곳들을 살핀다.
  7) 갈 곳으로 정한 곳은 빈 string ""를 넣는다.
  8) ans에 갈 곳으로 정한 곳을 넣는다.
  9) 다음 목적지를 dfs에 넣고 true를 반환하면 똑같이 true를 반환한다.
  10) false라면 빈 string을 원래대로 되돌리고 ans도 pop_back 한다.
3. dfs의 반환값이 있을 때 모든 노드를 다 확인하지 않아도 된다.
```
