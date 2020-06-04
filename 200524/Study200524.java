package study;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Study200524 {
	static Queue<Integer> queue = new LinkedList<Integer>();
	static Scanner scanner = new Scanner(System.in);
	static int r = 0;
	
	public void push() {
		int element = scanner.nextInt();
		queue.offer(element);
		r = element;
	}
	void pop() {
		if (!queue.isEmpty())
			queue.poll();
		else
			System.out.println(-1);
	}
	void size() {
		System.out.println(queue.size());
	}
	void empty() {
		if (!queue.isEmpty())
			System.out.println(0);
		else
			System.out.println(1);
	}
	void front() {
		System.out.println(queue.peek());
	}
	void back() {
		System.out.println(r);
	}
	
	public static void main(String[] args) {
		int n = scanner.nextInt();
		Study200524 s = new Study200524();
		
		for(int i = 0; i < n; i++) {
			String str = scanner.next();
			
			switch(str) {
				case("push"):
					s.push();
					break;
					
				case("pop"):
					s.pop();
					break;
					
				case("size"):
					s.size();
					break;
					
				case("empty"):
					s.empty();
					break;
					
				case("front"):
					s.front();
					break;
					
				case("back"):
					s.back();
					break;
			}
		}
	}

}
