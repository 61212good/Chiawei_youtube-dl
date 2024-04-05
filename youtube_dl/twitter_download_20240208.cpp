//g++ -o twitter_download_demo_20240208 twitter_download_20240208.cpp & twitter_download_demo_20240208.exe
#include <iostream>
#include <string>
#include <dirent.h>
#include <sstream>
#include <vector>
using namespace std;

string fileNamestring;

char split_char_comma = ',';//逗號字元切割

// 函数用于分割字符串
std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int getfileName(string getfilePath) {
    // 用实际目录路径替换 "your_directory_path_here"
    std::string directoryPath = getfilePath;

    // 打开目录
    DIR* directory = opendir(directoryPath.c_str());

    // 检查目录是否成功打开
    if (directory != nullptr) {
        // 读取目录中的条目
        dirent* entry;
        while ((entry = readdir(directory)) != nullptr) {
            // 获取当前条目的文件名
            std::string fileName = entry->d_name;

            // 忽略当前目录和上级目录
            if (fileName != "." && fileName != "..") {
                // 打印文件名
                // std::cout << "fileName: " << fileName << std::endl;
    			fileNamestring = fileName;
            }
        }

        // 关闭目录
        closedir(directory);
    } else {
        std::cerr << "Path not found!" << std::endl;
    }

    if(fileNamestring == ""){
    	return -1;
    }

    return 0 ;

}

int main() {
	string audio_cmd="youtube-dl -o \"twitter_download/tmp/audio/%(title)s.%(ext)s\" https://video.twimg.com";
	string video_cmd="youtube-dl -o \"twitter_download/tmp/video/%(title)s.%(ext)s\" https://video.twimg.com";
	string delete_tmp_cmd="rmdir /s /q \"twitter_download/tmp/\"";
	string stringcin_audio;
	string stringcin_video;
	string instruction_1;
	string instruction_2;
	string instruction_3;
	string audio_fileName;
	string video_fileName;

	do{
		cout<<"Enter audio url: "<<endl;
		cin>>stringcin_audio;
		if(stringcin_audio=="0"){
			cout<<"Exit"<<endl;
			break;
		}else{
			// 调用分割字符串的函数
		    std::vector<std::string> result = splitString(stringcin_audio, split_char_comma);

		    // // 打印分割后的字符串
		    // for (const auto& token : result) {
		    //     std::cout << token << std::endl;
		    // }

			stringcin_audio = result[4].substr(5, (result[4].length()-6));
		    // std::cout << stringcin_audio << std::endl;
		}		    

		cout<<"Enter video url: "<<endl;
		cin>>stringcin_video;
		if(stringcin_video=="0"){
			cout<<"Exit"<<endl;
			break;
		}
		//cout<<instruction_1<<endl;
		instruction_1 = audio_cmd+stringcin_audio;
		system(instruction_1.c_str());
		//cout<<instruction_2<<endl;
		instruction_2 = video_cmd+stringcin_video;
		system(instruction_2.c_str());

		if(getfileName("twitter_download/tmp/audio/") != 0){
			cout<<"getfileName Error!"<<endl;
			return 0;
		}
		audio_fileName = fileNamestring;
		if(getfileName("twitter_download/tmp/video/") != 0){
			cout<<"getfileName Error!"<<endl;
			return 0;
		}
		video_fileName = fileNamestring;

		//cout<<instruction_3<<endl;
		instruction_3 = "ffmpeg -i \"twitter_download/tmp/video/"+video_fileName+"\" -i \"twitter_download/tmp/audio/"+audio_fileName+"\" -c:v copy -c:a copy \"twitter_download/"+video_fileName+"\"";
		system(instruction_3.c_str());

		//cout<<delete_tmp_cmd<<endl;
		system(delete_tmp_cmd.c_str());
	}while(stringcin_video!="0" || stringcin_audio!="0");
	return 0;
}

