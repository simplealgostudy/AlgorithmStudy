import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Q30892 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long T = Long.parseLong(st.nextToken());

        ArrayList<Long> sharks = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) sharks.add(Long.parseLong(st.nextToken()));

        Collections.sort(sharks);

        Stack<Long> stk = new Stack<>();

        int cnt = 0;

        for (int i = 0; i < sharks.size(); i++){
            while (!stk.isEmpty() && sharks.get(i) >= T && cnt < K){
                T += stk.pop();
                cnt++;
            }

            if(cnt == K) break;
            if(sharks.get(i) >= T) break;
            stk.add(sharks.get(i));

        }

        for(int i = 0; i < K - cnt && !stk.isEmpty(); i++) T += stk.pop();

        System.out.println(T);

    }
}
