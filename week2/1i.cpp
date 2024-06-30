//문제해결프로젝트 2주차 과제 - 선택 정렬
// 192992 이준연
#include <cstdio>
#include <iostream>

using namespace std;

// 0 ~ n-1 번째 데이터 중 최솟값 찾아 첫 원소와 위치 변경
// 1 ~ n-1 번째 데이터 중 최솟값 찾아 두 번째 원소와 위치 변경

// 특정 범위에서, 최소의 원소를 가지는 인덱스 찾기
int getMinIndex(int data[], int n, int begin, int end) {
    int min = begin;
    for (int i = begin; i <= end; i++) {
        if (data[begin] > data[i]) {
            // 더 작은 원소가 있으면 그 때마다 최소 인덱스 갱신
            min = i;
        }
    }

    return min;
}

// 선택 정렬 함수
void selectionSort(int n, int data[]) {
    for (int i = 0; i < n; i++) {
        // 0 ~ n-1, 1 ~ n-1 ... 등등 차례대로 최소의 원소를 찾고, i번째 인덱스 원소와 맞바꾼다
        int minIdx = getMinIndex(data, n, i, n - 1);

        // 이제 최소 원소와 맞바꾼다
        int temp = data[minIdx];
        data[minIdx] = data[i];
        data[i] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);    // 전체 데이터 수 n 입력

    int* data;
    data = new int[n];  // 동적 배열 할당 ㄱㄱ

    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);  // n개의 정수 데이터 입력
    }

    selectionSort(n, data);

    // 선택 정렬 끝마친 배열을 출력한다!!
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", data[i]);
    }

    delete[] data;
    return 0;
}