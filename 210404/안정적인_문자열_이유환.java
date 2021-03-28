import java.util.Scanner;
import java.util.Stack;

public class 안정적인_문자열_이유환 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack<Character> stk = new Stack<>();
		int idx = 1;
		while(true) {
			int answer = 0;
			String input = sc.next();
			
			if(input.charAt(0) == '-') break;
			
			for(int i = 0; i < input.length(); i++) {
				if(!stk.empty() && stk.peek() == '{' && input.charAt(i) == '}') stk.pop();
				else stk.push(input.charAt(i));
				
			}
			
			int open = 0;
			int close = 0;
			while(!stk.empty()) {
				if(stk.peek() == '{') open++;
				else close++;
				
				stk.pop();
			}
			
			if(open == 1 && close == 1) answer = 2;
			else if (open % 2 == 1 && close % 2 == 1) answer = (open / 2) + (close / 2) + 2;
			else answer = (open / 2) + (close / 2);
			
			System.out.println(idx + ". " + answer);
			idx++;
			
			stk.clear();
		}
	}
}
