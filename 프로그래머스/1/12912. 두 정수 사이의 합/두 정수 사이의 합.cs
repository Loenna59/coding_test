using System;

public class Solution {
    public long solution(int a, int b) {
//         long answer = 0;
        
//         for (int num = Math.Min(a, b), end = Math.Max(a, b) + 1; num < end; num++)
//         {
//             answer += num;
//         }
        
//         return answer;
        
        // 아 등차수열 합... => (count * (first + last)) / 2
        
        return ((long)(Math.Abs(a - b) + 1) * (a + b)) / 2;
        
    }
}