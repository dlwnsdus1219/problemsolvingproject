// 문제해결 프로젝트 4주차 과제 - 2H. 소수의 판별
// 192992 이준연
#include<cstdio>
#include<iostream>

// 반지름이 임의의 R픽셀인 원이 포함하는 픽셀의 수는?

using namespace std;

// 입력: 테스트케이스 수 T, 각 테스트 케이스(반지름 입력)
// 출력: 입력에 대한 정답(반지름이 R인 원이 포함하는 픽셀 수)

bool isInside(long long x, long long y, long long R){
    long long sqd = x*x + y*y;
    // x^2 + y^2 < R^2 --> 해당 좌표가 원 안에 있다!!
    if(sqd < R * R){
        return true;
    } else{
        return false;
    }
}

void testcase(int caseIndex){
    long long R;    // int형 범위 넘어서는 값도 출력한다
    scanf("%lld", &R);

   long long sum = 0;   // 1사분면에 존재하는 총 픽셀의 수
   long long y = R;
   for(long x = 0; x <= R; x++){ // x: 0 ~ R까지 모두 확인(차례대로)
        long long height = 0;
        for(long long y = R; y >= 0; y--){
            if(isInside(x, y, R)){  // y: R부터 0까지 모두 확인(차례대로)
                // 위에서부터 내려오면서, 해당 픽셀이 원 안에 있는가 판단
                // 이 그룹의 높이는 y+1이 된다
                height = (y + 1); 
                break;
            }
        }
        sum += height;  // 너비는 1이므로!!
   }

   printf("#%d\n", caseIndex);
   printf("%lld\n", sum * 4); // 각 사분면 내 픽셀 수 * 4 = 원 내 픽셀 수!!
}

int main(){
    int caseSize;
    scanf("%d", &caseSize);
    for(int caseIndex=1; caseIndex<=caseSize; caseIndex+=1){
        testcase(caseIndex);    // 원 안에 들어오는 픽셀 수 return!!
    }
    return 0;
}