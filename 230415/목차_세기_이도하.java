import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

class Pair10{
    int first;
    int second;

    public Pair10(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class Q25956 {

    static Stack<Pair10> stk = new Stack<>();
    static int[] answerArr;

    static boolean check(int oldVal){
        int cnt = 0;
        int d1 = stk.peek().first;
        while (!stk.empty() && d1 > oldVal){
            stk.pop();
            cnt++;

            if(!stk.empty() && stk.peek().first != d1){
                int d2 = stk.peek().first;

                if(d2 == d1 - 1){
                    answerArr[stk.peek().second] = cnt;
                    d1 = stk.peek().first;
                    cnt = 0;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        answerArr = new int[N];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());

            if(i == 0 && l != 1) {
                bw.write(-1 + "");
                bw.close();
                System.exit(0);
            }

            if(!stk.empty() && stk.peek().first > l && ! check(l)){
                bw.write(-1 + "");
                bw.close();
                System.exit(0);
            }
            stk.push(new Pair10(l, i));
        }

        if(!stk.empty() && !check(0)){
            bw.write(-1 + "");
            bw.close();
            System.exit(0);
        };

        for(int i = 0; i < N; i++){
            bw.write(answerArr[i] + "\n");
        }
        bw.close();

    }
}
