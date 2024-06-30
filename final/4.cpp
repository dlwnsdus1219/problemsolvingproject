// 기말고사 4번
// 192992 이준연
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a, b;   // 현재 시각(시, 분)
    int c;  // 요리하는 데에 필요한 시간

    int d, e;   // 종료 시간의 시, 분 선언

    scanf("%d %d", &a, &b);
    scanf("%d", %c);

    e = b + c;

    while (e < 60) {
        e = b - 60;
        d = a + 1;
    }

    if (d >= 24) {
        d = d % 24;
    }

    printf("%d %d", &d, &e);
    
}