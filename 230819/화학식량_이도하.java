import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Q2257 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stk = new Stack<>();
        String str = br.readLine();

        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '(') stk.push(-1);
            else if (str.charAt(i) == 'H') stk.push(1);
            else if (str.charAt(i) == 'C') stk.push(12);
            else if (str.charAt(i) == 'O') stk.push(16);
            else if (str.charAt(i) >= '2' && str.charAt(i) <= '9'){
                int tmp = stk.peek() * (str.charAt(i) - '0');
                stk.pop();
                stk.push(tmp);
            }
            else if (str.charAt(i) == ')') {
                int tmp = 0;
                while (stk.peek() != -1) {
                    tmp += stk.peek();
                    stk.pop();
                }
                stk.pop();
                stk.push(tmp);
            }
        }

        int answer = 0;
        while (!stk.isEmpty()){
            answer += stk.peek();
            stk.pop();
        }

        System.out.println(answer);
    }
}
