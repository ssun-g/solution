import java.util.*;

class Solution {
	public int[] solution(int[] answers) {
		int[] answer = {};
		int su1[] = { 1, 2, 3, 4, 5 };
		int su2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
		int su3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
		int[] cnt = new int[3];
		for (int i = 0; i < answers.length; i++) {
			if (answers[i] == su1[i % 5])
				cnt[0]++;
			if (answers[i] == su2[i % 8])
				cnt[1]++;
			if (answers[i] == su3[i % 10])
				cnt[2]++;
		}

		int MAX = Math.max(cnt[0], Math.max(cnt[1], cnt[2]));
		ArrayList<Integer> list = new ArrayList<Integer>();

		for (int i = 0; i < 3; i++) {
			if (MAX == cnt[i])
				list.add(i + 1);
		}

		answer = new int[list.size()];
		for (int i = 0; i < answer.length; i++) {
			answer[i] = list.get(i);
		}

		return answer;
	}
}