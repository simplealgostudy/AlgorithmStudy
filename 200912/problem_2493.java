import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;


public class problem_2493 {
    public static void main(String[] args) throws Exception, IOException {
        Stack<int[]> tower = new Stack<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer stt = new StringTokenizer(br.readLine());

        for (int i = 1; i < n +1 ; i++) {
            int temp = Integer.parseInt(stt.nextToken());
            while (!tower.isEmpty()) {
                if (temp < tower.peek()[1]) {
                    System.out.print(tower.peek()[0] + " ");
                    break;
                }
                tower.pop();
            }
            if (tower.isEmpty()) {
                System.out.print("0 ");
            }

            tower.push(new int[] { i, temp });
        }
     
    }

}
