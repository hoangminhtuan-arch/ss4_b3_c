#include <stdio.h>

int main() {
    int n = 0;
    long long tong_doanh_thu = 0;

    printf("=== HE THONG POS - KIEM TOAN DOANH THU ===\n");
    printf("Nhap so luong giao dich trong ca: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("[!] LOI NGHIEP VU: So luong giao dich phai > 0. Dung he thong.\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        int ma_mon = 0, size = 0, topping = 0, the_gold = 0;
        long long gia_co_ban = 0, phu_thu_size = 0, phu_thu_topping = 0, tong_tien_mon = 0;

        printf("\n--- Giao dich thu %d ---\n", i);
        printf("Nhap ma mon (-1: Ngat, 0: Huy, 1: Phin Sua Da, 2: Tra Sen Vang, 3: Freeze): ");
        scanf("%d", &ma_mon);

        if (ma_mon == -1) {
            printf("[!] TIN HIEU NGAT KHAN CAP: Dung ca ngay lap tuc tai giao dich %d!\n", i);
            break;
        }

        if (ma_mon == 0) {
            printf("[-] Giao dich bi huy bo. Bo qua.\n");
            continue;
        }

        if (ma_mon != 1 && ma_mon != 2 && ma_mon != 3) {
            printf("[!] LOI DU LIEU: Ma do uong khong hop le (%d). Bo qua giao dich.\n", ma_mon);
            continue;
        }

        printf("Nhap Size (1-S, 2-M, 3-L): ");
        scanf("%d", &size);
        printf("Nhap so luong Topping (0-5): ");
        scanf("%d", &topping);

        if ((size != 1 && size != 2 && size != 3) || (topping < 0 || topping > 5)) {
            printf("[!] LOI HE THONG: Du lieu Size (%d) hoac Topping (%d) bi sai lech. Bo qua.\n", size, topping);
            continue;
        }

        printf("The thanh vien (1: Gold, 0: Khong): ");
        scanf("%d", &the_gold);

        if (ma_mon == 1) {
            gia_co_ban = 29000;
        } else if (ma_mon == 2) {
            gia_co_ban = 39000;
        } else if (ma_mon == 3) {
            gia_co_ban = 49000;
        }

        if (size == 1) {
            phu_thu_size = 0;
        } else if (size == 2) {
            phu_thu_size = 6000;
        } else if (size == 3) {
            phu_thu_size = 10000;
        }

        phu_thu_topping = topping * 8000;

        tong_tien_mon = gia_co_ban + phu_thu_size + phu_thu_topping;

        if (the_gold == 1) {
            tong_tien_mon = tong_tien_mon * 90 / 100; 
        }

        tong_doanh_thu += tong_tien_mon;
        printf("=> Thanh tien giao dich nay: %lld VND\n", tong_tien_mon);
    }

    printf("\n============================================\n");
    printf("CHOT SO CA LAM VIEC\n");
    printf("Tong doanh thu ca: %lld VND\n", tong_doanh_thu);
    printf("============================================\n");

    return 0;
}
