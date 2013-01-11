#include <stdio.h>
#include "base64.h"

//Sugarless���C�u����  ����� �΋��ˑ� / ���㐰���@�@�@�g�p
//�Ȉ�Base64 �G���R�[�_/�f�R�[�_
//LICENSE GPLv3
//copyright (C) ���� @alpha_kai_NET 2012-2013 alpha-kai-net.info /* ���㐰�� */
//Special Thanks! ==> �B���R�}���h���� : ���鐰���� @FujishiroSeiran
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
		printf("�Ȉ�base64�G���R�[�_/�f�R�[�_ VER:0.0%d\n", VER);
		printf("���:����\n\n");
		return 0;
	}

	if(asma==1 || za==1){
		if(strcmp(argv[1],"-e")==0 || strcmp(argv[1],"-d") || strcmp(argv[1],"-t")==0){
			sum=2;
		}
		if(argc!=0 && sum==1){
			printf("�����̐����s���ł�\n\n");
		}
		else if(argc!=0 && sum==2){
			printf("�I�v�V�������s���ł�\n\n");
		}
		//�g����
		pf();

		printf("�I�����܂�\n");
		return argc;
	}
	else{//-e
		if(strcmp(argv[1],"-e")==0){
			str=c2b(argv[2], strlen(argv[2]), 0);
			if(str==NULL){
				printf("������̃G���R�[�h�Ɏ��s���܂���\n");
				return 6;
			}
			num=1;
		}//-d
		else if(strcmp(argv[1],"-d")==0){
			str=b2c(argv[2], NULL);
			if(str==NULL){
				printf("������̃f�R�[�h�Ɏ��s���܂���\n");
				return 3;
			}
			num=2;
		}//-t
		else if(strcmp(argv[1],"-t")==0){
			str=malloc((strlen(argv[2]) * 4 + 24) * sizeof(char));
			sprintf(str, "�Q");
			for(num = 0; num < strlen(argv[2]) / 2 + 2; num++) strcat(str, "�l");
			sprintf(str, "%s�Q\n���@%s�@��\n�PY", str, argv[2]);
			for(num = 0; num < strlen(argv[2]) / 2; num++) strcat(str, "^Y");
			strcat(str, "�P");
			ind=str;
			num=0;
		}//-fe
		else if(strcmp(argv[1],"-fe")==0){
			sm=f2b(argv[2],argv[3]);
			if(sm==0){
				printf("�t�@�C���G���R�[�h�Ɏ��s���܂���\n");
				return 7;
			}
			num=3;
		}//-fd
		else if(strcmp(argv[1],"-fd")==0){
			sm=b2f(argv[2],argv[3]);
			if(sm==0){
				printf("�t�@�C���f�R�[�h�Ɏ��s���܂���\n");
				return 8;
			}
			num=4;
		}
		//�X�e�[�^�X
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

		printf("�Ȉ�base64�G���R�[�_/�f�R�[�_ VER:0.0%d\n", VER);
		printf("���:����\n\n");
		printf("�g�p���@:\n");
		printf("COMMAND : base64 [Option] [String] [OUTPUTFILENAME]\n");
		printf("[Option]:\n");
		printf("-e  :  ������̃G���R�[�h\n");
		printf("-d  :  ������̃f�R�[�h\n");
		printf("-fe  :  �t�@�C���̃G���R�[�h\n");
		printf("-fd  :  �t�@�C���̃f�R�[�h\n");
		printf("�t�@�C���̃G���f�R�̂Ƃ��̂�OUTPUTFILENAME�͂����܂�\n");
		printf("--help  :  �g�����\��(���݂̏o�͂Ɠ����ł�)\n");
		printf("-v  :  �o�[�W�������\n");

}