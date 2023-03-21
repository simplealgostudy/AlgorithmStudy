import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

class Pair4{
    int first;
    int second;
    int time;

    public Pair4(int first, int second, int time) {
        this.first = first;
        this.second = second;
        this.time = time;
    }
}

public class Q16954 {

    static int[] move_h = {0, 0, 1, -1, -1, -1, 1, 1};
    static int[] move_w = {1, -1, 0, 0, -1, 1, -1, 1};

    static char[][][] board = new char[8][8][8];
    static Queue<Pair4> q = new LinkedList<>();

    static int answer = 0;
    static boolean flag = false;

    static boolean check(int h, int w, int t){
        if(h == 0) return true;
        for(int i = h - 1; i >= 0; i--){
            if(board[i][w][t] == '#') return false;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int i = 0; i < 8; i++){
            String str = br.readLine();
            for(int j = 0; j < 8; j++){
                board[i][j][0] = str.charAt(j);
            }
        }

        for(int t = 1; t < 8; t++){
            for(int j = 0; j < 8; j++){
                for(int i = 8 - 2; i >= 0; i--){
                    board[i + 1][j][t] = board[i][j][t - 1];
                }
                board[0][j][t] = '.';
            }
        }

        Queue<Pair4> q = new LinkedList<>();
        q.offer(new Pair4(7, 0, 0));

        boolean flag = false;

        while (!q.isEmpty()){
            Pair4 p = q.poll();

            if(board[p.first][p.second][p.time >= 8 ? 7 : p.time] == '#') continue;

            if(check(p.first, p.second, p.time) || p.first == 0 && p.second == 7) {
                flag = true;
                break;
            }

            if(p.time + 1 >= 8 || board[p.first][p.second][p.time + 1] != '*'){
                q.offer(new Pair4(p.first, p.second, p.time + 1));
            }

            for(int i = 0; i < 8; i++){
                int tmp_h = p.first + move_h[i];
                int tmp_w = p.second + move_w[i];

                if (tmp_w < 0 || tmp_h < 0 || tmp_w > 7 || tmp_h > 7 || board[tmp_h][tmp_w][p.time >= 8 ? 7 : p.time] == '#') continue;
                q.offer(new Pair4(tmp_h, tmp_w, p.time + 1));
            }
        }
        if(flag) System.out.println(1);
        else System.out.println(0);
    }
}
