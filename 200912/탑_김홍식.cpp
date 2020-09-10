#include<iostream>
#include<stack>
#include<vector>
using namespace std;

stack <pair<int, int>>st;
vector<int>vec;

int main() {
    int num1;
    cin >> num1;

    for (int i = 1; i <= num1; i++) {
        int in;
        cin >> in;

        if (i == 1) { //첫번째 기입
            st.push(make_pair(in, i)); //높이값(in)과 순서값(i) 모두 pair로 push (첫 값은 항상 최댓값이 된다)
            vec.push_back(0);           //vector 마지막값에(제일 오른쪽) 0 삽입 >> 나중에 출력할거임
            continue;                   //바로 다음
        }

        if (in > st.top().first) {             //입력값이 스택 최대치보다 높을때 (여태중에 제일 큰 수가 들어올 경우)
            while (st.size()) {                //스택 사이즈만큼 반복해서
                if (st.top().first >= in)      //스택 최대치가 입력값보다 크거나 같아질때
                    break;
                st.pop();                      //스택 최대치를 버린다
            }
            if (st.size() == 0)                //스택 사이즈가 0이면
                vec.push_back(0);              //백터 마지막에 0삽입
            else
                vec.push_back(st.top().second);//그 외의 경우에는 백터값 마지막에 순서값(i) 삽입
        }
        else
            vec.push_back(st.top().second);    //입력값이 스택 최대치보다 낮을때 백터값 마지막에 순서값 (i) 삽입


        st.push(make_pair(in, i));             //높이값 입력해서 스택에 push
    }

    // 출력부 벡터값 저장된 순서대로 출력
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    return 0;
}
