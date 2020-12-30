LeetCode / c++
------------------

**1) [Two Sum](https://leetcode.com/problems/two-sum/)**
```
1. Easy, Array, Hash Table
2. 2중 for문을 쓰면 효율적이지 못하다.
3. map을 사용해서 하나의 for문으로 구현한다.
4. insert로 원소를 넣는 것보다 그냥 넣는것이 더 빠르다.
```

**2) [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)**
```
1. Medium, Linked List, Math
2. pointer의 이해와 활용이 필요하다. 이중 포인터.
3. 알고리즘
  1) List의 가장 처음이 되는 *ans 를 선언한다.
  2) *ans 를 가리키는 **node를 가지고 코드를 진행할 것이다. <= 이게 키포인트.
  3) sum으로 value를 계속 만들어주고 carry가 자동으로 만들어진다.
  4) 현재 node가 가리키는 *node를 new ListNode를 이용해서 초기화해준다.
  5) node가 가리키는 곳을 *node의 주소로 바꾸어 위를 반복한다.
4. 새로운 object를 만들어서 next에 할당하지 않아도 next의 주소만을 node가 계속 최신화한다.
5. node가 linked list의 각 노드를 가리키는 포인터가 되어 하나의 컨트롤러가 된다.
```

**3) [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)**
```
1. Medium, Hash Table, Two Pointers, String, Sliding Window
2. 두 개의 index를 이용하여 Sliding Window 방식을 사용했다
3. best solution
  1) start를 최신화 시키면서 최대 길이를 정한다
  2) 새로 추가되는 문자가 start 이후에 이미 있었으면 start를 이미 있던 문자 다음 위치로 이동시킨다.
  3) 그리고 새로 추가되는 문자의 위치를 최신화 시킨다.
  4) O(N)의 복잡도
```

**4) [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)**
```
1. Hard, Array, Binary Search, Divide and conquer
2. 두 벡터의 시작에서부터 2개의 지점을 비교해가며 median 값까지 진행하였다.
  - 예외를 처리하고 코드를 추가할수록 지저분해진다.
3. best solution 1
  1) 두 배열의 합이 짝수라면 두 값을 구해서 평균내고 홀수라면 바로 median 값을 구한다.
  2) kth함수를 재귀로 불러 진행한다.
  3) 예외조건 1 : 앞의 배열이 더 길어야 한다.
  4) 탈출조건 1 : 짧은 배열의 길이가 0일 때 긴 배열에서 k번째를 return한다.
  5) 탈출조건 2 : k=1일 때 바로 다음에 올 것을 구하면 되므로 두 배열의 처음 비교한다.
  6) k번째를 구해야하니 k/2씩 성큼성큼 좁혀간다.
4. best solution 2
  1) 나와 비슷한 방법으로 두 벡터의 앞에서부터 작은 값을 val에 넣고 이전 값을 prev_val에 넣는다. 두 값을 저장하면서 홀짝 모두 동작 가능하다.
  2) 나처럼 예외처리를 하지 않고 한쪽 vector가 끝나더라도 이전과 동일하게 진행한다.
5. best solution 3
  1) merge function으로 두 벡터를 합친다.
  2) median 값을 구한다.
```

**5) [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)**
```
1. Medium, String, DP, palindrome
2. 나는 길이가 짝수일 때와 홀수일 때를 나누어서 계산하였다. pal 이라는 vector를 따로 두기도 하였고 다른 것으로 대체할 수도 있을것 같았다.
3. best solution
  1) 중복된 문자들을 처리하여 한번에 뛰어 넘고 홀짝을 동시에 처리한다.
  2) 중간 값이 없이 왼쪽(l), 오른쪽(r) 만으로 길이를 계산한다.
4. 앞으로 팰린드롬은 이 방법을 사용하자.
5. complexity
  1) brute force 방법은시작과 끝을 찾는 O(n^2) + 팰린드롬 검사 O(n)
  2) 이전 정보를 사용하면 O(n^2) + 팰린드롬 검사 O(1)
```

