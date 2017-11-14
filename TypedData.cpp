#include "TypedData.h"
#include "Export.h"

namespace ExportTest
{

// Ideally we want to hide the implementation in .cpp files
// like this, so we're not parsing a whole load of bloat all
// the time, and so we don't ever have to worry about folks
// using TypedData<T> without first including another header
// which defines the appropriate specialisations for T.
template<typename T>
typename TypedData<T>::ValueType &TypedData<T>::writable()
{
	return m_value;
}

#if 1

// We need to define specialisations for some types, and this
// is the crux of our problem. If we define this specialisation,
// then GCC won't export our symbols any more.
template<>
typename TypedData<int>::ValueType &TypedData<int>::writable()
{
	m_value = { 10 };
	return m_value;
}

#endif

} // namespace ExportTest

// Explicitly instantiate the template, specifying that is is
// visible as part of the API.
template class EXPORTTEST_API ExportTest::TypedData<int>;
