// 문제해결 프로젝트 6주차 과제 - 소수 세기
// 192992 이준연
#include <cstdio>
#include <vector>

using namespace std;

// 입력: 테스트 케이스 수 N, 각 테스트 케이스 입력(L, R)
// 출력: 각 테스트 케이스에 대해 2줄씩 출력(Case: #%d, L이상 R이하 소수 개수)

// 소인수 분해를 빠르게 진행한다!!
class Sieve {
    public:
        int maximumValue;   // 에라토스테네스의 체에서 다룰 가장 큰 범위의 값
        vector<bool> isPrime; // 각 숫자별 소수 여부 저장!!

        Sieve(int maximumValue) {
            this -> maximumValue = maximumValue;    
            this -> isPrime.assign(maximumValue + 1, false);   // isPrime이라는 배열(벡터)을 새로 선언한다 --> 1000000 크기를 가지려면 사이즈를 1 더 크게 설정해야 한다!!
            // false: 소수가 아닙니다
            this -> fillSieve();
        }

        // 해당 수가 소수인지 아닌지 알려주는 함수(소수라면 true, 아니라면 false)
        bool isPrimeNumber(int num) const {
            return this -> isPrime[num];
        }

        // isPrime 배열의 값을 채우는 함수
        // 일단 먼저 모두 소수라고 저장해놨다가, 아닌 숫자들 걸러가는 구조!!
        void fillSieve() {
            isPrime.assign(this -> maximumValue, true);     // 처음에는 모두 소수라고 저장한다(default: true)
            isPrime[0] = isPrime[1] = false;    // 0과 1은 소수가 아니므로 미리 처리한다

            // 자연수 2부터는 소수인지 아닌지 직접 계산하면서 처리한다!!
            for (int num = 2; num <= maximumValue; num += 1) {
                // [2, N] 사이의 모든 자연수 N에 대해
                if (isPrime[num] == false) {
                    // 이미 소수가 아니라고 체크되면 건너뛴다.
                    continue;
                }

                // 이때 num은 소수다
                // 그러므로 num의 모든 배수를 소수가 아니라고 체크한다
                // num보다 작은 k에 대해 mul = num * num으로 표현되는 모든 자연수는 이미 처리
                // 그래서 mul = num * num 부터 처리하면 된다. 최대 100만의 제곱까지!! --> long long
                for (long long mul = (long long) num * num; mul <= maximumValue; mul += num){
                    // mul은 num의 배수만큼 증가시킨다
                    // 이 때 mul에 대해 mul을 나누는 최초의 소인수 num이 등장
                    // 이 정보 저장 시, 소인수 분해 시 유용함
                    int index = (int) mul; // mul값을 int 형으로 바꾸고 index에 저장!!
                    isPrime[index] = false; // 그리고 나서 isPrime의 해당 index값을 false로 바꾼다.
                }
        }
    }
};

// from과 to 사이의 소수들을 모두 구해준다!!
vector<int> getAllPrimeNumbers(int from, int to, const Sieve &sieve) {
    vector<int> primes;

    for(int num = from; num <= to; num += 1) {
        if(sieve.isPrimeNumber(num)) {
            // 만약 isPrimeNumber 함수 호출 결과가 소수이다?(true) --> 해당 숫자를 primes 벡터에 집어 넣는다!!
            primes.push_back(num);
        }
    }
    return primes;
}

void process(int caseIndex, const Sieve &sieve) {
    int L, R;   // L과 R은 1000000 이하의 수!!
    scanf("%d %d", &L, &R);

    vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);  // L과 R 사이 모든 소수 저장한다!!

    printf("Case #%d:\n", caseIndex);
    printf("%d\n", allPrimeNumbers.size());
}

int main() {
    const int MAX_VALUE = 1000000; // 전처리
    Sieve sieve = Sieve(MAX_VALUE); // 전처리
    // 1부터 MAX_VAL까지 어느 것이 소수고, 어느 것이 소수가 아닌지 미리 저장!!(체 알고리즘)

    int caseSize;   // test case size 입력
    scanf("%d", &caseSize);

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex, sieve);  // test case 개수만큼 process 함수 반복 수행(L, R 입력 후 사이에 있는 소수의 개수를 리턴)
    }
    return 0;
}