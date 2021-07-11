#include <concepts>
#include <cstddef>
#include <iostream>
#include <string>

template < typename INT_TYPE >
concept UnsignedIntegerType = std::is_integral_v< INT_TYPE >&& std::is_unsigned_v< INT_TYPE >;

template < UnsignedIntegerType INT_TYPE >
constexpr INT_TYPE bit( std::uint8_t shift ) noexcept( false )
{
	if( shift == 0 )
	{
		return {};
	}

	if( shift > sizeof( INT_TYPE ) * 8 )
	{
		throw std::logic_error( "Bit shift can't be larger then the size of type in bits." );
	}

	INT_TYPE i { 1 };
	i <<= ( shift - 1 );
	return i;
}

enum Test
{
	t1 = bit< std::uint32_t >( 1 ),
	t2 = bit< std::uint32_t >( 2 )
};

template < typename FRUIT_TYPE >
concept Fruit = requires( FRUIT_TYPE f )
{
	{
		f.type()
	}
	->std::convertible_to< std::string >;
};

class Apple
{
public:
	std::string type()
	{
		return { "Apple" };
	}
};

class Banana
{
public:
	std::string sample()
	{
		return {};
	}
};

template < Fruit F >
void test( F f )
{
	std::cout << f.type() << std::endl;
}

int main( int argc, char* argv[] )
{
	Apple a;
	Banana b;

	test( a );
	// test( b ); // Won't compile

	return 0;
}
