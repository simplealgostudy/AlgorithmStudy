import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Q21937 {

    static ArrayList<ArrayList<Integer>> al=new ArrayList<>();
    static boolean[] visit;
    static int X, answer = 0;

    static void dfs(int node){

        visit[node] = true;

        for(int i = 0; i < al.get(node).size(); i++){
            if(!visit[al.get(node).get(i)]){
                answer++;
                dfs(al.get(node).get(i));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());


        for(int i = 0; i <= N; i++) al.add(new ArrayList<>());

        visit = new boolean[N + 1];

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());

            int g1 = Integer.parseInt(st.nextToken());
            int g2 = Integer.parseInt(st.nextToken());

            al.get(g2).add(g1);
        }

        st = new StringTokenizer(br.readLine());
        X = Integer.parseInt(st.nextToken());

        dfs(X);

        System.out.println(answer);

    }
}
