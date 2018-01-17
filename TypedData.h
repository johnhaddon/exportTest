#pragma once

#include <vector>
#include <map>

#include "Export.h"
#include "RefCounted.h"

namespace ExportTest
{

typedef std::map<int, RefCountedPtr> MapType;

// We don't want to provide any visibility attributes for
// the template class itself, because different libraries
// will instantiate it with different types, and we want
// each library to export the symbols for its own instantiations.
template<typename T>
class EXPORTTEST_EXPORT TypedData
{

	public :

		typedef T ValueType;

		ValueType &writable();

	private :

		ValueType m_value;

};

typedef TypedData<MapType> MapTypedData;

};
