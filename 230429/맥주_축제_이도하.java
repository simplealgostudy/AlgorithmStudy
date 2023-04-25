import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pair11 implements Comparable<Pair11>{
    int first;
    int second;

    public Pair11(int first, int second) {    // 생성자
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair11 p) {
        return Integer.compare(this.second, p.second);
    }

}

public class Q17503 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayList<Pair11> al = new ArrayList<>();

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        for(int i = 0; i < K; i++){
            st = new StringTokenizer(br.readLine());

            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            al.add(new Pair11(v, c));

        }

        Collections.sort(al);

        PriorityQueue<Pair11> pq = new PriorityQueue<>();

        int answer = 0;
        int sum = 0;

        for(int i = 0; i < al.size(); i++){
            Pair11 p = al.get(i);

            sum += p.first;
            answer = p.second;

            while (pq.size() == N){
                Pair11 tmp = pq.poll();
                sum -= tmp.second;
            }

            pq.add(new Pair11(p.second, p.first));

            //System.out.println(p.first + " " + p.second + " " + sum);

            if(pq.size() == N && sum >= M){
                System.out.println(answer);
                System.exit(0);
            }

        }

        System.out.println(-1);
    }
}
