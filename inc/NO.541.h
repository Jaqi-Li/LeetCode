/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 16:27
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_541_H
#define LEETCODE_NO_541_H

#include <string.h>
#define MIN(x,y)    ((x<y)?x:y)
/**
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 *      如果剩余字符少于 k 个，则将剩余字符全部反转。
 *      如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 */

char * reverseStr(char * str, int k);

#endif //LEETCODE_NO_541_H
