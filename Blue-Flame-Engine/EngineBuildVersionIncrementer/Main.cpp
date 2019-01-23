#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//EBVE = Engine Build Version Incrementer
#define EBVE_VERSION_FILE_INDEX 1
#define EBVE_MAJOR_VERSION_INDEX 2

int main(int argc, char** argv)
{
	string versionFileLocation = argv[EBVE_VERSION_FILE_INDEX];

	//---------------------------- Read Version File ----------------------------
	ifstream inFile;
	inFile.open(versionFileLocation);

	stringstream strStream;
	strStream << inFile.rdbuf();
	string versionFileString = strStream.str();
	//---------------------------- Read Version File ----------------------------

	//---------------------------- Read Current Date ----------------------------
	string date;
	time_t now = time(0);
	tm *ltm = localtime(&now);

	date.append(to_string(1900 + ltm->tm_year));
	date.append("0");
	date.append(to_string(1 + ltm->tm_mon));
	date.append(to_string(ltm->tm_mday));
	//---------------------------- Read Current Date ----------------------------

	//---------------------------- Modify Version Number ----------------------------
	std::size_t majorPos = versionFileString.find("#define BFE_ENGINE_MAJOR_VERSION ");
	std::size_t spaceAfterDefinePos = versionFileString.find(" ", majorPos);
	std::size_t spaceAfterMajor = versionFileString.find(" ", spaceAfterDefinePos + 1);

	std::size_t minorPos = versionFileString.find("#define BFE_ENGINE_MINOR_VERSION ");
	spaceAfterDefinePos = versionFileString.find(" ", minorPos);
	std::size_t spaceAfterMinorPos = versionFileString.find(" ", spaceAfterDefinePos + 1);

	std::size_t patchPos = versionFileString.find("#define BFE_ENGINE_PATCH_VERSION ");
	spaceAfterDefinePos = versionFileString.find(" ", patchPos);
	std::size_t spaceAfterPatchPos = versionFileString.find(" ", spaceAfterDefinePos + 1);

	std::string major = versionFileString.substr(majorPos, spaceAfterMajor - majorPos);
	std::string minor = versionFileString.substr(minorPos, spaceAfterMinorPos - minorPos);
	std::string patch = versionFileString.substr(patchPos, spaceAfterPatchPos - patchPos);

	string version;

	version.append("/*\n-------------------------------------------------------------------------------------\n");
	version.append("DO NOT MODIFY THIS FILE.\n");
	version.append("THIS FILE IS AUTO GENERATED.\n");
	version.append("ANY CHANGES MADE HERE WILL BE OVERWRITTEN BY THE \"ENGINE BUILD VERSION INCREMENTER TOOL\"\n");
	version.append("-------------------------------------------------------------------------------------\n*/\n\n");

	version.append(major);
	version.append(" ");
	version.append(argv[EBVE_MAJOR_VERSION_INDEX]);
	version.append("\n");

	version.append(minor);
	version.append(" ");
	version.append(date);
	version.append("\n");

	version.append(patch);
	version.append(" ");
	version.append("0");
	//---------------------------- Modify Version Number ----------------------------

	//---------------------------- Write Version File ----------------------------`	
	ofstream myfile;
	myfile.open(versionFileLocation);
	myfile << version;
	myfile.close();
	//---------------------------- Write Version File ----------------------------

	return 0;
}