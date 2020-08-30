#include <iostream>
#include <string>

using namespace std;


bool isCpp(string input, int underbarIndex)
{
    if (underbarIndex!=-1) // _가 있는 경우입니다.
    {
        return true;
    }
    else
        return false;
}

bool isJava(string input, int underbarIndex)
{
    if (underbarIndex == -1) // _가 없는 경우입니다.
    {
        return true;
    }
    else
        return false;
}

bool isError(string input, int size, int underbarIndex)
{
    // 글자가 알파벳 또는 _ 가 아니면 에러
    for(int i = 0; i < size; i++){
        if( !(input[i] == '_' || isalpha(input[i]))) {
            return true;
        }
    }

    // 언더바와 대문자가 동시에 나온 경우 ex) mi_nSoo
    for(int i = 0; i < size; i++){
        if(isupper(input[i]) && underbarIndex!=-1){
            return true;
        }
    }

    // 첫 글자가 _이거나 대문자거나 알파벳이 아니면
    if(input[0]=='_' || isupper(input[0]) || !isalpha(input[0])){ 
        return true;
    }

    // 마지막 글자가 _이면
    else if ("_"==input.substr(input.length()-1, input.length())){
        return true;
    }

    // _뒤에 또 _가 나오면
    else if (input[underbarIndex+1]=='_'){ 
        return true;
    }

    // _다음 글자가 대문자면
    else if(isupper(input[underbarIndex+1])){
        return true;
    }

    // _전 글자가 대문자면
    else if(isupper(input[underbarIndex-1])){ 
        return true;
    }

    else
        return false;
}

void minsooString(string input, int size, int underbarIndex)
{
    char lowerFirstChar = tolower(input[0]);
    
    if (isError(input, size, underbarIndex)) // 에러가 있는 경우
        cout << "Error!" << endl;

    else if (isCpp(input, underbarIndex)) // cpp인 경우
    {
        for (int i = 0; i < size; i++)
        {
            underbarIndex = input.find("_");;
            if (underbarIndex!=-1)
            {
                input[underbarIndex + 1] = toupper(input[underbarIndex + 1]);
                input.erase(underbarIndex, 1);// underbarIndex위치부터 1개를 지웁니다.
            }
        }
        cout << input << endl;
    }

    else if (isJava(input, underbarIndex)) // java인 경우
    {
        for (int i = 0; i < size; i++)
        {
            if (isupper(input[i]))
            {
                input[i] = tolower(input[i]);
                input.insert(i, "_");
                size++; // size를 늘려주지 않으면 bAEKJOON같은 단어는 끝까지 진행되지 않습니다.
            }
        }
        cout << input << endl;
    }
}

int main()
{
    string input;
    int size;

    cin >> input;
    size = input.size();

    int underbarIndex = input.find("_");

    minsooString(input, size, underbarIndex);

    return EXIT_SUCCESS;
}
