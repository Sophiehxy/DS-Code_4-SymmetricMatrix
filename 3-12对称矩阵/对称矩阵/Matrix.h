#pragma once
//ѹ���洢
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
				if (i >= j)//�����ǲ���
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

	T& AccessNum(size_t i, size_t j)//����λ�ã�i,j���ϵ�����
	{
		assert (i < _n);
		assert (j < _n);
		if (i < j)//����������λ��
		{
			swap(i, j);//ת��Ϊ������
		}
		return _array[i*(i+1)/2+j];
	}

private:
	T* _array;
	size_t _n;
};