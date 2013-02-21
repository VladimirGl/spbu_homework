#ifndef _SORT_H_
#define _SORT_H_

void quikSort(City *cityN, int left, int right) {
    if (left < right) {
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (cityN[j].distance <= cityN[right].distance) {
                i++;
                swap(cityN[j].distance, cityN[i].distance);
                swap(cityN[j].number, cityN[i].number);
            }
        }
        i++;
        swap(cityN[i].distance, cityN[right].distance);
        swap(cityN[i].number, cityN[right].number);
        quikSort(cityN, left, i-1);
        quikSort(cityN, i+1, right);
    }
}

#endif
