package backjun.stack;

import java.util.*;
import java.io.*;

public class bakjun_1406 {

    public static void main(String args[]) throws IOException {
        Stack<Character> stack1 = new Stack<Character>();
        Stack<Character> stack2 = new Stack<Character>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        // abcd 입력
        String s = br.readLine();
        int len = s.length();

        for(int i = 0 ; i < len ; i++) {
            stack1.push(s.charAt(i));
        }
        
        // 3 번 입력
        int count = Integer.parseInt(br.readLine());

        StringTokenizer st;

        for(int i= 0  ; i  < count ; i ++) {
            // i -> 1 : P x
            // i -> 2 : L
            // i -> 3 : P y
            st = new StringTokenizer(br.readLine());
            char type = st.nextToken().charAt(0); // Tokenizer에서 P만 빼낸다. 그리고 x만 남는다.
            switch(type) {

                //  P $라는 문자를 커서 왼쪽에 추가함

                // i -> 1 : P x : stack1.push(x)
                // i -> 2 : L   : stack2.push(x) : stack1에 있는 x 제거
                // i -> 3 : P y : stack1.push(y)

                // 커서관리 stack
                // x의 이동 stack1 -> stack2
                // y의 이동 stack1

                case 'P': // 왼쪽에 char 붙임
                    stack1.push(st.nextToken().charAt(0));
                    break;
                case 'L': // 커서를 왼쪽으로 옮김
                    if(!stack1.isEmpty()) {
                        stack2.push(stack1.pop());
                    }
                    break;
                case 'D':
                    if(!stack2.isEmpty()) {
                        stack1.push(stack2.pop());
                    }
                    break;
                case 'B':
                    if(!stack1.isEmpty()) {
                        stack1.pop();
                    }
                    break;
            }

        }
        // 입력 순서
        // 오른쪽입력 stack
        while(!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }

        // 왼쪽 입력 stack
        while(!stack1.isEmpty()) {
            sb.append(stack1.pop());
        }
        System.out.println(sb.reverse());

    }
}
