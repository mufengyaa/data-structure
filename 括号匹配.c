#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
//bool isValid(char* s) {  //经典的栈题目,左括号入栈,右括号则与栈顶匹配,且出栈 //若最后栈顶==0,则完成全部的匹配
//    stacknode a;
//    init(&a);
//    char* t = s;
//    while (*t != '\0') {
//        if (*t == '(' || *t == '{' || *t == '[') {  
//            push(&a, *t); 
//        }
//        else {
//            if (a.top > 0) {
//                if ((printtop(&a) == '(' && *t == ')') || (printtop(&a) == '[' && *t == ']') ||
//                    (printtop(&a) == '{' && *t == '}')) {
//                    pop(&a);
//                }
//                else {  //栈顶有元素,但匹配不上,直接返回
//                    return false;
//                }
//            }
//            else {  //空栈且不为左括号,直接返回
//                return false;
//            }
//        }
//        t++;
//    }
//    if (a.top == 0) {   
//        return true;
//    }
//    destroy(&a);
//    return false;
//}

//char* GetMemory()
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test()
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
int main() {
	//Test();
	printf("%d\n", 0 % 4);
	return 0;
}