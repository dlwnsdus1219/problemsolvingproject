// 문제해결 프로젝트 2주차 과제 - 합구하기 2
// 192992 이준연
#include<iostream>
#include<stdio.h>

using namespace std;

//void 함수: 리턴값이 딱히 없을 때 사용한다!!
void solve(int data[], int n, int p, int q)
{
    // 1. 체중 제한을 통과한 인원 수 알아보자!!
    int count = 0;  // 놀이기구 탈 수 있는 사람
    int weight_sum = 0; // 놀이기구 탈 수 있는 사람의 중량 합

    for (int j = 0; j < n; j++) {
        if (data[j] <= p) {
            count += 1; // 인원 수 증가
            weight_sum += data[j];  // 중량 합 증가
        }
    }

    printf("%d %d", count, weight_sum);

    // 2. 체중제한 통과한 아이들은 모두 다 같이 탈 수 있는가?
    if (weight_sum <= q) {
        printf("YES\n");    // 통과
    } else {
        printf("NO\n");     // 통과 X
    }
}

// main 함수
int main()
{
    int n, p, q;    // 동아리 회원 수, 놀이기구 탑승 제한, 놀이기구 최대 하중
    int *data;  // 동아리 회원들 몸무게 담을 배열 가리키는 포인터

    scanf("%d %d %d", &n, &q, &q);

    data = new int[n];  // 배열의 동적 할당
    for (int i = 0; i < n; i++) {
        scanf("%d", data[i]);   // 동아리 회원들의 몸무게 입력
    }

    solve(data, n, p, q);

    delete[] data;
    return 0;
}