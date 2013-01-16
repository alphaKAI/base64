#include <stdio.h>
#include "b64.h"

//Sugarlessライブラリ 著作者 石橋祥太 / 藤代晴嵐　　　使用
//簡易Base64 エンコーダ/デコーダ
//LICENSE GPLv3
//copyright (C) α改 @alpha_kai_NET 2012-2013 alpha-kai-net.info /* 藤代晴嵐 */
//Special Thanks! ==> 隠しコマンド実装 : 藤城晴嵐氏 @FujishiroSeiran
#define VER 04

void pf(void);

int main(int argc, char *argv[]){

int num;
int sum;
char *str;
char *ind;
int i;
int rl;
int sm;
int za;
int asma;
asma=0;
za=0;
rl=0;
if(argc==1){
pf();
return 1;
}


if(strcmp(argv[1],"--help")==0 && argc!=2){
sum=1;
asma=1;
}
if(strcmp(argv[1],"-fe")==0 || strcmp(argv[1],"-fd")==0){
if(argc!=4){
sum=1;
za=1;
}
}
if(strcmp(argv[1],"-e")!=0 && strcmp(argv[1],"-d")!=0 && strcmp(argv[1],"-t")!=0 && strcmp(argv[1],"-v")!=0 && strcmp(argv[1],"--help")!=0 && strcmp(argv[1],"-fe")!=0 && strcmp(argv[1],"-fd")!=0){
sum=2;
asma=1;
}
//-v
if(strcmp(argv[1],"-v")==0){
printf("簡易base64エンコーダ/デコーダ VER:0.0%d\n", VER);
printf("作者:α改\n\n");
return 0;
}

if(asma==1 || za==1){
if(strcmp(argv[1],"-e")==0 || strcmp(argv[1],"-d") || strcmp(argv[1],"-t")==0){
sum=2;
}
if(argc!=0 && sum==1){
printf("引数の数が不正です\n\n");
}
else if(argc!=0 && sum==2){
printf("オプションが不正です\n\n");
}
//使い方
pf();

printf("終了します\n");
return argc;
}
else{//-e
if(strcmp(argv[1],"-e")==0){
str=c2b(argv[2], strlen(argv[2]), 0);
if(str==NULL){
printf("文字列のエンコードに失敗しました\n");
return 6;
}
num=1;
}//-d
else if(strcmp(argv[1],"-d")==0){
str=b2c(argv[2], NULL);
if(str==NULL){
printf("文字列のデコードに失敗しました\n");
return 3;
}
num=2;
}//-t
else if(strcmp(argv[1],"-t")==0){
str=malloc((strlen(argv[2]) * 4 + 24) * sizeof(char));
sprintf(str, "＿");
for(num = 0; num < strlen(argv[2]) / 2 + 2; num++) strcat(str, "人");
sprintf(str, "%s＿\n＞　%s　＜\n￣Y", str, argv[2]);
for(num = 0; num < strlen(argv[2]) / 2; num++) strcat(str, "^Y");
strcat(str, "￣");
ind=str;
num=0;
}//-fe
else if(strcmp(argv[1],"-fe")==0){
sm=f2b(argv[2],argv[3]);
if(sm==0){
printf("ファイルエンコードに失敗しました\n");
return 7;
}
num=3;
}//-fd
else if(strcmp(argv[1],"-fd")==0){
sm=b2f(argv[2],argv[3]);
if(sm==0){
printf("ファイルデコードに失敗しました\n");
return 8;
}
num=4;
}
//ステータス
switch(num){
case 1:
ind="STRING ENCODE";
break;
case 2:
ind="STRING DECODE";
break;
case 3:
ind="FILE ENCODE";
rl=1;
break;
case 4:
ind="FILE DECODE";
rl=1;
break;
}
if(rl==0){
printf("INPUT FILE:%s\n", argv[2]);
printf("MODE:\n%s\n", ind);
printf("RESULT:\n%s\n", str);
free(str);
}
else if(rl==1){
printf("INPUT FILE:%s\n", argv[2]);
printf("MODE:\n%s\n", ind);
printf("RESULT FILE:%s\n", argv[3]);
}
}

printf("COMPLETE\n");

return 0;
}

void pf(void){

printf("簡易base64エンコーダ/デコーダ VER:0.0%d\n", VER);
printf("作者:α改\n\n");
printf("使用方法:\n");
printf("COMMAND : base64 [Option] [String] [OUTPUTFILENAME]\n");
printf("[Option]:\n");
printf("-e : 文字列のエンコード\n");
printf("-d : 文字列のデコード\n");
printf("-fe : ファイルのエンコード\n");
printf("-fd : ファイルのデコード\n");
printf("ファイルのエンデコのときのみOUTPUTFILENAMEはつかえます\n");
printf("--help : 使い方表示(現在の出力と同じです)\n");
printf("-v : バージョン情報\n");

}
