import java.io.*;
import java.util.*;

public class Main {
	static int N, R, C;
	static char[][] map;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
	static int[][] deltas= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	public static void main(String[] args) throws Exception {
	    
	    N = Integer.parseInt(br.readLine());
	    
	    for(int t=0; t < N; t++) {
		    st = new StringTokenizer(br.readLine());
		    R = Integer.parseInt(st.nextToken());
		    C = Integer.parseInt(st.nextToken());
	    	map = new char[R][C];
	    	
	    	for(int i=0; i < R; i++) {
	    		String str = br.readLine();
	    		for(int j=0; j < C; j++) {
	    			map[i][j] = str.charAt(j);
	    		}
	    	}
	    	int count = 0;
	    	
	    	for(int i=0; i < R; i++) {
	    		for(int j=0; j < C; j++) {
	    			if(map[i][j] == '#') {
	    				dfs(i, j);
	    				count++;
	    			}
	    		}
	    	}
	    	sb.append(count+"\n");
	    }	    
    	bw.write(sb + "\n");
    	bw.flush();
	    br.close();
	    bw.close();
	}
	
	static void dfs(int r, int c) {
		map[r][c] = '.';
		for (int d=0;d<4;d++) {		//상하좌우 확인
			int nr = r+deltas[d][0];
			int nc = c+deltas[d][1];
			if (isIn(nr,nc) && map[nr][nc]=='#') {
				dfs(nr, nc);
			}
		}
		return;
	}
	
	static boolean isIn(int nr, int nc) {
		return nr>=0 && nr<R && nc>=0 && nc<C;
	}	
}
