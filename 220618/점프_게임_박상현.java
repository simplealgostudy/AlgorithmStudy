import java.io.*;
import java.util.*;

public class Main {
	static int N, k;
	static int[][] MAP;
	static int[] cal;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		cal = new int[] {1, -1, k};
		MAP = new int[2][N];
		
		String str;
		for(int i=0; i<2; i++) {
			str = br.readLine();
			for(int j=0; j<N; j++) {
				MAP[i][j] = str.charAt(j)-'0';
			}
		}
		if(bfs(0,0,0)) bw.write(1+"\n");
		else bw.write(0+"\n");
		bw.flush();
		bw.close();
		br.close();
	}
	
	public static boolean bfs(int index, int num, int current) throws IOException {
		boolean visit[][] = new boolean[2][N];
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {index, num, current});
		visit[0][0]=true;
		
		while(!q.isEmpty()) {
			int cur[] = q.poll();
			
			for(int i=0; i<cal.length; i++) {
				if(i == 2) {
					if(cur[0] == 0) {
						cur[0] = 1;
					}else {
						cur[0] = 0;
					}
				}
				if((cur[1]+cal[i]) >= N) {
					return true;
				}
				
				if((cur[1]+cal[i]) <= cur[2]) continue;
				if(visit[cur[0]][(cur[1]+cal[i])]) continue;
				if(MAP[cur[0]][(cur[1]+cal[i])] == 0) continue;
				visit[cur[0]][(cur[1]+cal[i])] = true;
				q.add(new int[] {cur[0], (cur[1]+cal[i]), (cur[2]+1)});
				
			}
		}
		return false;
	}
}
