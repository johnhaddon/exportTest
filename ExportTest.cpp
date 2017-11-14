#include "TypedData.h"

using namespace ExportTest;

int main()
{
	IntTypedData *i = new IntTypedData;
	i->writable();
	return 0;
}
