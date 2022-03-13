package bakjun;

import java.io.*;
import java.util.*;

public class 가희와은행_22234 {


    static int n, t, w, m;
    static Queue<Customer> q = new LinkedList<>();
    static PriorityQueue<Customer> customer_list;

    public static void main(String[] args) throws IOException {

        //입력
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String str = bf.readLine();
        StringTokenizer st = new StringTokenizer(str);
        n = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            str = bf.readLine();
            st = new StringTokenizer(str);
            int num = Integer.parseInt(st.nextToken());
            int time = Integer.parseInt(st.nextToken());
            q.offer(new Customer(num, time, 0));
        }

        m = Integer.parseInt(bf.readLine());
        customer_list = new PriorityQueue<>((o1, o2) -> o1.input_time - o2.input_time);
        for (int i = 0; i < m; i++) {
            str = bf.readLine();
            st = new StringTokenizer(str);
            int num = Integer.parseInt(st.nextToken());
            int time = Integer.parseInt(st.nextToken());
            int input_time = Integer.parseInt(st.nextToken());
            customer_list.offer(new Customer(num, time, input_time));
        }
        //입력 끝
        System.out.print(round_robin().toString());
    }

    public static StringBuilder round_robin() {
        StringBuilder sb = new StringBuilder();
        int current_time = 0;
        while (current_time < w) {
            Customer current = q.poll();

            if (current.time > t) {
                for (int i = 0; i < t; i++) {
                    if (current_time >= w) return sb;
                    sb.append(current.num + "\n");
                    current_time++;
                }
            } else {
                for (int i = 0; i < current.time; i++) {
                    if (current_time >= w) return sb;
                    sb.append(current.num + "\n");
                    current_time++;
                }
            }

            while (!customer_list.isEmpty() && customer_list.peek().input_time <= current_time) {
                q.offer(customer_list.poll());
            }

            if (current.time > t) {
                current.time -= t;
                q.offer(current);
            }
        }
        return sb;
    }

    public static class Customer {
        int num, time, input_time;

        public Customer(int num, int time, int input_time) {
            this.num = num;
            this.time = time;
            this.input_time = input_time;
        }
    }
}

