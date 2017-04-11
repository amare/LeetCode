
    Author:            cuckoo
    Date:              2017/04/11 19:44:37
    Update:            
    Problem:           Counting Bits
    Difficulty:        Medium
    Source:            https://leetcode.com/problems/counting-bits/#/description

#### Solution Step
 - 把一个整数减去1之后再和原来的整数做位与运算，得到的结果相当于是把原来的整数的二进制表示
 中的最右边一个1变成0 (剑指Offer, P82)

#### Discuss
 - [other](https://discuss.leetcode.com/topic/40162/three-line-java-solution)
 - [thinking on interview](https://discuss.leetcode.com/topic/40195/how-we-handle-this-question-on-interview-thinking-process-dp-solution)
```
    public int[] countBits(int num) {
    int result[] = new int[num + 1];
    int offset = 1;
    for (int index = 1; index < num + 1; ++index){
        if (offset * 2 == index){
            offset *= 2;
        }
        result[index] = result[index - offset] + 1;
    }
    return result;
}
```

