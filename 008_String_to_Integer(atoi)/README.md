
I think we only need to handle four cases:

 - discards all leading whitespaces
 - sign of the number
 - overflow
 - invalid input(out of the range of [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])

方案1：未思考完全就动手的后果，就是代码混乱(不需要调用substr()进行分割，利用下标遍历即可)

方案2：[morning_color](https://discuss.leetcode.com/topic/15891/8ms-c-solution-easy-to-understand)
 - find_first_not_of()
 - ? :
 - set ret to long type
 - str[i] >= '0' && str[i] <= '9'

方案3：[houzi](https://discuss.leetcode.com/topic/29207/8-line-c-concise-solution)
 - find_first_not_of()
 - ? :
 - set ret to int type, while [214748364][7] split into two parts
 - isdigit()
