// 프로젝트3: 직사각형
// 192992 이준연
// 1부터 N까지 각각 번호가 주어진 N개의 사각형이 주어진다.
// 용봉이는 x축 위에다 번호 순서대로 왼쪽에서 오른쪽으로 밀착시켜서 사각형을 붙이려고 한다.
// x축과 맞닿는 변은 짧은 변, 긴 변 상관없으며, 용봉이는 이 사각형의 윗둘레가 가장 길게 되도록 사각형을 놓으려 한다.
// (윗둘레란, x축과 붙어있는 바닥과 양 옆 사이드 변의 길이를 제외한 것을 말한다!!)
// 이 때, 윗둘레를 길게 만들고 해당 윗둘레의 길이를 구하시오?
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<vector>
#include<numeric>   // 후술할 accumulate 메서드 실행을 위해 선언한다
#include<time.h>    // 코드의 구동 시간 측정을 위해 해당 라이브러리를 설치해준다

using namespace std;
#define ITERATION_TIME 100000

// 입력: 테스트 케이스 개수(첫째줄), 그 이후로 각 테스트 케이스의 두 변의 길이 입력(공백 구분)
// 출력: 양의 정수로 최대 윗둘레를 출력한다


// 문제 풀이 원리
// 문제 내 숨은 규칙을 파악해 본 결과, 홀수번째 케이스에서는 더 긴 변이 x축과 맞닿게,
// 짝수번째 케이스에서는 더 짧은 변이 x축과 맞닿게 설계하면 윗둘레가 최대가 되게 나온다!!
// 각 사각형의 긴 변과 짧은 변은 각각의 벡터로 놓은 다음, 각 변의 대소 비교 과정을 통해 각 윗변들의 사이 변의 길이까지 구하고 다 더해준다.

// n번째 사각형에서 n+1번째 사각형으로 넘어갈 때 발생하는 높이의 차(윗둘레에 더해주는 용도)
int lineminus(int x, int y) {
    // 말그대로 변의 길이는 양수이므로, 더 긴 변에서 더 짧은 변을 빼줘야한다
    if (x >= y) {
        return x - y;
    } else{
        return y - x;
    }
}


int main() {
    int n;  // 테스트 케이스 개수 입력
    int sum; // 전체 윗둘레 길이 저장할 변수 선언
    std::cin >> n; // 테스트 케이스 개수를 먼저 입력한다.

    vector<int> smaller;    // 더 짧은 변의 길이를 저장할 변수
    vector<int> bigger; // 더 긴 변의 길이를 저장할 변수
    vector<int> upperline;  // 윗둘레 길이를 구하는 데에 쓰이는 변들의 길이를 저장

    // 각 test case의 변들을 for문을 통해서 입력받는다
    for(int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        // 더 긴 변은 bigger로, 더 짧은 변은 smaller로 push_back 해준다
        if (a <= b) {
            smaller.push_back(a);
            bigger.push_back(b);
        } else {
            smaller.push_back(b);
            bigger.push_back(a);
        }
    }
    
    //clock_t: clock_ticks의 자료를 담고 있는 자료형으로, clock()의 반환형이다!!
    clock_t start = clock(); // 시작 시간 저장

    // 최대 윗둘레를 구하는 데 필요한 변을 구하는 과정 (1) - 기존 test case에서 필요한 변 고르기
    for(int j = 0; j < n; ++j) {
        if(j % 2 == 0) {    // 홀수 번째 케이스(인덱스는 0부터 시작하므로 인덱스 기준으로는 짝수번째)에서는 더 긴 변이 x축과 맞닿는다. 고로 자연스럽게 윗변도 더 긴 변이 된다.
            upperline.push_back(bigger[j]);
        }
        else {  // 짝수 번째 케이스에서는 위와 반대로, 더 짧은 변이 x축과 맞닿게 설계한다.
            upperline.push_back(smaller[j]);
        }
    }

    // 최대 윗둘레를 구하는 데 필요한 변을 구하는 과정 (2) - 맞닿는 변의 차를 이용하여 n번째 사각형에서 n+1번째 사각형으로 넘어갈 때 생기는 변의 길이를 구한다.
    for(int k = 0; k < n-1; ++k) {  // n개의 사각형이 있을 때, 사각형 하나에서 다른 사각형으로 넘어갈 때의 횟수를 for문의 케이스 수로 정해야, 우리가 원하는 답을 얻을 수 있다.
        // 이번엔 위의 for문에서 쓰이지 않은 변들을 대상으로 lineminus 함수를 돌려서 반환값을 upperline에 저장한다.
        if (k % 2 == 0) {   
            upperline.push_back(lineminus(smaller[k], bigger[k + 1]));
        } else{
            upperline.push_back(lineminus(bigger[k], smaller[k + 1]));
        }
    }

    // accumulate 벡터 내 저장된 모든 인자들의 합을 구하기 위해 아래와 같이 accumulate 메서드를 사용해준다.
    sum = accumulate(upperline.begin(), upperline.end(), 0); // accumulate(시작 위치, 마지막 위치, 구하고자 하는 합의 초깃값)

    std::cout << sum; // 우리가 구하고자 하는 최대 윗둘레의 합을 출력한다.


    clock_t end = clock(); // 코드가 끝난 시간 저장!!

    // 걸린 시간 출력
    std::cout << "걸린 시간: " <<  (double)(end - start)/CLOCKS_PER_SEC << "초" << std::endl;

    return 0;
}