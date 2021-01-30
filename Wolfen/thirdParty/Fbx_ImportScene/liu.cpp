#include "wfpch.h"

#include "PackageHeader.h"
#include "Wolfen/File.h"


#define UNUSED_VAR(x) ((void *)x)

//---------------------------------------------------------------------------
// Leave this signature - do your LIU magic here
// Feel free to add files and methods to this project
//---------------------------------------------------------------------------

namespace Wolfen
{
	//todo -- combine liu and vodka and put into fbx import scene, make that its own project, only output the final compressed file types to read in at startup
	//todo maybe combine this with eat and vodka now too since its no longer going to be its own executable? at least combine with vodka...
	//todo implement this and change filename to .wfx or some shit
	//todo implement this and change filename to .wfx or some shit

	//int writeSpu( const char* bloStr, File::Handle spuFh )
	//{

	//	File::Handle bloFh( nullptr );
	//	DWORD fSize;
	//	File::Error msg;

	//	//open and get tot size of blo file
	//	msg = File::Open( bloFh, bloStr, File::Mode::READ_WRITE );
	//	assert( msg == File::Error::SUCCESS );

	//	msg = File::Seek( bloFh, File::Location::END, 0 );
	//	assert( msg == File::Error::SUCCESS );

	//	msg = File::Tell( bloFh, fSize );
	//	assert( msg == File::Error::SUCCESS );

	//	//seek back to begin and write to end of spu file
	//	msg = File::Seek( bloFh, File::Location::BEGIN, 0 );
	//	assert( msg == File::Error::SUCCESS );

	//	unsigned char* buffer = new unsigned char[(unsigned int)fSize];
	//	msg = File::Read( bloFh, buffer, fSize );
	//	assert( msg == File::Error::SUCCESS );

	//	msg = File::Seek( spuFh, File::Location::END, 0 );
	//	assert( msg == File::Error::SUCCESS );

	//	msg = File::Write( spuFh, buffer, fSize );
	//	assert( msg == File::Error::SUCCESS );

	//	//close .blo file 
	//	File::Close( bloFh );
	//	assert( msg == File::Error::SUCCESS );


	//	return (unsigned int)fSize;

	//}

	//int ReadIn( int argc, char* argv[] )
	//{
	//	PackageHeader package;
	//	int argName = 0;
	//	int argVer = 0;

	//	if( argc > 5 )
	//	{
	//		size_t nameSize = package.PACKAGE_NAME_SIZE;
	//		size_t verSize = package.PACKAGE_VERSION_SIZE;

	//		for( int i = 0; i < argc; i++ )
	//		{
	//			if( strncmp( (char*)argv[i], "-n", nameSize ) == 0 )
	//			{
	//				//strcpy_s(&package.packageName[0],PackageHeader::PACKAGE_NAME_SIZE, (char*)argv[i + 1]);
	//				argName = (i + 1);

	//			}

	//			else if( strncmp( (char*)argv[i], "-v", verSize ) == 0 )
	//			{
	//				//strcpy_s(&package.versionString[0],PackageHeader::PACKAGE_VERSION_SIZE, (char*)argv[i + 1]);
	//				argVer = (i + 1);

	//			}
	//		}
	//	}

	//	//create the spu file from cmd args
	//	File::Handle spuFh( nullptr );
	//	File::Error msg;
	//	//unsigned char* buffer = new unsigned char[sizeof(package)];

	//	if( package.packageName )
	//	{
	//		msg = File::Open( spuFh, argv[1], File::Mode::READ_WRITE );
	//		assert( msg == File::Error::SUCCESS );

	//		msg = File::Write( spuFh, &package, sizeof( package ) );
	//		assert( msg == File::Error::SUCCESS );

	//	}

	//	//find all blo files and add to list
	//	WIN32_FIND_DATA  fd;
	//	HANDLE fh;
	//	std::string str( "" );
	//	fh = ::FindFirstFileA( "*.blo", &fd );
	//	std::vector<std::string> list;
	//	int spuTotal = 0;
	//	int numFiles = 0;

	//	//if it could find blo files itr through
	//	if( fh )
	//	{
	//		str = fd.cFileName;
	//		list.push_back( str );
	//		//printf("filename is : %s\n", str.c_str());
	//		//numFiles++;

	//		//use find next to itr through blo files and add them to the spu file
	//		do
	//		{
	//			str = fd.cFileName;
	//			printf( "filename is : %s\n", str.c_str() );

	//			spuTotal += writeSpu( str.c_str(), spuFh );
	//			numFiles++;

	//		} while( ::FindNextFileA( fh, &fd ) );

	//	}

	//	//need to go back and rewrite chunk header
	//	strcpy_s( &package.packageName[0], PackageHeader::PACKAGE_NAME_SIZE, (char*)argv[argName] );
	//	strcpy_s( &package.versionString[0], PackageHeader::PACKAGE_VERSION_SIZE, (char*)argv[argVer] );

	//	strcpy_s( package.versionString, argv[argVer] );
	//	package.numChunks = numFiles;
	//	package.totalSize = spuTotal;

	//	msg = File::Seek( spuFh, File::Location::BEGIN, 0 );
	//	msg = File::Write( spuFh, &package, sizeof( PackageHeader ) );
	//	assert( msg == File::Error::SUCCESS );



	//	File::Close( spuFh );

	//	int i = 0;
	//	i = 1;

	//	return 0;
	//}
}

// End of file
