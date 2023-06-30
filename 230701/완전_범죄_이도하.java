import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair{
    int first;
    int second;

    public Pair(int first, int second){
        this.first = first;
        this.second = second;
    }
}

public class Q13700 {

    static Set<Integer> set = new HashSet<>();
    static int N, S, D, F, B, K, answer;
    static boolean[] visit;

    static void bfs(){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(S, 0));

        while (!q.isEmpty()){
            Pair pair = q.poll();

            if(pair.first == D){
                answer = pair.second;
                break;
            }

            int current = pair.first;

            visit[current] = true;

            int front = current + F;
            int back = current - B;

            if(!set.contains(front) && front <= N && !visit[front]){
                visit[front] = true;
                q.add(new Pair(front, pair.second + 1));
            }

            if(!set.contains(back) && back >= 1 && !visit[back]){
                visit[back] = true;
                q.add(new Pair(back, pair.second + 1));
            }

        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        F = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        visit = new boolean[N + 1];

        if(K > 0){
            st = new StringTokenizer(br.readLine());

            while (st.hasMoreTokens()){
                set.add(Integer.valueOf(st.nextToken()));
            }
        }

        bfs();

        if(answer == 0) System.out.println("BUG FOUND");
        else System.out.println(answer);

    }
}
