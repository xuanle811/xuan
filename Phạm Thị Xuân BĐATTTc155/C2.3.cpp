/*
Bai 3:
Xây dựng chương trình thao tác với phân số: nhập, in, tối giản, cộng, tích hai phân số
*/

/* Khai bao cau truc bieu dien thong tin cua mot phan so.
	Viet chuong trinh tinh nhap vao 2 phan so, tinh tong, hieu, tich,	
	thuong cua 2 phan so do!
*/

#include<iostream>
#include<math.h>
using namespace std;

typedef struct PHANSO
{
	int TS;
	int MS;
} Ps;

void NhapPS(Ps &x)
{
	cout<<"Nhap Tu so: "; cin>>x.TS;
	do
	{
		cout<<"Nhap Mau so: "; 
		cin>>x.MS;
		if(x.MS==0)
			cout<<"Nhap sai, yeu cau nhap lai mau so: ";
	}while(x.MS==0);
}

void XuatPS(Ps x)
{
	cout<<x.TS<<"/"<<x.MS;
}

Ps TongPS(Ps x1, Ps x2)
{
	Ps c;
	c.TS = x1.TS*x2.MS + x1.MS*x2.TS;
	c.MS = x1.MS*x2.MS;
	return c;
}

Ps HieuPS(Ps x1, Ps x2)
{
	Ps c;
	c.TS = x1.TS*x2.MS - x1.MS*x2.TS;
	c.MS = x1.MS*x2.MS;
	return c;
}

Ps TichPS(Ps x1, Ps x2)
{
	Ps c;
	c.TS = x1.TS * x2.TS;
	c.MS = x1.MS * x2.MS;
	return c;
}

Ps ThuongPS(Ps x1, Ps x2)
{
	Ps c;
	c.TS = x1.TS * x2.MS;
	c.MS = x1.MS * x2.TS;
	return c;
}
int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a * b != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}
 
Ps rutGon(Ps a)
{
    Ps c;
    c.TS = a.TS / UCLN(a.TS, a.MS);
    c.MS = a.MS / UCLN(a.TS, a.MS);
    return c;
}

int main() 
{ 
	Ps ps1, ps2;

	cout<<"Nhap phan so: ";

	NhapPS(ps1);
	NhapPS(ps2);
	
	cout<<"Phan so 1 la: "; XuatPS(ps1);
	cout<<"Sau khi rut gon ps1";
	rutGon(ps1);
	XuatPS(ps1);
	cout<<endl;
	cout<<"Sau khi rut gon ps2";
	XuatPS(rutGon(ps2));
	cout<<endl;
	
	cout<<"\nPhan so 2 la: "; XuatPS(ps2);

	cout<<"\nTong 2 phan so la: " ;
	 XuatPS(rutGon(TongPS(ps1, ps2)));
	cout<<endl;
	cout<<"\nHieu 2 phan so la: ";
	XuatPS(rutGon(HieuPS(ps1, ps2)));

	cout<<"\nTich 2 phan so la: ";
	 XuatPS(rutGon(TichPS(ps1, ps2)));
	cout<<endl;
	cout<<"\nThuong 2 phan so la: ";
	 XuatPS(rutGon(ThuongPS(ps1, ps2)));

	cout<<endl;
} 