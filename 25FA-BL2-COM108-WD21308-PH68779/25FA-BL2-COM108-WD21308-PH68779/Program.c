#include <stdio.h>
#include <math.h>

// ----------------- HÀM UCLN + BCNN ------------------
int UCLN(int a, int b) {
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
            float gio;
            printf("Nhap so gio hat Karaoke: ");
            scanf("%f", &gio);

            float tien = 0;
            if (gio <= 3)
                tien = gio * 150000;
            else
                tien = 3 * 150000 + (gio - 3) * 120000;

            if (gio >= 5)
                tien *= 0.9; // giảm 10%

            printf("Tien Karaoke = %.0f VND\n", tien);
            break;
        }

              // 4. Tính tiền điện  
              // Bậc thang đơn giản
        case 4: {
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
            int money;
            printf("Nhap so tien can doi: ");
            scanf("%d", &money);

            int menh[] = { 500000, 200000, 100000, 50000, 20000, 10000 };
            for (int i = 0; i < 6; i++) {
                printf("%d VND: %d to\n", menh[i], money / menh[i]);
                money %= menh[i];
            }
            break;
        }

              // 6. Lãi suất vay trả góp
        case 6: {
            double goc, rate, months;
            printf("Nhap so tien vay: ");
            scanf("%lf", &goc);
            printf("Nhap lai suat/thang (%%): ");
            scanf("%lf", &rate);
            printf("Nhap so thang vay: ");
            scanf("%lf", &months);

            double laithang = goc * (rate / 100);
            double traThang = goc / months + laithang;

            printf("Tien tra hang thang: %.0f VND\n", traThang);
            printf("Tong phai tra: %.0f VND\n", traThang * months);
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
        case 10: {
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