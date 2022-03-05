import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n=Integer.parseInt(br.readLine());
        int answer=0;
        Stack<Integer> s=new Stack<>();
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            int h = Integer.parseInt(st.nextToken());
            while(!s.isEmpty()&&s.peek()>h){
                answer+=1;
                s.pop();
            }
            if(!s.isEmpty()&&s.peek()==h) continue;
            s.push(h);
        }
        //마지막에 스택에 남은 건물 처리
        while(!s.isEmpty()&&s.peek()>0){
            answer+=1;
            s.pop();
        }
        System.out.println(answer);
    }
}
