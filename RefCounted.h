//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2014, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef IE_CORE_REFCOUNTED_H
#define IE_CORE_REFCOUNTED_H

#include "tbb/atomic.h"

#include "Export.h"

#include "boost/noncopyable.hpp"

EXPORTTEST_PUSH_DEFAULT_VISIBILITY

#include "boost/intrusive_ptr.hpp"

EXPORTTEST_POP_DEFAULT_VISIBILITY

namespace ExportTest
{

class EXPORTTEST_API RefCounted : private boost::noncopyable
{
	public:

		typedef size_t RefCount;

		RefCounted();

		/// Add a reference to the current object
		inline void addRef() const { m_numRefs++; };

		/// Remove a reference from the current object
		inline void removeRef() const
		{
			assert( m_numRefs > 0 );
			if( --m_numRefs==0 )
			{
				delete this;
			}
		};

		/// Returns the current reference count.
		inline RefCount refCount() const { return m_numRefs; };

	protected:

		virtual ~RefCounted();

	private :

		mutable tbb::atomic<RefCount> m_numRefs;

};

inline void intrusive_ptr_add_ref( const RefCounted *r )
{
	r->addRef();
}

inline void intrusive_ptr_release( const RefCounted *r )
{
	r->removeRef();
}

typedef boost::intrusive_ptr<RefCounted> RefCountedPtr;

} // namespace ExportTest


#endif // IE_CORE_REFCOUNTED_H
