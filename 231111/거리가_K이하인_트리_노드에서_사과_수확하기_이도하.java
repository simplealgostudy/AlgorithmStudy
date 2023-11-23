import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Q25516 {

    static int n;
    static int k;
    static int answer = 0;
    static int[] apple;

    static ArrayList<ArrayList<Integer>> al = new ArrayList<>();

    static void dfs(int idx, int cnt){
        if(cnt > k) return;
        if(apple[idx] == 1) answer++;

        for(int i = 0; i < al.get(idx).size(); i++){
            dfs(al.get(idx).get(i), cnt + 1);
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            al.add(new ArrayList<>());
        }

        apple = new int[n];

        for(int i = 0; i < n - 1; i++){
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            al.get(p).add(c);
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            apple[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0, 0);

        System.out.println(answer);

    }
}
