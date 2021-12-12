package backjun.queue;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * 1. 뿅망치, -> 맞은 사람의 키가 키/2 로 변한다.
 * 단, 1인경우 줄어들지 않아, 영향이 없다.
 *
 * 2. 횟수 제한이 있다. 매번 가장 키가 큰 거인 가운데 하나를 떄린다.
 *
 * 3. 입력
 * 인구수, 센티의 키, 횟수
 * 두번쨰 줄 부터 거인의 키를 나타내는 정수
 *
 * 4. 출력
 * 모든 거인이 센티보다 키가 작을수 있게 할수 있다면, -> Yes, 최소 사용 횟수
 * 그렇지 않다면 -> No, 가장 큰 거인의 키 출력
 *
 * */
public class bakjun_19638 {

    static StringTokenizer tokens;
    static int N,H,T;
    static PriorityQueue<Integer> giant = new PriorityQueue<>(Collections.reverseOrder());

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        tokens = new StringTokenizer(input.readLine());
        N = Integer.parseInt(tokens.nextToken()); // 인구수
        H = Integer.parseInt(tokens.nextToken()); // 센티의 키
        T = Integer.parseInt(tokens.nextToken()); // 횟수

        // 거인들의 키 giant에 집어 넣는다.
        for(int n=0; n<N; n++) {
            giant.offer(Integer.parseInt(input.readLine()));
        }
        
        int tallest;
        int magicStickCount = T;

        while(magicStickCount>0) {
            tallest = giant.poll();

            // 1. 센티보다 키가 작은 경우
            if(tallest < H) {
                giant.offer(tallest);
                break;
            // 2. 센티보다 키가 큰경우
            }else {
                // 키가 1일경우
                if(tallest/2 == 0) {
                    giant.offer(1);
                    break;

                //키가 1일 아닐경우
                }else {
                    giant.offer(tallest/2);
                }
            }
            magicStickCount--;
        }

        if(giant.peek() < H) {
            System.out.println("YES");
            System.out.println(T-magicStickCount); // 최소 사용 횟수
        }else {
            System.out.println("NO");
            System.out.println(giant.peek()); // 가장 큰거인의 키
        }
    }

}
