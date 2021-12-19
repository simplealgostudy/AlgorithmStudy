import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class 가희와_키워드_이유환 {
	public static void main(String[] args) throws IOException {
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         StringTokenizer st = new StringTokenizer(br.readLine());
         StringBuilder sb = new StringBuilder();
         int N = Integer.parseInt(st.nextToken());
         int M = Integer.parseInt(st.nextToken());
         
         HashMap<String, Integer> hm = new HashMap<>();
         for(int i = 0; i < N; i++) {
        	 String str = br.readLine();
        	 hm.put(str, 1);
         }
         
         for(int i = 0; i < M; i++) {      	 
        	 st = new StringTokenizer(br.readLine(), ",");
        	 while(st.hasMoreTokens()) {
                 String str = st.nextToken();
                 
                 if(hm.get(str) != null) {
                	 hm.remove(str);
                 }                
             }
        	 
        	 System.out.println(hm.size());
         }
	}
}
