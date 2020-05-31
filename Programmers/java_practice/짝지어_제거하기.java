import java.util.*;

class Solution {
	public int solution(String s) {
		int answer = 0;
		Stack<Character> stack = new Stack<>();
		for (char c : s.toCharArray()) {
			if (stack.empty() || stack.peek() != c)
				stack.push(c);
			else
				stack.pop();
		}
		answer = (stack.empty()) ? 1 : 0;
		return answer;
	}
1}