import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 트럭 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int W = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());

		Queue<Integer> cars = new LinkedList<Integer>();
		Queue<Integer> bridge = new LinkedList<Integer>();
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			cars.offer(Integer.parseInt(st.nextToken()));	
		}
		for(int i = 0; i < W; i++) {
			bridge.offer(0);		
		}
		int answer = 0;
		int weight = 0;
		
		while(!bridge.isEmpty()) {	
			weight -= bridge.poll();
			
			if(!cars.isEmpty()) {
				if(cars.peek() + weight <= L) {
					int truck = cars.poll();
					weight += truck;
					bridge.offer(truck);
				}
				else bridge.offer(0);
			}
						
			answer++;
		}
		
		System.out.println(answer);
	}
}
