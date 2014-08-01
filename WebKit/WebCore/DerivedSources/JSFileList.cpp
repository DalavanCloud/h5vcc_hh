/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSFileList.h"

#include "ExceptionCode.h"
#include "File.h"
#include "FileList.h"
#include "JSFile.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/PropertyNameArray.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSFileList);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSFileListTableValues[3] =
{
    { "length", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileListLength), (intptr_t)0 THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsFileListConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSFileListTable = { 5, 3, JSFileListTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSFileListConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSFileListConstructorTable = { 1, 0, JSFileListConstructorTableValues, 0 };
class JSFileListConstructor : public DOMConstructorObject {
public:
    JSFileListConstructor(JSC::ExecState*, JSDOMGlobalObject*);

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSFileListConstructor::s_info = { "FileListConstructor", 0, &JSFileListConstructorTable, 0 };

JSFileListConstructor::JSFileListConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(JSFileListConstructor::createStructure(globalObject->objectPrototype()), globalObject)
{
    putDirect(exec->propertyNames().prototype, JSFileListPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSFileListConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSFileListConstructor, DOMObject>(exec, &JSFileListConstructorTable, this, propertyName, slot);
}

bool JSFileListConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSFileListConstructor, DOMObject>(exec, &JSFileListConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSFileListPrototypeTableValues[2] =
{
    { "item", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsFileListPrototypeFunctionItem), (intptr_t)1 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSFileListPrototypeTable = { 2, 1, JSFileListPrototypeTableValues, 0 };
const ClassInfo JSFileListPrototype::s_info = { "FileListPrototype", 0, &JSFileListPrototypeTable, 0 };

JSObject* JSFileListPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSFileList>(exec, globalObject);
}

bool JSFileListPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSFileListPrototypeTable, this, propertyName, slot);
}

bool JSFileListPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSFileListPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSFileList::s_info = { "FileList", 0, &JSFileListTable, 0 };

JSFileList::JSFileList(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<FileList> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSFileList::~JSFileList()
{
    forgetDOMObject(this, impl());
}

JSObject* JSFileList::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSFileListPrototype(globalObject, JSFileListPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSFileList::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    const HashEntry* entry = JSFileListTable.entry(exec, propertyName);
    if (entry) {
        slot.setCustom(this, entry->propertyGetter());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<FileList*>(impl())->length()) {
        slot.setCustomIndex(this, index, indexGetter);
        return true;
    }
    return getStaticValueSlot<JSFileList, Base>(exec, &JSFileListTable, this, propertyName, slot);
}

bool JSFileList::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    const HashEntry* entry = JSFileListTable.entry(exec, propertyName);
    if (entry) {
        PropertySlot slot;
        slot.setCustom(this, entry->propertyGetter());
        descriptor.setDescriptor(slot.getValue(exec, propertyName), entry->attributes());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<FileList*>(impl())->length()) {
        PropertySlot slot;
        slot.setCustomIndex(this, index, indexGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), DontDelete | ReadOnly);
        return true;
    }
    return getStaticValueDescriptor<JSFileList, Base>(exec, &JSFileListTable, this, propertyName, descriptor);
}

bool JSFileList::getOwnPropertySlot(ExecState* exec, unsigned propertyName, PropertySlot& slot)
{
    if (propertyName < static_cast<FileList*>(impl())->length()) {
        slot.setCustomIndex(this, propertyName, indexGetter);
        return true;
    }
    return getOwnPropertySlot(exec, Identifier::from(exec, propertyName), slot);
}

JSValue jsFileListLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileList* castedThis = static_cast<JSFileList*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    FileList* imp = static_cast<FileList*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->length());
    return result;
}

JSValue jsFileListConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSFileList* domObject = static_cast<JSFileList*>(asObject(slotBase));
    return JSFileList::getConstructor(exec, domObject->globalObject());
}
void JSFileList::getOwnPropertyNames(ExecState* exec, PropertyNameArray& propertyNames, EnumerationMode mode)
{
    for (unsigned i = 0; i < static_cast<FileList*>(impl())->length(); ++i)
        propertyNames.add(Identifier::from(exec, i));
     Base::getOwnPropertyNames(exec, propertyNames, mode);
}

JSValue JSFileList::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSFileListConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsFileListPrototypeFunctionItem(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSFileList::s_info))
        return throwVMTypeError(exec);
    JSFileList* castedThis = static_cast<JSFileList*>(asObject(thisValue));
    FileList* imp = static_cast<FileList*>(castedThis->impl());
    int index = exec->argument(0).toInt32(exec);
    if (index < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return JSValue::encode(jsUndefined());
    }


    JSC::JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->item(index)));
    return JSValue::encode(result);
}


JSValue JSFileList::indexGetter(ExecState* exec, JSValue slotBase, unsigned index)
{
    JSFileList* thisObj = static_cast<JSFileList*>(asObject(slotBase));
    return toJS(exec, thisObj->globalObject(), static_cast<FileList*>(thisObj->impl())->item(index));
}
JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, FileList* object)
{
    return getDOMObjectWrapper<JSFileList>(exec, globalObject, object);
}
FileList* toFileList(JSC::JSValue value)
{
    return value.inherits(&JSFileList::s_info) ? static_cast<JSFileList*>(asObject(value))->impl() : 0;
}

}