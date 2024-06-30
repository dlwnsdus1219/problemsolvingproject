// 프로젝트2: 종이
// 192992 이준연
// 용봉이는 격자형으로 선 그어진 직사각형 종이 가지고 1*1 크기의 정사각형 종이 얻으려고 한다.
// 하지만 전남이가 대각선으로 종이를 잘라버린 상황, 직사각형 종이가 크기가 같은 2개의 정사각형으로 나뉘어버린 상황!!
// 용봉이는 이 상황에서 몇 개의 정사각형 종이를 얻을 수 있을까?
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<time.h>    // 코드의 구동 시간 측정을 위해 해당 라이브러리를 설치해준다

using namespace std;
#define ITERATION_TIME 100000

// 입력: 가로(W)와 세로(H) --> 이 둘은 각각 1억 이하의 자연수입니다!!
// 출력: 만들 수 있는 1 * 1 크기의 정사각형의 개수!!

// 문제 풀이 원리
// 가로의 길이, 세로의 길이의 최대 공약수를 G라고 치자. 
// 가로, 세로를 각각 G로 나눈 것만큼의 직사각형이 하나의 단위이며, 이 똑같은 단위가 총 G번 반복!!
// 그리고 직사각형 내에서, 짤리는 (정)사각형의 개수는 가로 + 세로 - 1!!
// 앞에서, 똑같은 단위가 G개만큼 반복되는 것이므로 결국 잘리는 사각형의 개수는 (가로 + 세로 - 1) * G = 전체 가로 + 전체 세로 - G입니다.
// 결론: 얻을 수 있는 1 * 1 정사각형의 개수는, 결국 전체 넓이에서, (전체 가로 + 전체 세로 - G) 이거 하나만 빼주면 끝이다!!

// 최대 공약수를 구하는 함수
int gcd(long long a, long long b) {
    int gr_div = 1; // default 값은 먼저 1로 초기화
    int range = min(a, b); // 가로, 세로 중 더 작은 값까지 순차적으로 최대공약수 계산

    // 본격적으로 최대 공약수를 구하는 과정
    for (int i = 1; i <= range; i++) {
        // 1보다 큰 수 중에서 공약수가 있을 경우 지속적으로 gr_div 갱신!!
        if ((a % i == 0) && (b % i == 0)) {
            gr_div = i;
        }
    }

    return gr_div;
}

// 위에서 설명한 원리를 바탕으로, 얻을 수 있는 1 * 1 크기의 정사각형의 개수를 구하는 함수
void square(long long x, long long y, int z) {
    long long answer = 1;   // 우선 결과 저장할 변수의 기본값을 1로 세팅한다.
    answer = (x * y) - (x + y - z);   // 앞에서 언급했던 방식으로 answer 값을 갱신해준다!!

    std::cout << answer << "\n";

}

int main() {
    long long w, h;
    int c;
    long long area; // 일단 정답 저장할 변수 선언
    std::cin >> w >> h;

    //clock_t: clock_ticks의 자료를 담고 있는 자료형으로, clock()의 반환형이다!!
    clock_t start = clock(); // 시작 시간 저장

    c = gcd(w, h);  // 가로와 세로의 최대공약수 저장!!

    square(w, h, c);    // 가로, 세로, 최대공약수 데이터 얻은 걸 바탕으로 1*1 정사각형의 개수 얻는다.

    clock_t end = clock(); // 코드가 끝난 시간 저장!!

    // 걸린 시간 출력
    std::cout << "걸린 시간: " <<  (double)(end - start)/CLOCKS_PER_SEC << "초" << std::endl;

    return 0;
}
