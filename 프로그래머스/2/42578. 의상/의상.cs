using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(string[,] clothes) {
        // 각 종류의 의상을 1개를 입거나 안 입을 경우의 수를 계산하고 모두 곱한다.
		// 최소 1가지의 의상을 입어야하므로 아무거도 안 입는 1가지는 제외해야한다.
		int answer = 0;

        Dictionary<string, int> categories = new Dictionary<string, int>();

		for (int i = 0; i < clothes.GetLength(0); i++)
		{
			if (categories.TryAdd(clothes[i, 1], 1))
			{
				continue;
			}
			categories[clothes[i, 1]] += 1;
		}

		var counts = categories.Select(pair => pair.Value + 1);

		foreach (int count in counts)
		{
			if (answer == 0)
            {
                answer = count;
                continue;
            }
            
            answer *= count;
		}

		return answer - 1;
    }
}