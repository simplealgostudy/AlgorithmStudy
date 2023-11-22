import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Q6566 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, ArrayList> hm = new HashMap<>();
        HashMap<String, Integer> cntHm = new HashMap<>();

        while (true) {
            String str = br.readLine();
            if (str == null || str.isEmpty()) break;

            char[] charArr = str.toCharArray();
            Arrays.sort(charArr);
            String srtStr = new String(charArr);

            ArrayList<String> al;

            if(hm.containsKey(srtStr)){
                al = hm.get(srtStr);
            }
            else {
                al = new ArrayList<>();
            }

            if(!al.contains(str)) al.add(str);
            hm.put(srtStr, al);

            if(cntHm.containsKey(srtStr)){
                int tmp = cntHm.get(srtStr);
                cntHm.put(srtStr, ++tmp);
            }
            else {
                cntHm.put(srtStr, 1);
            }
        }

        List<Map.Entry<String, Integer>> entryList = new LinkedList<>(cntHm.entrySet());
        entryList.sort(new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                if (o1.getValue() > o2.getValue()) {
                    return -1;
                }
                else if (o1.getValue() < o2.getValue()) {
                    return 1;
                }

                return o1.getKey().compareTo(o2.getKey());

            }
        });

        HashMap<String, Integer> ansMap = new HashMap<>();
        for(Map.Entry<String, Integer> entry : entryList){

            int ansCnt = entry.getValue();
            String ansStr = "";

            //System.out.print("Group of size " + entry.getValue() + ": ");

            ArrayList<String> al = hm.get(entry.getKey());

            Collections.sort(al);

            for(String str : al){
                ansStr += str + " ";
            }

            ansMap.put(ansStr, ansCnt);

        }

        List<Map.Entry<String, Integer>> AnsEntryList = new LinkedList<>(ansMap.entrySet());
        AnsEntryList.sort(new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                if (o1.getValue() > o2.getValue()) {
                    return -1;
                }
                else if (o1.getValue() < o2.getValue()) {
                    return 1;
                }

                return o1.getKey().compareTo(o2.getKey());

            }
        });

        int limitCnt = 0;
        for(Map.Entry<String, Integer> entry : AnsEntryList){

            if(limitCnt < 5){
                System.out.print("Group of size " + entry.getValue() + ": ");

                System.out.println(entry.getKey() + ".");

                limitCnt++;
            }
            else break;

        }

    }
}
