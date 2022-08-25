import java.io.*;
import java.util.*;

public class Main {
	static int N, M, startN, startM, result;
	static int[][] MAP, cal;
	static boolean[][] visit;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		MAP = new int[N][M];
		visit = new boolean[N][M];
		cal = new int[][] {{0,1}, {1,0}, {0,-1}, {-1,0}};
		
		String str;
		for(int i=0; i<N; i++) {
			str = br.readLine(); 
			for(int j=0; j<M; j++) {
				MAP[i][j] = str.charAt(j)-'0';
				if(MAP[i][j] == 2) {
					startN = i;
					startM = j;
				}
			}
		}
		result = 1;
		bfs(startN, startM, result);
	}
	
	public static void bfs(int n, int m, int result) {
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {n, m, result});
		visit[n][m] = true;
		
		while(!q.isEmpty()) {
			int current[] = q.poll();
			int currentN = current[0];
			int currentM = current[1];
			int resultR = current[2];
			for(int i=0; i<cal.length; i++) {
				if(currentN+cal[i][0] < 0 || currentN+cal[i][0] >= N || currentM+cal[i][1] < 0 || currentM+cal[i][1] >= M ) {
					continue;
				}else {
					if(MAP[currentN+cal[i][0]][currentM+cal[i][1]] > 2 && !visit[currentN+cal[i][0]][currentM+cal[i][1]]) {
						System.out.println("TAK");
						System.out.println(resultR);
						return;
					}else if(MAP[currentN+cal[i][0]][currentM+cal[i][1]] == 0 && !visit[currentN+cal[i][0]][currentM+cal[i][1]]) {
						q.add(new int[] {currentN+cal[i][0],currentM+cal[i][1],resultR+1});
						visit[currentN+cal[i][0]][currentM+cal[i][1]] = true;
					}
				}
			}
		}
		System.out.println("NIE");
		return;
	}
}
