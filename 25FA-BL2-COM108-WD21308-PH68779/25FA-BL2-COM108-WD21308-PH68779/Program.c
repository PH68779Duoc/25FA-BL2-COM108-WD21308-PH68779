#include <stdio.h>  
#include <string.h>



void thongTinThuCung()
{
    char tenThuCung[50];
    char maThuCung[50];
    int namSinh;
    printf("\n--- Thong Tin Thu Cung ---\n");
    printf("Nhap ma thu cung: ");
    scanf("%s", maThuCung);
    printf("Nhap ten thu cung: ");
    scanf("%s", tenThuCung);
    printf("Nhap nam sinh thu cung: ");
    scanf("%d", &namSinh);
    printf("\nThong tin thu cung:\n");
    printf("Ma: %s\n", maThuCung);
    printf("Ten: %s\n", tenThuCung);
    printf("Nam Sinh: %d\n", namSinh);
}

void tinhTong()
{
    
        int n, i, tong = 0;

        // Nhập n > 3
        printf("Nhap so nguyen duong n (n > 3): ");
        scanf("%d", &n);

        // Kiểm tra điều kiện
        if (n <= 3) {
            printf("Gia tri n phai lon hon 3.\n");
            return 0;
        }

        // Tính tổng các số lẻ từ 1 đến n
        for (i = 1; i <= n; i += 2) {
            tong += i;
        }
        printf("Tong cac so le tu 1 den %d la: %d\n", n, tong);

        // Kiểm tra n có chia hết cho 5 không
        if (n % 5 == 0) {
            printf("%d chia het cho 5.\n", n);
        }
        else {
            printf("%d khong chia het cho 5.\n", n);
        }

    
    
}

void thongTinCuaHang(){
    
        int n, i;
        float a[100];
        float tong = 0, trung_binh, thap_nhat;
        int dem_duoi_tb = 0;

        // ------------------------------------------
        // Yêu cầu nhập
        // ------------------------------------------
        printf("Nhap so luong thu cung: ");
        scanf("%d", &n);

        printf("Nhap mang can nang cua thu cung:\n");
        for (i = 0; i < n; i++) {
            printf("Can nang thu %d: ", i + 1);
            scanf("%f", &a[i]);
            tong += a[i];
        }

        // Tính cân nặng trung bình
        trung_binh = tong / n;

        // Tìm cân nặng thấp nhất
        thap_nhat = a[0];
        for (i = 1; i < n; i++) {
            if (a[i] < thap_nhat) {
                thap_nhat = a[i];
            }
        }

        // Đếm số thú có cân nặng dưới trung bình
        for (i = 0; i < n; i++) {
            if (a[i] < trung_binh) {
                dem_duoi_tb++;
            }
        }

        // ------------------------------------------
        // In ra kết quả
        // ------------------------------------------
        printf("\n------------------------------------------\n");
        printf("Can nang trung binh: %.2f\n", trung_binh);
        printf("Can nang thap nhat: %.2f\n", thap_nhat);
        printf("So thu cung nang duoi muc trung binh: %d\n", dem_duoi_tb);

        
    
}


int main()
{
    int chon;

    do
    {
        printf("\n================ MENU ================\n");
        printf("1. Thong tin thu cung\n");
        printf("2. Tinh tong\n");
        printf("3. Thong tin cua hang\n");
        printf("0. Thoat\n");
        printf("======================================\n");

        printf("Moi chon: ");
        scanf("%d", &chon);

        switch (chon)
        {
        case 1:
            thongTinThuCung();
            break;
        case 2:
            tinhTong();
            break;
        case 3:
            thongTinCuaHang();
            break;
        case 0:
            printf("\nDang thoat chuong trinh...\n");
            break;
        default:
            printf("\nLua chon khong hop le. Moi chon lai!\n");
        }

    } while (chon != 0);

}