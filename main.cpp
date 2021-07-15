
#include "ConceptExamples.hpp"

void conceptExample();

int main( int argc, char* argv[] )
{
	conceptExample();
	return 0;
}

void conceptExample()
{
	Apple a;
	Banana b;

	test( a );
	// test( b ); // Won't compile
}
