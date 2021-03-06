template<class T>
inline double Sphere<T>::GetVolume() const
{
	return (4.0 / 3) * pow(this->GetRadius(), 3) * M_PI;
}


template<class T>
inline ostream& Sphere<T>::print(ostream& os)
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

	os << "Radius: " << this->GetRadius() << endl;
	os << "Volume: " << GetVolume() << endl;

	return os;
}