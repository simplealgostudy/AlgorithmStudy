#include <string>
#include <vector>
#include <unordered_map>//해쉬맵 사용

using namespace std;

int solution(vector<vector<string>> clothes) {
	//곱하기 연산을 해야하기때문에 기본값 1
	int answer = 1;
	unordered_map<string, int> temp;
	//큰 테두리로 분류(얼굴, 상의, 하의, 겉옷 등)
	for (int i = 0; i < clothes.size(); i++)
		temp[clothes[i][1]]++;
	//Hash를 처음부터 순회
	for (auto pair : temp)
		answer *= (pair.second + 1);  //종류의 수 +1 (아무것도 입지않았을때) 를 계속 곱해준다.
	//무언가 하나는 입어야 하므로
	//아무것도 입지않은 경우의수 제외
	return answer-1;
    
}


int main(){
    vector< vector<string> > clothes;

    clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban, headgear"}};
    printf("%d\n", solution(clothes));
    return EXIT_SUCCESS;
}
