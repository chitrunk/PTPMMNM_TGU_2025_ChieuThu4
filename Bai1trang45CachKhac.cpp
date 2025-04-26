#include <iostream>
using namespace std;

struct thisinh
{
	char sbd[20];
	char hoten[40];
	int manganh; //Ma nganh la 1 hoac 2 hoac 3 tuong ung voi toan,ly,hoa. Xet nhan he so.
	int khuvuc; //Khu vuc la 1 hoac 2 hoac 3. Xet diem chuan.
	int doituong; //Doi tuong la 1 hoac 2 hoac 3. Xet diem chuan.
	float toan,ly,hoa; // Diem >=0 va <=10.
	float tongdiem;
	int ketqua; //Ket qua la 1 neu dau, 0 neu rot.
};

void Nhap1ThiSinh(thisinh &x);
void Xuat1ThiSinh(thisinh x);
//Cau a:
void NhapnThiSinh(thisinh x[],int &n);
//Cau d:
void XuatnThiSinh(thisinh x[],int n);
//Cau b:
void TinhTongDiem(thisinh x[],int n);
//Cau c:
void XetKetQua(thisinh x[],int n);
//Cau e:
void XuatThuKhoa(thisinh x[],int n);
//Cau f:
int main()
{
	thisinh x[50];
	int n;
	NhapnThiSinh(x,n);
	TinhTongDiem(x,n);
	XetKetQua(x,n);
	XuatnThiSinh(x,n);
	return 1;
}

void Nhap1ThiSinh(thisinh &x)
{
	cin.ignore(1);
	cout << "Nhap so bao danh: "; cin >> x.sbd;
	cout << "Nhap ho va ten: "; cin >> x.hoten;
	do
	{cout << "Nhap ma nganh 1-Toan, 2-Ly, 3-Hoa: "; cin >> x.manganh;} 
	while(!(x.manganh==1||x.manganh==2||x.manganh==3));
	do
	{cout << "Nhap khu vuc 1-KV1, 2-KV2, 3-KV3: "; cin >> x.khuvuc;}
	while(!(x.khuvuc==1||x.khuvuc==2||x.khuvuc==3));
	do
	{cout << "Nhap doi tuong 1-Nhom 1, 2-Nhom 2, 3-Nhom 3: "; cin >> x.doituong;}
	while(!(x.doituong==1||x.doituong==2||x.doituong==3));
	do {cout << "Nhap diem Toan: "; cin >> x.toan;} while (!(x.toan>=0&&x.toan<=10));
	do {cout << "Nhap diem Ly: "; cin >> x.ly;} while (!(x.ly>=0&&x.ly<=10));
	do {cout << "Nhap diem Hoa: "; cin >> x.hoa;} while (!(x.hoa>=0&&x.hoa<=10));
}
void Xuat1ThiSinh(thisinh x)
{
	cout << "So bao danh: " << x.sbd;
	cout << "\nHo va ten: " << x.hoten;
	cout << "\nMa nganh: " << x.manganh;
	cout << "\nKhu vuc: " << x.khuvuc;
	cout << "\nDoi tuong: " << x.doituong;
	cout << "\nDiem toan,ly,hoa: " << x.toan << "," << x.ly << "," << x.hoa;
	cout << "\nTong diem: " << x.tongdiem;
	if(x.ketqua==1) cout << "\nDau\n";
	if(x.ketqua==0) cout << "\nRot\n";
} 
void NhapnThiSinh(thisinh x[],int &n)
{
	do
	{cout << "Nhap so luong thi sinh: "; cin >> n;}
	while(!(n>0&&n<=50));
	for(int i=0;i<n;i++)
		Nhap1ThiSinh(x[i]);
}
void XuatnThiSinh(thisinh x[],int n)
{
	for(int i=0;i<n;i++)
		Xuat1ThiSinh(x[i]);
}
void TinhTongDiem(thisinh x[],int n)
{
	for(int i=0;i<n;i++)
	{	
		if(x[i].manganh==1) x[i].tongdiem=x[i].toan*2+x[i].ly+x[i].hoa;
		if(x[i].manganh==2) x[i].tongdiem=x[i].toan+x[i].ly*2+x[i].hoa;
		if(x[i].manganh==3) x[i].tongdiem=x[i].toan+x[i].ly+x[i].hoa*2;
	}
}
void XetKetQua(thisinh x[],int n)
{
	float diemchuan[3][3]={ {22.0,23.0,24.0},
				{22.5,23.5,24.5},
				{23.0,24.0,25.0} };
	for(int i=0;i<n;i++)
	{
		x[i].ketqua=x[i].tongdiem>=diemchuan[x[i].doituong-1][x[i].khuvuc-1];
	}
}

