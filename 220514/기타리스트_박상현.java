import java.io.*;
import java.util.*;

public class Main {
	static int N, S, M;
    static int[] V, arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
	    StringTokenizer st;
	    st = new StringTokenizer(br.readLine());
	    N = Integer.parseInt(st.nextToken());
	    S = Integer.parseInt(st.nextToken());
	    M = Integer.parseInt(st.nextToken());
	    
	    V = new int[N];
	    st = new StringTokenizer(br.readLine());
	    
	    for(int i=0; i<N; i++) {
	    	V[i] = Integer.parseInt(st.nextToken());
	    }
	    
	    arr = new int[M+1];		//몇 번째 곡인지 확인 및 볼륨을 확인하기 위한 배열

	    Arrays.fill(arr, -1);
	    
	    arr[S] = 0;		//첫번째 시작하는 값에 0
	    
	    for(int i = 1; i <= N; i++) {
	    	int v = V[i-1];
	    	List<Integer> list = new ArrayList<>();
	    	
	    	for(int j=0; j<=M; j++) {
	    		if(arr[j] == i-1) {		//i-1로 이전 곡의 위치를 비교
	    			int res1 = j + v;	//j는 arr[j](곡 위치)의 볼륨 값
	    			int res2 = j - v;
	    			
	    			if( 0 <= res1 && res1 <= M ) {
	    				list.add(res1);
	    			}
	    			if( 0 <= res2 && res2 <= M ) {
	    				list.add(res2);
	    			}
	    		}
	    	}
	    	for (int n : list) {
				arr[n] = i;
			}
	    }
    	int max = -1;
    	for(int i = 0; i <= M; i++) {
    		if(arr[i] == N) {	//마지막 곡의 위치를 찾음
        		max = Math.max(max, i);
    		}
    	}
    	bw.write(max + "\n");
    	bw.flush();
	    br.close();
	    bw.close();
	    
	}
}
