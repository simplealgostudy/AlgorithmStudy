import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Q25918 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        String S = br.readLine();

        int answer = 0;

        int a = 0, b = 0;

        for(int i = 0; i < S.length(); i++){
            if(S.charAt(i) == '(') a++;
            else b++;

            answer = Math.max(Math.abs(a - b), answer);
        }

        if (a == b) System.out.println(answer);
        else System.out.println(-1);
    }
}
