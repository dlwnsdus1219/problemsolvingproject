// 문제해결 프로젝트 4주차 과제 - 2E. 소수의 판별
// 192992 이준연
#include<cstdio>
#include<iostream>

using namespace std;

//입력: T(테스트 케이스 개수), 각 테스트 케이스 별로 한 줄에 자연수 하나씩
//출력: 테스트 케이스 번호를 1과 T 사이 자연수로 출력

bool isPrime (int N){
    // 소수의 판별? --> 약수가 1, 자기자신 포함 2개!!
    // int count = 0; // 약수의 개수 담는 변수
    // for(int i=1; i<=N; i+=1){ // N의 약수의 개수 판별
    //     if (N % i == 0){
    //         count++;
    //     }
    //     if (count >= 3){    // 가지치기 기법 통해서 연산량 감소(어차피 약수개수 3 넘으면 소수 아니야)
    //         break;
    //     }
    // }
    // if (count != 2){    // 소수인지 아닌지 여부 판단!!(소수면 true, 아니면 false)
    //     return false;
    // }else{
    //     return true;
    // }

    // 2번째 방법: 2부터 제곱근 n까지 탐색 후 나누어 떨어지는 수가 없으면 소수라고 판단할 수 있다!!
    // 이때는 시간복잡도 O(sqrt(n))
    if (N==1) return false; // 어차피 1은 소수가 아니기에!!
    for (int i=2; i*i <= N; i++){   // sqrt(N) 하면 소수가 나오므로 연산 복잡해짐 --> i <= sqrt(N) 대신 i*i <= N으로 대체
        if (N % i == 0){
            return false;   // 2부터 sqrt(N) 사이에 나누어 떨어지는 수? --> 이미 소수가 아니다(false)
        }
    }

    return true;
    
}

// testcase별로 소수인지, 아닌지에 대한 여부 출력!!
void testcase(int caseIndex){   
    int n;
    scanf("%d", &n);    // caseIndex 번째 case에서 판단할 정수 입력한다!!

    bool result = isPrime(n);   // 해당 숫자가 소수인지 아닌지 판단해 준다!!
    printf("Case #%d\n", caseIndex);
    if(result) {
        printf("YES\n");
    } else{
        printf("NO\n");
    }
}

int main(){
    int caseSize;
    scanf("%d", &caseSize); // casesize 입력하여 작업을 몇 번 수행할지 결정
    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1){  // caseSize 번 만큼 testcase 수행!!
        testcase(caseIndex);
    }
}