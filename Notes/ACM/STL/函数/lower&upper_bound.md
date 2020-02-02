# lower/upper_bound

$lower\_bound     (begin,end,值)$

- 返回一个 iterator 它指向在[first,last)标记的**有序序列**中可以插入value，而不会破坏容器顺序的第一个位置，而这个位置标记了一个**不小于**value 的值

$upper\_bound     (begin,end,值)$

- upper_bound()返回一个 iterator 它指向在[first,last)标记的**有序序列**中可以插入value，而不会破坏容器顺序的最后一个位置，而这个位置标记了一个**大于**value 的值

查到到的地址 $p$满足$p - begin = p位置元素的下标 = (begin->p的元素个数)-1$

``` 
假设a子序列是值全为a的序列

lower_bound(a)，返回的是a子序列的begin位置
	↓
 .. a a a a a b .. 
			  ↑
			upper_bound(a),返回的是a子序列的end位置
			
lower_bound(a)，如果a子序列为空则返回end位置
	↓
 .. b b b ...
 	↑
 upper_bound(a),此时返回值相同
```

