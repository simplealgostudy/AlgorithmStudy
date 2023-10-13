import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q3987 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        char[][] board = new char[N][M];

        for(int i = 0; i < N; i++){
            String str = br.readLine();
            for(int j = 0; j < M; j++){
                board[i][j] = str.charAt(j);
            }
        }

        st = new StringTokenizer(br.readLine());

        int PR = Integer.parseInt(st.nextToken()) - 1;
        int PC = Integer.parseInt(st.nextToken()) - 1;

        int answerNum = 0;
        int answerMove = 0;

        int[] moveH = {-1, 0, 1, 0};
        int[] moveW = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int pr = PR;
            int pc = PC;

            int idx = i;
            int cnt = 1;

            while(true){
                int tmpR = pr + moveH[idx];
                int tmpC = pc + moveW[idx];

                if (tmpR < 0 || tmpR >= N || tmpC < 0 || tmpC >= M || board[tmpR][tmpC] == 'C') {
                    break;
                }

                if(cnt > N * M * 2) {
                    answerNum = -1;
                    break;
                }

                if(board[tmpR][tmpC] == '/'){
                    if(idx == 0) idx = 1;
                    else if(idx == 1) idx = 0;
                    else if(idx == 2) idx = 3;
                    else if(idx == 3) idx = 2;
                }
                else if(board[tmpR][tmpC] == '\\'){
                    if(idx == 0) idx = 3;
                    else if(idx == 1) idx = 2;
                    else if(idx == 2) idx = 1;
                    else if(idx == 3) idx = 0;
                }

                pr = tmpR;
                pc = tmpC;
                cnt++;
            }

            if(answerNum == -1) {
                answerMove = i;
                break;
            }

            if(answerNum < cnt) {
                answerNum = cnt;
                answerMove = i;
            }
        }

        if(answerMove == 0) System.out.println('U');
        else if(answerMove == 1) System.out.println('R');
        else if(answerMove == 2) System.out.println('D');
        else if(answerMove == 3) System.out.println('L');

        if(answerNum == -1) System.out.println("Voyager");
        else System.out.println(answerNum);

    }
}
