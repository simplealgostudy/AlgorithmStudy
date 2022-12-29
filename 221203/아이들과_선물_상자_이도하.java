import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Q23757 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            pq.add(Integer.parseInt(st.nextToken()));
        }

        int answer = 1;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++){
            int man = Integer.parseInt(st.nextToken());
            int box = pq.poll();

            if(man > box){
                answer = 0;
                break;
            }
            pq.add(box - man);
        }

        System.out.println(answer);
    }
}
