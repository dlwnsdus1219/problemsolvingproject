// 기말고사 2번 - 192992 이준연
#include <iostream>
#include <climit>

const max_value = INT_MAX;

bool ifSieve(int n) {
    int count = 0;
    for (int i = 2; i * i  = n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    if (count == 0) {
        return true;
    } else {
        return false;
    }
}

void process(int caseIdx) {
    int l, r;
    int answer = 0;
    scanf("%d %d", &l, &r);   // 두 자연수 L과 R 입력

    for (int i = l; i <= r; i++) {
        if (ifSieve(i)) {
            answer += 1;
        } 
    }

    printf("Case #%d:\n", caseIdx);
    printf("%d", answer);
}

int main() {
    int caseSize;  // 테스트 케이스의 개수 입력
    scanf("%d", &caseSize);

    for (int caseIdx = 1; caseIdx <= caseSize; caseIdx++) {
        process(caseIdx);
    }

    return 0;
}