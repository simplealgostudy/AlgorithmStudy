import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1890 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        long[][] dp = new long [N + 1][N + 1];

        dp[0][0] = 1;

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                int n = Integer.parseInt(st.nextToken());

                if(n != 0){
                    if(i + n < N){
                        dp[i + n][j] += dp[i][j];
                    }
                    if(j + n < N){
                        dp[i][j + n] += dp[i][j];
                    }
                }

            }
        }

        System.out.println(dp[N - 1][N - 1]);

    }
}
