import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static int n;
    static int[][] W;
    static long result_min = Integer.MAX_VALUE;
    static int count = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    n = Integer.parseInt(br.readLine());
	    StringTokenizer st;
	    
	    int[] nums = new int[n];
	    W = new int[n][n];
	    for (int i = 0; i < n; i++) {
	    	nums[i] = i;
	        st = new StringTokenizer(br.readLine());
	        for (int j = 0; j < n; j++) {
	            W[i][j] = Integer.parseInt(st.nextToken());
	        }
	    }
	    
		List<Integer> tempList = new ArrayList<Integer>();

		backtracking(tempList, nums);
		
		System.out.println(result_min);
	}
	
	public static void backtracking(List<Integer> tempList, int[] nums) {
		if (tempList.size() == nums.length) {
			int sum = 0;
		
			for(int i=0; i < n; i++) {
				if(i == n-1) {
					if(W[tempList.get(i)][tempList.get(0)] == 0) {
						break;
					}
					sum += W[tempList.get(i)][tempList.get(0)];
					if(sum < result_min) {
						result_min = sum;
					}
				} else {
					if(W[tempList.get(i)][tempList.get(i+1)] == 0) {
						break;
					}
					sum += W[tempList.get(i)][tempList.get(i+1)];
				}
			}
			
		} else {
			for (int i = 0; i < nums.length; i++) {
				if (tempList.contains(nums[i])) {
					continue;
				}
				tempList.add(nums[i]);
				backtracking(tempList, nums);
				tempList.remove(tempList.size() - 1);
			}
		}
	}
}
