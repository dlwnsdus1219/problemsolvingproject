// 문제해결프로젝트 3주차 과제 - 2A. 도토리 키재기
// 192992 이준연
#include<iostream>  // C++ 표준 입력 라이브러리
#include<cstdio>

using namespace std;

// 입력
// 도토리의 수, N개의 도토리의 키 데이터, N개의 도토리들의 생일이 속한 달, 현재 달(M)

// 출력
// 이번 달에 생일인 도토리 중 가장 키가 큰 도토리?(없으면 -1 출력한다)

int getMaximumHeight(int height[], int month[], int n, int m){
    int answer = -1;    // 없으면 -1 출력하므로, 얘를 default 값으로 설정한다
    for (int i = n-1; i >= 0; i--) {
        // 뒤에서부터 계산(오름차순이므로 일부러 키 큰사람 일찍 찾는다 -> 가지치기 기법)
        if (month[i] == m) {
            answer = height[i]; // 가장 큰 키를 가지는 도토리의 키 대입 ㄱㄱ
            break;  // 정답 찾으면 break 한다!!
        }
    }

    return answer;  // 최종 정답 도출
}

int main(){
    int n, m;  // 도토리의 수
    int* height;
    int* month;

    scanf("%d", &n);    // 도토리의 수 N 입력!!
    height = new int[n];    // N개의 도토리의 키
    month = new int[n]; // N개의 도토리의 생일이 속한 달!!

    for (int i = 0; i < n; i++) {
        // n개의 도토리의 키 입력
        scanf("%d", &height[i]);
    }

    for (int i = 0; i < n; i++) {
        // n개의 도토리의 생일 달 입력
        scanf("%d", &month[i]);
    }

    scanf("%d", &m);    // 현재 달 입력 ㄱㄱ

    int answer = getMaximumHeight(height, month, n, m);

    printf("%d\n", answer);

    delete[] height;
    delete[] month;
    
}

// 시간 복잡도?
// main 함수 for문 2개: O(n)
// getMaximumHeight 함수: O(n)
// 결과: O(n) * 3 = O(n)
