import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q15270 {

    static int N, M, answer;
    static int[][] g;
    static boolean[] visit;

    static void dfs(int idx, int cnt){
        if (M == idx){
            answer = Math.max(answer, cnt);
            return;
        }

        if(visit[g[idx][0]] || visit[g[idx][1]]){
            dfs(idx + 1, cnt);
        }
        else{
            visit[g[idx][0]] = true;
            visit[g[idx][1]] = true;

            dfs(idx + 1, cnt + 2);

            visit[g[idx][1]] = false;
            visit[g[idx][0]] = false;

            dfs(idx + 1, cnt);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        g = new int[M + 1][2];
        visit = new boolean[N + 1];
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            g[i][0] = u;
            g[i][1] = v;
        }

        dfs(0, 0);

        if(answer < N) answer++;

        System.out.println(answer);

    }
}
