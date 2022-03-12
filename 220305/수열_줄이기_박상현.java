import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 	// 선언
		ArrayList<Integer> list = new ArrayList<Integer>(); 						//ArrayList 선언
		
		long cost_sum = 0;									//cost sum값
		int len = 0;									//입력받을 크기
		
		len = Integer.parseInt(br.readLine());
		
		for(int i=0; i<len; i++) {
			list.add(Integer.parseInt(br.readLine()));
		}
		
	
		for(int j=0; j<list.size()-1; j++) {
			cost_sum += Math.max(list.get(j), list.get(j+1));
		}

		System.out.print(cost_sum);
		
		br.close();
	}

}
