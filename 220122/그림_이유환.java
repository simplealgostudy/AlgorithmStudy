package testProject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair{
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}


public class 그림_이유환 {
	
	static int n = 0;
	static int m = 0;
	static int cnt = 0;
	static int max = 0;
	static int[][] arr = new int[501][501];
	static int[] move_h = { -1, 1, 0, 0};
	static int[] move_w = { 0, 0, -1, 1};
	static boolean[][] visit = new boolean[501][501];

	static void bfs(int startH, int startW) {				
		Queue<Pair> q = new LinkedList<Pair>();

		q.offer(new Pair(startH, startW));

		int tmp = 0;
		visit[startH][startW] = true;
		tmp++;
		
		while (!q.isEmpty()) {
			Pair p = q.poll();
			int h = p.first;
			int w = p.second;

			for (int i = 0; i < 4; i++) {
				int tmp_w = w + move_w[i];
				int tmp_h = h + move_h[i];
				if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < m && tmp_h < n) {
					if (arr[tmp_h][tmp_w] == 1 && !visit[tmp_h][tmp_w]) {
						visit[tmp_h][tmp_w] = true;
						tmp++;
						q.offer(new Pair(tmp_h, tmp_w));
					}
				}
			}
		}
		
		if(max < tmp) max = tmp;	
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(!visit[i][j] && arr[i][j] == 1) {
					cnt++;				
					bfs(i, j);
				}
			}
		}
		
		System.out.println(cnt);
		System.out.println(max);
	}
}
