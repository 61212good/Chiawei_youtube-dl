//g++ -o pornhub_download_demo pornhub_download.cpp & pornhub_download_demo.exe
//https://cn.pornhub.com/view_video.php?viewkey=ph5f91c378ad68a
#include <iostream> 
#include <string> 
using namespace std;
int main() {
	string url="youtube-dl -o \"./pornhub_download/%(title)s.%(ext)s\" ";
	string stringcin;
	do{
		cout<<"Enter pornhub link : "<<endl;
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