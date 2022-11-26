import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int N = Integer.parseInt(br.readLine());
	    char[] S = br.readLine().toCharArray();
	    Stack<Integer> stack = new Stack<>();
	    int max = 0;
	    stack.add(-1);
	    
	    for(int i=0; i<N; i++) {
	    	if(S[i]=='(') stack.add(i);
	    	else {
	    		stack.pop();
	    		if(stack.empty()) {
	    			stack.add(i);
	    		}
	    		int top = stack.peek();
	    		max = Math.max(max, i-top);
	    	}
	    }
	    System.out.println(max);
	}
}