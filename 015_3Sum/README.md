
方案一：

1. 把数据分成两部分，小于等于0的和大于0的，分别存在vector和set中。

2. 对vector数据进行排序。

3. 轮询第一部分，选取两个元素，并在第二部分寻找第三个元素。去重

4. 轮询第二部分，选取两个元素，并在第一部分寻找第三个元素。去重

5. 处理多个元素等于0的情况，因为所有等于0的元素都被分到了第一部分。

 空间上，需要两个数组以及两个hash表。时间上O($n^{2}$)，在hash值获取为常数时间下。

========
方案二：类似[Two Sum](../001_Two_Sum/two-sum.cc)的思路，两个指针。
 详见[Disscuss](https://discuss.leetcode.com/topic/8107/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments/2)




