// 문제해결프로젝트 9주차 실습과제 - 6A. 괄호문자열
// 192992 이준연
#include <iostream>
#include <stack> // last in first out: top에 있는 데이터만 삽입. 삭제 가능!!
#include <string>
#include <vector>

// 괄호 문자열(PS): 두 개의 괄호 기호('(', ')') 만으로 구성되어 있는 문자열
// 괄호 모양이 바르게 구성? --> Valid PS
// 한 쌍의 괄호 기호로 구성? --> 기본 VPS
// if x가 VPS? -> 이를 하나의 괄호에 넣은 새로운 문자열 "(x)"도 VPS가 된다!!
// 두 VPS x, y를 접합? -> xy 얘도 VPS가 된다!!
// "(())()"와 "((()))" 는 모두 VPS이지만, "(()(", "(())()))"는 모두 VPS가 아니다!!

// 입력된 문자열이 VPS인지 아닌지 판단하라?

// 입력: test case 개수(첫째 줄), 그 이후로 test case 문자열들 차례로 입력
// 출력: 주어진 문제에 대한 해답(Yes or No)

using namespace std;
class Parenthesis {
    public:
        bool type;
        int index;

        // Parenthesis를 구성하는 인자 index, type의 선언!!(생성자 정의)
        Parenthesis(int index, bool type) {
            this -> index = index;
            this -> type = type;
        }

        // 괄호 문자 여부에 따른 생성자 정의!!
        Parenthesis(int index, char c) {
            this -> index = index;
            if (c == '(') { 
                this -> type = true;    // 열린 괄호면 true
            } else {
                this -> type = false;   // 열린 괄호가 아니면 false
            }
        }
};

// 괄호들의 정보가 차례대로 배열 형태로 주어질 때, 올바른 괄호 문자열인가?
bool isValidParentheses(const vector<Parenthesis>& parenthesis) {
    // 벡터 내 괄호를 하나씩 순차적으로 정의한다!!
    // 현재 짝을 찾지 못한 괄호를 저장!!
    // 닫힌 괄호? -> 탑에 저장된 괄호 삭제!!
    stack<Parenthesis> st;

    for (int i = 0; i < parenthesis.size(); i++) {
        Parenthesis p = parenthesis[i]; // 좌 -> 우로 차례대로 조회한다!!

        if (p.type == true) {
            // 열린 괄호라면 true!!
            st.push(p);
        } else if (p.type == false) {
            // 닫힌 괄호라면 false

            if (st.size() > 0) {
                // 가장 마지막에 추가된 열린 괄호와 짝은 맞출 수 있음 -> 제거 ㄱㄱ
                st.pop();
            } else {
                // 짝 맞출 수 있는 열린 괄호 없다 -> 올바르지 않은 괄호 문자열!!
                return false;
            }
        }
    }
}

void process(int caseIdx) {
    string str;
    cin >> str; // 테스트 할 문자열을 먼저 입력한다!!

    vector<Parenthesis> parentheses; // 벡터 변수의 선언!!
    // 벡터는 (front ~ back) 모든 위치의 원소에 접근 가능함!!
    // 반면, 스택은 탑 위치의 원소만 접근 가능함
    for (int i = 0; i < str.length(); ++i) {
        parentheses.push_back(Parenthesis(i, str[i]));   // 앞에서 class 선언 -> 문자열 하나씩 열린 괄호 여부 판단 ㄱㄱ
    }

    bool isValid = isValidParentheses(parentheses); // 올바른 괄호 문자열인지 여부 판단 ㄱㄱ


    // 결과에 따라 YES or NO 출력
    if (isValid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int caseSize;  // 테스트 케이스 개수 n
    cin >> caseSize;

    for (int caseIdx = 1; caseIdx <= caseSize; caseIdx++) {
        process(caseIdx);
    }
}