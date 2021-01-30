#include "wfpch.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Wolfen/File.h"
#include "ChunkHeader.h"
#include <stdio.h>
#include "md5.h"

namespace Wolfen
{
	int vodka( int argc, char* argv[] )
	{
		ChunkHeader chunk;

		if( argc == 7 )
		{

			size_t cmpName = chunk.CHUNK_NAME_SIZE;

			//loop through to get cmd line inputs
			for( int i = 0; i < argc; i++ )
			{
				//if -n save the next param to name
				if( strncmp( argv[i], "-n", cmpName ) == 0 )
				{
					strcpy_s( &chunk.chunkName[0], ChunkHeader::CHUNK_NAME_SIZE, argv[i + 1] );
					printf( "Chunk name is: %s \n", argv[i + 1] );
				}

				//if -t save type to chunk type
				if( strncmp( argv[i], "-t", cmpName ) == 0 )
				{

					if( strncmp( (char*)argv[i + 1], "VERTS_TYPE", cmpName ) == 0 )
					{
						chunk.type = ChunkType::VERTS_TYPE;
						printf( "Chunk type is: VERTS_TYPE\n" );// %s \n", argv[i + 1]);
					}

					else if( strncmp( (char*)argv[i + 1], "NORMS_TYPE", cmpName ) == 0 )
					{
						chunk.type = ChunkType::NORMS_TYPE;
						printf( "Chunk type is: NORMS_TYPE\n" );// %s \n", argv[i + 1]);
					}

					else if( strncmp( (char*)argv[i + 1], "ANIM_TYPE", cmpName ) == 0 )
					{
						chunk.type = ChunkType::ANIM_TYPE;
						printf( "Chunk type is: ANIM_TYPE\n" );// %s \n", argv[i + 1]);
					}

					else if( strncmp( (char*)argv[i + 1], "HEIRARCHY_TYPE", cmpName ) == 0 )
					{
						chunk.type = ChunkType::HEIRARCHY_TYPE;
						printf( "Chunk type is: HEIRARCHY_TYPE\n" );// %s \n", argv[i + 1]);
					}
					else if( strncmp( (char*)argv[i + 1], "SKIN_TYPE", cmpName ) == 0 )
					{
						chunk.type = ChunkType::SKIN_TYPE;
						printf( "Chunk type is: SKIN_TYPE\n" );// %s \n", argv[i + 1]);
					}
					else if( strncmp( (char*)argv[i + 1], "VBO_TYPE", cmpName ) == 0 )
					{
						chunk.type = ChunkType::VBO_TYPE;
						printf( "Chunk type is: VBO_TYPE\n" );// %s \n", argv[i + 1]);
					}
					else if( strncmp( (char*)argv[i + 1], "TEXTURE_TYPE", cmpName ) == 0 )
					{
						chunk.type = ChunkType::TEXTURE_TYPE;
						printf( "Chunk type is: TEXTURE_TYPE\n" );// %s \n", argv[i + 1]);
					}

					else if( strncmp( (char*)argv[i + 1], "UV_TYPE", cmpName ) == 0 )
					{
						chunk.type = ChunkType::UV_TYPE;
						printf( "Chunk type is: UV_TYPE\n" );// %s \n", argv[i + 1]);
					}

					else
					{
						//make this an error message call
						printf( "THIS IS AN ERROR MESSAGE!!\nThe input of this function is inFile.bin outFile.blo -n chunkName -t chunkType\n" );
						return -1;
					}
				}


				//file stuff
				File::Handle fh( nullptr );
				//File::Handle blo(nullptr);
				File::Error msg;
				DWORD fSize;
				MD5Output output;
				//DWORD offset(0);


				//open file
				msg = File::Open( fh, (char*)argv[1], File::Mode::READ );
				assert( msg == File::Error::SUCCESS );

				//seek to end to get size of file
				msg = File::Seek( fh, File::Location::END, 0 );
				assert( msg == File::Error::SUCCESS );

				msg = File::Tell( fh, fSize );
				assert( msg == File::Error::SUCCESS );

				chunk.chunkSize = (unsigned int)fSize;

				//go back to beginning of file to read into buffer
				msg = File::Seek( fh, File::Location::BEGIN, 0 );
				assert( msg == File::Error::SUCCESS );


				//read buffer and then hash using md5
				unsigned char* buffer = new unsigned char[chunk.chunkSize];

				msg = File::Read( fh, buffer, chunk.chunkSize );
				assert( msg == File::Error::SUCCESS );

				MD5Buffer( buffer, chunk.chunkSize, output );
				chunk.hashNum = output.dWord_0 ^ output.dWord_1 ^ output.dWord_2 ^ output.dWord_3;

				//close file
				msg = File::Close( fh );
				assert( msg == File::Error::SUCCESS );

				//create new file to write into 
				msg = File::Open( fh, (char*)argv[2], File::Mode::READ_WRITE );
				assert( msg == File::Error::SUCCESS );

				msg = File::Write( fh, &chunk, sizeof( ChunkHeader ) );
				assert( msg == File::Error::SUCCESS );

				msg = File::Write( fh, buffer, chunk.chunkSize );
				assert( msg == File::Error::SUCCESS );

				//close up files

				msg = File::Close( fh );
				assert( msg == File::Error::SUCCESS );


			}
		}

		return 0;
	}
}

// End of File
