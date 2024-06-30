// 문제해결 프로젝트 11주차 실습과제 - 6H. 중복 제거하기
// 192992 이준연
#include <iostream>
#include <set> 
// set의 장점: 특정 멤버 함수 찾는 메커니즘이 매우 빠르게 작동한다!!
// 시간복잡도: O(log2N)으로 낮은 편!!

// 입력: 테스트 케이스 수 N, 이후 N줄에 거쳐서 하나씩 정수 입력(20만 이하)
// 출력: 각 정수에 대한 중복 여부 결과(OK or DUPLICATED)

// 보통은 이중 for문으로 해결할 수 있는 문제 --> 시간 복잡도가 높다!!

using namespace std;

int main() {
    int n;  // 주어진 정수의 개수 n
    scanf("%d", &n);    // 입력 ㄱㄱ

    set<int> s; // 여태까지 등장했던 정수를 모두 저장한다 -> 사실 이걸 통해서 중복 제거 의도

    for (int i = 0; i < n; i++) {
        // 테스트 케이스 개수에 맞게 각 정수를 입력한다!!
        int x;
        scanf("%d", &x);

        // 해당 숫자가 있는지 찾아본다!!
        // 아래 조건문 말고 s.count(x) > 0으로 찾아도 가능!!
        if (s.find(x) != s.end()) {
            printf("DUPLICATED\n"); // 중복 O
        } else {
            s.insert(x);        // 중복 안된다 -> 아예 첨 등장 -> s에 삽입 ㄱㄱ
            printf("OK!\n");    // 중복 X
        }     
    }
    return 0;
}