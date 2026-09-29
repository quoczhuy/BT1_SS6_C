#include <stdio.h>
#include <string.h>

int main() {
    // 1. Khai bao cac hang so va mang du lieu
    const int MAX_PHIEU = 50;
    const int PHI_PHAT = 5000;
    
    char maPhieu[50][20] = {
        "PM101",
        "PM102",
        "PM103"
    };
    int ngayQuaHan[50] = {0, 3, 5};
    int soLuong = 3;
    
    int luaChon;
    
    // 2. Vong lap Menu dieu khien
    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        
        scanf("%d", &luaChon);
        
        // Xu ly troi lenh: Lam sach bo dem ban phim sau scanf
        while (getchar() != '\n');
        
        switch (luaChon) {
            case 1: {
                // Hien thi danh sach
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    long long tienPhat = (long long)ngayQuaHan[i] * PHI_PHAT;
                    printf("%d | %s | %d ngay | %lld VNĐ\n", i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }
                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }
            
            case 2: {
                // Them moi phieu muon
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                } else {
                    printf("Nhap ma phieu muon moi: ");
                    scanf("%19s", maPhieu[soLuong]);
                    while (getchar() != '\n'); // Lam sach bo dem
                    
                    ngayQuaHan[soLuong] = 0; // Mac dinh so ngay qua han = 0
                    soLuong++;
                    printf("Them moi thanh cong!\n");
                }
                break;
            }
            
            case 3: {
                // Cap nhat so ngay qua han
                char maTimKiem[20];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", maTimKiem);
                while (getchar() != '\n'); // Lam sach bo dem
                
                // Tim kiem tuyen tinh bang strcmp
                int viTri = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTimKiem) == 0) {
                        viTri = i;
                        break;
                    }
                }
                
                if (viTri != -1) {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maTimKiem, viTri);
                    int ngayMoi;
                    do {
                        printf("Nhap so ngay qua han moi: ");
                        scanf("%d", &ngayMoi);
                        while (getchar() != '\n'); // Lam sach bo dem
                        
                        if (ngayMoi < 0) {
                            printf("Loi: So ngay qua han phai la so nguyen khong am. Vui long nhap lai!\n");
                        }
                    } while (ngayMoi < 0);
                    
                    ngayQuaHan[viTri] = ngayMoi;
                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", maTimKiem, ngayMoi);
                } else {
                    printf("Loi: Khong tim thay ma phieu muon '%s' trong he thong.\n", maTimKiem);
                }
                break;
            }
            
            case 0:
                printf("Thoat chuong trinh. Chuc ban mot ngay tot lanh!\n");
                break;
                
            default:
                printf("Loi: Lua chon khong hop le. Vui long chon lai tu 0 den 3.\n");
        }
    } while (luaChon != 0);

    return 0;
}