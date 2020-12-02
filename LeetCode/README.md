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
