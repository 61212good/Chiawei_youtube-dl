//g++ -o youtube_download_demo youtube_download.cpp & youtube_download_demo.exe
#include <iostream> 
#include <string> 
using namespace std;
int main() {
	string url="yt-dlp --output \".\\youtube_download\\%(title)s.%(ext)s\" \"";
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