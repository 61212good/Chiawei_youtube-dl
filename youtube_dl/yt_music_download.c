//gcc -o yt_music_download_demo yt_music_download.c & yt_music_download_demo.exe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *url = "yt-dlp --output \".\\yt_music_download\\%(title)s.%(ext)s\" -f 251 \"";
char *url_end = "\"";

char stringcin[1000];
char instruction[1000];

int main() {

	while(1){
		printf("Enter youtube link : \n");
		memset(stringcin, 0, sizeof(stringcin));//初始化字串
		scanf("%s",&stringcin);
		memset(instruction, 0, sizeof(instruction));//初始化字串
		strcat(instruction, url);//字串合併
		strcat(instruction, stringcin);//字串合併
		strcat(instruction, url_end);//字串合併
		//printf("%s\n", instruction);
		system(instruction);
		printf("\n");
		//system("pause");//等待使用者
	}

	return 0;
}