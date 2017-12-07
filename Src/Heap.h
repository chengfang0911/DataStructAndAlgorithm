#pragma once    

template<class T>
class CHeap
{
public:
	CHeap():m_data(NULL), m_nSize(0), m_nPos(-1)
	{};
	~CHeap() 
	{
		if (m_data)
		{
			delete[]m_data;
		}
	}
	void Init(int nSize = 32)
	{
		m_data = new T[nSize + 1];
		if (m_data)
		{
			m_nSize = nSize;
			m_nPos = 0;
			memset(m_data, 0, sizeof(T) * nSize);
			m_data[0] = 0;
		}
	}

	bool Insert(T val)
	{
		if (!m_data)
			Init();
		//m_data[m_nPos] = val;
		int i;
		for (i = ++m_nPos; m_data[i / 2] > val; i /= 2)
			m_data[i] = m_data[i / 2];
		m_data[i] = val;

		return true;
	}
	T Get()
	{
		T data;
		return data;
	}
	T Delete()
	{
		T data = m_data[1];
		int i = 1;
		for (;m_data[])
		{
		}
		return data;
	}

private:
	int m_nSize;
	int m_nPos;
	T* m_data;
};