#include <CONIO.H>    
#include <STDLIB.H>    
#include <STDIO.H>    
#include <MATH.H>   
#include <MALLOC.H> 
#include <string.h>
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
#include <pshpack2.h> 
typedef struct tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfoffBits;
} BITMAPFILEHEADER;
#include <poppack.h>  
typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    DWORD biWidth;
    DWORD biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompress;
    DWORD biSizeImage;
    DWORD biXPeIsPerMeter;
    DWORD biYPeIsPerMeter;
    DWORD biCIrUsed;
    DWORD biClrImprotant;
} BITMAPINFOHEADER;
typedef struct tagRGBDATA {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
} RGBDATA;
int main(int argc, char* argv[]) {
    RGBDATA* color = NULL;
    FILE* fp1, * fp2;
    long i, j, k;
    long width = 128;
    long height = 112;
    long square = width * height;
    BITMAPFILEHEADER bmfHeader;
    BITMAPINFOHEADER bmiHeader;
    if (argc < 2)
    {
        printf("\n    ��ָ����Ҫ���ɵ�BMP�ļ�����\n");
        printf("\n    ����1����cmd�������룺 demo xxxx.bmp����س�ִ�У�\n");
        printf("\n    ����2����VC�Ĺ�����������Ӳ����� xxxx.bmp����������У�\n");
        printf("\n    ���ܣ� �����趨��������ɫ������ֵ��������ʾ��ͬ�Ĳ�ɫ���ƣ�\n\n");
        exit(0);
    }
    printf("�ļ����ɳɹ�������\n");
    printf("���ߣ������\n");
    if ((fp1 = fopen(argv[1], "wb+")) == NULL) {
        printf("�ļ���ʧ��");
        exit(0);
    }
    bmfHeader.bfType = 0x4d42;
    bmfHeader.bfSize = 14 + 40 + width * height * 3;
    bmfHeader.bfReserved1 = 0;
    bmfHeader.bfReserved2 = 0;
    bmfHeader.bfoffBits = 0x36;
    fwrite(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, fp1);

    bmiHeader.biSize = 40;
    bmiHeader.biWidth = width;
    bmiHeader.biHeight = height;
    bmiHeader.biPlanes = 1;
    bmiHeader.biBitCount = 24;
    bmiHeader.biCompress = 0;
    bmiHeader.biSizeImage = width * height * 3;
    bmiHeader.biXPeIsPerMeter = 0;
    bmiHeader.biYPeIsPerMeter = 0;
    bmiHeader.biCIrUsed = 2;
    bmiHeader.biClrImprotant = 2;
    fwrite(&bmiHeader, sizeof(BITMAPINFOHEADER), 1, fp1);

    color = (RGBDATA*)malloc(width * height * sizeof(RGBDATA));
    if (color == NULL) {
        printf("�ڴ����ʧ��");
        exit(0);
    }
    
    char** inte = (char**)malloc(sizeof(char*) * height);
    if ((fp2 = fopen("��������.txt", "r")) == NULL) {
        printf("�ļ���ʧ��");
        exit(0);
    }

    for (i = 0; i < height; i++) {
        inte[i] = (char*)malloc(sizeof(char) * (width + 1)); 
        fgets(inte[i], width + 1, fp2); 
        printf("%s\n", inte[i]);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = (height - i - 1) * width + j;
            if (inte[i][j] == 'X' || i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                color[k].rgbBlue = 0;
                color[k].rgbGreen = 0;
                color[k].rgbRed = 255;
            }
            else {
                color[k].rgbBlue = 255;
                color[k].rgbGreen = 255;
                color[k].rgbRed = 255;
            }
        }
    }
 
    for (i = 0; i < height; i++) {
        fwrite(&color[i * width], sizeof(RGBDATA), width, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    free(color);
    for (i = 0; i < height; i++) {
        free(inte[i]);
    }
    free(inte);

    printf("���ɳɹ�����");
    return 0;
}
