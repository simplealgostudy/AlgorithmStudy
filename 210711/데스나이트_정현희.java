import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static boolean[][] check;
	static int SR, SC, ER, EC;

	static int[][] dirs = { { -2, -1 }, { -2, 1 }, { 0, -2 }, { 0, 2 },
			{ 2, -1 }, { 2, 1 } };

	static class Point {
		int r;
		int c;
		int depth;

		public Point(int r, int c, int depth) {
			this.r = r;
			this.c = c;
			this.depth = depth;
		}

	}

	public static void main(String[] args) {

		initMap();

		int answer = bfs();
		System.out.println(answer);
	}

	private static int bfs() {

		Queue<Point> queue = new LinkedList<>();
		check[SR][SC] = true;
		queue.offer(new Point(SR, SC, 0));

		while (!queue.isEmpty()) {
			Point cur = queue.poll();
			if(cur.r==ER && cur.c==EC){
				return cur.depth;
			}
			
			int nr, nc;
			for(int d=0;d<dirs.length;d++){
				nr = cur.r + dirs[d][0];
				nc = cur.c + dirs[d][1];
				if(canGo(nr,nc)){
					check[nr][nc] = true;
					queue.offer(new Point(nr,nc,cur.depth+1));
				}
			}
		}
		
		return -1;

	}

	private static boolean canGo(int r, int c) {
		return r>=0 && r<N && c>=0 && c<N && !check[r][c];
	}

	private static void initMap() {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(
					System.in));
			N = Integer.parseInt(br.readLine());
			check = new boolean[N][N];
			StringTokenizer str = new StringTokenizer(br.readLine(), " ");
			SR = Integer.parseInt(str.nextToken());
			SC = Integer.parseInt(str.nextToken());
			ER = Integer.parseInt(str.nextToken());
			EC = Integer.parseInt(str.nextToken());

		} catch (Exception e) {

		}

	}

}
