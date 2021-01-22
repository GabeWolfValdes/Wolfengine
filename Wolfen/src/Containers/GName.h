#pragma once

#include <string_view>
#include <string>


// class to be used as a way to quickly compare strings. uses a map 
namespace Wolfen
{

	class Name
	{
	public:

		//Name( std::string_view<CharT>& );
		Name( const char* inStr, int length );
		Name( const Name& inName );
		const Name& operator= ( const Name& );
		~Name();

	private:
		int GenerateHashVal( char* inStr );
					
	private:
		int hashVal;
}