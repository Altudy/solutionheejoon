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
