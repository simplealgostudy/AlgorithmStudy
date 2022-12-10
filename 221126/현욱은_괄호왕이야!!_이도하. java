import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Q15926 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        String S = br.readLine();

        Stack<Integer> stk = new Stack<>();

        int answer = 0;

        stk.push(-1);

        for(int i = 0; i < S.length(); i++){
            if(S.charAt(i) == '(') stk.push(i);
            else {
                stk.pop();
                if(!stk.empty()) answer = Math.max(answer, i - stk.peek());
                else stk.push(i);
            }
        }

        System.out.println(answer);

    }
}
