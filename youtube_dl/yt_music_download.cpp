//g++ -o yt_music_download_demo yt_music_download.cpp & yt_music_download_demo.exe
#include <iostream> 
#include <string> 
using namespace std;
int main() {
	string url="yt-dlp --output \".\\yt_music_download\\%(title)s.%(ext)s\" -f 251 \"";
	string url_end="\"";
	string stringcin;
	do{
		cout<<"Enter youtube link : "<<endl;
		cin>>stringcin;
		if(stringcin=="0"){
			cout<<"Exit"<<endl;
			break;
		}
		//cout<<url+stringcin<<endl;
		string instruction = url+stringcin+url_end;
		system(instruction.c_str());
	}while(stringcin!="0");
	return 0;
}