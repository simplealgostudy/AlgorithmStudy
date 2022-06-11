import java.io.*;
import java.util.*;

public class Main {
	static int N, M;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
	    StringTokenizer st;
	    st = new StringTokenizer(br.readLine());
	    N = Integer.parseInt(st.nextToken());
	    M = Integer.parseInt(st.nextToken());
	    boolean[] visited = new boolean[N+1];
	    LinkedList<Integer>[] list = new LinkedList[N+1];
	    
	    for(int i=0; i<N+1; i++) {
	    	list[i] = new LinkedList<Integer>();
	    }
	    
	    for(int i=0; i<M; i++) {
		    st = new StringTokenizer(br.readLine());
	    	int A_i = Integer.parseInt(st.nextToken()); 
	    	int B_i = Integer.parseInt(st.nextToken());
	    	
	    	list[A_i].add(B_i);
	    	list[B_i].add(A_i);
	    }
	    
	    bfs(1, list, visited);

	    br.close();
	}
	
	public static void bfs(int v, LinkedList<Integer>[] list, boolean[] visited) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Queue<Integer> q = new LinkedList<>();
		int len[] = new int[N+1];	//각 노드의 거리를 저장할 배열 선언
		int max = 0;	//최대 먼 거리를 저장하기 위한 변수 선언
		int index = 0;	//최대 먼 노드 중 가장 작은 노드를 저장할 변수 선언
		int count = 0;	//거리가 같은 노드의 수를 저장하기 위한 변수 선언
			
		q.add(v);
		visited[v] = true;
		
		while(!q.isEmpty()) {
			v = q.poll();
			
			for(int i : list[v]) {
				if(!visited[i]) {
					q.add(i);
					visited[i] = true;
					len[i] = len[v] + 1;
				}
			}
		}
		
		for(int j=1; j<N+1; j++) {
			if(len[j] > max) {
				max = len[j];
				index = j;
				count = 1;
			}else if(max == len[j]) {
				count++;
			}
		}
    	bw.write(index + " " + len[index] + " " + count + "\n");
    	bw.flush();
	    bw.close();
	}
}
