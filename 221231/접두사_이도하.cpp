import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayList<String> al = new ArrayList<>();

        int N = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            al.add(str);

        }

        Collections.sort(al);
        int answer = 0;
        for(int i = 0; i < al.size(); i++){
            boolean check = true;
            for(int j = i + 1; j < al.size(); j++){
                if((al.get(j)).startsWith(al.get(i))) {
                    check = false;
                    break;
                }
            }

            if(check) answer++;

        }

        System.out.println(answer);
    }
}