**10) [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)**
```
1. Hard, String, DP, Backtracking
2. my solution
  1) backtracking 방식으로 가능한 경우를 자식 노드로 만들어 살펴본다.
  2) 패턴 string을 훑어보며 '.' '*'를 찾고 type에 저장한다.
    a) type 0 : 일반 수
    b) type 1 : 현재 위치가 '.'
    c) type 2 : 다음 위치가 '*'
    d) type 3 : 다음 위치가 '*' 이며 현 위치가 '.'
  3) 두 string을 가리키는 두 개의 포인터를 움직이며 진행한다.
  4) 두 포인터가 동시에 마지막+1 위치에 도달했을 때 true를 반환
  5) index 범위를 넘었을 때를 방지하기 위한 탈출코드는 case안에 넣는다. 그렇지 않으면 a / ab*c*d* 와 같은 것을 해결하지 못한다.
  6) type 별로 진행
    a) type 1 : 범위 확인 후 바로 다음 노드로 넘어간다.
    b) type 2 : 몇 번을 건너뛸지 모르므로 다 해본다. 5)의 경우때문에 늦게 범위를 계산한다. s[i]==p[pp]이어야 다음 노드를 또 검사할 수 있다.
    c) type 3 : type 2와 동일하고 s[i]==p[pp]만 검사하지 않고 넘어간다.
    d) default : type 0으로 비교하고 같으면 다음 노드로 넘어가고 다르면 false 반환
  7) 새로운 함수를 만들 때 인자의 주소&를 넘겨서 메모리를 절약하는 것을 잊지 말자.
3. best solution
  1) DP 중 어려운 편
  2) row=s.length()+1, col=p.length()+1 사이즈의 bool형 2차원 배열을 생성한다.
  3) *붙은 수가 연속으로 있으면 처음부터 반복이 일어날 수 있으므로 OPT 검사를 수행한다.
    a) 이걸 하지 않으면 처음부터 반복이 일어나는 것들을 캐치할 수 없다.
  4) 2중 for문으로 하나씩 살핀다. OPT[i+1][j+1]은 현재 s[i]와 p[j]가 일치할 수 있을 때 true를 갖는다.
    a) p[j]가 '.'이거나 s[i]이면 일치하고 다음으로 넘어갈 수 있다. 따라서 OPT[i+1][j+1]=OPT[i][j]
    b) p[j]가 '*'일 때, p[j-1]이 s[i]와 다르고 '.'도 아니라면 *는 0번 반복을 해야만 한다. 그래서 OPT[i + 1][j + 1] = OPT[i + 1][j - 1]
    c) p[j]가 '*'일 때, 위의 조건이 아니라면 OPT[i+1][j+1]은 셋 중 하나여야 한다.
      - OPT[i + 1][j] 한 번만 반복
      - OPT[i][j + 1] 같은 것을 계속 반복 
      - OPT[i + 1][j - 1] 0번 반복 
```

**11) [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)**
```
1. Medium, Array, Two pointers
2. 양쪽의 값 중 작은 값을 더 큰 값이 되도록 당긴다.
  1) test에 cout을 넣으면 시간이 더 오래 걸리므로 마지막엔 제거한다.
  2) 예외처리를 적게 하는 것이 더 빠를 수도 있다.
  3) 모든 예외가 한번에 처리되는 알고리즘을 찾아라.
3. best solution
  1) 나와 크게 다른 것이 없다.
  2) 한번에 한번씩 당긴다.
  3) 실행시킬 때마다 시간이 조금 다르기도 하다.
```

