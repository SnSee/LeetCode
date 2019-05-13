/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/

// 利用栈
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    false, true
}bool;

bool isValid(char * s){
    int i = 0, j = 0;
    int len = strlen(s);
    char *container = (char *)malloc(len*sizeof(char));
    while(s[i] != '\0'){
        switch(s[i]){
            case '(':
            case '{':
            case '[':
                container[j++] = s[i];
                break;
            case ')':
                if(j > 0 && container[j-1] == '('){
                    --j;
                    break;
                }
                return false;
            case '}':
                if(j > 0 && container[j-1] == '{'){
                    --j;
                    break;
                }
                return false;
            case ']':
                if(j > 0 && container[j-1] == '['){
                    --j;
                    break;
                }
                return false;
            default:
                return false;
        }
        ++i;
    }
    if(j > 0){
        if(container[j-1] == '(' || container[j-1] == '{' || container[j-1] == '['){
            return false;
        }
    }
    return true;
}

int main(int argc, const char *argv[]){
    char str[] = "[()]";
    int ret = isValid(str);
    printf("ret = %d\n", ret);
    return 0;
}