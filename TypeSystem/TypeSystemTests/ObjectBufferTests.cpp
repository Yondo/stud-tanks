#include "stdafx.h"
#include "CppUnitTest.h"

#include "../TypeSystem/ObjectBuffer.h"
#include "../TypeSystem/Pointer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace fakeit;

namespace TypeSystemTests
{		
	TEST_CLASS(ObjectBufferTests)
	{
	public:
		
		TEST_METHOD(createObjectBuffer)
		{
			Mock<Object> mockObject;
			Mock<Pointer<Object>> mockPointerToObject;
			
			size_t callCounterObject = 0;
			size_t callCounterPointerToObject = 0;

			When(Dtor(mockObject)).Do( [&callCounterObject] ()
			{ ++callCounterObject; } );
			When(Dtor(mockPointerToObject)).Do( [&callCounterPointerToObject] ()
			{ ++callCounterPointerToObject; } );

			vector<Pointer<Object>*> buffer;
			buffer.push_back(&(mockPointerToObject.get()));

			auto objectBuffer = make_shared<ObjectBuffer>(ObjectBuffer(buffer));

			(mockObject.get()).~Object();
			((objectBuffer.get())->getPointerToObject(0))->~Pointer();

			Assert::AreEqual<size_t>(1, callCounterObject, L"Destructor not was called.");
			Assert::AreEqual<size_t>(1, callCounterPointerToObject, L"Destructor not was called.");
		}

		TEST_METHOD(addObjectTest)
		{
			Mock<Object> mockObject;
			Mock<Pointer<Object>> mockPointerToObject;
			
			size_t callCounterObject = 0;
			size_t callCounterPointerToObject = 0;

			When(Dtor(mockObject)).Do( [&callCounterObject] ()
			{ ++callCounterObject; } );
			When(Dtor(mockPointerToObject)).Do( [&callCounterPointerToObject] ()
			{ ++callCounterPointerToObject; } );

			vector<Pointer<Object>*> buffer;
			buffer.push_back(&(mockPointerToObject.get()));

			auto objectBuffer = make_shared<ObjectBuffer>(ObjectBuffer(buffer));

			(objectBuffer.get())->addObject(&(mockPointerToObject.get()));

			(mockObject.get()).~Object();
			((objectBuffer.get())->getPointerToObject(1))->~Pointer();

			Assert::AreEqual<size_t>(1, callCounterObject, L"Destructor not was called.");
			Assert::AreEqual<size_t>(1, callCounterPointerToObject, L"Destructor not was called.");
		}
	};
}
