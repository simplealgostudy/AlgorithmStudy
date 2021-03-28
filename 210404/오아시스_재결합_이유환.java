import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

class Pair3{
    int first;
    int second;
 
    public Pair3(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class 오아시스_재결합_이유환 {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(reader.readLine());
		
		Stack<Pair3> stk = new Stack<>();

		long answer = 0;
		for(int i = 0; i < N; i++) {
			int person = Integer.parseInt(reader.readLine());
			Pair3 pair = new Pair3(person, 1);
			
			while(!stk.empty()) {
				if(stk.peek().first <= person) {
                    answer += stk.peek().second;
                    if(stk.peek().first == person){
                        pair.second += stk.peek().second;
                    }
                    stk.pop();
                } else if(!stk.isEmpty()) {
	                answer += 1;
                    break;
                }
			}
			
            stk.push(pair);
		}
		
		System.out.println(answer);
	}
}
