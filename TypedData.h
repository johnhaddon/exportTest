#pragma once

#include <vector>

#include "Export.h"

namespace ExportTest
{

// We don't want to provide any visibility attributes for
// the template class itself, because different libraries
// will instantiate it with different types, and we want
// each library to export the symbols for its own instantiations.
template<typename T>
class EXPORTTEST_EXPORT TypedData
{

	public :

		typedef std::vector<T> ValueType;

		ValueType &writable();

	private :

		ValueType m_value;

};

typedef TypedData<int> IntTypedData;

};
