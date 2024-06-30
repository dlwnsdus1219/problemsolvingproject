// 문제해결 프로젝트 5주차 과제 - 3D. 피보나치 나머지
// 192992 이준연
#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE;

// 입력: 테스트 케이스 수 T, 그 다음 줄부터 테스트 케이스
// 출력: 각 테스트 케이스 별로 한 줄에 정답을 출력한다(단, 숫자 가장 앞의 0들은 생략)

// 피보나치 수열의 1~n 번째 항을 미리 저장 후 반환
vector<int> makeFibonacciTable(int n) {
    const int MOD = 10000000;   // 피보나치 수의 마지막 8자리 출력을 위해 미리!!

    // 미리 피보나치 배열 선언
    vector<int> ret(n + 1);
    ret[1] = 0; // 첫 항은 0
    ret[2] = 1; // 두 번째 항은 1

    // 세 번째 항부터는 피보나치 정의 ㄱㄱ
    for (int i = 3; i <= n; ++i) {
        ret[i] = ret[i - 1] + ret[i - 2];

        // 모듈러 값을 이용 -> 뒤에 8자리만 남게 ㄱㄱ
        ret[i] %= MOD;
    }

    return ret;
}

int getFibo(int n) {
    int answer = FIBONACCI_TABLE[n];    // 미리 계산해 놓은 피보나치 테이블 값 반환 ㄱㄱ(피보나치 테이블은 전역 변수라 어디서든 접근 가능)
    return answer;
}

int main() {
    FIBONACCI_TABLE = makeFibonacciTable(MAX_N);    // 전처리를 통해 미리 계산한다

    int caseSize;   // 테스트 케이스 개수 입력
    scanf("%d", &caseSize);

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        int n;
        scanf("%d", &n);    // 피보나치 계산할 정수 입력

        // 피보나치 수열의 n번째 항은?
        int answer = getFibo(n);
        printf("%d", answer);
    }

    // 이제 안 쓰면 배열 할당 해제!!
    FIBONACCI_TABLE.clear();

    return 0;
}
