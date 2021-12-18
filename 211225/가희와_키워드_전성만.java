import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    
    static HashSet<String> hs = new HashSet<String>();
    static int n, m;

    public static void main(String args[]) {
        inputMap();
    }

    private static void inputMap() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringBuilder sb = new StringBuilder();
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            for (int i = 0; i < n; ++i) {
                hs.add(br.readLine());
            }
            for (int i = 0; i < m; ++i) {
                st = new StringTokenizer(br.readLine(), ",");
                while(st.hasMoreTokens()) {
                    String tmp = st.nextToken();
                    if (hs.contains(tmp)) {
                        hs.remove(tmp);
                    }
                }
                sb.append(hs.size()).append('\n');
            }
            System.out.println(sb);
        } catch (Exception e) {

        }
    }
    
}