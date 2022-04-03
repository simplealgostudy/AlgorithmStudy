package bakjun;
import java.io.*;
import java.util.*;

public class 서울지하철_16166 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static List<Integer>[] a = new ArrayList[11];
    static List<Integer>[] b = new ArrayList[110];
    static Map<Integer, Integer> map=new HashMap<>();
    static boolean[][] visit = new boolean[11][110];

    static class Entity implements Comparable<Entity>
    {
        int cnt,num,line;

        public Entity(int cnt, int num, int line) {
            this.cnt = cnt;
            this.num = num;
            this.line = line;
        }

        @Override
        public int compareTo(Entity o) {
            if(this.cnt == o.cnt)
            {
                if(num == o.num)
                {
                    return this.line - o.line;
                }
                else
                    return this.num-o.num;
            }
            else
                return this.cnt -o.cnt;
        }
    }
    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i <= N; i++) {
            a[i] = new ArrayList<>();
        }
        for(int i=0;i<110;i++)
        {
            b[i] = new ArrayList<>();
        }
        int idx =0 ;
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            for (int j = 0; j < k; j++) {
                int num = Integer.parseInt(st.nextToken());
                if(!map.containsKey(num)) {
                    map.put(num,++idx);
                    b[idx].add(i+1);
                    a[i+1].add(idx);
                }
                else
                {
                    b[map.get(num)].add(i+1);
                    a[i+1].add(map.get(num));
                }
            }
        }
        int e = Integer.parseInt(br.readLine());
        int e_idx;
        if(map.containsKey(e))
            e_idx = map.get(e);
        else
        {
            bw.write("-1");
            bw.flush();
            return;
        }
        //map 번호의 인덱스
        //b[인덱스] - 인덱스에 해당하는 번호가 속해있는 호선
        //a[i] - i 호선에 속해있는 번호
        PriorityQueue<Entity> pq = new PriorityQueue();
        for(int i=0;i<b[map.get(0)].size();i++) {
            pq.add(new Entity(0, map.get(0),b[map.get(0)].get(i)));
        }

        while(!pq.isEmpty())
        {
            int curNum = pq.peek().num;
            int curLine = pq.peek().line;
            int curCnt = pq.peek().cnt;
            pq.poll();
            if(curNum == e_idx)
            {
                bw.write(Integer.toString(curCnt));
                bw.flush();
                return;
            }
            for(int i=0;i<a[curLine].size();i++)
            {
                int nextNum = a[curLine].get(i);
                if(!visit[curLine][nextNum]) {
                    visit[curLine][nextNum] =true;
                    pq.add(new Entity(curCnt, nextNum, curLine));
                }
            }
            for(int i=0;i<b[curNum].size();i++)
            {
                int nextLine = b[curNum].get(i);
                if(!visit[nextLine][curNum]) {
                    visit[nextLine][curNum] =true;
                    pq.add(new Entity(curCnt + 1, curNum, nextLine));
                }
            }
        }

        bw.write("-1");
        bw.flush();


    }
}
