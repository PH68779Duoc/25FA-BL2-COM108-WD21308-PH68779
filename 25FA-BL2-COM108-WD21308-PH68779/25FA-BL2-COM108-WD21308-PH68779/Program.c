#include <stdio.h>
#include <math.h>

// ----------------- HÀM UCLN + BCNN ------------------
int UCLN(int a, int b)
{
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}

// ----------------- MAIN MENU ------------------
int main() {
    int choice;

    do {
        printf("\n========== MENU CHUONG TRINH ==========\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Uoc so chung - Boi so chung\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT (chon 2/15)\n");
        printf("10. Tinh toan phan so\n");
        printf("11. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);

        switch (choice) {

            // 1. Kiểm tra số nguyên
        case 1: {
            float x;
            printf("Nhap 1 so: ");
            scanf("%f", &x);
            if (x == (int)x)
                printf("%.0f la so nguyen\n", x);
            else
                printf("%.2f KHONG phai so nguyen\n", x);
            break;
        }

              // 2. Ước chung và bội chung
        case 2: {
            int a, b;
            printf("Nhap so thu nhat: \n");
            printf("Nhap so thu hai: \n");
            scanf("%d %d", &a, &b);
            printf("UCLN = %d\n", UCLN(a, b));
            printf("BCNN = %d\n", BCNN(a, b));
            break;
        }

              // 3. Tính tiền Karaoke
        case 3: {
            int start, end;
            printf("Nhap gio bat dau (12 - 23): ");
            scanf("%d", &start);
            printf("Nhap gio ket thuc (12 - 23): ");
            scanf("%d", &end);

            // Kiểm tra hợp lệ
            if (start < 12 || start > 23 || end < 12 || end > 23 || end <= start) {
                printf("Gio khong hop le! Quay hoat dong tu 12h den 23h.\n");
                break;
            }

            int gio = end - start;  // số giờ hát
            float tien = 0;

            // Tính tiền theo số giờ
            if (gio <= 3) {
                tien = gio * 150000;
            }
            else {
                // 3 giờ đầu
                tien = 3 * 150000;

                // Từ giờ thứ 4 giảm 30%
                tien += (gio - 3) * (150000 * 0.7);
            }

            // Giảm thêm 10% nếu giờ bắt đầu từ 14 -> 17
            if (start >= 14 && start <= 17) {
                tien *= 0.9;
            }

            printf("So gio hat: %d\n", gio);
            printf("Tong tien thanh toan: %.0f VND\n", tien);
            break;
        }

              // 4. Tính tiền điện  
              // Bậc thang đơn giản
        case 4:
        {
            int soDien;
            printf("Nhap so kWh: ");
            scanf("%d", &soDien);

            float tien;
            if (soDien <= 50)
                tien = soDien * 1678;
            else if (soDien <= 100)
                tien = 50 * 1678 + (soDien - 50) * 1734;
            else
                tien = 50 * 1678 + 50 * 1734 + (soDien - 100) * 2014;

            printf("Tien dien = %.0f VND\n", tien);
            break;
        }

              // 5. Chức năng đổi tiền
        case 5: {
            int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
            int soTien, i;

            printf("Nhap so tien can doi: ");
            scanf("%d", &soTien);

            if (soTien <= 0) {
                printf("So tien khong hop le!\n");
                return;
            }

            printf("Ket qua doi tien:\n");

            for (i = 0; i < 9; i++) 
            {
                if (soTien >= menhGia[i]) {
                    int soTo = soTien / menhGia[i];
                    soTien %= menhGia[i];
                    printf("%d to %d\n", soTo, menhGia[i]);
                }
            }
            break;
        }

              // 6. Lãi suất vay trả góp
        case 6: {
            double tienVay;
            printf("Nhap so tien muon vay: ");
            scanf("%lf", &tienVay);

            if (tienVay <= 0) {
                printf("So tien vay khong hop le!\n");
                return;
            }

            double laiSuat = 0.05;                    // 5% / tháng
            double gocPhaiTra = tienVay / 12;         // goc tra co dinh moi thang
            double soTienConLai = tienVay;

            printf("\n%-10s %-15s %-15s %-18s %-15s\n",
                "Ky han", "Lai phai tra", "Goc phai tra", "So tien phai tra", "Con lai");
            printf("--------------------------------------------------------------------------\n");

            for (int i = 1; i <= 12; i++) {
                double laiPhaiTra = soTienConLai * laiSuat;
                double tongTra = laiPhaiTra + gocPhaiTra;
                soTienConLai -= gocPhaiTra;

                if (soTienConLai < 0) soTienConLai = 0;

                printf("%-10d %-15.0f %-15.0f %-18.0f %-15.0f\n",
                    i, laiPhaiTra, gocPhaiTra, tongTra, soTienConLai);
            }
            break;
        }

              // 7. Vay tiền mua xe
        case 7: {
            double xe, traTruoc, rate, months;
            printf("Gia xe: ");
            scanf("%lf", &xe);
            printf("Tra truoc bao nhieu %%: ");
            scanf("%lf", &traTruoc);
            printf("Lai suat/thang (%%): ");
            scanf("%lf", &rate);
            printf("So thang vay: ");
            scanf("%lf", &months);

            double vay = xe * (1 - traTruoc / 100);
            double laithang = vay * (rate / 100);
            double traThang = vay / months + laithang;

            printf("So tien phai vay: %.0f VND\n", vay);
            printf("Tien tra/thang: %.0f VND\n", traThang);
            break;
        }

              // 8. Sắp xếp thông tin sinh viên
        case 8: {
            int n;
            printf("Nhap so sinh vien: ");
            scanf("%d", &n);

            struct SV {
                char ten[30];
                float diem;
            } sv[100];

            for (int i = 0; i < n; i++) {
                printf("Ten SV %d: ", i + 1);
                fflush(stdin);
                gets(sv[i].ten);
                printf("Diem: ");
                scanf("%f", &sv[i].diem);
            }

            // Sắp xếp tăng dần theo điểm
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (sv[j].diem < sv[i].diem) {
                        struct SV t = sv[i];
                        sv[i] = sv[j];
                        sv[j] = t;
                    }
                }
            }

            printf("\n--- Danh sach sau sap xep ---\n");
            for (int i = 0; i < n; i++)
                printf("%s - %.1f\n", sv[i].ten, sv[i].diem);

            break;
        }

              // 9. Game FPOLY-LOTT
        case 9: {
            int a, b;
            printf("Chon 2 so (1-15): ");
            scanf("%d %d", &a, &b);

            int x = rand() % 15 + 1;
            int y = rand() % 15 + 1;

            printf("So trung thuong: %d - %d\n", x, y);

            int trung = (a == x || a == y || b == x || b == y);

            if (trung) printf("CHUC MUNG BAN TRUNG GIAI!\n");
            else printf("Chuc ban may man lan sau!\n");
            break;
        }

              // 10. Tính toán phân số
        case 10: 
        {
            int a, b, c, d;
            printf("Nhap phan so a/b: ");
            scanf("%d %d", &a, &b);
            printf("Nhap phan so c/d: ");
            scanf("%d %d", &c, &d);

            int tu = a * d + b * c;
            int mau = b * d;

            int g = UCLN(tu, mau);
            tu /= g; mau /= g;

            printf("Tong = %d/%d\n", tu, mau);
            break;
        }

        case 11:
            printf("Thoat chuong trinh!\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }

    } while (choice != 11);

    return 0;
}