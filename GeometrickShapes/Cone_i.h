
template<class T>
inline double Cone<T>::GetRadius() const
{
	double sum = 0;
	for (int i = 0; i < this->GetDim(); i++)
		sum += pow((this->C[i] - this->GetA()[i]), 2);
	return sqrt(sum);
}

template<class T>
inline double Cone<T>::GetHeight() const
{
	double sum = 0;
	for (int i = 0; i < this->GetDim(); i++)
		sum += pow((this->C[i] - this->GetB()[i]), 2);
	return sqrt(sum);
}

template<class T>
inline double Cone<T>::GetVolume() const
{
	return (GetHeight() * GetArea()) / 3;
}

template<class T>
inline double Cone<T>::GetArea() const
{
	return pow(GetRadius(), 2) * M_PI;
}

template<class T>
inline ostream& Cone<T>::print(ostream& os)
{
	os << typeid(*this).name() << endl;
	os << "Dim: " << this->GetDim() << endl << "C(";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->GetC()[i] << ", ";
		else
			os << this->GetC()[i];
	}
	os << ")" << endl;

	os << "A(";
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
			os << this->B[i] << ", ";
		else
			os << this->B[i];
	}
	os << ")" << endl;

	os << "Radius: " << GetRadius() << endl;
	os << "Height: " << GetHeight() << endl;
	os << "Area: " << GetArea() << endl;
	os << "Volume: " << GetVolume() << endl;

	return os;
}
