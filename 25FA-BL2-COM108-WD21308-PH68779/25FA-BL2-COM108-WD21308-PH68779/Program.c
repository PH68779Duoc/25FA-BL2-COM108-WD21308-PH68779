// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
#include<conio.h>

void kiemTraSoNguyen()
{
    printf("Kiem tra so nguyen: \n");
}
void uocChungBoiChung()
{
    printf("Uoc chung boi chung: \n");
}
void lapChucNang(int chonChucNang)
{
    int tieptuc = 1;
    while (tieptuc == 1)
    {
        switch (chonChucNang)
        {
        case 1:
            kiemTraSoNguyen();
            break;
        case 2:
            kiemTraSoNguyen();
            break;
        case 3:
            kiemTraSoNguyen();
            break;
        case 4:
            kiemTraSoNguyen();
            break;
        case 5:
            kiemTraSoNguyen();
            break;
        case 6:
            kiemTraSoNguyen();
            break;
        case 8:
            //goi Ten chuc nang 2
            break;
        case 0:
            return;
        default:
            printf("Hay chon chuc nang tren MENU: [0-8]");
            return;
        }
        printf("\n");
        printf("Co tiep tuc chuc nang nay: [1-Co] [Khac-Khong]\n" );
        scanf("%d", &tieptuc);
    }
}
int main()
{
    int chonChucNang;
    do
    {
        printf("Menu\n");
        printf("1.Kiem Tra So Nguyen\n");
        printf("2.CN2\n");
        printf("3.CN3\n");
        printf("4.CN3\n");
        printf("5.CN3\n");
        printf("6.CN3\n");
        printf("7.CN3\n");
        printf("8.CN3\n");
        printf("0.Thoat\n");
        printf("Hay chon CN tu [0-10]\n");
        scanf("%d", &chonChucNang);
    } while (chonChucNang != 0);
}

void soPhanTu()
{
    int main();
    {
        // 1. Khai báo biến
        int N;

        // 2. INPUT nhập liệu
        printf("Moi nhap N: ");
        scanf("%d", &N);

        // 3. Khoi tao mang 1 chieu gom N phan tu
        int dsconso[20];

        // 4. Duyet vong lap tu 0->N. Moi nguoi dung nhap lieu
        for (int i = 0; i < N; i++) {
            printf("Moi nhap phan tu vi tri thu %d: ", i);
            scanf("%d", &dsconso[i]);
        }

        // 4. OUTPUT xuất ra màn hình
        printf("=== CHUONG TRINH TINH TRUNG BINH TONG CAC CON SO CHIA HET CHO 3 TRONG MANG ===\n");
        printf("Thong tin:\n");
        printf("- Mang vua nhap la\n");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", dsconso[i]);
        }

    }
}