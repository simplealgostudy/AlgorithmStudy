import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        ArrayList<BigInteger> dp = new ArrayList<>();
        dp.add(new BigInteger("1"));
        dp.add(new BigInteger("2"));
        BigInteger bi = new BigInteger("10");
        for (int i = 0; i < 100; ++i) {
            bi = bi.multiply(new BigInteger("10"));
        }
        while (dp.get(dp.size()-1).compareTo(bi) < 0) {
            dp.add(dp.get(dp.size() - 1).add(dp.get(dp.size() - 2)));
        }
        while (true) {
            st = new StringTokenizer(br.readLine());
            BigInteger a = new BigInteger(st.nextToken());
            BigInteger b = new BigInteger(st.nextToken());
            if (a.compareTo(new BigInteger("0")) == 0 && b.compareTo(new BigInteger("0")) == 0) {
                break;
            }
            int l = 0 , r = dp.size();
            while (l < r) {
                int mid = (l + r) / 2;
                if (dp.get(mid).compareTo(a) >= 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int indexA = l;
            l = 0;
            r = dp.size();
            while (l < r) {
                int mid = (l + r) / 2;
                if (dp.get(mid).compareTo(b) > 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int indexB = l;
            sb.append(indexB-indexA).append("\n");
        }
        System.out.println(sb);
    }
}