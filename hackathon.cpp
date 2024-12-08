#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool isPerfectNumber(int num) {
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) sum += num / i;
        }
    }
    return sum == num && num != 1;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int findSecondLargest(int arr[], int n) {
    int largest = -1, secondLargest = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int findSecondSmallest(int arr[], int n) {
    int smallest = 1e9, secondSmallest = 1e9;
    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] > smallest) {
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
}

void insertAtPosition(int arr[], int *n, int pos, int value) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void deleteAtPosition(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void sortAscending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortDescending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void binarySearch(int arr[], int n, int value) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            printf("Gia tri %d duoc tim thay tai vi tri %d\n", value, mid);
            return;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Gia tri %d khong co trong mang.\n", value);
}

void removeDuplicates(int arr[], int *n) {
    sortAscending(arr, *n);
    int temp[*n], j = 0;
    for (int i = 0; i < *n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[*n - 1];
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }
    *n = j;
    printf("Mang sau khi xoa cac phan tu trung lap:\n");
    for (int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortEvenOdd(int arr[], int n, bool evenFirst) {
    int temp[n], index = 0;
    if (evenFirst) {
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) temp[index++] = arr[i];
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) temp[index++] = arr[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) temp[index++] = arr[i];
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int arr[100];
    int n = 0;
    do {
        printf("\nMenu\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2 (khong sap xep)\n");
        printf("6. Tim gia tri nho thu 2 (khong sap xep)\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (sap xep chen)\n");
        printf("10. Sap xep mang giam dan (sap xep chen)\n");
        printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Sap xep va hien thi so le dung truoc, so chan dung sau\n");
        printf("15. Dao nguoc mang\n");
        printf("16. Thoat\n");
        printf("Nhap lua chon cua ban:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong phan tu: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            case 3:
                {
                    int count = 0;
                    for (int i = 0; i < n; i++) {
                        if (isPerfectNumber(arr[i])) count++;
                    }
                    printf("So luong so hoan hao: %d\n", count);
                }
                break;
            case 4:
                {
                    int count = 0;
                    for (int i = 0; i < n; i++) {
                        if (isPrime(arr[i])) count++;
                    }
                    printf("So luong so nguyen to: %d\n", count);
                }
                break;
            case 5:
                printf("Gia tri lon thu 2: %d\n", findSecondLargest(arr, n));
                break;
            case 6:
                printf("Gia tri nho thu 2: %d\n", findSecondSmallest(arr, n));
                break;
            case 7:
                {
                    int pos, value;
                    printf("Nhap vi tri: ");
                    scanf("%d", &pos);
                    printf("Nhap gia tri: ");
                    scanf("%d", &value);
                    insertAtPosition(arr, &n, pos, value);
                }
                break;
            case 8:
                {
                    int pos;
                    printf("Nhap vi tri: ");
                    scanf("%d", &pos);
                    deleteAtPosition(arr, &n, pos);
                }
                break;
            case 9:
                sortAscending(arr, n);
                printf("Mang sau khi sap xep tang dan: \n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 10:
                sortDescending(arr, n);
                printf("Mang sau khi sap xep giam dan: \n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 11: {
                int value;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                sortAscending(arr, n);
                binarySearch(arr, n, value);
                break;
            }
            case 12:
                removeDuplicates(arr, &n);
                break;
            case 13:
                sortEvenOdd(arr, n, true);
                break;
            case 14:
                sortEvenOdd(arr, n, false);
                break;
            case 15:
                reverseArray(arr, n);
                printf("Mang sau khi dao nguoc: \n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 16:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 12);

    return 0;
}

