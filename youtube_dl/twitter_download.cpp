//g++ -o twitter_download_demo twitter_download.cpp & twitter_download_demo.exe
#include <iostream> 
#include <string> 
using namespace std;
int main() {
	string url="youtube-dl -o \"twitter_download/%(title)s.%(ext)s\" https://video.twimg.com";
	string stringcin;
	do{
		cout<<"Enter url: "<<endl;
		cin>>stringcin;
		if(stringcin=="0"){
			cout<<"Exit"<<endl;
			break;
		}
		//cout<<url+stringcin<<endl;
		string instruction = url+stringcin;
		system(instruction.c_str());
	}while(stringcin!="0");
	return 0;
}