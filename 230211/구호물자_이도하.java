import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q11581 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        boolean[][] dist = new boolean[N + 1][N + 1];

        for(int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int C = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < C; j++){
                int M = Integer.parseInt(st.nextToken());
                dist[i][M - 1] = true;
            }
        }

        for(int k = 0; k < N; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(dist[i][k] && dist[k][j]) dist[i][j] = true;
                }
            }
        }

        boolean sw = false;
        for(int i = 0; i < N; i++){
            if(dist[0][i] && dist[i][i]) sw = true;
        }

        if(sw) System.out.println("CYCLE");
        else System.out.println("NO CYCLE");

    }
}
