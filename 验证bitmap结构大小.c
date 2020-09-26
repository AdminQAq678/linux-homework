#include <stdio.h>
//3.5 验证nmp图像文件格式头 32个字节
struct tagBitmapFileHeader{
	unsigned short bmp_Type;
	unsigned long bmp_Size;
	unsigned short bmp_Reserved1;
	unsigned short bmp_Reserved2;
	unsigned long bmp_OffBits;
};

int  main (int argc,char * argv[]){
	struct tagBitmapFileHeader bh;
	printf("%ld",sizeof(bh));
	return 0;
}

