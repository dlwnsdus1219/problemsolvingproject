// 기말고사 1번 - 192992 이준연
#include <iostream>
#include <cstdio>

using namespace std;

void findOreum(int n, int data[]) {
    int count = 0;  // 오름차순을 셀 정수

    for (int i = 0; i < n - 1; i++) {
        if (data[i] > data[i + 1]) {
            // 학생들의 키가 오름차순인지 본격적으로 판단해 준다.
            // 만약 앞의 학생이 뒤의 학생보다 키가 크다면 1을 더해주는 식으로!!
            count += 1;
        }
    }


    // count가 0보다 커졌다는 의미는 즉, 이미 오름차순이 깨졌다는 의미로, count가 0이 아니라면 NO를 출력한다
    if (count != 0) {
        printf("NO\n");
    } else {
        // 그리고 count가 0 그대로라면 YES를 출력한다. 
        printf("YES\n");
    }
}

int main() {
    int n;
    int* data;

    scanf("%d", &n);    // 학생들의 수 입력

    new data = int[n];  // 학생들의 총 키 입력할 배열

    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);  // 학생의 키 입력!
    }

    findOreum(n, data); // 함수 통해 오름차수 여부 판단한다
}
