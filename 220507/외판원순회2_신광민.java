import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class bak_jun10971 {

    static int n ;
    static int[][] arr;
    static long min = Integer.MAX_VALUE;
    static boolean[] visited;

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[n][n];
        visited = new boolean[n];

        for (int i = 0; i <n ; i++) {
            for (int j = 0; j <n ; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        // 출력용
//        for (int i = 0; i <n ; i++) {
//            for (int j = 0; j <n ; j++) {
//                System.out.println("arr[" + i + "]" + "[" + j + "]" + arr[i][j]);
//            }
//        }

        for (int i = 0; i <n ; i++) {
            dfs(i,i,0,0);
        }
        System.out.println(min);
    }
    public static void dfs(int start, int i, int cnt, int sum){


        if(cnt == n && start == i){
            // 최소 경로값
            min = Math.min(min, sum);
            return;
        }

        for (int j = 0; j <n ; j++) {
            // 스스로 이동 시 continue;
            if(arr[i][j]==0){
                continue;
            }

            if(!visited[i] && arr[i][j] > 0){
                visited[i]=true;
                sum += arr[i][j];
                dfs(start, j, cnt +1, sum);
                visited[i] = false;
                sum -= arr[i][j];
            }
        }
    }
}
