import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q21938 {

    static int[] moveH = {-1, 1, 0, 0};
    static int[] moveW = {0, 0, -1, 1};
    static boolean[][] visited;
    static int[][] board;
    static int N, M, T, answer;

    static void bfs(int h, int w) {
        Queue<int[]> que = new LinkedList<>();
        que.offer(new int[] {h, w});

        while (!que.isEmpty()){
            int tmp[] = que.poll();

            for(int i = 0; i < 4; i++){
                int tmpH = tmp[0] + moveH[i];
                int tmpW = tmp[1] + moveW[i];

                if(tmpH < 0 || tmpW < 0 || tmpH >= N || tmpW >= M || visited[tmpH][tmpW] || board[tmpH][tmpW] == 0) continue;

                visited[tmpH][tmpW] = true;

                que.add(new int[] {tmpH, tmpW});

            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        visited = new boolean[N][M];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++){
                int r = Integer.parseInt(st.nextToken());
                int g = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                board[i][j] = (r + g + b) / 3;

            }
        }

        T = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if(board[i][j] >= T) board[i][j] = 255;
                else board[i][j] = 0;
            }
        }

        for(int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if(board[i][j] == 255 && !visited[i][j]) {
                    answer++;
                    bfs(i, j);
                }
            }
        }

        System.out.println(answer);

    }
}
