import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
//	버퍼 및 경로 길이 선언
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N;

	public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
//        경로 배열, 부모 배열 선언
		int arr[] = new int[N];
		int parent[] = new int[N];
		
		int i = 0;
		
//		  Hashset으로 선언
		HashSet<Integer> tree = new HashSet<Integer>();
		
//        StringToken 선언
		StringTokenizer st = new StringTokenizer(br.readLine());
		
//        배열에 값 저장
		while(st.hasMoreTokens()) {
        	arr[i] = Integer.parseInt(st.nextToken());
        	i++;
        }
        
//		  부모 배열 첫번째 값(root의 부모) -1 저장
        parent[arr[0]] = -1;
//        Hashset에 root 추가
        tree.add(arr[0]);
        
        for(int j=1; j < arr.length; j++) {
//        	Hashset에 입력받은 경로가 존재하지 않으면 추가 및 부모 값 저장
        	if(!tree.contains(arr[j])) {
        		parent[arr[j]] = arr[j-1];
        		tree.add(arr[j]);
        	}
        }
        
//        출력
        bw.write(String.valueOf(tree.size()));
        bw.newLine();
        for(int k=0; k < tree.size(); k++) {
        	bw.write(String.valueOf(parent[k]));
        	bw.write(" ");
        }
        bw.flush();
	}
}
