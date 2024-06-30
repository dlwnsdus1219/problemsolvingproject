// 문제해결프로젝트 2주차 과제 - 탐색하기 2
// 192992 이준연
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// 첫, 마지막 인덱스를 출력하는 함수 구현
void printIndexes(int n, string* s) {
    // 일단 모든 인덱스의 초기값은 -1로 설정!!
    int firstIdx = -1;
    int lastIdx = -1;

    // for문을 통해 찾고자 하는 데이터가 있는지 찾아준다!!
    for (int i = 0; i < n; i++) {
        if (s[i] == "AJOU") {
            // 인덱스 갱신(firstIdx는 한 번만!!)
            if (firstIdx == -1) {
                firstIdx = i + 1;
            }

            lastIdx = i + 1;
        }
    }

    printf("%d %d\n", firstIdx, lastIdx);
}

int main() {
    int n;
    scanf("%d", &n);    // 사람(데이터) 수 입력

    string* s;  // string 가리킬 동적 배열 선언
    char buff[11];  // 최대 10글자의 문자열을 입력할 버퍼!!

    s = new string[n];  // string 동적 배열 할당

    for (int i = 0; i < n; i++) {
        scanf("%s", buff);  // 문자열을 입력 후, 버퍼에 저장함
        s[i] = buff;   // 입력한 문자열을 school 배열에 저장한다
    }

    printIndexes(n, s); // 함수 호출

    delete[] s; // 동적 메모리 해제
    return 0;
}