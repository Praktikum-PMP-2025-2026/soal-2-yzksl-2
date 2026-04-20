/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 02 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Muhammad Zaki Azzamy Syauqi (13224045)
 *   Nama File           : soal2.c
 *   Deskripsi           : Tugas Pendahuluan Bagian 1
 */

#include <stdio.h>

int main() {
    int arr_size;
    scanf("%d", &arr_size);
    int num_arr[arr_size];
    int sum = 0;
    for (int i = 0; i < arr_size; i += 1) {
        scanf("%d", &num_arr[i]);
        sum += num_arr[i];
    }

    // divide total sum by 3
    float ftarget = (float)sum / 3.0;
    int target;
    if ((ftarget - (int)ftarget) >= 0.5) target = (int)(ftarget + 1);
    else target = ftarget;
    int sum_arr[3];

    // check which index to split by comparing with target
    int temp_sum = 0;
    int first_cut, second_cut, min, max;
    printf("MIN_DIFF ");
    if (arr_size == 3) {
        first_cut = 1;
        second_cut = 2;
        sum_arr[0] = num_arr[0];
        sum_arr[1] = num_arr[1];
        sum_arr[2] = num_arr[2];
    }

    else {

        for (int i = 0; i < arr_size; i += 1) {
            temp_sum += num_arr[i];
            if (temp_sum >= target) {
                int temp = temp_sum - num_arr[i] - target;
                if (temp < 0) temp = - temp;
                if (temp < temp_sum - target) {
                    first_cut = i;   
                    sum_arr[0] = temp_sum - num_arr[i];
                } else {
                    first_cut = i + 1;
                    sum_arr[0] = temp_sum;
                }
                break;
            }
        }
    
        temp_sum = 0;
        for (int i = first_cut; i < arr_size; i += 1) {
            temp_sum += num_arr[i];
            if (temp_sum >= target) {
                int temp = temp_sum - num_arr[i] - target;
                if (temp < 0) temp = - temp;
                if (temp < temp_sum - target) {
                    // printf("HERERE %d", temp);
                    second_cut = i;   
                    sum_arr[1] = temp_sum - num_arr[i];
                } else {
                    second_cut = i + 1;
                    sum_arr[1] = temp_sum;
                    // printf("JDSFLDSF%d %d df %d heli", second_cut, temp_sum, target);
                }
                break;
            }
            second_cut = first_cut + 1;
            sum_arr[1] = num_arr[first_cut];
        }
    
        temp_sum = 0;
        for (int i = second_cut; i < arr_size; i += 1) {
            temp_sum += num_arr[i];
        }
        sum_arr[2] = temp_sum;
    
       
    }
    if (sum_arr[0] >= sum_arr[1] && sum_arr[0] >= sum_arr[2]) max = sum_arr[0];
    else if (sum_arr[1] >= sum_arr[0] && sum_arr[1] >= sum_arr[2]) max = sum_arr[1];
    else max = sum_arr[2];

    if (sum_arr[0] <= sum_arr[1] && sum_arr[0] <= sum_arr[2]) min = sum_arr[0];
    else if (sum_arr[1] <= sum_arr[0] && sum_arr[1] <= sum_arr[2]) min = sum_arr[1];
    else min = sum_arr[2];

    printf("%d\nCUT %d %d\n", max-min, first_cut, second_cut);
}