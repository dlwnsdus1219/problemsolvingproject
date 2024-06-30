#include<iostream>
#include<stdio.h>

using namespace std;

// 배열 내 최대 정수를 찾는 함수
int getMax(int data[], int n)
{
    // n회 반복하면서 계속해서 최댓값을 update 해나간다
    int ans = data[0];  // 초깃값은 첫 번째 원소로 설정!!

    for (int i = 0; i < n; i++) {   // 배열 원소 개수만큼 반복!!
        if (data[i] > ans) {
            ans = data[i];
        }
    }

    return ans;
}

int main()
{
    int n;  // 정수의 개수
    int *data;  // n개의 정수 담을 배열 가리키는 포인터 변수

    scanf("%d", &n);    // 정수의 개수 n 입력
    data = new int[n];  // 정수들 담을 동적 배열의 선언!!

    // 배열 내에 정수 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int answer = getMax(data, n);   // 배열에 대해 getMax 함수 실행 ㄱㄱ
    
    printf("%d\n", answer);

    delete[] data;  // 동적 할당 해준 메모리 해제 
    return 0;
}