/*
#EXTM3U
#EXT-X-VERSION:6
#EXT-X-INDEPENDENT-SEGMENTS
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-128000",AUTOSELECT=YES,URI="/ext_tw_video/1754499299742978049/pu/pl/mp4a/128000/FAOweYiYtiaYTxc9.m3u8?container=cmaf"
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-64000",AUTOSELECT=YES,URI="/ext_tw_video/1754499299742978049/pu/pl/mp4a/64000/THs_GYP6Lo01hqf-.m3u8?container=cmaf"
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-32000",AUTOSELECT=YES,URI="/ext_tw_video/1754499299742978049/pu/pl/mp4a/32000/pBgc9KGv2KzURAF1.m3u8?container=cmaf"

#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=832424,BANDWIDTH=1065651,RESOLUTION=1280x720,CODECS="mp4a.40.2,avc1.64001F",AUDIO="audio-128000"
/ext_tw_video/1754499299742978049/pu/pl/avc1/1280x720/mp4a/128000/D2FhKY88_KS_Y_KM.m3u8?container=cmaf
#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=364379,BANDWIDTH=459790,RESOLUTION=640x360,CODECS="mp4a.40.2,avc1.4D401E",AUDIO="audio-64000"
/ext_tw_video/1754499299742978049/pu/pl/avc1/640x360/mp4a/64000/SHZ8U_FQGoQjNkbB.m3u8?container=cmaf
#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=204214,BANDWIDTH=239958,RESOLUTION=480x270,CODECS="mp4a.40.2,avc1.4D4015",AUDIO="audio-32000"
/ext_tw_video/1754499299742978049/pu/pl/avc1/480x270/mp4a/32000/lisW6eAvLjFSXCiU.m3u8?container=cmaf


#EXTM3U
#EXT-X-VERSION:6
#EXT-X-INDEPENDENT-SEGMENTS
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-128000",AUTOSELECT=YES,URI="/amplify_video/1754363816098611200/pl/mp4a/128000/bY7lWt7kJJAG7ULz.m3u8?container=cmaf"
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-64000",AUTOSELECT=YES,URI="/amplify_video/1754363816098611200/pl/mp4a/64000/e8UVhv2CmnpuypgM.m3u8?container=cmaf"
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-32000",AUTOSELECT=YES,URI="/amplify_video/1754363816098611200/pl/mp4a/32000/GlnSbwIh0J2ghWi5.m3u8?container=cmaf"

#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=1713028,BANDWIDTH=2338088,RESOLUTION=720x1280,CODECS="mp4a.40.2,avc1.64001F",AUDIO="audio-128000"
/amplify_video/1754363816098611200/pl/avc1/720x1280/mp4a/128000/Y2Rm2NPo_M5VU-d_.m3u8?container=cmaf
#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=908970,BANDWIDTH=1073211,RESOLUTION=480x852,CODECS="mp4a.40.2,avc1.4D401F",AUDIO="audio-64000"
/amplify_video/1754363816098611200/pl/avc1/480x852/mp4a/64000/IwlaYnj7q2JfpAUH.m3u8?container=cmaf
#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=544843,BANDWIDTH=656227,RESOLUTION=320x568,CODECS="mp4a.40.2,avc1.4D401E",AUDIO="audio-32000"
/amplify_video/1754363816098611200/pl/avc1/320x568/mp4a/32000/8O1-YpW0dB6uxKLD.m3u8?container=cmaf


#EXTM3U
#EXT-X-VERSION:6
#EXT-X-INDEPENDENT-SEGMENTS
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-128000",AUTOSELECT=YES,URI="/amplify_video/1684427426796032000/pl/mp4a/128000/f-2sjKTQTIctIPq4.m3u8?container=cmaf"
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-64000",AUTOSELECT=YES,URI="/amplify_video/1684427426796032000/pl/mp4a/64000/tfhL-LTn_6k27yNF.m3u8?container=cmaf"
#EXT-X-MEDIA:NAME="Audio",TYPE=AUDIO,GROUP-ID="audio-32000",AUTOSELECT=YES,URI="/amplify_video/1684427426796032000/pl/mp4a/32000/6DmNNBcp-w6Jc4Yl.m3u8?container=cmaf"

#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=1412237,BANDWIDTH=2119260,RESOLUTION=720x1280,CODECS="mp4a.40.2,avc1.640028",AUDIO="audio-128000"
/amplify_video/1684427426796032000/pl/720x1280/mp4a/128000/unydwMpRExpM2NH1.m3u8?container=cmaf
#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=702637,BANDWIDTH=964650,RESOLUTION=480x852,CODECS="mp4a.40.2,avc1.4D401F",AUDIO="audio-64000"
/amplify_video/1684427426796032000/pl/480x852/mp4a/64000/fn69eSRkBuXKA2Ec.m3u8?container=cmaf
#EXT-X-STREAM-INF:AVERAGE-BANDWIDTH=359475,BANDWIDTH=495741,RESOLUTION=320x568,CODECS="mp4a.40.2,avc1.4D401E",AUDIO="audio-32000"
/amplify_video/1684427426796032000/pl/320x568/mp4a/32000/4vVei_D0fcGFRjad.m3u8?container=cmaf
*/