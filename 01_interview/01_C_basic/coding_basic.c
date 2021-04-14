/*编程基本功*/

#include <stdio.h>
#include <stdlib.h>

// 1.字符类型统计器
// 【题目要求】请编写一个C程序，在终端用键盘输入字符串，以 Ctrl +
// Z组合键表示输入完毕，统计输入的字符串中空格符、制表符、换行符的个数，并显示统计的结果。
void demo01_calc_special_char() {
  int space, table, enter = 0;
  char c;
  printf("Please input a string:\n");
  scanf("%c", &c);
  while (c != EOF) {
    switch (c) {
      case 32:
        space++;
        break;
      case 9:
        table++;
        break;
      case 10:
        enter++;
        break;
      default:
        break;
    }
    scanf("%c", &c);
  }
  printf("The number of space:%d\n", space);
  printf("The number of table:%d\n", table);
  printf("The number of enter:%d\n", table);
  getchar();
  return;
}

// 2.计算字符的ASCII码
// 【题目要求】编写一个程序，在终端输入一个字符，输出它的 ASCII码。
void demo02_calc_character_ascii() {
  char c;
  printf("Please input a character:\n");
  scanf("%c", &c);
  getchar();
  printf("The ascii of the character is %d\n", c);
}

void main(int argc, char* argv[]) {
  //   demo01_calc_special_char();
  demo02_calc_character_ascii();
  return;
}