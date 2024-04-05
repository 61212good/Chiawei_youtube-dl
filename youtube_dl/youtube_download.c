//gcc -o youtube_download_demo youtube_download.c & youtube_download_demo.exe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *url_1 = "yt-dlp --output \".\\youtube_download\\%(title)s_";
char *url_2;
char *url_3 = ".%(ext)s\" \"";
char *url_end = "\"";

char stringcin[1000];
char instruction[1000];

char *NowTime_to_Str(){
	char *result = malloc (sizeof (char) * 30);
	char time_str[30];
	
	time_t totaltime = time(NULL);
	struct tm *totaltimePtr = localtime(&totaltime);

	strftime(time_str, 30, "%Y%m%d%H%M%S", totaltimePtr);

	sprintf(result,"%s",time_str);

	return result;
}

int main() {

	while(1){
		printf("Enter youtube link : \n");
		memset(stringcin, 0, sizeof(stringcin));//初始化字串
		scanf("%s",&stringcin);
		memset(instruction, 0, sizeof(instruction));//初始化字串

		url_2 = NowTime_to_Str();

		strcat(instruction, url_1);//字串合併
		strcat(instruction, url_2);//字串合併
		strcat(instruction, url_3);//字串合併
		strcat(instruction, stringcin);//字串合併
		strcat(instruction, url_end);//字串合併
		// printf("%s\n", instruction);
		// return 0;
		system(instruction);
		printf("\n");
		//system("pause");//等待使用者
	}

	return 0;
}