
__解题思路__：
 - 使用两个指针，其中一个指针normal从head开始，另一个指针advanced从第(n+1)个node开始。
 - 当advanced指向最后一个node时，normal指向倒数第(n+1)个node。
 - 删除倒数第n个node。

注意：移除的node为head的情况。
