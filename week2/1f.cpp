// 문제해결프로젝트 2주차 과제 - 탐색하기 1
// 192992 이준연
#include<stdio.h>
#include<iostream>

using namespace std;

// 해당 원소가 위치한 인덱스를 찾아라!!
int findIndex(int data[], int n, int m) {
    int index = -1; // 일단 초기값을 -1로 설정

    for (int j = 0; j < n; j++) {
        // 차례대로 m이 있는지 확인(배열 내에서)
        if (data[j] == m) {
            index = j;  // 만약 찾으면 해당 인덱스로 업데이트
        }
    }

    return index;

}

int main() {
    int n, m;   // 정수의 개수, 배열 내에서 찾고자 하는 수
    int *data;  // 동적 배열 가리킬 포인터 할당

    scanf("%d %d", &n, &m); // 숫자 입력

    data = new int[n];  // 동적 배열 할당
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);  // 배열 내 원소 입력
    }

    int answer = findIndex(data, n, m);

    printf("%d", answer);

    delete[] data;  // 동적 메모리 해제!!
    return 0;
}

