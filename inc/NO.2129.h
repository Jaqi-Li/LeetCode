/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 22:50
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_2129_H
#define LEETCODE_NO_2129_H

#include <string.h>
#include <stdio.h>
#include <malloc.h>

#define SPACE 0x20


/**
 * 给你一个字符串 title ，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母大写
 * 如果单词的长度为 1 或者 2 ，所有字母变成小写。
 * 否则，将单词首字母大写，剩余字母变成小写。
 *
 * @param title
 * @return
 */
char * capitalizeTitle(char * title);

void toUpper(char * word, int start);

void toLower(char * word, int start, int end);


#endif //LEETCODE_NO_2129_H
