// 문제해결프로젝트 7주차 실습과제 - 3I. 새 카드
// 192992 이준연
#include <stdio.h>
#include <vector>
#include <algorithm> // 이진 탐색, sort 위해선 반드시 필요한 헤더!! 

using namespace std;

/* 입력: 사용할 카드의 수 N, 당첨 번호의 수 M,
    두 번째 줄에는 N개의 카드에 적힌 숫자들(공백으로 구분), 
    세 번째 줄에는 M개의, 이번주에 사용될 당첨번호들!!*/ 

/* 출력: M개의 당첨번호들 중, 실제로 세 카드에 적힌 숫자의 합으로 표현 가능한 당첨번호들!!
    만약, 당첨번호가 여러개라면 오름차순 정렬, 각 숫자는 공백으로 구분하여 한 줄에 출력
    만들 수 있는 당첨번호가 없다면 NO를 출력한다!!!*/

// 표현 가능한 당첨번호를, 벡터에 담아서 오름차순으로 출력하는 함수!!
vector<int> getPossibleTargets(int n, int m, int cards[], int targets[]) {
    vector<int> possibleTargets;    // 만들 수 있는 당첨 번호들

    // 이진 탐색을 위해, 일단 모든 카드를 오름차순 정렬한다
    sort(cards, cards + n); // sorts(시작주소, 시작주소 + 배열크기)

    // 모든 타깃 k를 대상으로 수행한다!
    for (int i = 0; i < m; ++i) {
        int k = targets[i];
        bool possible = false;  // 일단 기본 값 false로 설정 ㄱㄱ(binary 서치 값 성립 -> true로 추후에 변경)

        for (int j = 0; j < n; ++j) {
            int x = cards[j];   // 모든 카드 중 하나인 x에 대해서 수행 ㄱㄱ
            for (int p = 0; p <= j; p++) {
                // 숫자 조합의 중복 제거
                int y = cards[p];   // 카드 중 하나 y를 선택
                int z = k - (x + y);    // k = (x + y) + z가 되는 z를 계산 ㄱㄱ

                // 만약 숫자 z가 cards 내에 존재한다면?(feat. binary search)
                if (binary_search(cards, cards + n, z) == true) {   // 시작 위치, 끝 위치, 찾을 값
                    possible = true;    // k = x + y + z가 가능!!
                    break;  // 찾고자 하는 값을 찾음 -> for문 탈출
                }
            }
            if (possible) {
                // 이미 찾았으면 for문 탈출!
                break;
            }

        }

        if (possible) {
            // 세 카드의 합으로 k를 만들 수 있다면, possibleTargets 벡터에 추가한다!!
            possibleTargets.push_back(k);
        }
    }

    sort(possibleTargets.begin(), possibleTargets.end());   //우리가 찾은 표현 가능한 당첨번호들, 모두 오름차순으로 정렬해준다!!
    return possibleTargets; // 오름차순까지 끝나면 벡터 반환!!
}

// main 함수 선언
int main() {
    int n;  // 카드의 수
    int m;  // 검사 할 당첨번호의 수
    scanf("%d %d", &n, &m);

    int *cards = new int[n]; // n개의 카드
    int *targets = new int[m]; // m개의 당첨번호

    // 각 카드의 정보 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    // 각 후보 당첨번호를 입력받는다
    for (int i = 0; i < m; i++) {
        scanf("%d", &targets[i]);
    }

    vector<int> answers = getPossibleTargets(n, m, cards, targets); // 반환 가능한 당첨 번호를 찾기 위해 함수 호출!!

    if (answers.size() == 0) {
        // 가능한 당첨번호가 없으면 NO를 출력한다!!
        printf("NO");
    } else {
        // 가능한 당첨번호가 존재하면 그 목록을 출력
        for (int i = 0; i < answers.size(); i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", answers[i]);
        }
    }

    // 동적 메모리 할당되었던 거 초기화
    delete[] cards;
    delete[] targets;

    return 0;
}