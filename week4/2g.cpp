// 문제해결프로젝트 4주차 과제 - 2G. 버블 정렬
// 192992 이준연
#include<iostream>
#include<cstdio>

// 버블 정렬이란?: 배열 내, 이웃한 두 원소의 값을 비교하고 더 큰 값이 뒤로 오게 자리 바꾼다
// 선택 정렬, 버블 정렬 모두 시간 복잡도 O(n)
// 그러나 평균적으로 실제 연산량은 버블 정렬이 더 적어? --> 버블 정렬이 더 빠릅니다!!

using namespace std;

// 입력: 데이터의 수 N, N개의 정수(공백으로 구분)
// 출력: N개의 오름차순으로 정렬된 숫자들!!(공백으로 구분)

// 버블 정렬 수행 함수
void bubbleSort(int data[], int n) {
    for (int i = 0; i < n; i++) {
        int negativecount = 0;
        for (int j = 0; j < n-1-i; j++) {
            // 오름차순 여부를 위해 원소를 하나씩 비교한다
            if (data[j] > data[j+1]) {
                // 오름차순 아니면, 2개의 값 자리를 바꾼다
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                negativecount++;
            }
        }

        // 이미 오름차순이 되어버린 경우?
        if (negativecount == 0) {
            break;
        }
    }
}

int main() {
    int n;
    int* data;

    scanf("%d", &n);    // 데이터의 개수 n 입력
    data = new int[n];

    for (int i = 0; i < n; i++) {
        // 데이터 입력
        scanf("%d", &data[i]);
    }

    bubbleSort(data, n);    // 버블 정렬 수행(배열에 대해서)

    for (int i = 0; i < n; i++) {
        // bubbleSort 이후의 배열 값 출력
        if (i > 0) {
            printf(" ");
        } 
        printf("%d", data[i]);  
    }

    delete[] data;
    return 0;
}