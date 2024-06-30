// 문제해결프로젝트 2주차 과제 - 합구하기 3
// 192992 이준연
#include<stdio.h>
#include<iostream>

using namespace std;

// 누적합 구하기 문제
// (1) + (1+2) + (1+2+3) + ... + (1+2+3+...+n) 의 값은??

// 1이상 n 이하 모든 자연수의 합을 구해주는 함수
int getRangeSumFromOne(int i) {
    int answer = 0;
    for (int j = 0; j <= i; j++) {
        answer += j;
    }
    return answer;
}

// 누적합을 구해주는 함수
long long getAnswer(int n) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += getRangeSumFromOne(i+1); // 1부터 N까지 모든 자연수에 대해 getRangeSumFromOne을 시행해준다
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);    // 정수 n 입력받는다!!

    long long answer = getAnswer(n);    // int형 연산에서 초과되는 범위 다룬다 -> long long(8바이트) 사용

    printf("%lld\n", answer);

    return 0;
}