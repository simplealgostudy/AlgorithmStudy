import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair2{
    int S;
    int T;
    int cnt;

    public Pair2(int S, int T, int cnt) {
        this.S = S;
        this.T = T;
        this.cnt = cnt;
    }
}

public class Q14562 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int C = Integer.parseInt(st.nextToken());

        Queue<Pair2> q = new LinkedList<>();



        for(int i = 0; i < C; i++){
            st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken());
            int T = Integer.parseInt(st.nextToken());

            q.add(new Pair2(S, T, 0));

            int answer = 0;
            while (!q.isEmpty()){
                Pair2 pair = q.poll();

                if(pair.S <= pair.T) {
                    if (pair.S == pair.T) {
                        answer = pair.cnt;
                        break;
                    }

                    q.add(new Pair2(pair.S * 2, pair.T + 3, pair.cnt + 1));
                    q.add(new Pair2(pair.S + 1, pair.T, pair.cnt + 1));
                }
            }

            System.out.println(answer);
            q.clear();
        }


    }
}
