#include<bits/stdc++.h>
using namespace std;
class phieu;
class sv{
	private:
		string msv, ten, lop;
		int khoa;
	public:
		void nhap(){
			cout<<"nhap ma msv: ";fflush(stdin);getline(cin, msv);
			cout<<"nhap ten sv: ";getline(cin, ten);
			cout<<"nhap lop sv: ";getline(cin, lop);
			cout<<"nhap khoa sinh vien: ";cin>>khoa;
		}
		void xuat(){
			cout<<setw(15)<<"MSV: "<<msv<<setw(15)<<"Ten sinh vien: "<<ten<<endl;
			cout<<setw(15)<<"Lop: "<<lop<<setw(15)<<"Khoa: "<<khoa<<endl;
		}
};
class monhoc{
	private:
		string mon;
		long sotrinh;
		int diem;
	public:
		void nhap(){
			cout<<"nhap ten mon: ";fflush(stdin);getline(cin, mon);
			cout<<"nhap so trinh: ";cin>>sotrinh;
			cout<<"nhap diem: ";cin>>diem;
		}
		int tongsotrinh(){
			return sotrinh;
		}
		int tichstvadiem(){
			return sotrinh*diem;
		}
		void xuat(){
			//cout<<setw(15)<<"Ten hang"<<setw(15)<<"Don gia"<<setw(15)<<"So luong"<<setw(15)<<"Thanh tien";
			cout<<setw(15)<<mon<<setw(15)<<sotrinh<<setw(15)<<diem<<endl;
		}
		friend void inten(phieu a);
		friend void chen(phieu &a);
		friend void suaphieu(phieu &a);
		friend void sapxep(phieu a);
};
class phieu{
	private:
		//string map, ngaylap;
		sv x;
		monhoc *y;
		int n;
	public:
		void nhap(){
			//cout<<"nhap ma phieu: ";fflush(stdin);getline(cin, map);
			//<<"nhap ngay lap phieu: ";getline(cin, ngaylap);
			x.nhap();
			cout<<"nhap so luong mon hoc: ";
			cin>>n;
			while(n<3){
				cout<<"mon qua it! vui long nhap lai: ";
				cin>>n;
			}
			y=new monhoc[n];
			for(int i=0;i<n;i++){
				cout<<"nhap thong tin mon hoc thu "<<i+1<<endl;
				y[i].nhap();
			}
		}
		void xuat(){
		//	cout<<setw(15)<<"Ma phieu: "<<map<<setw(15)<<"Ngay lap: "<<ngaylap<<endl;
			x.xuat();
			cout<<setw(15)<<"STT"<<setw(15)<<"Ten mon"<<setw(15)<<"So trinh"<<setw(15)<<"Diem"<<endl;
			float tong0=0;
			float tong=0;
			for(int i=0; i<n; i++){
				cout<<setw(15)<<i+1;
				y[i].xuat();
				tong0+=y[i].tongsotrinh();
				tong+=y[i].tichstvadiem();
			}
			cout<<setw(45)<<"Diem trung binh:"<<setw(15)<<right<<tong/tong0<<endl;
		}
		friend void inten(phieu a);
		friend void chen(phieu &a);
		friend void suaphieu(phieu &a);
		friend void sapxep(phieu a);
};
void inten(phieu a){
	for(int i=0;i<a.n;i++){
		if(a.y[i].sotrinh>3){
			cout<<setw(15)<<a.y[i].mon<<setw(15)<<a.y[i].sotrinh<<setw(15)<<a.y[i].diem<<endl;
		}
	}
}
void chen(phieu &a){
	int k;
	cout<<"nhap vao vi tri can chen: ";
	cin>>k;
	while(k<0 or k>a.n){
		cout<<"Vi tri chen khong hop le! Vui long nhap lai: ";
		cin>>k;
	}
	monhoc x;
	x.nhap();
	for(int i=a.n-1; i>=k; i--){
		a.y[i]=a.y[i-1];
	}
	a.y[k]=x;
	a.n++;
}
void suaphieu(phieu &a){
	bool co=false;
	for(int i=0; i<a.n ;i++){
		if(a.y[i].mon=="co so du lieu"){
			a.y[i].diem=10;
			co=true;
		}
	}
	if(co)
		a.xuat();
	else
		cout<<"khong co mon nao theo yeu cau"<<endl;
}
void sapxep(phieu a){
	for(int i=0;i<a.n;i++){
		for(int j=i+1;j<a.n;j++){
			if(a.y[i].diem>a.y[j].diem)
				swap(a.y[i],a.y[j]);
		}
	}
}
int main(){
	cout<<"Nhap tong tin phieu"<<endl;
	phieu x;
	x.nhap();
	cout<<"                 Phieu nhap hang"<<endl;
	x.xuat();
	cout<<"                 Thong tin mon hoc co so trinh lon hon 3"<<endl;
	inten(x);
//	cout<<"                 Phieu nhap hang sau khi chen"<<endl;
//	chen(x);
//	x.xuat();
	cout<<"sau khi sua:"<<endl;
	suaphieu(x);
	sapxep(x);
	x.xuat();
	return 0;
}