**15) [3Sum](https://leetcode.com/problems/3sum/)**
```
1. Medium, Array, Two pointers
2. map과 set을 활용한다.
  1) 배열의 모든 값을 map에 넣으면서 그 수의 숫자를 증가시킨다. map<number, count>
  2) 이중 for문으로 두 값을 가리키고 map에 합이 0이 되는 나머지 값이 있는 지 확인한다.
  3) 중복된 것을 없애기 위해 결과를 set에 넣은 후 마지막에 ans에 옮긴다.
3. best solution
  0) 3개의 수 중 가장 작은 놈을 고르고 그걸로 인한 target을 설정하여 나머지 두 값을 구한다.
  1) 배열을 먼저 정렬한다.
  2) 가장 작은 값이 양수거나 가장 큰 값이 음수면 빈 매열 return
  3) 탈출조건 1 : 가장 작은 놈이 양수면 for문 break;
  4) 탈출조건 2 : 가장 작은 놈이 이전에 나왔던 놈이라면 continue; 내가 한 map의 count역할을 대체
  5) 탈출조건 3 : 가장 작은 놈과 가장 큰놈x2를 더했을 때 음수면 continue; 덜 작은놈이 나올 때까지
  6) 탈출조건 4 : 가장 작은 놈과 배열에서 가장 작은 놈x2을 더했을 때 양수면 break; ->조건1때문에 안해도 되지 않나?
  7) 가장 작은 놈과 더해서 0이 될 두 값을 찾는다.
    a) 배열 범위를 벗어나면 return
    b) 가장 작은 놈 기준 오른쪽 부분배열에서 양쪽에서 다가온다.
    c) 합이 0이 될 때 값의 대소관계를 알고 있으니 그대로 결과 vector에 넣는다.
```

**17) [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)**
```
1. Medium, String, Backtracking, Depth first Search, Recursion
2. 재귀를 사용하여 해결한다.
  1) 길이가 0일 때 빈 벡터를 return
  2) 함수 addletter()는 string과 digits 길이를 인자로 받는다.
    a) addletter()에서 탈출조건은 남은 길이 l이다. l==0 이면 ans에 s를 넣고 함수 종료
    b) digits의 해당 순서의 문자를 집어넣고 다음 재귀로 들어간다.
3. 다른 solution들과 방법이 같다.
```

**19) [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)**
```
1. Medium, Linked List, Two Pointers
2. 노드들의 포인터를 벡터에 저장하고 알맞은 위치의 포인터 하나만 바꿔줌
3. best solution
  1) vector로 저장하지 않고 n의 간격을 가진 두 포인터가 같이 전진함
  2) 속도 차이는 없음
  3) 맨 앞에 노드를 하나 더 만들면서 예외를 처리함
```

**20) [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)**
```
1. Easy, String, Stack
2. stack에 왼쪽 괄호들을 넣고 짝을 찾으면 pop. 마지막까지 수행했을 때 stack이 비어야 true를 반환
3. best solution
  1) 왼쪽 괄호를 보고 오른쪽 괄호를 stack에 넣는 방식이 다르다.
  2) 이렇게 하면 일찍 탈출하는 코드가 만들어진다.
  3) 왼쪽 괄호가 들어오면 짝이 맞는 오른쪽 괄호를 넣고, 오른쪽 괄호가 들어오면 stack.top에 자신이 있어야만 옳다.
```

**21) [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)**
```
1. Easy, Linked List
2. 화살표가 번갈아가며 나와야 한다. l1은 항상 다음 화살표의 시작이다.
  1) 가장 처음 예외의 return 조건을 붙인다.
  2) l1과 l2 중에 더 작은 val로 시작하는 놈을 ans에 넣는다.
  3) l1의 다음의 val이 l2의 val보다 클때까지 진행
  4) l1의 끝이 nullptr이면 break
  5) l1의 끝이 nullptr이 아니면 화살표를 잇고 swap
3. best solution
  1) 이 코드를 내 컴퓨터로 돌리니 시간이 똑같이 걸렸다.
  2) 새로운 ListNode* 를 만들어서 새로운 길을 만든다.
  3) 따로 빠져나가는 코드는 없다.
```

**22) [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)**
```
1. Medium, String, Backtracking
2. backtracking의 기본 문제
  1) 함수 back은 인자로 n, 남은 왼쪽 오른쪽 괄호 개수, string
  2) 규칙 : 현재까지 나온 오른쪽 괄호수는 왼쪽 괄호수를 넘을 수 없다.
  3) 왼쪽, 오른쪽 괄호를 추가하며 back을 반복한다.
```

