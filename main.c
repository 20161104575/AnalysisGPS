//
//  main.c
//  AnalysisGPS
//
//  Created by 20161104575 on 17/6/22.
//  Copyright © 2017年 20161104575. All rights reserved.
//
#include <stdio.h>
#include <string.h>
int main()
{

    char lat[9];
    char mat[63];
    char num[70];
    char time[7];
    char longitude[10];
    char high[5];
    int i;
    FILE *fp1,*fp2;
    fp1=fopen("//Users//a20161104575//Desktop//GPS170510.txt","r");
    fp2=fopen("//Users//a20161104575//Desktop//GPS.txt","w+");
if(fp1==NULL)
    printf("打开文件错误");
    else
    {
        fscanf(fp1,"%s%s",mat,num);
        printf("%s\n%s\n",mat,num);
        
            
        for(i=0; i<2; i++)
            time[i]=mat[i+7];
        time[2]='\0';
        fprintf(fp2,"北京时间：%s",time);
        for(i=0; i<4;i++)
            time[i]=mat[i+9];
        time[4]='\0';
        fprintf(fp2,"%s\n",time);
        
        
        for(i=0; i<8; i++)
            lat[i]=mat[i+16];
            lat[8]='\0';
            fprintf(fp2,"纬度：%s\n",lat);
        
        
        for(i=0; i<9; i++)
            longitude[i]=mat[i+27];
            longitude[9]='\0';
            fprintf(fp2,"经度：%s\n",longitude);
        
        
        for(i=0; i<4; i++)
            high[i]=num[i+43];
            high[4]='\0';
        fprintf(fp2,"海拔：%sm\n",high);
    }
    return 0;
}
