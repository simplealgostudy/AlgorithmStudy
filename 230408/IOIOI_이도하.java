import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static long answer = 0;
	static int[] makeTable(String p) {
        int psize = p.length();
        int[] table = new int[psize];
        int j = 0;
        for (int i = 1; i < psize; i++) {
            while (j > 0 && p.charAt(i) != p.charAt(j)) {
                j = table[j - 1];
            }
            if (p.charAt(i) == p.charAt(j)) {
                table[i] = ++j;
            }
        }
        return table;
    }
 
    static void kmp(String p, String check) {
        int[] table = makeTable(check);
        int parentSize = p.length();
        int patternSize = check.length();
        int j = 0;
        for (int i = 0; i < parentSize; i++) {
            while (j > 0 && p.charAt(i) != check.charAt(j)) {
                j = table[j - 1];
            }
            if (p.charAt(i) == check.charAt(j)) {
                if (j == patternSize - 1) {
                    answer++;
                    j = table[j];
                } else {
                    j++;
                }
            }
        }
    }
	
	public static void main(String []args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		StringBuilder p = new StringBuilder(br.readLine());
		
		StringBuilder check = new StringBuilder("I");
		for(int i = 0; i < n; i++) {
			check.append("OI");
		}
		
		kmp(p.toString(), check.toString());
		
		System.out.println(answer);
	}
}