**23) [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)**
```
1. Hard, Linked List, Divide and Conquer, Heap
2. priority queue에 모든 list를 넣어 빼면서 정답을 만든다.
  1) vector에 있는 모든 list를 pq에 넣어서 pq를 만든다.
  2) pq의 top에는 가장 작은 val의 요소가 들어있다.
  3) 정답의 가장 처음을 ans, pre에 넣는다.
  4) 이전에 top에 있던 놈을 뽑아 다음 top을 가리키는 작업을 반복
  5) 마지막 top은 자기 자신을 가리키게 되므로 next에 nullptr을 넣어준다.
3. nullptr으로라도 초기화를 해주어야 한다. 일반적인 초기화는 = new ListNode;
4. pq cmp를 구조체를 만들어서 사용한다.
5. for(auto list : lists)
6. best solution
  1) vector 양 끝의 list 두 개를 하나로 합친다.
    a) 두 list중 하나가 null이면 다른 list 한 쪽을 반환
    b) val를 비교해서 작은 val을 가진 list의 next에 mergeTwoLists(l1->next, l2)에 넣는다.
    c) mergeTwoLists(l1->next, l2)에서 나오는 것은 다음 두 list 중 작은 놈이다.
    d) 작은 놈을 return한다.
  2) 1을 수행하면 vector의 길이는 반이 되고 vector의 길이가 1이될 때까지 수행한다.
```

**32) [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)**
```
1. Hard, String, Dynamic Programming, Stack
2. stack의 top에 유효하기 시작한 곳의 index를 넣으면서 해결
  1) stack을 만들고 가장 초기 위치를 표시하기 위해 -1을 넣는다.
  2) 문자가 '('일 때는 그 때의 index를 stack에 넣음
  3) 문자가 ')'일 때는 stack.pop(); 그러면 유효한 곳의 시작은 이전 '('의 위치가 된다.
  4) stack이 비어있지 않으면 현재 index와의 거리를 계산해서 result에 더 큰 값을 넣음
  5) 만약 ')'가 너무 많이 들어와서 stack에 아무것도 없을 경우에만 stack에 ')'의 index를 넣어 유효한 곳의 시작이 된다.
  6) ')'가 연속되더라도 이전 ')'는 없어지고 새로운 ')'가 쌓이는 방식이므로 ')'로 쌓일수 있는 stack의 높이는 최대 1이다.
```

**33) [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)**
```
1. Medium, Array, Binary Search
2. Brute force 로 해결
3. best solution
  1) helper를 재귀로 이용하여 binary search 방식을 사용
  2) 첫 번째 if문으로 n[mid]가 돌아간 배열의 앞 or 뒤인지 확인. 즉, 돌아가기 전 배열의 시작이 mid의 왼쪽 or 오른쪽인지 확인
  3) 두 번째 if문으로 target이 mid 왼쪽 or 오른쪽인지 확인.
  4) 확인된 쪽을 helper에 넣어 return
```

**34) [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)**
```
1. Medium, Array, Binary Search
2. 모든 target을 binary search로 찾고 그중 가장 작은 위치와 큰 위치를 찾아서 반환
3. best solution 1
  1) lower_bound()와 upper_bound로 target의 시작 index와 target보다 큰 값의 시작 index를 구하여 범위를 구한다.
4. best solution 2
  1) sol 1과 비슷하지만 좀 더 깔끔하다.
  2) lower_bound() 반환값이 last이거나 target을 가리키지 않을 때 upper_bound를 하지 않을 수 있는 장치가 되어 있다.
  3) 반환을 {-1,-1} 식으로 vector<int>를 반환한다.
5. iterator에서 begin()을 빼면 몇 번째 인자 인지 알 수 있다.
6. 내 컴퓨터로 돌렸을 때 3가지 방법 모두 같은 시간이 걸렸다.
```

**39) [Combination Sum](https://leetcode.com/problems/combination-sum/)**
```
1. Medium, Array, Backtracking
2. best solution
  1) candidates를 정렬한다.
  2) backtracking으로 답을 구한다.
    a) begin을 인자로 받으면서 각 후보자로 시작하는 조합을 구한다.
    b) combination에 후보자를 넣고 target에 도달하면 그 때의 조합을 ans에 넣는다.
3. 후보자 넣기 -> backtracking -> 후보자 빼기   => 이 구조를 잘 기억하라.
```

**41) [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)**
```
1. Hard, Array
2. my solution
  1) nums를 하나씩 보고 301 이하의 숫자면 chk에 true로 표시
  2) chk를 살펴보면서 가장 먼저 false가 나온 인자를 반환
3. best solution
  1) nums를 정렬 (sort)
  2) 앞에서부터 하나씩 보면서 a와 같으면 a를 증가시킨다.
  3) 빈 부분이 있다면 a는 더이상 증가되지 않고 그대로 반환됨
  4) 시간복잡도는 내 방법이 더 좋다.
```

