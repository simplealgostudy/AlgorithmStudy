import java.util.Arrays;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        //int[] answer = {};
        //return answer;
        int results[] = new int[2];
        int count = 0;
        int missing = 0;

        for (int i = 0; i<6;i++){
            if(lottos[i]==0){
                missing++;
            }
            for(int j=0;j<6;j++){
                if (lottos[i]==win_nums[j]){
                    count++;}

            }
        }


        switch (count) {
            case 6:
                results[1]=1;
                break;
            case 5:
                results[1]=2;
                break;
            case 4:
                results[1]=3;
                break;
            case 3:
                results[1]=4;
                break;
            case 2:
                results[1]=5;
                break;
            case 1:
            case 0:
                results[1]=6;
                break;
        }

        int possiblity = count+missing;

        switch (possiblity) {
            case 6:
                results[0]=1;
                break;
            case 5:
                results[0]=2;
                break;
            case 4:
                results[0]=3;
                break;
            case 3:
                results[0]=4;
                break;
            case 2:
                results[0]=5;
                break;
            case 1:
            case 0:
                results[0]=6;
                break;
        }  

        Arrays.toString(results);
        return results;
    }
}
