package backjun.queue;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * 1. N개의 강의
 *
 * 2. 최대한의 적은수의 강의실 사용, 모든강의가 이루어지도록
 *
 * 3. 동시에 2개 이상 상의 진행 X
 *
 * 4. 강의 종료 시간, 강의 시작시간 겹치는것 O
 *
 * 5. 최소 강의실 수 출력
 *
 * 6. 입력
 * 첫쨰줄 : 강의의 갯수
 * 둘쨰줄 : 강의 번호, 강의 시작시간, 강의 종료시간
 *
 * 7. 출력
 * 첫째 줄(강의) 에 필요한 최소 강의실 갯수
 * */

public class bakjun_1374 {
    public static class Node {
        int o, s, e;
        Node(int o, int s, int e) {
            this.o = o; // 강의 번호
            this.s = s; // 강의 시작 시간 start
            this.e = e; // 강의 종료 시간 end
        }

        @Override
        public String toString() {
            return "Node{" +
                    "o=" + o +
                    ", s=" + s +
                    ", e=" + e +
                    '}';
        }
    }

    public static List<Node> list = new ArrayList<>();
    public static PriorityQueue<Integer> que = new PriorityQueue<>();
    public static Comparator<Node> comparator = new Comparator<>() {
        @Override
        public int compare(Node o1, Node o2) {
            return Integer.compare(o1.s, o2.s);
        }
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int o = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            list.add(new Node(o, s, e));
        }

        Collections.sort(list, comparator);

        /*for (int z = 0; z < list.size(); z++) {
            System.out.println("list.get(z).toString() = " + list.get(z).toString());;
        }*/

        /**
         * Node{o=3, s=2, e=14}
         * Node{o=1, s=3, e=8}
         * Node{o=8, s=6, e=27}
         * Node{o=5, s=6, e=20}
         * Node{o=2, s=7, e=13}
         * Node{o=4, s=12, e=18}
         * Node{o=6, s=15, e=21}
         * Node{o=7, s=20, e=25}
         * */

        int max = Integer.MIN_VALUE;

        for(int i = 0; i < n; i++) {
            System.out.println("que.peek() = " + que.peek() + " list.get(i).s = " + list.get(i).s);

            // 시작 시간 순으로 나열후, 가장 빠른 시작시간과 겹치거나 빠른 종료시간이 있다면
            // 데이터를 빼낸다. 아니라면, 강의가 겹치기 때문에 강의실을 추가해 나간다.
            while(!que.isEmpty() && que.peek() <= list.get(i).s) {
                que.poll();
            }

            que.add(list.get(i).e);
            System.out.println("list.get(i).e = " + list.get(i).e);
            max = Math.max(max, que.size());
            System.out.println("max = " + max);
        }

        System.out.println(max);

    }
}
