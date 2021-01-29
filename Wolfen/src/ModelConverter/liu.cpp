//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
//#include <string.h>
//#include <vector>
#include <assert.h>

#include "PackageHeader.h"
#include "File.h"


#define UNUSED_VAR(x) ((void *)x)

//---------------------------------------------------------------------------
// Leave this signature - do your LIU magic here
// Feel free to add files and methods to this project
//---------------------------------------------------------------------------

int writeSpu(const char* bloStr, File::Handle spuFh) {

	File::Handle bloFh(nullptr);
	DWORD fSize;
	File::Error msg;

	//open and get tot size of blo file
	msg = File::Open(bloFh, bloStr, File::Mode::READ_WRITE);
	assert(msg == File::Error::SUCCESS);

	msg = File::Seek(bloFh,File::Location::END, 0);
	assert(msg == File::Error::SUCCESS);

	msg = File::Tell(bloFh,fSize);
	assert(msg == File::Error::SUCCESS);

	//seek back to begin and write to end of spu file
	msg = File::Seek(bloFh,File::Location::BEGIN,0);
	assert(msg == File::Error::SUCCESS);

	unsigned char* buffer = new unsigned char[(unsigned int)fSize];
	msg = File::Read(bloFh,buffer, fSize);
	assert(msg == File::Error::SUCCESS);

	msg = File::Seek(spuFh,File::Location::END,0);
	assert(msg == File::Error::SUCCESS);

	msg = File::Write(spuFh,buffer,fSize);
	assert(msg == File::Error::SUCCESS);

	//close .blo file 
	File::Close(bloFh);
	assert(msg == File::Error::SUCCESS);


	return (unsigned int)fSize;

}




int main(int argc, char *argv[])
{
	PackageHeader package;
	//strcpy_s( package.packageName,PackageHeader::PACKAGE_NAME_SIZE, "did not copy" );
	//strcpy_s(package.versionString, PackageHeader::PACKAGE_VERSION_SIZE, "did not copy");
	int argName = 0;
	int argVer = 0;
	//first retrieve command line arguments

	//for (int i = 0; i < 7; i++) {
	//	printf("Argument %d  is: %s\n", i, argv[i]);
	//}
	//system("pause");

	if (argc > 5) {
		size_t nameSize = package.PACKAGE_NAME_SIZE;
		size_t verSize = package.PACKAGE_VERSION_SIZE;

		for (int i = 0; i < argc; i++) {
			if (strncmp((char*)argv[i], "-n",nameSize) == 0) {
				//strcpy_s(&package.packageName[0],PackageHeader::PACKAGE_NAME_SIZE, (char*)argv[i + 1]);
				argName = (i + 1);

			}

			else if (strncmp((char*)argv[i], "-v", verSize) == 0) {
				//strcpy_s(&package.versionString[0],PackageHeader::PACKAGE_VERSION_SIZE, (char*)argv[i + 1]);
				argVer = (i+1);

			}
		}
	}

	//create the spu file from cmd args
	File::Handle spuFh(nullptr);
	File::Error msg;
	//unsigned char* buffer = new unsigned char[sizeof(package)];

	if (package.packageName) {
		msg = File::Open(spuFh, argv[1] ,File::Mode::READ_WRITE);
		assert(msg  == File::Error::SUCCESS);

		msg = File::Write(spuFh,&package,sizeof(package));
		assert(msg == File::Error::SUCCESS);

	}

	//find all blo files and add to list
	WIN32_FIND_DATA  fd;
	HANDLE fh;
	std::string str("");
	fh = ::FindFirstFileA("*.blo", &fd);
	std::deque<std::string> list;
	int spuTotal = 0;
	int numFiles = 0;

	//if it could find blo files itr through
	if (fh) {
		str = fd.cFileName;
		list.push_back(str);
		//printf("filename is : %s\n", str.c_str());
		//numFiles++;

		//use find next to itr through blo files and add them to the spu file
		 do{
			str = fd.cFileName;
			printf("filename is : %s\n", str.c_str());

			spuTotal += writeSpu(str.c_str(), spuFh);
			numFiles++;

		 } while (::FindNextFileA(fh, &fd));

	}

	//need to go back and rewrite chunk header
	//strcpy_s(package.packageName, argv[argName]);
	strcpy_s(&package.packageName[0], PackageHeader::PACKAGE_NAME_SIZE, (char*)argv[argName]);
	strcpy_s(&package.versionString[0], PackageHeader::PACKAGE_VERSION_SIZE, (char*)argv[argVer]);

	strcpy_s(package.versionString, argv[argVer]);
	package.numChunks = numFiles;
	package.totalSize = spuTotal;

	//printf("chunk name is : %s\n",package.packageName);
	//system("pause");
	//printf("chunk ver is : %s\n", package.versionString);
	//system("pause");


	msg = File::Seek(spuFh, File::Location::BEGIN,0);
	msg = File::Write(spuFh, &package, sizeof(PackageHeader));
	assert(msg == File::Error::SUCCESS);



	File::Close(spuFh);

	//return list;

	//std::deque<std::string> list = File::Search("*.blo");
	//auto iter = list.begin;
	int i = 0;
	i = 1;

	UNUSED_VAR(argc);
	UNUSED_VAR(argv);

	return 0;
}

// End of file
