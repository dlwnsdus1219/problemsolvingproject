#include<stdio.h>
#include<iostream>

using namespace std;

//키가 비슷한 사람의 수 찾기
int findPerson(int data[], int n, int m, int s) {
    int count = 0;  // 사람의 수

    // 키가 같은 사람의 수 세기!!
    for (int j = 0; j < n; j++) {
        if (data[j] == m || data[j] == s) {
            count += 1; // 찾을 때마다 count 수 증가
        }
    }

    return count;

}

// main 함수
int main() {
    int n, m, s;    // 전체 사람 수, 미주 키, 지수 키
    int *data;  // 사람들 키 담을 동적 배열 가리키는 포인터

    scanf("%d %d %d", &n, &m, &s);  // 정수들 입력 받기

    data = new int[n];  // 사람들 키 입력받을 배열 동적 할당받기
    for (int i = 0; i < n; i++) {
        // 사람들 키 입력받기
        scanf("%d", &data[i]);
    }

    // findPerson 함수 통해 정답 도출
    int answer = findPerson(data, n, m, s);
    
    printf("%d\n", answer); // 정답 출력!!

    delete[] data;  // 동적 할당 받은 배열 해제
    return 0;

}