import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1443 {

    static long N, P;
    static long answer = -1;

    static void dfs(int num, int cnt, int idx){
        if((num + "").length() > N) return;
        if(cnt == P) {
            answer = Math.max(answer, num);
            return;
        }

        for(int i = idx; i <= 9; i++){
            dfs(num * i, cnt + 1, i);
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        dfs(1, 0, 2);

        System.out.println(answer);

    }
}