**42) [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)**
```
1. Hard, Array, Two Pointers, Stack
2. my solution
  1) 높이와 index를 pair로 만들어 priority_queue에 넣는다.
  2) 같은 높이를 가진 원소를 모두 꺼내서 그 기둥들의 최소, 최대 idx를 구한다.
  3) 이전에 검사하지 않은 범위 내에서 더 낮은 기둥과의 차이를 ans에 더해준다.
3. best solution
  1) 역방향으로 height를 보면서 maxRight를 채운다.
    a) maxRight : idx에서 오른쪽을 봤을 때 가장 높은 기둥
  2) 정방항으로 height를 보면서 total을 채운다.
    a) maxH : idx에서 왼쪽을 봤을 때 가장 높은 기둥
    b) 물의 높이 : 왼쪽에서 볼때의 최대와 오른쪽에서 볼 때의 최대 중 더 작은 값
    c) 그 최대값이 기둥의 높이와 같다면 물의 높이는 0
    d) 현재가 이전보다 높으면 total에 더해지는 것이 없음
```

**45) [Jump Game II](https://leetcode.com/problems/jump-game-ii/)**
```
1. Hard, Array, Greedy
2. DP로 풀면 시간 초과였다.
2. my solution
  1) 범위(idx ~ end)를 정하고 그 범위를 for문으로 훑으면서 가장 멀리갈 수 있는 끝 위치를 next에 저장하고 마지막에 end로 올겨준다.
  2) 가장 멀리갈 수 있는 위치의 idx를 저장한다.
  3) 이 for문이 한 번 진행될 때 ans++
```

**46) [Permutations](https://leetcode.com/problems/permutations/)**
```
1. Medium, Backtracking
2. my solution
  1) backtracking의 일반적인 방식으로 해결
  2) 노드에 가능한 모든 노드를 자식으로 두고 유망성을 검사하여 아래로 내려갈 지 결정
  3) 끝까지 내려간 것을 결과로 저장
3. best solution
  1) 내 방식과 거의 동일하다.
  2) 차이 1 : 유망성을 검사하는 함수에 value만 넣고 비교
  3) 차이 2 : 유망성을 검사하는 함수를 inline 함수로 선언
  4) 차이 3 : temp에 값을 넣고 유망성 검사를 하지 않고 유망성 검사를 통과한 후 값을 넣는다.
```

**48) [Rotate Image](https://leetcode.com/problems/rotate-image/)**
```
1. Medium, Array
2. my solution
  1) 하나하나 회전해서 새로운 곳에 넣어 저장 후 나중에 copy
3. best solution
  1) 새로운 2차원 배열을 생성하지 않고 진행한다.
  2) 하나의 위치가 4번 돌면 자기 자신으로 돌아온다.
  3) 2차원 배열의 한 사분면만 하면 나머지가 다 채워진다.
```

**49) [Group Anagrams](https://leetcode.com/problems/group-anagrams/)**
```
1. Medium, Hash Table, String
2. my solution
  1) map을 만들었다. 정렬된 문자열이 key이고 value에 원래의 문자열을 넣었다.
  2) 모든 문자열을 map에 넣은 후 map의 모든 노드의 value를 결과로 반환하였다.
3. best solution
  1) 내 코드보다 아주 조금 빠르다.
  2) map보다 unordered_map이 조금 더 빠르다.
  3) 내 for문 안의 if문을 map[str].emplace_back(origin); 한줄로 바꿀 수 있다.
```

**53) [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)**
```
1. Easy, Array, Divide and Conquer, Dynamic Programming
2. best solution
  1) 단 하나의 for문으로 O(n)으로 해결한다.
  2) 처음부터 쭉 누적 값을 더하고 누적값이 0보다 작을 때는 0으로 되돌린다.
  3) 누적이 음수면 최대 누적값을 구하는데 도움이 되질 않는다.
```

