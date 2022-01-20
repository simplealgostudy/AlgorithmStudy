package backjun.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class picture {

    static Queue<Node> queue;
    static int dx[] = {1, 0, -1, 0};
    static int dy[] = {0, 1, 0, -1};
    static int N;
    static int M;
    static int map[][];
    static boolean visited[][];
    static int drawCount = 0;
    static int maxDrawSize = 0;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        visited=  new boolean[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                }
            }
        }

        System.out.println(drawCount);
        System.out.println(maxDrawSize);

    }

    public static void bfs(int x, int y) {
        queue = new LinkedList<>();
        queue.add(new Node(x, y));
        int count = 0 ;
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            count++;
            for (int dir = 0; dir < 4; dir++) {
                int nx = node.x + dx[dir];
                int ny = node.y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (visited[nx][ny] || map[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                queue.add(new Node(nx, ny));
            }
        }

        drawCount++;
        if(count >1 ) {
            count--;
        }
        maxDrawSize = Math.max(maxDrawSize, count);



    }
}

class Node {
    int x;
    int y;


    public Node(int x, int y) {
        super();
        this.x = x;
        this.y = y;

    }

}
