import java.io.*;
import java.util.*;

public class Main {
	static int N, result;
	static int[][] MAP;
	static boolean[][] visit;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		MAP = new int[N][N];
		visit = new boolean[N][N];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine()); 
			for(int j=0; j<N; j++) {
				MAP[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0,0);
		
		if(result == 1) {
			bw.write("HaruHaru" + "\n");
		}else {
			bw.write("Hing" + "\n");
		}
		bw.flush();
		bw.close();
		br.close();
	}
	
	public static void dfs(int n, int r) {
		visit[n][r] = true;
		int move = MAP[n][r];
		if(MAP[n][r] == -1){
			result = 1;
			return;
		}
		if(r+move < N && visit[n][r+move] == false){
			dfs(n, r+move);
		}	
		if(n+move < N && visit[n+move][r] == false){
			dfs(n+move, r);
		}	
	}
}
