package backjun.stack;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


// 출처 : https://m.blog.naver.com/adamdoha/221632572638
public class bakjun_2304 {

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        /*
        7 -- 기둥 갯수
        세운 위치, 높이
        2 4
        11 4
        15 8
        4 6
        5 3
        8 10
        13 6
        * */

        int n=Integer.parseInt(br.readLine()); // 7
        int[] arr=new int[1001];
        int start=1000;
        int end=0;
        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine());
            int l=Integer.parseInt(st.nextToken()); // X 축
            int h=Integer.parseInt(st.nextToken()); // Y 축
            arr[l]=h;
            start=Math.min(l,start); // 가장 앞에 있는 기둥
            end=Math.max(l,end); // 가장 끝에 있는 기둥
        }
        Stack<Integer> trace=new Stack<>();

        System.out.println("start : " + start + " end : " + end);

        // 1. 인덱스는 X축 인덱스 값은 Y축
        // left 부분 부터 

        //left
        int pivot=arr[start];
        for(int l=start+1;l<=end;l++){
            // 기둥이 없는 부분 
            if(arr[l]<pivot) {
                trace.push(l);
            }
            // 부분이 있는 부분
            else{
                while(!trace.isEmpty()){
                    int p=trace.pop();
                    arr[p]=pivot;
                }
                pivot=arr[l];
            }
        }

        trace.clear();

        //right
        pivot=arr[end];
        for(int l=end-1;l>=start;l--){
            if(arr[l]<pivot) trace.push(l);
            else{
                while(!trace.isEmpty()){
                    int p=trace.pop();
                    arr[p]=pivot;
                }
                pivot=arr[l];
            }
        }

        int answer=0;
        for(int l=start;l<=end;l++){
            answer+=arr[l];
        }
        System.out.println(answer);
    }
}
