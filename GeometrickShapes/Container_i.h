Container::Container()
{
	size = 0;
	Array = 0;
}

Container::Container(const Container& c)
{
	size = c.size;
	Array = c.Array;
}

Container::~Container()
{
	delete[] Array;

}

Base* Container::operator[](const int i)
{
	return Array[i];
}

template<class A>
void Container::Add(A& elem)
{
	Base** tmp = new Base * [size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = Array[i];
	}
	delete[]Array;
	size++;
	Array = new Base * [size];
	for (int i = 0; i < size - 1; i++)
	{
		Array[i] = tmp[i];
	}
	Array[size - 1] = &elem;
	delete[]tmp;
}

void Container::Remove(int r)
{
	Base** tmp = new Base * [size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == r)
		{
			k = 1;
		}
		else
		{
			tmp[j] = Array[i];
			j++;
		}
	}
	if (k == 0)
		throw - 1;
	delete[] Array;
	Array = new Base * [size - 1];
	size = size - 1;
	for (int i = 0; i < size; i++)
		Array[i] = tmp[i];
	delete[] tmp;
}

void Container::ShowAll()
{
	cout << "Moi kontainer: " << endl;
	for (int i = 0; i < size; i++)
		cout << i << ") " << typeid(*Array[i]).name() << endl;
}

inline void Container::Show(int i)
{
	cout << "Object nomer " << i << ":" << endl << *Array[i] << endl;
}