**55) [Jump Game](https://leetcode.com/problems/jump-game/)**
```
1. Medium, Array, Greedy
2. my solution
  1) 벡터 처음부터 하나씩 살피면서 최대 어디까지 갈 수 있는 지 체크
  2) 최대 갈 수 있는 곳이 마지막 위치 이상이 되면 true 반환
  3) 최대 갈 수 있는 곳이 마지막 위치 이상이 되기 전에 끝이 나면 false
2. best solution
  1) 나와 반대의 방향으로 진행(배열 뒤에서 앞으로)
  2) 해당 index 위치까지 도달할 수 있으면 d=1로 초기화 됨
  3) 내 코드와 같은 속도
```

**56) [Merge Intervals](https://leetcode.com/problems/merge-intervals/)**
```
1. Medium, Array, Sort
2. my solution
  1) sort를 진행
  2) 이전 범위의 끝과 현재 범위의 시작이 겹치는 지 확인
    a) 겹치면 ans 초기화
    b) 안겹치면 ans를 anss에 넣고 ans에 현재 범위를 넣는다.
  3) for문 이후 마지막 ans를 anss에 넣는다.
2. best solution
  1) 범위 중 가장 끝 값 max를 구한다.
  2) sum(int)과 tag(bool)를 max 크기만큼 0으로 채운다.
  3) 범위의 시작과 끝이 같으면 tag는 true, 다르면 sum[l]++, sum[r]--
  4) sum의 처음부터 끝까지 누적 값을 넣는다.
  5) sum이 0일 때는 범위가 포함된 것이 아니므로 while로 left를 증가시켜 건너뛴다.
    a) 건너뛰더라도 tag가 true면 포함한다.
  6) left가 max보다 크면 break;
  7) sum이 양수일 때까지 right를 증가시킨다.
  8) 범위를 res에 넣고 다음 tag를 false로
```

**62) [Unique Paths](https://leetcode.com/problems/unique-paths/)**
```
1. Medium, Array, Dynamic Programming
2. my solution
  1) 조합(순서에 상관 없는 쌍)을 구하는 문제이지만 조합으로 풀면 시간 초과
  2) 2차원 배열을 만들고 첫번재 열과 첫번째 행은 1로 채운다.
  3) map[i][j] = map[i-1][j] + map[i][j-1] 방식으로 채운다.
```

**64) [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)**
```
1. Medium, Array, Dynamic Programming
2. my solution
  1) 62번 문제와 같은 방법
  2) map의 의미는 해당 위치까지의 가장 작은 합의 경로이다.
  3) map 배열에서 왼쪽 혹은 위쪽에서 합이 작은 경로를 통해 도착하도록 한다.
```

**70) [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)**
```
1. Easy, Dynamic Programming
2. my solution
  1) 기본적인 DP문제, DP문제라는 것을 파악할 줄 아는 것이 중요하다.
  2) 피보나치 수열
```

**72) [Edit Distance](https://leetcode.com/problems/edit-distance/)**
```
1. Hard, String, Dynamic Programming
2. my solution
  1) 이차원벡터 dp의 의미는 dp[i][j]까지의 최소 edit distance이다.
  2) word1[i]==word2[i]라면 추가되는 작업이 없으므로 dp[i][j]=dp[i-1][j-1]
  3) 다르다면 삭제할 수 있으므로 dp[i][j-1] or dp[i-1][j], 대체할 수 있으므로 dp[i-1][j-1]에 작업량 1을 더한다.
```

**75) [Sort Colors](https://leetcode.com/problems/sort-colors/)**
```
1. Medium, Array, Two Pointers, Sort
2. my solution
  1) sort를 직접 구현
  2) 0, 1, 2의 개수를 count하고 nums에 넣는다.
```

**394) [Decode String](https://leetcode.com/problems/decode-string/)**
```
1. Medium, Stack, DFS
2. my solution
  1) vector로 2개의 stack을 사용하였다.
  2) 주어진 string을 하나씩 살펴본다.
  3) 숫자일 때, num을 최신화시킨다. 이전에도 숫자였으면 이전값*10 에 더한다.
  4) 여는 괄호일 때, 숫자가 끝났으므로 repeat stack에 넣는다. wasnum은 false가 되고 string stack에 ""를 push하여 새로운 시작을 한다.
  5) 닫는 괄호일 때, stack의 마지막을 pop하여 repeat 수만큼 뒤에 붙인다.
  6) 문자일 때, stack의 string 뒤에 쌓는다.
3. best solution
  1) 재귀를 사용하였고 my sol과 속도는 같다.
  2) 숫자가 나올때까지 char를 더해간다.
  3) 숫자가 나오면 반복되는 총 횟수를 찾기 위해 while을 돈다.
  4) 숫자가 끝나면 괄호를 건너띄기 위해 i++를 하고 다음 위치부터 다시 decode를 한다.
  5) decode로 나온 문자열을 ret에 반복하여 더해준다.
```

**1047) [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)**
```
1. Easy, Strack
2. my solution
  1) string ans에 S를 하나씩 넣는다.
  2) 만일 ans의 top이 넣으려는 S와 같다면 top을 pop
3. best solution
  1) 동일한 방법
  2) idx 변수를 쓰지 않고 ans.back을 사용
```

