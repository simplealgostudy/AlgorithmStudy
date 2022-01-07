package backjun.dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *   1,2,3,2 -> 1 버림
 *  -> 2,3,2 -> 2,2,3 정렬
 *
 *  1,2,3,2 -> 3 버림
 *  -> 1,2,2 -> 1,2,2 정렬
 *
 *  1,2,3,2 -> 첫번쨰 2버림
 *  -> 1,3,2 -> 1,2,3 정렬
 *
 *  수 하나를 버린뒤 정렬된 배열을 남기는 방법의 수를 구하자.
 */
public class bakjun_17074 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int N;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(solution());
    }

    private static int solution() {

        int sortCount = 0;
        int index =0;
        for (int i = 0; i < N-1; i++) {
            if (arr[i]>arr[i+1]) {
                index = i; // 정렬되어야하는 인덱스
                sortCount++;    // 정렬 할수 있는 횟수
            }
        }
        if (sortCount == 0) return N; // 횟수가 0 이라면 전부 동일한 요소로 N 개
        if (sortCount == 1) { // 정렬 가능횟수 횟수가 1일때,
            if (index == 0) {
                // arr[0], arr[2]
                if (arr[index] <= arr[index+2]) return 2;
                return 1;
            }

            if (index==N-2) {
                if (arr[index-1] <= arr[index+1]) return 2;
                return 1;
            }

            int c = 0;
            if (arr[index-1] <= arr[index+1])c++;
            if (arr[index] <= arr[index+2]) c++;
            return c;
        }
        return 0;
    }
}
