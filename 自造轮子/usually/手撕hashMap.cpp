/*
一、手撕哈希表？
哈希表包括插入，删除，包含操作
以插入操作为例，其手撕的过程主要分为以下几步：
1.把插入的对象转为int类型，调用hashCode()函数就可以了；
2.转为合法的下标（哈希函数：hash(key)=key%capacity),如：int index=hashValue%array.length;
3.遍历index位置处的链表，确定key在不在元素中
4.把key装进结点中，并插入到对应的链表中
5.维护元素的个数
6…通过维护负载因子，进而维护较低的负载因子
*/


/*
key是int，value是string
把输入的key值经过hash函数计算，算出它要放入的桶的编号
采用一个指针数组记录各个桶
*/