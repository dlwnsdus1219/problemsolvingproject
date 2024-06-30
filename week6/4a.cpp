// 문제해결 프로젝트 6주차 과제 - 4A. 스도쿠 보드
// 192992 이준연
#include<cstdio>

// 나머지 연산의 특징 고려해서 문제 해결할 수 있다!!

// 입력: 테스트케이스 개수 T, 각 테스트 케이스 별로 지수가 말한 칸의 번호
// 출력: 테스트 케이스 별로 행, 열, 그룹 번호를 출력한다.

using namespace std;

// 스도쿠 판은 9 * 9 구조!! --> 아래와 같이 행/열의 최대치를 정의해 준다!!
const int MAX_ROW = 9;
const int MAX_COL = 9;

class SudokuBoard {
    public:
        //칸 번호로 행 번호 계산하는 메서드
        int getRowByIndex(int index) {
            //칸 번호에 대해 마디 가지고 증가 --> 몫으로 계산 가능!!
            return (index - 1) / 9 + 1; // 해당 인덱스 - 1을 9로 나눈 몫에서 1을 더해준다!!
        }

        //칸 번호로 열 번호 계산하는 메서드
        int getColByIndex(int index) {
            //칸 번호에 대해 규칙적 순환 --> 나머지로 계산 가능!!
            return (index - 1) % 9 + 1;
        }

        // 칸 번호로 그룹 번호 계산하는 메서드
        int getGroupByIndex(int index) {
            int r = getRowByIndex(index);
            int c = getColByIndex(index);
            return getGroupByPosition(r, c);
        }

        //칸의 위치(행, 열)로 그룹 번호 계산 메서드
        int getGroupByPosition(int row, int column) {
            // 행 번호 통해, 해당 행에 존재하는 그룹 중 가장 왼쪽의 그룹 번호를 알 수 있다
            int left = ((row - 1) / 3) * 3 + 1; // 나올 수 있는 값: 1, 4, 7
            // 열 번호 통해, 해당 행에 존재하는 그룹들 중 몇 번째 그룹에 속하는지 알 수 있다
            int offset = ((column - 1) / 3);    // 나올 수 있는 값: 0, 1, 2
            return left + offset;
        }

        //칸의 위치(행, 열)로 칸의 번호 계산하는 메서드
        int getIndexByPosition(int row, int column) {
            //행, 열 번호 알면 반대로 인덱스도 쉽게 계산 가능!!
            return (row - 1) * 9 + (column - 1) % 9 + 1;
        }
};

// 입력받은 숫자에 대해 행, 열, 그룹번호 알아내서 출력
void process(int caseIndex) {
    int index;
    scanf("%d", &index);    // 인덱스 입력

    SudokuBoard board = SudokuBoard();  // 스도쿠보드 클래스 위에 정의해놓았습니다

    int row = board.getRowByIndex(index);   // 칸의 번호로 행의 번호를 계산한다!!
    int col = board.getColByIndex(index); // 칸의 번호로 열의 번호를 계산한다!!
    int group = board.getGroupByIndex(index); // 칸의 번호로 그룹의 번호를 계산한다!!

    printf("Case #%d:\n", caseIndex);
    printf("%d %d %d\n", row, col, group);

}

int main() {
    int caseSize;
    scanf("%d", &caseSize); // testcase 수 입략

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex); // 숫자에 대해서 해당 숫자에 대해 행, 열, 그룹 번호 출력!!
    }

    return 0;
}