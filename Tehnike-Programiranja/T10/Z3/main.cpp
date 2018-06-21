/* 
    TP 16/17 (Tutorijal 10, Zadatak 3)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>

class Vektor3d
{
	double koordinate[3];
	mutable int broj_ispisa = 0;
public:
	Vektor3d(){ koordinate[0] = koordinate[1] = koordinate[2] = 0; }
	Vektor3d(double x1, double y1, double z1){ koordinate[0] = x1; koordinate[1] = y1; koordinate[2] = z1; }
	void Postavi(double x, double y, double z) {
	 koordinate[0] = x; koordinate[1] = y; koordinate[2] = z;
	}
	Vektor3d(const Vektor3d &v1){ for(int i=0; i < 3; i++){ koordinate[i] = v1.koordinate[i]; } broj_ispisa = 0; }
	void PostaviX(double x){ koordinate[0] = x; }
	void PostaviY(double y){ koordinate[1] = y; }
	void PostaviZ(double z){ koordinate[2] = z; }
	void Ocitaj(double &x, double &y, double &z) const {
		x = DajX(); y = DajY(); z = DajZ();
	}
	void Ispisi() const {
		std::cout << "{" << DajX() << "," << DajY() << "," << DajZ() << "}";
		broj_ispisa++;
	}
	double DajX() const { return koordinate[0]; }
	double DajY() const { return koordinate[1]; }
	double DajZ() const { return koordinate[2]; }
	double DajDuzinu() const { return std::sqrt(koordinate[0]*koordinate[0] + koordinate[1]*koordinate[1]  + koordinate[2]*koordinate[2] ); }
	void  PomnoziSaSkalarom(double s) { koordinate[0] *= s; koordinate[1] *= s; koordinate[2] *= s; }
	void SaberiSa(const Vektor3d &v) { koordinate[0] += v.koordinate[0]; koordinate[1] += v.koordinate[1]; koordinate[2] += v.koordinate[2]; }
	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
	int DajBrojIspisa() const { return broj_ispisa; } 
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2){
	Vektor3d novi;
	novi.koordinate[0] = v1.koordinate[0] + v2.koordinate[0]; novi.koordinate[1] = v1.koordinate[1] + v2.koordinate[1]; novi.koordinate[2] = v1.koordinate[2] + v2.koordinate[2];
	return novi;
}

int main ()
{
	// testiranje svega
	std::cout << "Pravimo vektor v i stavljamo koordinate sve na 1337: " << std::endl;
	Vektor3d v;
	v.Postavi(1337, 1337, 1337);
	v.Ispisi();
	
	std::cout << std::endl << "Kreiramo ponovo novi vektor a i stavljamo koordinate na 123 posebno: " << std::endl;
	Vektor3d a;
	a.PostaviX(123);
	a.PostaviY(123);
	a.PostaviZ(123);
	a.Ispisi();
	
	std::cout << std::endl << "Saberimo ova 2 vektora i imamo: " << std::endl;
	v.SaberiSa(a);
	std::cout << "Koordinate v-a: " << std::endl;
	std::cout << "X: " << v.DajX() << " ";
	std::cout << "Y: " << v.DajY() << " ";
	std::cout << "Z: " << v.DajZ() << std::endl;
	std::cout << "Duzina: " << v.DajDuzinu() << std::endl;
	
	std::cout << "Mnozimo vektor a sa 123: " << std::endl;
	a.PomnoziSaSkalarom(123);
	a.Ispisi();
	
	std::cout << std::endl << "Saberimo ova dva vektora, pri tome kreiramo neki novi vektor h: " << std::endl;
	Vektor3d h;
	h = ZbirVektora(v, a);
	h.Ispisi();
	
	std::cout << std::endl << "Primjer iz postavke: " << std::endl;
	Vektor3d v1, v2;
	v1.Postavi(3, 4, 2); v2.Postavi(2, 0, 5);
	v1.Ispisi(); v1.Ispisi(); v1.Ispisi(); v2.Ispisi(); v2.Ispisi();
	std::cout << std::endl;
	std::cout << "Objekat v1 je ispisan " << v1.DajBrojIspisa() << " puta , a objekat v2 " << v2.DajBrojIspisa() << " puta." << std::endl;
	std::cout << std::endl;
	std::cout << "Testiramo konstruktore: ";
	Vektor3d v5(1337, 122, 422), v12, v3{-22,22,-120};
	v5.Ispisi(); std::cout<<" "; v1.Ispisi();
	std::cout<<" "; v2.Ispisi(); std::cout<<" ";
	v2.Ispisi(); std::cout<<" "; v3.Ispisi();
	std::cout<<" "; v3.Ispisi(); std::cout<<" ";
	v3.Ispisi(); std::cout << std::endl;
	
	std::cout << "Testiramo dajbrojispisa: ";
	for(int i=0;i<5;i++) {v1.Ispisi();std::cout<<" ";}
	std::cout<<std::endl;
	for(int i=0;i<2;i++) {v2.Ispisi();std::cout<<" ";}
	std::cout<<std::endl;
	for(int i=0;i<1;i++) {v3.Ispisi();std::cout<<" ";}
	std::cout<<std::endl;
	std::cout<<"Vektor v1 je ispisan "<<v1.DajBrojIspisa()<<", vektor v2 "<<v2.DajBrojIspisa()<<" i vektor v3 "<<v3.DajBrojIspisa()<<" puta." << std::endl;
	
	std::cout << "Testiramo naslijedivanje: ";
	for(int i=0;i<3;i++) {v1.Ispisi();std::cout<<" ";}
	std::cout<<std::endl;
	const Vektor3d v6(v5);
	v2.Ispisi(); std::cout << std::endl;
	std::cout << v6.DajBrojIspisa() << std::endl;
	const Vektor3d v9(v5);
	std::cout << v9.DajBrojIspisa() << std::endl;
	
	std::cout << "Testiramo velicinu klase privatnih: ";
	std::cout<<sizeof(Vektor3d)<<std::endl;
	return 0;
}