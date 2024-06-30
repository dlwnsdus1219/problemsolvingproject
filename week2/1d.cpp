#include<stdio.h>
#include<iostream>

using namespace std;
// 정수 n개가 주어졌을 때, 이들의 합을 구하시오?

// n개의 정수 합을 구하는 함수
int getSum(int data[], int n) {
    int answer = 0; // 0으로 일단 초기화

    for (int i = 0; i < n; i++) {
        answer += data[i];  // 순차적으로 배열의 원소 더해 나감
    }

    return answer;
}

int main() {
    int n;  // 데이터 개수 n
    int *data;  // n개의 정수 담을 배열 가리킬 동적 배열 포인터 선언
    
    scanf("%d", &n);    // n 입력

    data = new int[n];  // 동적 배열의 선언!!
    for (int i = 0; i < n; i++) {
        scanf("%d", data[i]);   // 배열의 원소 직접 입력
    }

    int answer = getSum(data, n);

    printf("%d", answer);   // answer 출력

    delete[] data;
    return 0;
}