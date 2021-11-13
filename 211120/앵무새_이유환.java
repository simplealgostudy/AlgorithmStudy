import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class 앵무새_이유환 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		Queue<String>[] que = new LinkedList[N];
		Queue<String> checkQue = new LinkedList<>();
		
		for(int i = 0; i < N; i++) {
			que[i] = new LinkedList<String>();
		}
		
		for(int i = 0; i < N; i++) {
			String str = br.readLine();
			String[] strArray = str.split(" ");
			
			for(int j = 0; j < strArray.length; j++) {
				que[i].add(strArray[j]);
			}
		}
		
		String check = br.readLine();
		String[] checkArray = check.split(" ");
		
		for(int i = 0; i < checkArray.length; i++) {
			checkQue.add(checkArray[i]);
		}
		
		for(int i = 0; i < checkArray.length; i++) {
			for(int j = 0; j < N; j++) {
				if(checkQue.peek().equals(que[j].peek())) {
					que[j].poll();
					checkQue.poll();
					
					if(checkQue.isEmpty()) break;
				}
			}
			if(checkQue.isEmpty()) break;
		}
		
		
		boolean sw = true;
		for(int i = 0; i < N; i++) {
			if(!que[i].isEmpty()) {
				sw = false;
				break;
			}
		}
		
		if(sw && checkQue.isEmpty()) System.out.println("Possible");
		else System.out.println("Impossible");
	}
}
