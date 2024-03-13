#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ThueBao{
    char matb[20];
    char hoten[30];
    char ngaydangki[20];//ngay,thang,nam
    int sdt;
    char loaitb[10];//TT or TS
    int tgnoimang;
    int tgngoaimang;
};
//NHAP THUE BAO
void nhapTB(ThueBao &a)
{
    printf("Ma thue bao: ");  scanf("%s",a.matb); fflush(stdin);
    printf("Ho ten: ");  scanf("%s",a.hoten);
    printf("Ngay dang ki: "); scanf("%s",a.ngaydangki);
    printf("So dien thoai: "); scanf("%d",&a.sdt);
    printf("Loai thue bao (TT or TS): ");  scanf("%s",a.loaitb);
    printf("Thoi gian goi noi mang: "); scanf("%d",&a.tgnoimang);
    printf("Thoi gian goi ngoai mang: "); scanf("%d",&a.tgngoaimang);
}
//XUAT THUE BAO
void xuatTB(ThueBao a)
{
    printf("%s \t%s \t%s \t%d \t%s \t%d \t%d \n",a.matb,a.hoten,a.ngaydangki,a.sdt,a.loaitb,a.tgnoimang,a.tgngoaimang);
}
void danhsach(ThueBao a[],int n)
{
    for(int i=0;i<n;i++)
    {
        xuatTB(a[i]);
    }
}
//THEM THUE BAO
void themtb(struct ThueBao a[],int n) {
    printf("Them thue bao moi\n");
    nhapTB(a[n]);
}
//SAP XEP THUE BAO
void swap(ThueBao &x, ThueBao &y)
{
    ThueBao t;
    t = x;
    x = y;
    y = t;
}
void sapXepTang(ThueBao a[], int n)
{
    for(int i = 0; i<n-1; i++)
        for(int j = i+1;j<n; j++)
            if(a[j].matb > a[i].matb)
                swap(a[j], a[i]);
}
//TIM THUE BAO THEO HO TEN CHU THUE BAO
int timkiemTB(char ho_ten[], ThueBao a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if (strcmp(ho_ten,a[i].hoten)==0){
            printf("Ma thue bao: %s\n", a[i].matb);
            printf("Ho ten: %s\n",a[i].hoten);
            printf("Ngay dang ki: %d\n",a[i].ngaydangki);
            printf("So dien thoai: %d\n",a[i].sdt);
            printf("Loai thue bao: %s\n",a[i].loaitb);
            printf("Thoi gian goi noi mang %d phut\n",a[i].tgnoimang);
            printf("Thoi gian goi ngoai mang %d phut\n",a[i].tgngoaimang);
        }
        else
            return -1;//khong tim thay
    }
}
//XUAT CAC THUE BAO THEO LOAI
void xuatTBloai(char loai[],ThueBao a[],int n)
{
    printf("Cac thue bao loai %s:\n", loai);
    for(int i=0;i<n;i++)
    {
        if(strcmp(a[i].loaitb, loai)==0)
        {
            xuatTB(a[i]);
        }
    }

}
//XUAT THUE BAO DANG KI SAU NAM 2020
void xuatTBnam2020(ThueBao a[],int n)
{
    printf("Danh sach thue bao dang ki sau nam 2020:\n");
    for(int i=0;i<n;i++)
    {
        int year;
        scanf(a[i].ngaydangki,"%*d/%*d/%d",&year);
        if(year>2020){
            xuatTB(a[i]);
        }
    }
}
//TINH GOI CUOC
void tinhcuocphi(ThueBao &a)
{
    int noimang= a.tgnoimang *1500;
    int ngoaimang= a.tgngoaimang*3000;
    printf("Ma thue bao: %s\n",a.matb);
    printf("Ho ten: %s\n",a.hoten);
    printf("Cuoc goi noi mang: %d\n",noimang);
    printf("Cuoc goi ngoai mang: %d\n",ngoaimang);
}
//DEM SO LUONG THUE BAO TRA TRUOC
int soluong(ThueBao a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(a[i].loaitb, "TT")==0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    struct ThueBao a[50];
    int n;
    int chon;
    do{
        printf("\n--Quan li thue bao--\n");
        printf("1.Nhap thong tin cua cac thue bao.\n");
        printf("2.Xuat thong tin cua cac thue bao.\n");
        printf("3.Them mot thue bao vao danh sach.\n");
        printf("4.Sap xep danh sach cac thue bao theo ma thue bao.\n");
        printf("5.Tim thue bao theo ho ten chu thue bao.\n");
        printf("6.Xuat cac thue bao theo loai(loai nao la do nguoi dung chon).\n");
        printf("7.Xuat cac thue bao dang ki sau nam 2020.\n");
        printf("8.Tinh cuoc phi cua moi thue bao biet gia cuoc goi noi mang la 1500d, ngoai mang la 3000d.\n");
        printf("9.Dem so luong thue bao tra truoc.\n");
        printf("0.Thoat\n");
        printf("Chon chuc nang(0-9): ");
        scanf("%d",&chon);

        switch (chon) {
            case 1:
                printf("Nhap so luong thue bao(toi da 50):");
                scanf("%d",&n);
                printf("--Nhap thong tin thue bao--\n");
                for(int i=0;i<n;i++)
                {
                    nhapTB(a[i]);
                }
                break;
            case 2:
                printf("--Xuat thong tin thue bao--\n");
                for(int i=0;i<n;i++)
                {
                    xuatTB(a[i]);
                }
                break;
            case 3:
                themtb(a,n);
                break;
            case 4:
                printf("Sau khi sap xep theo ma thue bao: \n");
                sapXepTang(a,n);
                danhsach(a,n);
                break;
            case 5:
                char ho_ten[30];
                printf("Nhap ho ten muon tim kiem: "); scanf("%s",&ho_ten);

                timkiemTB(ho_ten,a,n);
                break;
            case 6:
                char loai[2];
                printf("\nNhap loai thue bao: "); scanf("%s", &loai);
                xuatTBloai(loai, a, n);
                break;
            case 7:
                printf("Xuat thue bao dang ki sau nam 2020\n");
                xuatTBnam2020(a,n);
                break;
            case 8:
                printf("Tinh cuoc phi moi thue bao\n");
                for(int i=0;i<n;i++)
                {
                    printf("Thue bao %d\n",i+1);
                    tinhcuocphi(a[i]);
                    printf("\n");
                }
                break;
            case 9:
                printf("So luong thue bao tra truoc: %d\n",soluong(a,n));
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Khong hop le. Vui long nhap lai.\n");
        }
    }while (chon != '0');
    return 0;
}