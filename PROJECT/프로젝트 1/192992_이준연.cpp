// 문제해결프로젝트 프로젝트 1 -  192992 이준연
// 시침과 분침이 가리키는 방향을 보고 시계 고장 여부를 알려주는 코드를 작성하시오?
#include<iostream>
#include<stdio.h>
#include<time.h>    // 코드의 구동 시간 측정을 위해 해당 라이브러리를 설치해준다

using namespace std;
#define ITERATION_TIME 100000

// 입력: 시침, 분침이 각각 이루는 각도!!(12시 기준)
// 출력: 시계의 각도 정상 여부에 따라 O/X 출력, 그 다음줄에 전체 코드 수행 시간 출력

void clockisBroken(int x, int y){
    // O 출력
    int b = x % 30; // 시침이, 정각으로부터 얼마나 흘러갔는지 측정!!(n시 몇 분인지 알아낼 수 있다!!)
    int c = b * 12; // 시침이 흘러간 정도를 토대로 얻은 분 수만큼, 분침이 움직인 정도 측정(시침이 1도 움직일 때, 분침은 12도 움직인다는 가정)

    // 앞서 구했던 분침이 움직인 정도와, 분침의 각도를 비교하여 둘이 같으면 시계 각도 정상 판정!!(아니면 X)
    if (c == y) {
        std::cout << "O\n";
    } else {
        std::cout << "X\n";
    }
    

    // X 출력
}

int main() {
    
    int a, b; // 시침과 분침의 각도 저장할 변수 호출!!
    
    std::cin >> a >> b; // 변수 입력

    //clock_t: clock_ticks의 자료를 담고 있는 자료형으로, clock()의 반환형이다!!
    clock_t start = clock(); // 시작 시간 저장
    
    clockisBroken(a, b);    // 시계 고장 여부를 위해 함수 호출!!
    

    clock_t end = clock(); // 코드가 끝난 시간 저장!!

    // 걸린 시간 출력
    // printf("걸린 시간: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
    std:cout << "걸린 시간: " <<  (double)(end - start)/CLOCKS_PER_SEC << "초" << std::endl;

    return 0;
}