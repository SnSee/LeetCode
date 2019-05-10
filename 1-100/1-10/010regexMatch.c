/*
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*/
#include <stdio.h>

typedef enum{
    false, true
}bool;

bool match(char **sss, char **ppp){
    char *ss = *sss, *pp = *ppp;
    if(*ss == *pp || *pp == '.'){
        ++(*sss);
        ++(*ppp);
        return true;
    }
    if(*pp != '*'){
        return false;
    }

    // *pp == '*'
    char c = *ss;
    int c_count = 0;        // 统计ss字符串中连续的相同的字符个数
    int r_count = 0;        // 统计pp字符串中连续的相同的字符或.或*的个数
    int total_count = 0;
    char *ns = ss, *np = pp;
    while(c == *ss){
        ++c_count;
    }
    char *notc = ss + c_count;  // 第一个不是当前字符的字符位置
    while(*pp == c || *pp == '*' || *pp == '.'){
        ++total_count;
        if(*pp == c && *(pp+1) != '*'){
            ++r_count;
        }
        else if(*pp == '.' && *(pp+1) != '*' && *(pp+1)!=0 && *(pp+2)==c){
            ++r_count;
        }
        if(r_count > c_count){
            return false;
        }
        ++pp;
    }
    if(*notc == *(np + total_count)){
        *sss = notc;
        *ppp = np + total_count;
        return true;
    }
    else{
        if(*(np + total_count - 1) != '.' && *(np + total_count - 1) != '*'){
            return false;
        }
    }
    // 正则表达式指针跳到下一个另一个字符的位置
    while(r_count > 0){
        ++(*ppp);
        --r_count;
    }
    // 字符串指针跳到下一个另一个字符的位置
    while(c_count > 0){
        ++(*sss);
        --c_count;
    }
    return true;
}

bool isMatch(char* s, char* p) {
    // printf("str = [%s], reg = [%s]\n", s, p);
    char *sp, *sc = s, *pp;
    bool flag;
    while(*sc != '\0'){
        sp = sc;
        pp = p;
        flag = true;
        while(*pp != '\0'){
            if(*sp == '\0'){
                return false;
            }
            // printf("*sp = %c, *pp = %c\n", *sp, *pp);
            if(!match(&sp, &pp)){
                flag = false;
                break;
            }
        }
        if(*pp == '\0' && *sp != '\0')
            return false;
        if(flag)
            return true;
        ++sc;
    }
    return false;
}

int main(int argc, char *argv[]){

    char str[20] = "";
    char regex[20] = "";
    while(true){
        printf("input str: ");
        scanf("%s", str);
        printf("input reg: ");
        scanf("%s", regex);
        bool ret = isMatch(str, regex);
        printf("ret = %d\n", ret);
    }

    return 0;
}