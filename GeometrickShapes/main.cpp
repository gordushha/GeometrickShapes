#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"
#include "Sphere.h"
#include "Cone.h"
#include "Container.h"

using namespace std;

int main()
{
	Point<int> Tochka(2);
	Tochka.SetA()[0] = 1;
	Tochka.SetA()[1] = 2;
	cout << Tochka << endl;
	Point<int> Tochka2(Tochka);

	Line<int> Lin(2);
	Lin.SetA()[0] = 0;
	Lin.SetA()[1] = 0;
	Lin.SetB()[0] = 3;
	Lin.SetB()[1] = -4;
	cout << Lin << endl;
	Line<int> Lin2(Lin);

	Circle<int> Krug(2);
	Krug.SetA()[0] = 0;
	Krug.SetA()[1] = 0;
	Krug.SetB()[0] = 3;
	Krug.SetB()[1] = -4;
	cout << Krug << endl;

	Triangle<int> Tri(2);
	Tri.SetA()[0] = 0;
	Tri.SetA()[1] = 0;
	Tri.SetB()[0] = 0;
	Tri.SetB()[1] = 2;
	Tri.SetC()[0] = 3;
	Tri.SetC()[1] = 0;
	cout << Tri << endl;

  Square<int> Kvad(2);
	Kvad.SetA()[0] = 0;
	Kvad.SetA()[1] = 0;
	Kvad.SetB()[0] = 0;
	Kvad.SetB()[1] = 2;
	Kvad.SetC()[0] = 2;
	Kvad.SetC()[1] = 2;
	Kvad.SetD()[0] = 2;
	Kvad.SetD()[1] = 0;
	cout << Kvad << endl;
	Square<int> Sk(Kvad);

	Container Cont;
	Cont.Add(Tochka);
	Cont.Add(Kvad);
	Cont.Add(Tri);

	Cont.ShowAll();
	cout << endl;
	Cont.Show(0);

	Cont.Remove(1);
	Cont.ShowAll();
	cout << endl;

	Sphere<int> Sph(3);
	Sph.SetA()[0] = 0;
	Sph.SetA()[1] = 0;
	Sph.SetA()[2] = 0;
	Sph.SetB()[0] = 5;
	Sph.SetB()[1] = 5;
	Sph.SetB()[2] = 0;
	cout << Sph << endl;

	Cone<int> Konus(3);
	Konus.SetA()[0] = 2;
	Konus.SetA()[1] = 2;
	Konus.SetA()[2] = 0;
	Konus.SetB()[0] = 0;
	Konus.SetB()[1] = 0;
	Konus.SetB()[2] = 5;
	Konus.SetC()[0] = 0;
	Konus.SetC()[1] = 0;
	Konus.SetC()[2] = 0;
	cout << Konus << endl;

	return 0;
}