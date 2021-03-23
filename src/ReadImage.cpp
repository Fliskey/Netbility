#define _CRT_SECURE_NO_WARNINGS
#include "include.h"

#define BOUNDARY 127


bool is_black(Vec3b p) {
	if (p[0] <= BOUNDARY && p[1] <= BOUNDARY && p[2] <= BOUNDARY) {
		return 1;
	}
	return 0;
}


void my_read(FILE* fp, const char* path, int row, int col, double step, int r_start, int c_start) {
	Mat read_image = imread(path);
	int count = 0;
	int l_byte = 0;
	r_start += step / 2;
	c_start += step / 2;//移到第一个像素的中间点
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int r = r_start + i * step;
			int c = c_start + j * step;
		//	printf("%d,%d\t",r,c);
			int bit = 0;
			if (is_black(read_image.at<Vec3b>(r, c))) {
				bit = 1;
			}
			else {
				bit = 0;
			}

			l_byte *= 2;
			l_byte += bit;
			count++;
			if (count == 8) {
				count = 0;
				l_byte = 0;
				fwrite(&l_byte, 1, 1, fp);
			}
		}
	}
}

int use_read() {
	FILE* fp;
	fp = fopen("reduc.bin", "wb+");
	for (int i = 0; i <= 1; i++) {//2592
		char path[11];
		sprintf(path, "pic%d.png", i);
		my_read(fp, path, 64, 64, 193.0/64.0, 0, 0);
	}
	return 0;
}
