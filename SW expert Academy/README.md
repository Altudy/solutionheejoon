SW expert Academy / c++
------------------

[8856. 북북서](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW1BsILa2X0DFARC&categoryId=AW1BsILa2X0DFARC&categoryType=CODE&&&)

```
1. 기약분수로 표현하기 위해 분모와 분자를 따로 계산한다.
2. 45로 묶었을 때 분자는 2의 지수승이 순차적으로 더해지고 분모는 2^(n-2)로 고정이다.
3. 가장 마지막에 '서'가 있을 때는 0도 이므로 계산하지 않도록 한다. 
4. '북', '서', '북서', '서북' 을 if문으로 예외처리한다.
```

[1768. 숫자야구게임](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4su3xKXFUDFAUf)

```
1. from leechanwoo
2. main.cpp가 주어지고 참고되는 doUserImplementation() 함수만 작성하면 된다. 문제 이해 어려움.
3. 미리 작성된 query() API를 사용하고 예상 숫자와 비교하고 결과를 확인할 때마다 query 수가 증가한다. query가 적을수록 유리.
4. 가능한 숫자 조합을 초기 작업으로 구하여 배열에 저장한다.
5. query()로 결과를 받았을 때 정답을 배열에 있다고 가정하고 fake_query로 같은 결과가 나오는 것만 살린다. -> 핵심. 후보를 제거하는 방법.
```

[9229. 한빈이와 Spot Mart](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW8Wj7cqbY0DFAXN)

```
1. greedy algorithm
2. 가장 크게 가져갈 수 있는 물건부터 집는다. 범위를 넘어가면 바로 다음 것을 집는다.
3. index를 잘 정해주어야 한다.
```

[8016. 홀수 피라미드](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWvzGUKKPVwDFASy)

```
1. 수학
2. 공식을 찾아서 간단하게 풀었다.
3. pow() 함수는 double형을 반환하기에 e^ 형태로 값이 출력되므로 주의하라.
```

[8771. 덧셈 문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW3R9ga6F9wDFATy&categoryId=AW3R9ga6F9wDFATy&categoryType=CODE&&&&&&)

```
1. 시간 줄이는 문제
2. 공식과 예외만 처리하면 쉽다.
3. endl 말고 "\n" 사용하여 통과했다.
```

[4259. 제곱수의 합 계산하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWLL3yk6ALUDFAUW)

```
1. 구현, 큰수
2. my solution
  1) 하나의 수를 받으면 solution에 넣는다.
  2) 지수 expo와 지수 아래의 수 a를 구한다.
  3) temp[0]=1 로 시작해서 각 자리에 a를 곱한다.
  4) 각 자리에서 10을 넘어가는 carry를 이후 index에 더해주고 자신은 일의 자리만 남긴다.
  5) expo만큼 위를 반복한 후 temp의 각 자리의 수를 sum 각 자리에 더한다. 동시에 carry도 처리한다.
  6) 하나의 case에서 주어진 수를 모두 처리하면 앞의 0을 제외하고 출력한다.
3. 999^9는 long long int의 범위를 넘어서기 때문에 새로운 방식을 사용해야한다.
```
