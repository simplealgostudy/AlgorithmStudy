package backjun.dp;

import java.util.*;
public class bakjun_17404 {

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][]list=new int[n+1][n+1];  //페인트 칠 비용 입력
        int[][]dp=new int[n+1][n+1]; //  0:빨강 1:초록 2:파랑  ex) dp[2][1] ->집 2개의 마지막집을 초록색으로 색칠했을때 드는 최소 비용
        int[]paint=new int[n+1]; //첫집의 색깔에 따라 나오는 최소비용

        for(int i=1;i<=n;i++) {
            for (int j = 0; j < 3; j++) {
                list[i][j] = sc.nextInt();
            }
        }

        for(int i=0;i<3;i++) {    //이번에는 첫집에 i색을 칠하겠어요
            for (int j = 0; j < 3; j++) { //색깔들은 준비해주세요
                if (i == j)
                    dp[1][j] = list[1][j]; // 예정대로 첫집에 i색을 칠하겠어요
                else
                    dp[1][j] = 1001; //나머지 색은 색칠안해요 (완전 논외로 취급)
            }

            //이제 2번째 집 부터 색칠해줄게요
            for (int k = 2; k < n + 1; k++) {
                dp[k][0] = Math.min(dp[k - 1][1], dp[k - 1][2]) + list[k][0];
                dp[k][1] = Math.min(dp[k - 1][0], dp[k - 1][2]) + list[k][1];
                dp[k][2] = Math.min(dp[k - 1][0], dp[k - 1][1]) + list[k][2];
                if(k==n){     //마지막집은 첫집이랑 색깔이 달라야한다
                    if(i==0){ //첫집에 빨간색을 칠했을경우 마지막은 초록 아님 파랑
                        paint[i]=Math.min(dp[n][1],dp[n][2]);
                    }
                    if(i==1){ //첫집에 초록색을 칠했을경우 마지막은 빨강 아님 파랑
                        paint[i]=Math.min(dp[n][0],dp[n][2]);
                    }
                    if(i==2){ //첫집에 파랑색을 칠했을경우 마지막은 빨강 아님 초랑
                        paint[i]=Math.min(dp[n][0],dp[n][1]);
                    }

                }
            }

        }

        //그중에서 최솟값이 페인트 최소 비용
        System.out.print(Math.min(paint[0],Math.min(paint[1],paint[2])));
    }
}
