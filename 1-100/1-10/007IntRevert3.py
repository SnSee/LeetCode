class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        flag = True
        if x == INT_MIN:
            return 0
        if x < 0:
            flag = False
            x = -x
        ret = 0
        units = 0
        while x != 0:
            units = x % 10
            x /= 10
            # if ret > INT_MAX/10 or (ret == INT_MAX/10 and units > 7):
            #     return 0
            ret = ret * 10 + units
        if not flag:
            ret = -ret
        if ret > INT_MAX or ret < INT_MIN:
            return 0
        return ret


print(Solution().reverse(-123))