**1209) [Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)**
```
1. Medium, Strack
2. my solution
  1) string을 ans와 벡터 count를 stack으로 활용한다.
  2) 인자로 받은 string s를 하나씩 보고 ans를 채운다. (1047번과 동일)
  3) count의 해당 idx에 지금까지 몇 번 중복되었는지 표시한다.
  4) 중복횟수가 인자로 받은 k와 같아질 때, ans에서 중복되는 부분 문자열을 삭제하고 idx를 뒤로 돌린다.
3. best solution
  1) stack counts를 사용하고 반환할 string은 인자로 받은 string을 사용한다.
  2) j는 답을 만드는데 쓰이는 index이다.
  3) s[j]에 s[i]를 넣고 둘이 다르거나 j==0이면 counts에 1을 쌓는다.
  4) 둘이 같다면 counts를 증가시키면서 k와 비교해본다.
  5) k와 같다면 count.top을 pop 하고 j를 k만큼 감소시킨다.
```

**1704) [Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)**
```
1. Easy, String
2. my solution
  1) string을 넣으면 모음의 개수를 반환하는 함수를 생성
  2) 인자로 받은 string을 반으로 나누어 모음의 개수를 비교
```

**1705) [Maximum Number of Eaten Apples](https://leetcode.com/problems/maximum-number-of-eaten-apples/)**
```
1. Medium, Heap, Greedy
2. my solution
  1) 사과를 받으면 언제까지 먹을 수 있는 사과가 몇 개인지 pq에 넣는다.
    a) {언제까지 먹을 수 있는지, 남은 사과가 몇 개인지}
    b) 날짜가 빠른 순으로 정렬된다.
  2) 그리고 먹을 수 있는 사과가 있는지 pq의 top을 살펴본다.
    a) 날짜가 지났으면 pop()
    b) 안지났으면 pop()한 후 사과를 하나 빼고 push (사과가 0개면 넣지 않는다.)
3. best solution
  0) p는 포인터
  1) for문을 last만큼 돌리는 데 last는 for문안에서 사과가 남는 마지막 날에 맞춰 최신화된다.
  2) d가 apples의 길이보다 작을 때 if문 실행
    a) 사과 기한일을 ne에 저장
    b) dp[기한일]에 사과의 개수를 더한다.
    c) ne가 p보다 작으면 p=ne, ne가 last보다 크면 last=ne
  3) p가 last보다 작을 때, dp[p]가 0이고(p 날짜에 끝나는 먹을 사과가 없고) p<=d(오늘 이전에 끝난 사과)라면 p를 증가
  4) dp[p]가 0이 아니라면 먹을 사과가 있으므로 먹을 사과를 줄이고(dp[p]--) cnt++
```

**1706) [Where Will the Ball Fall](https://leetcode.com/problems/where-will-the-ball-fall/)**
```
1. Medium, Dynamic Programming
2. my solution
  1) 공 하나씩 떨어뜨린다.
  2) 끝까지 도달하면 그 공 index에 마지막에 몇번재 col에서 떨어졌는지 입력
  3) '\'일 때 오른쪽이 '/'이거나 현재 col이 오른쪽 끝이면 break하여 다음 공을 확인
  4) '/'일 때 왼쪽이 '\'이거나 현재 col이 왼쪽 끝이면 break하여 다음 공을 확인
```
