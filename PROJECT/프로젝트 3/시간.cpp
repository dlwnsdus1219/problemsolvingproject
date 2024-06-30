// 프로젝트3: 시간
// 192992 이준연
// 공대생이 인문대생과 약속을 잡았다. 각 공대생은 한 명의 인문대생을 만날 예정이지만, 공대생은 약속 시간보다 빨리 혹은 늦게 도착할 수 있다.
// 그로 인해, 기다리는 시간을 최소화하고자 모든 약속 시간은 T씩 조정하려고 하는데, 대기 시간이 최소가 되게 하는 서로 다른 정수 T의 개수를 구하라?
// (대기 시간이란 참고로, 먼저 도착한 사람이 늦게 도착한 사람을 기다리는 시간을 의미하며
// 공대생의 약속 시간을 A1, 도착 시간을 B1이라고 할 때, 시간을 T만큼 조정했다고 하면 대기 시간은 |A1 + T - B1|이 된다)

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<time.h>    // 코드의 구동 시간 측정을 위해 해당 라이브러리를 설치해준다

using namespace std;
#define ITERATION_TIME 100000

// 입력: 테스트 케이스 개수(첫째 줄), 각각 test case별로 약속시간, 도착시간 입력(공백 구분)
// 출력: 대기 시간의 합이 최소인 서로 다른 정수 T의 개수를 출력한다

// 문제 풀이 원리
// 절댓값 함수의 합이 최소가 되려면? --> 각 항을 0으로 만드는 숫자를 각각 a라고 치면, a값들의 중간값을 찾는다
// 1. test case가 홀수일 경우 --> 무조건 답이 1(이때는 중간값이 정해짐)
// 2. test case가 짝수인 경우 --> 중간값이 없으므로, n/2와 n/2 - 1번째의 원소의 사이의 원소 개수를 반환한다!!


int main() {
    int n; // 테스트 케이스 개수
    
    vector<int> midtime; // 중간값 time을 일단 저장할 벡터 선언

    std::cin >> n; // 테스트 케이스 입력(개수)

    // for문을 통해 test case를 입력받는다.
    for (int i = 0; i < n; ++i) {
        int app, arr; // 각각 약속 시간, 도착 시간 저장 변수 선언
        std::cin >> app >> arr; //  약속 시간과 도착 시간을 입력받는다
        midtime.push_back(app - arr);   // 약속 시간과 도착 시간을 뺀 값을 일단 넣는다
        // 각 test case의 a - b값을 기준으로 합을 최소가 되게 만들 수 있으므로 해당 값들을 구해서 일단 벡터에 저장한다.
    }
    
    //clock_t: clock_ticks의 자료를 담고 있는 자료형으로, clock()의 반환형이다!!
    clock_t start = clock(); // 시작 시간 저장

    sort(midtime.begin(), midtime.end()); // 중간값을 찾아주는 게 목적이므로 정렬을 기본으로 해 준다.

    if (n % 2 == 1) {   // test case가 홀수일 때는 항상 답이 1!!
        std::cout << 1;
    } else {    // test case가 짝수일 때는 n/2번째 원소와 n/2-1번째 원소 사이의 값 개수를 출력
        std::cout << midtime[n/2] + midtime[n/2 - 1] + 1;
    }

    clock_t end = clock(); // 코드가 끝난 시간 저장!!

    // 걸린 시간 출력
    std::cout << "걸린 시간: " <<  (double)(end - start)/CLOCKS_PER_SEC << "초" << std::endl;

    return 0;
}
