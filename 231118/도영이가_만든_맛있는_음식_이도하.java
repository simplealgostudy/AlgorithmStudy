import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.StringTokenizer;

public class Q2961 {

    static int[] S;
    static int[] B;
    static int answer = Integer.MAX_VALUE;
    static int N;

    static void dfs(int cnt, int idx, int s, int b){
        if(idx == N){
            if(cnt != 0) answer = Math.min(answer, Math.abs(s - b));
            return;
        }

        dfs(cnt, idx + 1, s, b);
        dfs(cnt + 1, idx + 1, s * S[idx], b + B[idx]);

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = new int[N];
        B = new int[N];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());

            S[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0, 0, 1, 0);
        System.out.println(answer);


    }
}
