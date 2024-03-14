#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct ThueBao {
    char maThueBao[10];
    char hoTen[30];
    struct Ngay ngayDangKy;
    char sdt[15];
    char loaiThueBao[15];
    int thoiGianGoiNoiMang;
    int thoiGianGoiNgoaiMang;
};

void nhap_1_ThueBao(struct ThueBao *t) {
    printf("Nhap ma thue bao: ");
    scanf("%s", t->maThueBao);
    printf("Nhap ho ten chu thue bao: ");
    scanf("%s", t->hoTen);
    printf("Nhap ngay dang ky (ngay thang nam): ");
    scanf("%d %d %d", &t->ngayDangKy.ngay, &t->ngayDangKy.thang, &t->ngayDangKy.nam);
    printf("Nhap so dien thoai: ");
    scanf("%s", t->sdt);
    printf("Nhap loai thue bao (TT hoac TS): ");
    scanf("%s", t->loaiThueBao);
    printf("Nhap thoi gian goi noi mang (phut): ");
    scanf("%d", &t->thoiGianGoiNoiMang);
    printf("Nhap thoi gian goi ngoai mang (phut): ");
    scanf("%d", &t->thoiGianGoiNgoaiMang);
}

void nhap_n_ThueBoa(struct ThueBao a[], int *n) {
    printf("Nhap so luong thue bao: ");
    scanf("%d", n);

    for (int i = 0; i < *n; ++i) {
        printf("Nhap thue bao thu %d:\n", i + 1);
        nhap_1_ThueBao(&a[i]);
    }
}

void xuat_1_ThueBao(struct ThueBao t) {
    printf("Ma thue bao: %s\n", t.maThueBao);
    printf("Ho ten chu thue bao: %s\n", t.hoTen);
    printf("Ngay dang ky: %d/%d/%d\n", t.ngayDangKy.ngay, t.ngayDangKy.thang, t.ngayDangKy.nam);
    printf("So dien thoai: %s\n", t.sdt);
    printf("Loai thue bao: %s\n", t.loaiThueBao);
    printf("Thoi gian goi noi mang: %d phut\n", t.thoiGianGoiNoiMang);
    printf("Thoi gian goi ngoai mang: %d phut\n", t.thoiGianGoiNgoaiMang);
}

void xuat_n_ThueBao(struct ThueBao a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Thong tin thue bao thu %d:\n", i + 1);
        xuat_1_ThueBao(a[i]);
        printf("\n");
    }
}

void them_ThueBao(struct ThueBao a[],int *n) {
    printf("Them thue bao moi\n");
        nhap_1_ThueBao(&a[*n]);
    
}

void swap(ThueBao &x,ThueBao &y)
{
	ThueBao a;
	a=x;
	x=y;
	y=a;
}
void sapxep_ThueBao(struct ThueBao a[],int *n)
{
	for(int i=0;i<*n-1;i++)
		for(int j=i+1;j<*n;j++)
			if(a[j].maThueBao>a[i].maThueBao)
				swap(a[i],a[j]);
			
}

int timkiem_ThueBao(struct ThueBao a[],int *n,char name[])
{
	for(int i=0;i<*n;i++)
	{
		if(strcmp(name,a[i].hoTen)==0){
			printf("Ma thue bao: %s\n", a[i].maThueBao);
    		printf("Ho ten chu thue bao: %s\n", a[i].hoTen);
    		printf("Ngay dang ky: %d/%d/%d\n", a[i].ngayDangKy.ngay, a[i].ngayDangKy.thang, a[i].ngayDangKy.nam);
    		printf("So dien thoai: %s\n", a[i].sdt);
    		printf("Loai thue bao: %s\n", a[i].loaiThueBao);
    		printf("Thoi gian goi noi mang: %d phut\n", a[i].thoiGianGoiNoiMang);
    		printf("Thoi gian goi ngoai mang: %d phut\n", a[i].thoiGianGoiNgoaiMang);
    		return 1;
		}
	}
}

void xuat_ThueBao_loai(struct ThueBao a[],int n,char loai[])
{
	
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i].loaiThueBao,loai)==0)
		{
			xuat_1_ThueBao(a[i]);
		}
	}
}

void xuat_ThueBao_2020(struct ThueBao a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i].ngayDangKy.nam>2020)
		{
			xuat_1_ThueBao(a[i]);
		}
	}
}

void cuocphi_ThueBao(struct ThueBao *t)
{
	int noi_mang= t->thoiGianGoiNoiMang*1500;
	int ngoai_mang= t->thoiGianGoiNgoaiMang*3000;
	printf("Ma thue bao: %s\n",t->maThueBao);
	printf("Ho ten: %s\n",t->hoTen);
	printf("Cuoc goi noi mang: %d\n",noi_mang);
	printf("Cuoc goi ngoai mang: %d\n",ngoai_mang);
}

int soluong_ThueBao(struct ThueBao a[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i].loaiThueBao,"TT")==0)
		{
			count++;
		}
	}
	return count;
}


int main() {
    struct ThueBao danhSach[MAX];
    int soLuong;
	char name[30];
	char loai[2];
    nhap_n_ThueBoa(danhSach, &soLuong);
    printf("\nDanh sach thue bao:\n");
    xuat_n_ThueBao(danhSach, soLuong);
	them_ThueBao(danhSach,&soLuong);
	printf("\nDanh sach thue bao sau khi sap xep:\n");
	sapxep_ThueBao(danhSach,&soLuong);
	xuat_n_ThueBao(danhSach, soLuong);
	printf("\nTen can tim la: \n");
	scanf("%s",name);
	timkiem_ThueBao(danhSach,&soLuong,name);
	printf("\nCac thue bao loai: \n");
	scanf("%s",loai);
	xuat_ThueBao_loai(danhSach,soLuong, loai);
	printf("\nThue bao dang ki sau nam 2020: \n");
	xuat_ThueBao_2020(danhSach,soLuong);
	printf("\nCuoc phi cua cac thue bao: \n");
	cuocphi_ThueBao(danhSach);
	printf("\nSo luong thue bao tra truoc:%d \n",soluong_ThueBao(danhSach,soLuong));
	
    return 0;
}