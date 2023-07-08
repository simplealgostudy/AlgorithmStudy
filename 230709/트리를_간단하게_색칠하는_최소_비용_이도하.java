import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Q25512 {

    static ArrayList<ArrayList<Integer>> al = new ArrayList<>();
    static int[][] color = new int[100001][2];
    static int n = 0;
    static long sumW = 0, sumB = 0;

    static void dfs(int c, boolean chk){
        sumW += color[c][(chk) ? 1 : 0];
        sumB += color[c][(!chk) ? 1 : 0];

        chk = !chk;

        for(int i = 0; i < al.get(c).size(); i++){
            dfs(al.get(c).get(i), chk);
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            al.add(new ArrayList<>());
        }

        for(int i = 0; i < n - 1; i++){
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            al.get(p).add(c);
        }

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            color[i][0] = w;
            color[i][1] = b;
        }

        dfs(0, false);

        System.out.println(Math.min(sumW, sumB));

    }
}
