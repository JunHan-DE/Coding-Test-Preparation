# 다이나믹 프로그래밍 
***한번 계산한 문제는 다시 계산하지 않는다. ***
-----
## 사용 조건 
 1. 큰 문제를 작은 문제로 나눌 수 있음 
 2. 작은 문제에서의 정답이 큰 문제에서도 포함됨. 
 
## 설계전략 
 1. 작은 문제부터 해결 (재귀 관계식 정립)
 2. 인덱스를 조정하며 중복계산 회피
 3. 작은 문제의 해를 모아 다음 단계의 문제 해결에 사용
-------
## 설명 

다이나믹 프로그래밍은 보통 `상향식 해결법(bottom-up)` 방식
(`메모제이션 기법`을 통하여 분할정복처럼 `하향식 해결법(top-down)`도 사용 가능(엄밀히 말하면 DP는 아님))

* 상향식(bottom-up) 해결법 : `DP table`을 이용 
* 하향식(top-down) 해결법 : `메모제이션`을 이용

> 근데 사실 DP table이나 memozation이나 똑같음. 그냥 결과값 리스트 or 행렬에 넣어서 중복 계산 
> 피하게끔 하는 용도 ㅇㅇ

#### What is Top-dwon & bottom-up method? 
* 하향식 해결법(Top-down method)  : `재귀 함수`를 이용하여 큰 문제를 작은 문제로 쪼개서 해결 
* 상향식 해결법(Bottom-up method) : `반복문`을 이용하여 작은 문제로부터 큰 문제 해결

#### cf. 분할정복과의 차이점 
분할정복 - 분할된 요소들이 서로 영향을 미치지 않음 
DP         - 분할된 요소들이 서로 영향을 미침 
                 ex) DP로 구현된 피보나치 수열은 각 노드의 결과값이 다른 노드 계산에도 쓰임 

--------

## 예제 

피보나치 수열 (top-down/ 메모제이션 사용)
``` python

#한번 계산된 결과를 메모제이션하기 위한 리스트 초기화

d = [0] * 100

def fiob(x):

    if x == 1 or x == 2:
        return 1
    
    if d[x] != 0:
        return d[x]
    
    d[x] = fibo(x - 1) + fibo(x - 2)
    
    return d[x]
    
print(fibo(99))
```
피보나치 수열 (bottom-up/ dp table 사용) - 다이나믹 프로그래밍의 예 
``` python

#한번 계산된 결과를 저장하기 위한 DP 테이블 초기화

d = [0] * 100

d[1] = 1
d[2] = 1
n = 99
    
for i in range(3, n+1):
    d[i] = d[i - 1] + d[i - 2]

print(d[n]
```
------
