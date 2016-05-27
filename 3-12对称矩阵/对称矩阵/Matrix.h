#pragma once
//压缩存储
#include<assert.h>
template <class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(T* a, size_t n)
		:_array(new T[n*(n + 1) / 2])
		, _n(n)
	{
		size_t index = 0;
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (i >= j)
				{
					_array[index++] = a[i*n + j];
				}
				else
				{
					break;
				}
			}
		}
	}

	~SymmetricMatrix()
	{
		if (_array)
		{
			delete[] _array;
		}
	}
public:
	void Display()
	{
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (i >= j)//下三角部分
				{
					cout << _array[i*(i + 1)/2 + j] << " ";
				}
				else
				{
					cout << _array[j*(j + 1)/2 + i] << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	T& AccessNum(size_t i, size_t j)//访问位置（i,j）上的数据
	{
		assert (i < _n);
		assert (j < _n);
		if (i < j)//处于上三角位置
		{
			swap(i, j);//转换为下三角
		}
		return _array[i*(i+1)/2+j];
	}

private:
	T* _array;
	size_t _n;
};