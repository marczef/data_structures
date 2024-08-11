#include <iostream>
#include <stdint.h>

void quicksort(int32_t *tab, int32_t left, int32_t right) {
    if(right <= left) return;
	int32_t i = left, j = right, pivot = tab[(left+right)/2]; 
	
	do
	{
		while(pivot>tab[i]) i++;
		while(pivot<tab[j]) j--;

		if(i <= j) {
			std::swap(tab[i],tab[j]);
            i++;
            j--;
        }
		else
			break;
	} while(i <= j);

	if(j > left)
	quicksort(tab, left, j);
	if(i < right)
	quicksort (tab, i, right);
}

// int main() {
//     int32_t tab[] = {4, 5, 1, 9, 0, 4, 6, 3, 1};
//     // std::cout <<sizeof(tab)/sizeof(tab[0]);
//     quicksort(tab, 0, sizeof(tab)/sizeof(tab[0])-1);
//     for (auto i=0; i < sizeof(tab)/sizeof(tab[0]); i++) {
//         printf("%i ", tab[i]);
//     }
// }