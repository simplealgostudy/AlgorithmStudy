#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 9;// 작은 값 찾을거라 최대 값 9 미리 넣어 둠

void dp(int N, int number, int count, int currentNumber){
    // N은 사용할 숫자
    // number는 비교할 숫자
    // count는 N을 사용한 횟수
    if(count>8)return;// 최솟값이 8보다 크면 -1을 리턴한다는 조건이 있었음. count가 8보다 커지면 dp를 더 호출할 이유가 없음.
    if(currentNumber == number){//현재수가 number와 같다면 작은횟수를 answer에 저장후 리턴
        answer = count<answer?count:answer;// 작은값 찾기
        return;
    }
    int sequence_number = 0;
    for(int i = 0; i+count<9; i++){//최대 N의 사용횟수는 9번까지이므로 이때까지 반복
        sequence_number = sequence_number*10 + N;//N,NN,NNN,NNNN .....
        dp(N, number, i+count+1, currentNumber+sequence_number);
        dp(N, number, i+count+1, currentNumber-sequence_number);
        dp(N, number, i+count+1, currentNumber*sequence_number);
        dp(N, number, i+count+1, currentNumber/sequence_number);
    }
}

int solution(int N, int number){
    dp(N, number, 0, 0);
    if(answer>8)return -1;// -1을 리턴해야 하므로 넣었음.
    return answer;
}

int main(){
    cout << "N = 5, number = 12, answer = \n" << solution(5, 12) << endl;
}