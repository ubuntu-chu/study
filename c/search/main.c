#include <stdio.h>

int find(int *array, int len, int value){

	int		rt = -1;
	int		end		= len-1;
	int		begin = 0;
	int		middle = (begin + end)/2;

	//while ((middle <= end) && (middle >= begin)){
	while (begin <= end){
		//printf("begin = %d, end = %d, middle = %d;array[middle] = %d\n", begin, end, middle, array[middle]);
		if (value == array[middle]){
			rt	=  middle;
			break;
		}else if (value < array[middle]){
			end		= middle -1;
		}else {
			begin	= middle + 1;
		}
		middle = (begin + end)/2;
	}


	return rt;

}

//无序区从0开始   
int select_sort(int *array, int len){

	int pos	= 0;
	int min;
	int j, i;
	int tmp;

	for (; pos < len-1; pos++){
		min		= pos;
		for (j = pos; j < len; j++){
			if (array[min] > array[j]){
				min = j;
			}
		}
		if (min != pos){
			tmp		= array[pos];
			array[pos] = array[min];
			array[min] = tmp;
		}
		for (i = 0; i < len; i++){
			printf("pos = %d array[%d] = %d\n", pos, i, array[i]);
		}
		printf("\n");
	}



	return 0;
}

//无序区从1开始   
int insert_sort(int *array, int len){

	int pos	= 1;
	int j, i;
	int tmp;

	for (; pos < len; pos++){
		for (j = pos; j > 0; j--){
			if (array[j] < array[j-1]){
				tmp		= array[j-1];
				array[j-1] = array[j];
				array[j] = tmp;
			}else {
				continue;
			}
		}
		for (i = 0; i < len; i++){
			printf("pos = %d array[%d] = %d\n", pos, i, array[i]);
		}
		printf("\n");

	}
	return 0;
}

int pop_sort(int *array, int len){

	int tmp;
	int j, i;
	int pos	= len;

	for (; pos > 0; pos--){
		for (j = 0; j < pos - 1; j++){
			if (array[j] > array[j+1]){
				tmp		= array[j+1];
				array[j+1] = array[j];
				array[j] = tmp;
			}
		}

		for (i = 0; i < len; i++){
			printf("pos = %d array[%d] = %d\n", pos, i, array[i]);
		}
		printf("\n");
	}

	return 0;
}

int main(void){

	//int aa[]	= {0, 1, 2, 3, 4, 5, 6};
	int aa[]	= {6, 4, 3, 1, 5, 0, 2, -1};
	int i;

	//select_sort(aa, sizeof(aa)/sizeof(aa[0]));
	//insert_sort(aa, sizeof(aa)/sizeof(aa[0]));
	pop_sort(aa, sizeof(aa)/sizeof(aa[0]));

	for (i = 0; i < sizeof(aa)/sizeof(aa[0]); i++){
		printf("aa[%d] = %d\n", i, aa[i]);
	}
#if 1
	for (i = -2; i < 10; i ++){

		printf("find %d in array_pos = %d\n", i, find(aa, sizeof(aa)/sizeof(aa[0]), i));
		//sleep(1);
	}
#endif

	return 0;
}
