import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q1189 {
    static int R;
    static int C;
    static int K;
    static int answer = 0;

    static char[][] board = new char[6][6];
    static boolean[][] visit = new boolean[6][6];

    static int[] moveH = {-1, 1, 0, 0,};
    static int[] moveW = {0, 0, -1, 1};

    static void dfs(int h, int w, int cnt){
        if(h == 0 && w == C - 1){
            if(cnt == K) answer++;
            return;
        }

        for(int i = 0; i < 4; i++){
            int tmpH = h + moveH[i];
            int tmpW = w + moveW[i];

            if(!(tmpH < 0 || tmpW < 0 || tmpH >= R || tmpW >= C) && !(visit[tmpH][tmpW] || board[tmpH][tmpW] == 'T')){
                visit[tmpH][tmpW] = true;
                dfs(tmpH, tmpW, cnt + 1);
                visit[tmpH][tmpW] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for(int i = 0; i < R; i++){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();

            for(int j = 0; j < str.length(); j++){
                board[i][j] = str.charAt(j);
            }
        }

        visit[R - 1][0] = true;
        dfs(R - 1, 0, 1);

        System.out.println(answer);
    }

}
