#include<iostream>
#include<cstring>
using namespace std;
class MonHoc{
	private:
		int mamh;
		string tenmh;
		float diemtb;
		int sotc;
	public:
		MonHoc(){
		}
		~MonHoc(){
		}
		int tinchi(){
			return sotc;
		}
		float DTB(){
			return diemtb;
		}
		void nhap();
		void xuat();
};
void MonHoc::nhap(){
	cout<<"NHAP MA MON HOC : "<<endl;
	cin >>this->mamh;
	cout<<"NHAP TEN MON HOC : "<<endl;
	cin.ignore();
	getline(cin, this->tenmh);
	cout<<"NHAP DIEM TRUNG BINH : "<<endl;
	cin>>this->diemtb;
	cout<<"NHAP SO TIN CHI : "<<endl;
	cin>>this->sotc;
}
void MonHoc::xuat(){
	cout<<"MA MON HOC : "<<this->mamh<<endl;
	cout<<"TEN MON HOC : "<<this->tenmh<<endl;
	cout<<"DIEM TRUNG BINH : "<<this->diemtb<<" DIEM"<<endl;
	cout<<"SO TIN CHI : "<<this->sotc<<" TIN"<<endl;
}
class SinhVien{
	private:
		string masv;
		string tensv;
		int somh;
		MonHoc *mh;
	public:
		SinhVien(){
		}
		~SinhVien(){
			delete []mh;
		}
		void nhap1();
		void xuat1();
		float DTK();
		friend void lietkesv(SinhVien *sv, int n);
};
void SinhVien::nhap1(){
	cout<<"NHAP MA SINH VIEN : "<<endl;
	cin.ignore();
	getline(cin, this->masv);
	cout<<"NHAP TEN SINH VIEN : "<<endl;
	cin.ignore();
	getline(cin, this->tensv);
	cout<<"NHAP SO LUONG MON HOC : "<<endl;
	cin>>this->somh;
	mh = new MonHoc[somh];
	cout<<"NHAP MON HOC : "<<endl;
	for(int i=0;i<somh;i++){
		cout<<"Nhap mon hoc "<<i+1<<":"<<endl;
		mh[i].nhap();
	}
}
void SinhVien::xuat1(){
	cout<<"******************************"<<endl;
	cout<<"MA SINH VIEN : "<<this->masv<<endl;
	cout<<"TEN SINH VIEN : "<<this->tensv<<endl;
	cout<<"SO LUONG MON HOC : "<<this->somh<<endl;
	cout<<"MON H0C LAN LUOT LA : "<<endl;
	for(int i=0;i<somh;i++){
		cout<<"******************************"<<endl;
		cout<<"MON HOC SO "<<i+1<<":"<<endl;
		mh[i].xuat();
	}
	cout<<"DIEM TONG KET : "<<DTK()<<endl;
}
float SinhVien::DTK(){
	float tongd = 0;
	float tongtc = 0;
	for(int i=0;i<somh;i++){
		tongd += mh[i].DTB()*mh[i].tinchi();
	}
	for(int i=0;i<somh;i++){
		tongtc += mh[i].tinchi();
	}
	return (float)(tongd/tongtc);
}
void lietkesv(SinhVien *sv, int n){
	for(int i=0;i<n;i++){
		if(sv[i].DTK()>=8.0){
			sv[i].xuat1();
		}
	}
}
int main(){
	SinhVien *sv;
	int n;
	cout<<"Nhap so luong sinh vien : "<<endl;
	cin>>n;
	sv = new SinhVien[n];
	cout<<"NHAP MANG SINH VIEN : "<<endl;
	for(int i=0;i<n;i++){
		cout<<"******************************"<<endl;
		cout<<"NHAP SINH VIEN SO "<<i+1<<endl;
		sv[i].nhap1();
	}
	cout<<"MANG SINH VIEN lAN LUOT LA : "<<endl;
	for(int i=0;i<n;i++){
		cout<<"******************************"<<endl;
		cout<<"SINH VIEN SO "<<i+1<<endl;
		sv[i].xuat1();
	}
	cout<<"*********************************"<<endl;
	cout<<"SINH VIEN DUOC HOC BONG LA : "<<endl;
	lietkesv(sv,n);
	system("pause");
	return 0;
}
