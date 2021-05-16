class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int matched = 0;
        int zero = 0;
        int max = 0;
        int min = 0 ;
        
        for(int i = 0 ; i < 6 ; i++){
            for(int j = 0 ; j < 6 ; j++){
                if(win_nums[i] == lottos[j]){
                    matched++;
                }
            }
            if(lottos[i] == 0){
                zero++;
            }
        }
        
        min = 7 - matched;
        
        
        max = 7 - matched - zero;
        if(min > 6){
            min = 6;
        }
        if(max > 6){
            max = 6;
        }
        
        int[] answer = {max,min}; 
        return answer;
    }
}
