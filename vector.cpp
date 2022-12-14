#include <iostream>
#include <vector>
/**
 * vector:向量容器
 * 底层数据结构：
 * 	动态开辟的数组，每次以原来空间大小的两倍进行扩容
 *
 * vector<int> vec;
 * 常用方法:
 * 	增加
 * 		vec.push_back(30); // 末尾添加，O(1)  ---可能会导致容器扩容
 * 		vec.insert(it, 20); // 会返回一个迭代器，指向当前位置
 * 		vec.insert(vec.begin() + i, 20); // O(n)
 * 	删除
 * 		vec.pop_back(); // O(1)
 * 		vec.erase(it); // O(n)
 * 		vec.erase(vec.begin() + i);
 * 	查询
 * 		 operator[] // 随机访问 O(1)
 * 		 foreach() // 语法糖
 * 		 find, for_each()
 *
 *	注意：对容器进行进行连续的插入或者删除操作，一定要更新迭代器，否则会有迭代器失效的问题
 *
 * size()
 * empty()
 * reserve(20): vector预留空间  只给容器底层开辟指定大小的内存空间，并不会添加新的元素
 * resize(20); 容器扩容 不仅会给容器底层开辟指定大小的内存空间，还会添加新的元素
 * swap 容器进行元素交换
 */

int main(void)
{
	std::vector<int> vec;
	vec.reserve(200000);
	for (int i = 0; i < 200000; ++i)
	{ vec.push_back(rand() % 100 + 1); }

	/*for (int i = 0; i < vec.size(); ++i)
	{ std::cout << vec[i] << " "; }
	std::cout << std::endl;
	*/
	// delete all even numbers of the container
	for (auto it = vec.begin(); it != vec.end();)
	{
		if (*it % 2 == 0)
		{ it = vec.erase(it); }
		else
		{ it++; }
	}

	for (auto &i : vec)
	{ std::cout << i << " "; }
	std::cout << std::endl;


	return 0;
}
