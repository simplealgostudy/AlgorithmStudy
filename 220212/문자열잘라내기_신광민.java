import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        char[][] word = new char[R][C];
        for (int r=0;r<R;r++) {
            word[r] = br.readLine().toCharArray();
        }

        Set<String> set;
        StringBuilder sb;
        int cnt = 0;
        String[] arr = new String[C];

        for (int c=0;c<C;c++) {
            sb = new StringBuilder();
            for (int r=1;r<R;r++) { // 제일 윗행은 중복될 일이 없으므로 1부터 탐색
                sb.append(word[r][c]);
            }
            arr[c] = sb+"";
        }
        
        //  R줄에 걸쳐서 C개의 알파벳 소문자
        String now = "";
        stop:for (int r=0;r<R;r++) {
            set = new HashSet<>();
            for (int c=0;c<C;c++) {
                now = arr[c].substring(r); // substring 함수를 통해 초기 문자열을 잘라가며 사용
                if (set.contains(now)) break stop; // 문자열이 중복되면 그만!
                else set.add(now);
            }
            cnt++;
        }
        System.out.println(cnt);
    }

    /**
     * 3 4
     * alfa
     * beta
     * zeta
     */
}
