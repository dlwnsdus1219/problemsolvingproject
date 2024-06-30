// 문제해결 프로젝트 6주차 과제 - 4B. Probing
// 192992 이준연
#include <cstdio>
#include <vector>

// 프로빙이란?
// 해시 테이블 칸 내에 숫자 저장하고 관리하는 느낌
// 입장한 고객은 자신의 회원 번호를 N(전체 행운권 수)으로 나눈 나머지를 계산 후, 그 번호와 같은 행운권을 지급받는다
// 또 만약, 해당 행운권이 이미 타인에게 지급된 것이라면, 지급 안 된 번호가 나올때까지 +1 하면서 찾아간다.(쉽게 말하면, 선형 탐사!!)
// 고객들은 순서대로 한 명씩 입장하며, 한 번 지급된 행운권 번호는 교환이 불가능하다!! 

using namespace std;

// 입력: 준비한 행운권 수 N, 팀 회원 수 M(공백으로 구분) / 그 뒤에 이어서 회원들의 회원번호 입력
// 출력: 입장 회원 순서대로 해당 회원이 지급받게 될 행운권 번호를 한 줄에 하나씩 정수 형태로 출력한다

class TicketTable {
    public:
        vector<bool> used;
        int length;

        TicketTable(int length) {
            this -> length = length;
            this -> used.assign(length, false); // 일단 길이는 length, 내부 원소들은 모두 false로 초기화한다!!
        }

        // 사용자의 회원 번호로 지급받을 행운권 번호를 계산하는 메서드
        int findEmptyIndexByUserId(int userId) {
            int index = userId % length;    // 가장 초기에 시도할 티켓 번호 == 회원권 번호 % 1
            while (this -> isUsing(index) == true) {
                // 만약 자신의 회원권 번호가 사용 중이라면
                index = (index + 1) % length;
            }
            return index;   // 사용 안 된 인덱스를 최종적으로 찾아서 반환!!
        }

        // 해당 행운권 번호가 사용 중인지를 판단!!
        bool isUsing(int ticketIndex) {
            return this -> used[ticketIndex];   // 사용여부: used[ticketIndex]
        }

        // 티켓 사용 여부의 갱신
        void setUsed(int index, bool status) {
            // default는 앞에서 이미 false로 선언함
            this -> used[index] = status;
        }
        

};

// 행운권 번호 출력
vector<int> getTicketNumbers(int n, int m, const vector<int> &ids) {
    vector<int> ret;    // 행운권 번호를 저장할, 벡터 선언 ㄱㄱ
    TicketTable table = TicketTable(n); // TicketTable 구조체 선언, length에 n 대입 ㄱㄱ -> 회원 번호에 대해 행운권 번호를 구하는 데 쓰임

    // 사람 수만큼 작업 반복 ㄱㄱ
    for (int i = 0; i < m; i++) {
        int userId = ids[i];    // 앞에서 입력했던 회원번호들
        int ticketIndex = table.findEmptyIndexByUserId(userId); // 지급이 아직 되지 않은 숫자를 찾는다.
        ret.push_back(ticketIndex);
        table.setUsed(ticketIndex, true);   // 해당 티켓 번호가 사용 중이면, true로 상태 바꾼다
    }

    return ret;
    
}

int main() {
    int n, m;   // 준비한 행운권 수, 팀 회원 수
    scanf("%d %d", &n, &m);

    vector<int> ids(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &ids[i]);   // 회원번호 하나씩 입력하기
    }

    vector<int> tickets = getTicketNumbers(n, m, ids);

    // tickets 내 원소들 출력 ㄱㄱ
    for (int i = 0; i < tickets.size(); i++) {
        printf("%d\n", tickets[i]);
    }


    return 0;
}

