#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <iostream>

using namespace std;

#if 0

template <class t="" t1="">
T sum_impl(I iter ,T1 n , T t)
{
    //通过模板的特性，可以获取I所指之物的型别,此处为int
    T sum = 0;
	//这里做func应该做的工作
	for(int i = 0 ; i < n ;i++)
	{
		sum+=*iter++;
	} 
	return sum;
}

template <class i="" t1="">
inline T1 sum(I iter , T1 n) 
{
	//此处暴露了template参数推导机制的缺陷，在型别用于返回值时便束手无策
	return sum_impl(iter , n ,*iter);
}
int main()
{
	int a[5] = {1,2,3,4,5};
	int sum1 = sum(a , 5);
	cout<<sum1<<endl; 
}
#endif

template <class T>
struct MyIter
{
	typedef T value_type;    // 内嵌型别声明
	T* ptr;
	MyIter(T* p =0):ptr(p){}
	T& operator*() const {return *ptr;}
};

template <class I>
typename I::value_type  func(I iter)
{   
	return *iter;
}


	




int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	MyIter<int> iter(new int(8));
	cout<<func(iter)<<endl;






	return a.exec();
}
