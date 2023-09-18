import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Q28107 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        PriorityQueue<int []> que = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0] == o2[0]){
                    return o1[1] - o2[1];
                }
                return o1[0] - o2[0];
            }
        });

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());

            for(int j = 0; j < k; j++){
                que.offer(new int[] {Integer.parseInt(st.nextToken()), i});
            }

        }

        PriorityQueue<Integer> food = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < m; i++){
            food.offer(Integer.parseInt(st.nextToken()));
        }

        int answer[] = new int[n];
        while(!food.isEmpty()){
            if(que.isEmpty()) break;

            if(que.peek()[0] == food.peek()){
                int tmp[] = que.poll();
                food.poll();
                answer[tmp[1]]++;
            }
            else if (que.peek()[0] > food.peek()) food.poll();
            else que.poll();

        }

        for(int i = 0; i < n; i++){
            System.out.print(answer[i] + " ");
        }

    }
}

