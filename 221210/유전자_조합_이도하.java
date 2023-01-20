import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;

class Pair{
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] larr = new int[26];
        int[] rarr = new int[26];

        ArrayList<Pair> al = new ArrayList<>();

        int N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            String n = st.nextToken();
            larr[n.charAt(0) - 'A']++;
            rarr[n.charAt(1) - 'A']++;
            al.add(new Pair(n.charAt(0) - 'A', n.charAt(1) - 'A'));
        }

        for (int i = 1; i < 26; i++){
            larr[i] += larr[i-1];
            rarr[i] += rarr[i-1];
        }

        TreeMap<Character, Integer> m = new TreeMap<>();

        for(Pair pair : al){
            int a1 = rarr[pair.first], a2 = larr[pair.second];
            if (pair.first <= pair.second) {
                a2 -= 1;
            }
            if (pair.first >= pair.second) {
                a1 -= 1;
            }
            if (a1 > 0)
                m.put((char)(pair.first + 'A'), 1);
            if (a2 > 0)
                m.put((char)(pair.second  + 'A'), 1);
        }

        System.out.println(m.size());

        for(Character c : m.keySet()){ //저장된 key값 확인
            System.out.print(c + " ");
        }

    }
}
