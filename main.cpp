#include <concepts>
#include <cstddef>
#include <iostream>

template < typename INT_TYPE >
concept UnsignedInteger = std::is_integral_v< INT_TYPE >&& std::is_unsigned_v< INT_TYPE >;

template < UnsignedInteger INT_TYPE >
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

int main( int argc, char* argv[] )
{
	return 0;
}
