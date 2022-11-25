import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int N = Integer.parseInt(br.readLine());
	    int a = 0, b = 0;
	    int result = 0;
	    String S = br.readLine();
	    
    	for(int i=0; i<N; i++) {
    		if(S.charAt(i)=='(') {
    			a++;
    		}else {
    			b++;
    		}
    		result = Math.max(Math.abs(a-b), result);
    	}
    	
    	if(a == b) {
    		System.out.println(result);
    	}else {
    		System.out.println(-1);
    	}
	}
}
