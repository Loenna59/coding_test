using System;
using System.Text;
using System.Linq;

public class Solution {
    public string solution(string s, int n) {
        
        StringBuilder builder = new StringBuilder();
        
        foreach (char c in s)
        {
            if (char.IsWhiteSpace(c))
            {
                builder.Append(c);
                continue;
            }
            
            char shiftCharacter = (char)(c + n);
            
            if (char.ToLower(c) + n > (int)'z')
            {
                builder.Append((char)(shiftCharacter - 26));
                continue;
            }
            
            builder.Append(shiftCharacter);
        }
        
        return builder.ToString();
        
        // return string.Concat(s.Select(c => char.IsWhiteSpace(c)? c : (char)(char.ToLower(c) + n > (int)'z' ? c + n - 26 : c + n)));
    }
}