#!/usr/bin/python
# -*- coding: UTF-8 -*-


class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        要点：max函数会找到字符串对象列表中最大的字符串，字符串的大小是由字符的ASCII码决定的
            如：a < b;    abcde < f;      abc < abcd
            min函数同理
            这样一来，得到最大和最小的字符串对象，他们之间共同的前缀必定为所有字符串对象的共同前缀
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)==0:
             return ""
        ans=""
        big=max(strs)
        small=min(strs)
        print(big)
        print(small)
        for i in range(min(len(small),len(big))):
            if small[i] != big[i]:
                break
            else:
                ans+=big[i]
        return ans


strs = ["flower","flo","flpt"]
print(Solution().longestCommonPrefix(strs))
