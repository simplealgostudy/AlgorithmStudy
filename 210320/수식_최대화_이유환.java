import java.util.ArrayList;
class Permutation { 
    private int n; 
    private int r; 
    private char[] now; // 현재 순열 
    private ArrayList<ArrayList<Character>> result; // 모든 순열

    public ArrayList<ArrayList<Character>> getResult() { 
        return result; 
    } 

    public Permutation(int n, int r) { 
        this.n = n;
        this.r = r;
        this.now = new char[r];
        this.result = new ArrayList<ArrayList<Character>>(); 
    } 

    public void swap(char[] arr, int i, int j) { 
        char temp = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = temp; 
    } 

    public void permutation(char[] arr, int depth) { // 현재 순열의 길이가 r일 때 결과 저장 
        if (depth == r) { ArrayList<Character> temp = new ArrayList<>(); 

        for (int i = 0; i < now.length; i++) { 
            temp.add(now[i]); 
        } 

        result.add(temp); 

        return; 
        } 

        for (int i = depth; i < n; i++) { 
            swap(arr, i, depth); 
            now[depth] = arr[depth]; 
            permutation(arr, depth + 1); 
            swap(arr, i, depth); 
        } 
    }   
}

class Solution {    
    public long solution(String expression) {
        long answer = 0;
        char[] operator = {'+', '-', '*'};

        Permutation perm = new Permutation(operator.length, 3); 
        perm.permutation(operator, 0); 
        ArrayList<ArrayList<Character>> result = perm.getResult();

        for (int ci = 0; ci < result.size(); ci++) { 

            ArrayList<Long> numbers = new ArrayList<>();
            ArrayList<Character> oper = new ArrayList<>();

            String num = "";
            for(int i = 0; i < expression.length(); i++) {
                if(expression.charAt(i) >= '0' && expression.charAt(i) <= '9') {
                    num+= expression.charAt(i);
                }else {
                    numbers.add(Long.parseLong(num));
                    num = "";
                    oper.add(expression.charAt(i));
                }
            }
            numbers.add(Long.parseLong(num));

            ArrayList<Character> checkOper = new ArrayList<>();
            long sum = 0;
            for (int cj = 0; cj < result.get(ci).size(); cj++) { 
                checkOper.add(result.get(ci).get(cj));
            }

            for(int i = 0; i < checkOper.size(); i++) {
                for(int j = 0; j < oper.size(); j++) {
                    if(checkOper.get(i) == oper.get(j)) {
                        long sumT = 0;
                        if(oper.get(j) == '+') { 
                            sumT = numbers.remove(j) + numbers.remove(j);                           
                        }
                        else if(oper.get(j) == '-') {
                            sumT = numbers.remove(j) - numbers.remove(j);
                        }
                        else if(oper.get(j) == '*') {
                            sumT = numbers.remove(j) * numbers.remove(j);
                        }

                        numbers.add(j, sumT);
                        oper.remove(j);
                        j--;
                    }
                }
            }

            long resultNum = numbers.get(0);            
            if(resultNum < 0) resultNum *= -1;
            if(answer < resultNum) answer = resultNum;          
        }    
        return answer;
    }
}
