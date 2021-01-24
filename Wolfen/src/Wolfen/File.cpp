#include "wfpch.h"
#include "File.h"

namespace Wolfen
{
	File::Error File::Open( File::Handle& fh, const char* const fileName, File::Mode mode ) noexcept
	{
		HANDLE result;

		switch( mode )
		{
		case File::Mode::READ:
			result = ::CreateFileA( fileName, GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, fh );
			break;
		case File::Mode::WRITE:
			result = ::CreateFileA( fileName, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, fh );
			break;
		case File::Mode::READ_WRITE:
			result = ::CreateFileA( fileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, fh );
			break;
		default:
			result = INVALID_HANDLE_VALUE;
			break;
		}

		File::Error returnMsg = File::Error::SUCCESS;
		if( result == INVALID_HANDLE_VALUE )
		{
			returnMsg = File::Error::OPEN_FAIL;
		}

		fh = (Handle*)result;

		return 	returnMsg;
	}

	File::Error File::Close( const File::Handle fh ) noexcept
	{
		File::Error result = File::Error::CLOSE_FAIL;

		bool close = ::CloseHandle( fh );

		if( close )
		{
			result = File::Error::SUCCESS;
		}

		return 	result;
	}

	File::Error File::Write( File::Handle fh, const void* const buffer, const DWORD inSize ) noexcept
	{

		File::Error result = File::Error::WRITE_FAIL;
		LPDWORD bytesWritten = 0;

		bool write = ::WriteFile( fh, buffer, inSize, bytesWritten, NULL );

		if( write )
		{
			result = File::Error::SUCCESS;
		}

		return result;
	}

	File::Error File::Read( File::Handle fh, void* const buffer, const DWORD inSize ) noexcept
	{
		File::Error result = File::Error::READ_FAIL;
		LPDWORD bytesRead = 0;

		bool read = ::ReadFile( fh, buffer, inSize, bytesRead, NULL );

		if( read )
		{
			result = File::Error::SUCCESS;
		}

		return result;
	}

	File::Error File::Seek( File::Handle fh, File::Location location, int offset ) noexcept
	{


		DWORD seek;
		File::Error result = File::Error::SEEK_FAIL;
		switch( location )
		{
		case File::Location::BEGIN:
			seek = ::SetFilePointer( fh, offset, NULL, FILE_BEGIN );
			break;
		case File::Location::CURRENT:
			seek = ::SetFilePointer( fh, offset, NULL, FILE_CURRENT );
			break;
		case File::Location::END:
			seek = ::SetFilePointer( fh, offset, NULL, FILE_END );
			break;
		default:
			seek = 0xFFFFFFFF;
			break;
		}

		if( seek != 0xFFFFFFFF )
		{
			result = File::Error::SUCCESS;
		}

		return 	result;
	}

	File::Error File::Tell( File::Handle fh, DWORD& offset ) noexcept
	{

		offset = ::SetFilePointer( fh, 0, NULL, FILE_CURRENT ) - ::SetFilePointer( fh, 0, NULL, FILE_BEGIN );
		File::Error result = Seek( fh, File::Location::BEGIN, (int)offset );
		if( result != File::Error::SUCCESS )
		{
			result = File::Error::TELL_FAIL;
		}


		return 	result;
	}

	File::Error File::Flush( File::Handle fh ) noexcept
	{

		File::Error result = File::Error::FLUSH_FAIL;


		bool flush = ::FlushFileBuffers( fh );

		if( flush )
		{
			result = File::Error::SUCCESS;
		}

		return 	result;
	}
}
