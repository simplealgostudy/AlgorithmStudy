import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Q6146 {

    static int[] moveH = {-1, 1, 0, 0};
    static int[] moveW = {0, 0, -1, 1};
    static int board[][] = new int[1001][1001];
    static int x, y;
    static boolean visited[][] = new boolean[1001][1001];
    static boolean block[][] = new boolean[1001][1001];

    static void bfs(){
        Queue<int []> que = new LinkedList<>();
        que.offer(new int[] {500, 500, 0});

        while (!que.isEmpty()){
            int[] tmp = que.poll();

            for(int i = 0; i < 4; i++){
                int tmpH = tmp[0] + moveH[i];
                int tmpW = tmp[1] + moveW[i];

                if(tmpH < 0 || tmpW < 0 || tmpH > 1000 || tmpW > 1000 || visited[tmpH][tmpW] || block[tmpH][tmpW]) continue;

                visited[tmpH][tmpW] = true;

                if(tmpH == y && tmpW == x){
                    System.out.println(tmp[2] + 1);
                    return;
                }

                que.add(new int[] {tmpH, tmpW, tmp[2] + 1});

            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        x = Integer.parseInt(st.nextToken()) + 500;
        y = Integer.parseInt(st.nextToken()) + 500;
        int n = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++){
            st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken()) + 500;
            int b = Integer.parseInt(st.nextToken()) + 500;

            block[b][a] = true;
        }

        bfs();
    }
}
