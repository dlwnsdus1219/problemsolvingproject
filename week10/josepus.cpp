// 문제해결 프로젝트 10주차 실습과제 - 6D. 조세퍼스 문제
// 192992 이준연
#include <iostream>
#include <vector>
#include <queue>    // queue 변수 사용 위해 헤더파일 선언!!

using namespace std;

// N명의 사람들 중, 테스트 케이스가 M인 경우, M번째 사람 제거, 
// 그 이후로 M+1번째부터 다시 시작하여 M-1번째 이후 사람 제거하는 식으로 반복....

// ex) 4, 2 --> 2 4 3 1
//     7, 3 --> 3 6 2 7 5 1 4
// 입력: 첫째 줄에는 테스트 케이스 개수 T, 이후 테스트 케이스 입력받아
// 출력: 각 플레이어가 제거된 순서대로 출력한다!!

class Player {
    public:
        int index;

        // 플레이어의 인덱스 생성자
        Player() {
            this -> index = 0;
        }

        Player(int index) {
            this -> index = index;
        }
};

// 직접 죽은 사람을 찾아 나가는 함수
vector<Player> getDeadPlayers(int n, int m, const vector<Player>& players) {
    // 현재 게임에서 제외된 플레이어 리스트?
    vector<Player> deadPlayers;

    // 아직 게임에서 제외 안 된 플레이어들(한 명씩 빼고 다시 뒤로 넣고 반복...)
    queue<Player> qwer;

    // 일단 큐에 모든 플레이어 다 때려넣기
    for (int i = 0; i < n; i++) {
        qwer.push(players[i]);
    }

    for (int j = 0; j < n; j++) {
        // m + 1명의 사람을 건너 뛴다!!
        int jump = m;
        for (int k = 0; k < jump - 1; k += 1) {
            Player p = qwer.front();
            qwer.pop();
            qwer.push(p);
        }

        // m번째 사람 제외 ㄱㄱ
        Player dead = qwer.front();
        qwer.pop();

        // 제외한 사람은 리스트에 추가한다
        deadPlayers.push_back(dead);
    }
    return deadPlayers;

}

// 테스트 케이스 메소드
void testcase(int caseIndex) {
    int n, m;
    scanf("%d %d", &n, &m); // n: 전체 사람의 수, m: 사람을 제외해 나가는 간격

    vector<Player> players; // 각 플레이어를 담을 벡터 선언!!

    for (int i = 0; i < n; i++) {
        players.push_back(Player(i + 1));
    }

    // 죽은 플레이어 벡터 형태로 반환 받는다!!
    vector<Player> dead = getDeadPlayers(n, m, players);

    for (int i = 0; i < n; i++) {
        // 공백으로 구분 ㄱㄱ
        if (i > 0) {
            printf(" ");
        } 

        Player p = dead[i];
        printf("%d", p.index);  // getDeadPlayersList를 통해 제외된 플레이어의 리스트(인덱스)를 차례로 출력 ㄱㄱ
    }
    printf("\n");
}

int main() {
    int caseSize;   
    scanf("%d", &caseSize); // 테스트 케이스 수 입력

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1){
        // 테스트 케이스 수 만큼 테스트 케이스 실행한다
        testcase(caseIndex);    
    }

    return 0;
}