#include <iostream>
#include <string>
#include <vector>

std::vector<int> compute_lps(const std::string& p)
{
    int size = p.size();
    std::vector<int> lps(size, 0);

    int prefix_len = 0;
    int i = 1;

    while (i < size)
    {
        if (p[i] == p[prefix_len])
        {
            prefix_len++;
            lps[i] = prefix_len;
            i++;

            continue;
        }

        if (prefix_len == 0)
        {
            lps[i] = 0;
            i++;
            continue;
        }

        prefix_len = lps[prefix_len - 1];
    }

    return lps;
    
}

// KMP
int kmp_search(const std::string& s, const std::string& p)
{
    int result = 0;
    
    int s_size = s.size();
    int p_size = p.size();

    if (s_size < p_size)
    {
        return result;
    }

   std::vector<int> lps = compute_lps(p);

   int i = 0;
   int j = 0;

   while (i < s_size)
   {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }

        if (j == p_size)
        {
            result++;
            j = lps[j - 1];
            continue;
        }

        if (i < s_size && s[i] != p[j])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
   }
   
   return result;

}

int main()
{
    int n;
    int m;

    std::string s;

    std::cin >> n >> m >> s;

    std::string p = "I";

    p.reserve(2 * n + 1);  // 미리 메모리 확보 (최적화)

    for (int i = 0; i < n; i++) 
    {
        p += "OI";
    }

    std::cout << kmp_search(s, p);

    return 0;
}