// 문제해결 프로젝트 6주차 과제 - 소인수 분해
// 192992 이준연
#include <cstdio>
#include <vector>

using namespace std;

// 자연수를 소인수분해하고, 그에 대한 모든 소인수를 출력하라?
// 입력: 테스트케이스 개수 T, 그 이후 각 테스트 케이스 입력(각 자연수는 2 이상, 10억 이하)
// 출력: 테스트 케이스에 대한 정답을 두 줄씩 출력한다!!(첫줄: 테스트 케이스 번호, 둘쨰 줄: 입력으로 주어진 숫자들의 소인수 공백으로 구분 후 출력)

vector<int> factorize(int n) {
    // 소인수 분해 함수
    vector<int> factors;

    // 본격적인 소인수 분해 과정
    for (int div = 2; div * div <= n; div++) {
        // sqrt(n) 이하의 모든 자연수에 대해서!!
        while(n % div == 0) {
            // div가 N의 약수이다 -> div보다 작은 약수는 모두 처리되었으므로 div는 소인수임이 보장!!

            // 소인수로 판정된 div를 factors에 추가!!
            factors.push_back(div);

            // 기존 자연수 n에서 div를 소거한다(div 나누고 남은 몫으로 연산 ㄱㄱ)
            n /= div;
        }
    }
}

// 소인수분해 본격 수행
void process(int caseIndex) {
    int n;
    scanf("%d", &n);

    // 소인수분해 수행하기
    vector<int> factors = factorize(n);

    printf("%d\n", caseIndex);  // 몇 번째 case인가?

    for (int i = 0; i < factors.size(); ++i) {
        // 각 test case마다 나온 소인수를 출력한다!!
        if (i > 0) {
            printf(" ");
        }
        printf("%d", factors[i]);
    }
    printf("\n");
}

// main 함수
int main() {
    int caseSize;
    scanf("%d", &caseSize);

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex){
        process(caseIndex); // process 수행(테스트 케이스)
    }
    return 0;
}

