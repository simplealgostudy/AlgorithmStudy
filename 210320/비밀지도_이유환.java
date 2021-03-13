class Solution {
    static String check(String bin, int size) {
        int num = size - bin.length();
        for(int i = 0 ; i < num; i++) {
            bin = "0" + bin;
        }
        return bin;
    }
    public String[] solution(int n, int[] arr1, int[] arr2) {
        int size = n;   
        String[] result = new String[size];

        for(int i = 0; i < size; i++) {
            String bin1 = Integer.toBinaryString(arr1[i]);
            if(bin1.length() < size) {
                bin1 = check(bin1, size);
            }

            String bin2 = Integer.toBinaryString(arr2[i]);
            if(bin2.length() < size) {
                bin2 = check(bin2, size);
            }
            String tmp = "";
            for(int j = 0; j < size; j++) {
                if(bin1.charAt(j) == bin2.charAt(j)) {
                    if(bin1.charAt(j) == '0')
                        tmp += " ";
                    else 
                        tmp += "#";

                }
                else {
                    if(bin1.charAt(j) == '0' && bin2.charAt(j) == '0')
                        tmp += " ";
                    else 
                        tmp += "#";
                }
            }
            result[i] = tmp;
            System.out.println(result[i]);
        }
    return result;
}}
