// 문제해결프로젝트 2주차 과제 - 탐색하기 3
// 192992 이준연
#include <cmath>    // abs 연산의 수행을 위해!!
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

int findIndex(int data[], int n) {
    int sum = 0;    // 합 저장
    int x = 0;    // 첫 번째 원소와 이후 원소들 비교하며 값을 찾을거기 때문!!

    for (int i = 0; i < n; i++) {
        // 원소의 총합을 먼저 구한다!!
        sum += data[i];
    }

    for (int j = 0; j < n; j++) {
        int dx = abs(n*data[x] - sum);
        int dj = abs(n*data[j] - sum);

        // 점차 평균과의 거리가 더 좁은 것을 x로 갱신
        if (dj < dx) {
            x = j;
        }
    }

    return x + 1;   // 실제로는 인덱스 번호보다 1 많기 때문(기존 숫자 번호)
}

int main() {
    int n;
    int* data;

    scanf("%d", &n);    // 전체 데이터 수 입력
    data = new int[n];  // 원소 개수가 n인 정수형 배열

    for (int i = 0; i < n; i++) {
        // n개의 수치 데이터 입력하기
        scanf("%d", &data[i]);
    }

    int answer = findIndex(data, n);

    printf("%d %d", answer, data[answer-1]);    // answer는 기존 index보다 1 많은 값 포함

    delete[] data;

    return 0;
}