#define _CRT_SECURE_NO_WARNINGS 
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	int count = 500;
	while (count--) {
		int i;
		char Buf[800 * 480 * 3] = { 0 };
		int tempbuf[800 * 480] = { 0 };
		int lcd_buf1[800 * 480] = { 0 };
		int lcd_buf2[800 * 480] = { 0 };
		int j = 0;


		int bmp1_fd = open("./1.bmp", O_RDONLY);
		int bmp2_fd = open("./2.bmp", O_RDONLY);
		int lcd_fd = open("/dev/fb0", O_RDWR);
		//FILE * lcdout = fopen("/dev/fb0", "r");

		lseek(bmp1_fd, 54, SEEK_SET);
		lseek(bmp2_fd, 54, SEEK_SET);

		read(bmp1_fd, Buf, 800 * 480 * 3);
		for (i = 0; i<800 * 480; i++)
		{
			tempbuf[i] = Buf[2 + i * 3] << 16 | Buf[1 + i * 3] << 8 | Buf[i * 3];

		}
		for (i = 0; i < 800; i++) {
			for (j = 0; j < 480; j++) {
				lcd_buf1[(479 - j) * 800 + i] = tempbuf[j * 800 + i];
			}
		}

		read(bmp2_fd, Buf, 800 * 480 * 3);
		for (i = 0; i<800 * 480; i++)
		{
			tempbuf[i] = Buf[2 + i * 3] << 16 | Buf[1 + i * 3] << 8 | Buf[i * 3];
		}

		for (i = 0; i < 800; i++) {
			for (j = 0; j < 480; j++) {
				lcd_buf2[(479 - j) * 800 + i] = tempbuf[j * 800 + i];
			}
		}

		int count = 50;

		write(lcd_fd, lcd_buf1, 800 * 480 * 4);
		close(lcd_fd);
		//fflush(lcdout);
		sleep(1);
		lcd_fd = open("/dev/fb0", O_RDWR);
		write(lcd_fd, lcd_buf2, 800 * 480 * 4);
		close(lcd_fd);
		sleep(1);
		//fflush(lcdout);
		close(bmp1_fd);
		close(bmp2_fd);
	}
	return 0;
}