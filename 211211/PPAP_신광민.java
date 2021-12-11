package backjun.stack;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class bakjun_16120 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        Stack<Character> stack = new Stack<>();

        // 결과적으로 PPAP를 P로 치환하다보면 P만 남음
        for(int i=0; i<input.length(); i++) {
            char temp = input.charAt(i);

            if(temp=='P')
                stack.push('P');

            else {
                // PPAP인지 확인 하는 로직
                // A 앞에 두개이상의 P가 존재
                // 끝에 존재 하지 말아야함
                // A뒤에 P가 존재해야함
                if(stack.size()>=2 && i<input.length()-1 && input.charAt(i+1)=='P') {
                    stack.pop();
                    stack.pop();
                } else {
                    System.out.println("NP");
                    return;
                }
            }
        }
        // P가 남는다면
        if(stack.size()==1)
            System.out.println("PPAP");
        // A가 남는다면
        else
            System.out.println("NP");
    }
}
