import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static Map<String, Integer> hm = new HashMap<String, Integer>();
    static PriorityQueue<Integer> pq[];
    static int n;
    static long answer = 0;

    public static void main(String args[]) {
        inputMap();
        System.out.println(answer);
    }

    private static void inputMap() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            pq = new PriorityQueue[n+1];
            for (int i = 0; i < n+1; ++i) {
                pq[i] = new PriorityQueue<>(Collections.reverseOrder());
            }
            int index = 1;
            StringTokenizer st;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; ++i) {
                st = new StringTokenizer(br.readLine());
                int sw = Integer.parseInt(st.nextToken());
                String str = st.nextToken();
                int m = Integer.parseInt(st.nextToken());
                if (sw == 1) {
                    if (! hm.containsKey(str)) {
                        hm.put(str, index);
                        index++;
                    }
                    int k = hm.get(str);
                    while (st.hasMoreTokens()) {
                        pq[k].add(Integer.parseInt(st.nextToken()));
                    }
                } else {
                    if (! hm.containsKey(str)) {
                        continue;
                    }
                    int k = hm.get(str);
                    while(!pq[k].isEmpty() && m != 0) {
                        answer += pq[k].poll();
                        m--;
                    }
                }
            }
        } catch (Exception e) {

        }
    }

}