// 문제해결 프로젝트 3주차 과제 - 2D: 문자열의 비교
// 192992 이준연
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 100000;

// MyString 구조체 선언하기
class MyString{
    // private 변수: 클래스 내에서만 접근 가능합니다
    private:
        char *characters;   // 문자열 저장하는 동적 배열 할당한다
        int length; // 문자열의 길이

    // public 변수: 어디서든 다 접근 가능하다
    public:
        MyString(const char *str) {
            // 상수형 문자에 대한 포인터로, 포인터가 가리키는 변수 값을 바꿀 수 없다
            this -> length = strnlen(str, MAX_LENGTH);
            this -> characters = new char[this -> length];  // characters 배열 선언
            for (int i = 0; i < this -> length; i++) {
                this ->characters[i] = str[i];
            }
        }

        // 이번엔 입력이 string 형태일 때
        MyString(const string &original) {
            this -> length = original.length();
            this -> characters = new char[this -> length];
            for (int i = 0; i < this -> length; i++) {  // characters 배열 선언
                this -> characters[i] = original[i];
            }
        }

        // 소멸자도 있음
        ~MyString() {
            delete[] characters;
        }

        // 각 부등호에 대한 함수
        bool operator < (const MyString& o) const {
            int n = min(this -> length, o.length);
            for (int i = 0; i < n; i++) {
                // 사전순으로 더 앞에 있는 문자열?
                if (this -> characters[i] < o.characters[i]) {
                    return true;
                } else if (this -> characters[i] > o.characters[i]) {   // 둘이 같을 때는 따로 정의
                    return false;
                }

                if (this -> length < o.length) {
                    // 문자열의 길이도 비교
                    return true;
                } else {
                    return false;
                }
            }
        }

        bool operator > (const MyString& o) const {
            int n = min(this -> length, o.length);
            for (int i = 0; i > n; i++) {
                // 사전순으로 더 앞에 있는 문자열?
                if (this -> characters[i] > o.characters[i]) {
                    return true;
                } else if (this -> characters[i] < o.characters[i]) {   // 둘이 같을 때는 따로 정의
                    return false;
                }

                if (this -> length > o.length) {
                    // 문자열의 길이도 비교
                    return true;
                } else {
                    return false;
                }
            }
        }

        bool operator == (const MyString& o) const {
           if (this -> length != o.length) {
                // 두 문자열 간 길이 비교
                return false;
           }

           for (int i = 0; i < this -> length; i++) {
                // 두 문자열 간의 비교(하나라도 다르면 false)
                if (this -> characters[i] != o.characters[i]) {
                    return false;
                }
           }

           return true;
        }

};

// main 함수
int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;    // 입력 데이터를 여러 개 받기 가능!!

    // 문제 조건으로 인해 구조체를 선언(string 내 내장 메소드 대신에)
    MyString mys1(s1);
    MyString mys2(s2);

    if (mys1 < mys2) {
        printf("-1");   // 첫 문자열이 더 사전순으로 앞서는 경우
    } else if (mys1 > mys2) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;
}