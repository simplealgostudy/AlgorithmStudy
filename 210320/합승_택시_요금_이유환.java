class Solution {    
    int[][] floyd(int n, int arr[][]) { 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    if(arr[j][k] > arr[j][i] + arr[i][k])
                        arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }

        return arr;
    }

    public int solution(int n, int s, int a, int b, int[][] fares) {    
        int answer = 100001 * 201;
        int[][] arr = new int[201][201];

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                arr[i][j] = 100001 * 201;

        for(int i = 1; i <= n; i++) arr[i][i]=0;

        for(int i = 0; i < fares.length; i++){
            arr[fares[i][0]][fares[i][1]]=fares[i][2];
            arr[fares[i][1]][fares[i][0]]=fares[i][2];
        }

        arr = floyd(n, arr);

        for(int i=1;i<=n;i++) {
            if(answer > arr[s][i]+arr[i][a]+arr[i][b]) answer = arr[s][i]+arr[i][a]+arr[i][b];
        }

        return answer;
    }
}
