import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair3{
    int first;
    int second;

    public Pair3(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class Q18404 {

    static int N;

    static int[] move_h = { -2, -2, -1, -1, 1, 1, 2, 2};
    static int[] move_w = { -1, 1, -2, 2, -2, 2, -1, 1};

    static int[][] arr = new int[501][501];

    static void bfs(int startH, int startW) {
        Queue<Pair3> q = new LinkedList<Pair3>();
        q.offer(new Pair3(startH, startW));

        while (!q.isEmpty()) {
            Pair3 p = q.poll();
            int h = p.first;
            int w = p.second;

            for (int i = 0; i < 8; i++) {
                int tmp_w = w + move_w[i];
                int tmp_h = h + move_h[i];
                if (tmp_w >= 0 && tmp_h >= 0 && tmp_w <= N && tmp_h <= N && arr[tmp_h][tmp_w] == 0) {
                    arr[tmp_h][tmp_w] = arr[h][w] + 1;
                    q.offer(new Pair3(tmp_h, tmp_w));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());

        arr[X][Y] = 1;
        bfs(X, Y);

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            System.out.print(arr[A][B] - 1 + " ");
        }

    }
}
