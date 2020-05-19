template<class T>
inline Square<T>::Square()
{
	this->SetDim() = 0;
	this->SetA() = new T[0];
	this->SetB() = new T[0];
	this->SetC() = new T[0];
	D = new T[0];
}

template<class T>
inline Square<T>::Square(int n)
{
	this->SetDim() = n;
	this->SetA() = new T[n];
	this->SetB() = new T[n];
	this->SetC() = new T[n];
	D = new T[n];
	for (int i = 0; i < n; i++)
	{
		this->SetA()[i] = 0;
		this->SetB()[i] = 0;
		this->SetC()[i] = 0;
		D[i] = 0;
	}
}

template<class T>
inline Square<T>::Square(const Square& q)
{
	this->SetDim() = q.GetDim();
	this->SetA() = new T[q.GetDim()];
	this->SetB() = new T[q.GetDim()];
	this->SetC() = new T[q.GetDim()];
	D = new T[q.GetDim()];
	for (int i = 0; i < q.GetDim(); i++)
	{
		this->SetA()[i] = q.GetA()[i];
		this->SetB()[i] = q.GetA()[i];
		this->SetC()[i] = q.GetA()[i];
		D[i] = q.D[i];
	}
}

template<class T>
inline Square<T>::~Square()
{
	delete[] D;
}

template<class T>
inline T* Square<T>::GetD() const
{
	return D;
}

template<class T>
inline T*& Square<T>::SetD()
{
	return D;
}

template<class T>
inline double Square<T>::GetPerimeter() const
{
	double sum = 0, temp = 0;
	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetB()[i] - this->GetA()[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - this->GetB()[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - D[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - D[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	return sum;
}

template<class T>
inline double Square<T>::GetArea() const
{
	double p = GetPerimeter() * 0.5;
	double temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetB()[i] - this->GetA()[i]), 2);
	double a = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - this->GetB()[i]), 2);
	double b = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - D[i]), 2);
	double c = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - D[i]), 2);
	double d = sqrt(temp);
	temp = 0;

	return sqrt((p - a) * (p - b) * (p - c) * (p - d));
}


template<class T>
inline ostream& Square<T>::print(ostream& os)
{
	os << typeid(*this).name() << endl;
	os << "Dim: " << this->GetDim() << endl << "A(";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->GetA()[i] << ", ";
		else
			os << this->GetA()[i];
	}
	os << ")" << endl;

	os << "B(";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->GetB()[i] << ", ";
		else
			os << this->GetB()[i];
	}
	os << ")" << endl;

	os << "C(";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->C[i] << ", ";
		else
			os << this->C[i];
	}
	os << ")" << endl;

	os << "D(";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->D[i] << ", ";
		else
			os << this->D[i];
	}
	os << ")" << endl;

	os << "Perimeter: " << GetPerimeter() << endl;
	os << "Area: " << GetArea() << endl;

	return os;
}