# for( : )

for( 元素 : 容器）对容器用元素进行遍历 支持 auto

如果要修改容器中的元素，将变量声明为 引用& 即可

 

可以遍历的对象包括：

- 数组。（不包括指针）
- 定义了begin()和end()方法，且返回该方法返回迭代器的类对象。（STL     中所有容器都可以）

可以进行删除操作，不影响遍历

```C++
for(auto &it : map_m)
	cout<<it.first<<' ';

for(int &x : vector_v)

for(char &c : string_s)
```

$\\$

## 自定义可遍历容器：

参考：http://www.cnblogs.com/h46incon/archive/2013/06/02/3113737.html

![clip_image001](for(  ：).assets/clip_image001.png)