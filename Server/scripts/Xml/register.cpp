// Author: Grzegorz "Atom" Jagiella
// This file is public domain.

#include "tinyxml.h"
#include "factory.h"
#include "../fonline.h"

#define BIND_CLASS BindClass::

extern int XmlTextId;
extern int XmlNodeId;
extern int XmlUnknownId;
extern int XmlAttributeId;
extern int XmlCommentId;
extern int XmlDeclarationId;
extern int XmlElementId;
extern int XmlDocumentId;

struct BindClass
{
	/* Support functions */
#define XmlNode_To(name, type)												\
	TiXml##name* XmlNode_To##name(T* node)									\
	{																		\
		return node->Type() == TiXmlNode::type ? (TiXml##name*)node : NULL;	\
	}																		\

	template<class T>
	static XmlNode_To(Document,    TINYXML_DOCUMENT)

	template<class T>
	static XmlNode_To(Element,     TINYXML_ELEMENT)

	template<class T>
	static XmlNode_To(Comment,     TINYXML_COMMENT)

	template<class T>
	static XmlNode_To(Unknown,     TINYXML_UNKNOWN)

	template<class T>
	static XmlNode_To(Text,        TINYXML_TEXT)

	template<class T>
	static XmlNode_To(Declaration, TINYXML_DECLARATION)

	/* ScriptString wrappers */

	/* XmlNode and derived */
	template<class T>
	static ScriptString* XmlNode_Value(T* node)
	{
		return NewString(node->Value());
	}

	template<class T>
	static TiXmlNode* XmlNode_FirstChild(T* node, ScriptString& value)
	{
		return node->FirstChild(value.c_str());
	}

	template<class T>
	static TiXmlNode* XmlNode_LastChild(T* node, ScriptString& value)
	{
		return node->LastChild(value.c_str());
	}

	template<class T>
	static TiXmlNode* XmlNode_IterateChildren(T* node, ScriptString& value, TiXmlNode* previous)
	{
		return node->IterateChildren(value.c_str(), previous);
	}

	template<class T>
	static TiXmlNode* XmlNode_PreviousSibling(T* node, ScriptString& value)
	{
		return node->PreviousSibling(value.c_str());
	}

	template<class T>
	static TiXmlElement* XmlNode_NextSiblingElement(T* node, ScriptString& value)
	{
		return node->NextSiblingElement(value.c_str());
	}

	template<class T>
	static TiXmlNode* XmlNode_NextSibling(T* node, ScriptString& value)
	{
		return node->NextSibling(value.c_str());
	}

	template<class T>
	static TiXmlElement* XmlNode_FirstChildElement(T* node, ScriptString& value)
	{
		return node->FirstChildElement(value.c_str());
	}

	/* XmlAttribute */
	static ScriptString* XmlAttribute_Name(TiXmlAttribute* attr)
	{
		return NewString(attr->Name());
	}

	static ScriptString* XmlAttribute_Value(TiXmlAttribute* attr)
	{
		return NewString(attr->Value());
	}

	static int XmlAttribute_Compare(TiXmlAttribute* attr, const TiXmlAttribute& other)
	{
		if(*attr<other) return -1;
		if(other<*attr) return 1;
		return 0;
	}

	/* XmlDeclaration */
	static ScriptString* XmlDeclaration_Version(TiXmlDeclaration* declaration)
	{
		return NewString(declaration->Version());
	}

	static ScriptString* XmlDeclaration_Encoding(TiXmlDeclaration* declaration)
	{
		return NewString(declaration->Encoding());
	}

	static ScriptString* XmlDeclaration_Standalone(TiXmlDeclaration* declaration)
	{
		return NewString(declaration->Standalone());
	}

	/* XmlElement */
	static ScriptString* XmlElement_Atribute(TiXmlElement* element, ScriptString& name)
	{
		return NewString(element->Attribute(name.c_str()));
	}

	static ScriptString* XmlElement_Atribute(TiXmlElement* element, ScriptString& name, int& i)
	{
		return NewString(element->Attribute(name.c_str(), &i));
	}

	static ScriptString* XmlElement_Atribute(TiXmlElement* element, ScriptString& name, double& d)
	{
		return NewString(element->Attribute(name.c_str(), &d));
	}

	static int XmlElement_QueryIntAttribute(TiXmlElement* element, ScriptString& name, int& value)
	{
		return element->QueryIntAttribute(name.c_str(), &value);
	}

	static int XmlElement_QueryUnsignedAttribute(TiXmlElement* element, ScriptString& name, unsigned int& value)
	{
		return element->QueryUnsignedAttribute(name.c_str(), &value);
	}

	static int XmlElement_QueryBoolAttribute(TiXmlElement* element, ScriptString& name, bool& value)
	{
		return element->QueryBoolAttribute(name.c_str(), &value);
	}

	static int XmlElement_QueryDoubleAttribute(TiXmlElement* element, ScriptString& name, double& value)
	{
		return element->QueryDoubleAttribute(name.c_str(), &value);
	}

	static int XmlElement_QueryFloatAttribute(TiXmlElement* element, ScriptString& name, float& value)
	{
		return element->QueryFloatAttribute(name.c_str(), &value);
	}

	static ScriptString* XmlElement_GetText(TiXmlElement* element)
	{
		return NewString(element->GetText());
	}

	/* XmlDocument */
	static ScriptString* XmlDocument_ErrorDesc(TiXmlDocument* document)
	{
		return NewString(document->ErrorDesc());
	}

	static bool XmlDocument_LoadFile(TiXmlDocument* document, TiXmlEncoding encoding)
	{
		bool ret=document->LoadFile(encoding);
		ReleaseAll();
		return ret;
	}

	/* AS GC functions */

	static void XmlNode_EnumReferences(TiXmlNode* node, asIScriptEngine* engine)
	{
		engine->GCEnumCallback(node->parent.ptr);
		engine->GCEnumCallback(node->firstChild.ptr);
		engine->GCEnumCallback(node->lastChild.ptr);
		engine->GCEnumCallback(node->prev.ptr);
		engine->GCEnumCallback(node->next.ptr);
	}

	static void XmlNode_ReleaseAllReferences(TiXmlNode* node, asIScriptEngine* engine)
	{
		node->parent=NULL;
		node->firstChild=NULL;
		node->lastChild=NULL;
		node->prev=NULL;
		node->next=NULL;
	}

	static void XmlAttribute_EnumReferences(TiXmlAttribute* node, asIScriptEngine* engine)
	{
		engine->GCEnumCallback(node->document.ptr);
		engine->GCEnumCallback(node->prev.ptr);
		engine->GCEnumCallback(node->next.ptr);
	}

	static void XmlAttribute_ReleaseAllReferences(TiXmlAttribute* node, asIScriptEngine* engine)
	{
		node->document=NULL;
		node->prev=NULL;
		node->next=NULL;
	}

	static void XmlElement_EnumReferences(TiXmlElement* node, asIScriptEngine* engine)
	{
		XmlNode_EnumReferences(node, engine);
		XmlAttribute_EnumReferences(&(node->attributeSet.sentinel), engine);
	}

	static void XmlElement_ReleaseAllReferences(TiXmlElement* node, asIScriptEngine* engine)
	{
		XmlNode_ReleaseAllReferences(node, engine);
		node->attributeSet.sentinel.next=&(node->attributeSet.sentinel);
		node->attributeSet.sentinel.prev=&(node->attributeSet.sentinel);
		node->attributeSet.sentinel.document=NULL;
	}

	/* Global */

	static TiXmlDocument* Global_NewXmlDocument(ScriptString& name)
	{
		return NewTiXmlDocument(name.c_str());
	}
};

#define BIND_ASSERT(x)    if((x)<0) Log("XML bind error, line<%d>.\n", __LINE__ );

template<class T>
void RegisterNodeMethods_Native(asIScriptEngine* engine, const char* typeName)
{
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "string@ Value() const", asFUNCTION(BIND_CLASS XmlNode_Value<T>), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ Parent() const", asMETHODPR(T, Parent, (void), TiXmlNode*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ FirstChild() const", asMETHODPR(T, FirstChild, (void), TiXmlNode*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ FirstChild(string& value) const", asFUNCTION(BIND_CLASS XmlNode_FirstChild<T>), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ LastChild() const", asMETHODPR(T, LastChild, (void), TiXmlNode*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ LastChild(string& value) const", asFUNCTION(BIND_CLASS XmlNode_LastChild<T>), asCALL_CDECL_OBJFIRST));

	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ LastChild(XmlNode@+ previous) const", asMETHODPR(T, IterateChildren, (const TiXmlNode*), TiXmlNode*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ IterateChildren(string& value,  XmlNode@+ previous) const", asFUNCTION(BIND_CLASS XmlNode_IterateChildren<T>), asCALL_CDECL_OBJFIRST));

	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ PreviousSibling() const", asMETHODPR(T, PreviousSibling, (void), TiXmlNode*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ PreviousSibling(string& value) const", asFUNCTION(BIND_CLASS XmlNode_PreviousSibling<T>), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ NextSibling() const", asMETHODPR(T, NextSibling, (void), TiXmlNode*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNode@+ NextSibling(string& value) const", asFUNCTION(BIND_CLASS XmlNode_NextSibling<T>), asCALL_CDECL_OBJFIRST));

	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlElement@+ NextSiblingElement() const", asMETHODPR(T, NextSiblingElement, (void), TiXmlElement*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlElement@+ NextSiblingElement(string& value) const", asFUNCTION(BIND_CLASS XmlNode_NextSiblingElement<T>), asCALL_CDECL_OBJFIRST));

	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlElement@+ FirstChildElement() const", asMETHODPR(T, FirstChildElement, (void), TiXmlElement*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlElement@+ FirstChildElement(string& value) const", asFUNCTION(BIND_CLASS XmlNode_FirstChildElement<T>), asCALL_CDECL_OBJFIRST));

	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlNodeType Type() const", asMETHOD(T, Type), asCALL_THISCALL));

	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlDocument@+ GetDocument() const", asMETHODPR(T, GetDocument, (void), TiXmlDocument*), asCALL_THISCALL));

	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlDocument@+    ToDocument()    const",  asFUNCTION(BIND_CLASS XmlNode_ToDocument<T>),     asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlElement@+     ToElement()     const",  asFUNCTION(BIND_CLASS XmlNode_ToElement<T>),      asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlComment@+     ToComment()     const",  asFUNCTION(BIND_CLASS XmlNode_ToComment<T>),      asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlUnknown@+     ToUnknown()     const",  asFUNCTION(BIND_CLASS XmlNode_ToUnknown<T>),      asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlText@+        ToText()        const",  asFUNCTION(BIND_CLASS XmlNode_ToText<T>),         asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod(typeName, "XmlDeclaration@+ ToDeclaration() const",  asFUNCTION(BIND_CLASS XmlNode_ToDeclaration<T>),  asCALL_CDECL_OBJFIRST));
}

template<class A, class B>
B* RefCast(A* a)
{
    // If the handle already is a null handle, then just return the null handle
    if( !a ) return 0;

    // Now try to dynamically cast the pointer to the wanted type
    B* b = dynamic_cast<B*>(a);
    if( b != 0 )
    {
        // Since the cast was made, we need to increase the ref counter for the returned handle
        b->AddRef();
    }
    return b;
}

template<class Base, class Derived>
void RegisterInheritance_Native(asIScriptEngine* engine, const char* base, const char* derived)
{
	char buf[256];
	sprintf_s(buf, "%s@ f() const", derived);
	BIND_ASSERT(engine->RegisterObjectBehaviour(base,    asBEHAVE_REF_CAST,          buf, asFUNCTION((RefCast<Base, Derived>)), asCALL_CDECL_OBJLAST));
	sprintf_s(buf, "%s@ f() const", base);
	BIND_ASSERT(engine->RegisterObjectBehaviour(derived, asBEHAVE_IMPLICIT_REF_CAST, buf, asFUNCTION((RefCast<Derived, Base>)), asCALL_CDECL_OBJLAST));
}

// does not include asBEHAVE_ENUMREFS and asBEHAVE_RELEASEREFS
template<class T>
int RegisterGCType_Native(asIScriptEngine* engine, const char* name)
{
	int ret=engine->RegisterObjectType(name, 0, asOBJ_REF | asOBJ_GC);
	if(ret<0)
	{
		Log("Couldn't register type %s.\n",name);
		return ret;
	}
#ifdef XML_DEBUG
	printf("registered %s with id %d\n",name,ret);
#endif
	BIND_ASSERT(engine->RegisterObjectBehaviour(name, asBEHAVE_ADDREF, "void f()", asMETHOD(T, AddRef), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectBehaviour(name, asBEHAVE_RELEASE, "void f()", asMETHOD(T, Release), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectBehaviour(name, asBEHAVE_SETGCFLAG, "void f()", asMETHOD(T, SetGCFlag), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectBehaviour(name, asBEHAVE_GETGCFLAG, "bool f()", asMETHODPR(T, GetGCFlag, (void), bool), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectBehaviour(name, asBEHAVE_GETREFCOUNT, "int f()", asMETHODPR(T, GetRefCount, (void), int), asCALL_THISCALL));
	return ret;
}

void RegisterXml_Native(asIScriptEngine* engine, bool compiler)
{
	/* Enums */
	BIND_ASSERT(engine->RegisterEnum("XmlNodeType"));
	BIND_ASSERT(engine->RegisterEnumValue("XmlNodeType", "XML_DOCUMENT",    TiXmlNode::TINYXML_DOCUMENT   ));
	BIND_ASSERT(engine->RegisterEnumValue("XmlNodeType", "XML_ELEMENT",     TiXmlNode::TINYXML_ELEMENT    ));
	BIND_ASSERT(engine->RegisterEnumValue("XmlNodeType", "XML_COMMENT",     TiXmlNode::TINYXML_COMMENT    ));
	BIND_ASSERT(engine->RegisterEnumValue("XmlNodeType", "XML_UNKNOWN",     TiXmlNode::TINYXML_UNKNOWN    ));
	BIND_ASSERT(engine->RegisterEnumValue("XmlNodeType", "XML_TEXT",        TiXmlNode::TINYXML_TEXT       ));
	BIND_ASSERT(engine->RegisterEnumValue("XmlNodeType", "XML_DECLARATION", TiXmlNode::TINYXML_DECLARATION));
	BIND_ASSERT(engine->RegisterEnumValue("XmlNodeType", "XML_TYPECOUNT",   TiXmlNode::TINYXML_TYPECOUNT  ));

	BIND_ASSERT(engine->RegisterEnum("XmlAttributeQuery"));
	BIND_ASSERT(engine->RegisterEnumValue("XmlAttributeQuery", "XML_SUCCESS",      TIXML_SUCCESS     ));
	BIND_ASSERT(engine->RegisterEnumValue("XmlAttributeQuery", "XML_NO_ATTRIBUTE", TIXML_NO_ATTRIBUTE));
	BIND_ASSERT(engine->RegisterEnumValue("XmlAttributeQuery", "XML_WRONG_TYPE",   TIXML_WRONG_TYPE  ));

	BIND_ASSERT(engine->RegisterEnum("XmlEncoding"));
	BIND_ASSERT(engine->RegisterEnumValue("XmlEncoding", "XML_ENCODING_UNKNOWN", TIXML_ENCODING_UNKNOWN));
	BIND_ASSERT(engine->RegisterEnumValue("XmlEncoding", "XML_ENCODING_UTF8",    TIXML_ENCODING_UTF8   ));
	BIND_ASSERT(engine->RegisterEnumValue("XmlEncoding", "XML_ENCODING_LEGACY",  TIXML_ENCODING_LEGACY ));

	/* Types */
	XmlTextId=RegisterGCType_Native<TiXmlDocument>(engine,"XmlText");
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlText", asBEHAVE_ENUMREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_EnumReferences), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlText", asBEHAVE_RELEASEREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_ReleaseAllReferences), asCALL_CDECL_OBJFIRST));

	XmlNodeId=RegisterGCType_Native<TiXmlNode>(engine,"XmlNode");
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlNode", asBEHAVE_ENUMREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_EnumReferences), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlNode", asBEHAVE_RELEASEREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_ReleaseAllReferences), asCALL_CDECL_OBJFIRST));
	
	XmlUnknownId=RegisterGCType_Native<TiXmlUnknown>(engine,"XmlUnknown");
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlUnknown", asBEHAVE_ENUMREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_EnumReferences), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlUnknown", asBEHAVE_RELEASEREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_ReleaseAllReferences), asCALL_CDECL_OBJFIRST));

	XmlAttributeId=RegisterGCType_Native<TiXmlAttribute>(engine,"XmlAttribute");
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlAttribute", asBEHAVE_ENUMREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlAttribute_EnumReferences), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlAttribute", asBEHAVE_RELEASEREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlAttribute_ReleaseAllReferences), asCALL_CDECL_OBJFIRST));

	XmlCommentId=RegisterGCType_Native<TiXmlComment>(engine,"XmlComment");
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlComment", asBEHAVE_ENUMREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_EnumReferences), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlComment", asBEHAVE_RELEASEREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_ReleaseAllReferences), asCALL_CDECL_OBJFIRST));

	XmlDeclarationId=RegisterGCType_Native<TiXmlDeclaration>(engine,"XmlDeclaration");
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlDeclaration", asBEHAVE_ENUMREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_EnumReferences), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlDeclaration", asBEHAVE_RELEASEREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_ReleaseAllReferences), asCALL_CDECL_OBJFIRST));

	XmlElementId=RegisterGCType_Native<TiXmlElement>(engine,"XmlElement");
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlElement", asBEHAVE_ENUMREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlElement_EnumReferences), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlElement", asBEHAVE_RELEASEREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlElement_ReleaseAllReferences), asCALL_CDECL_OBJFIRST));

	XmlDocumentId=RegisterGCType_Native<TiXmlDocument>(engine,"XmlDocument");
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlDocument", asBEHAVE_ENUMREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_EnumReferences), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectBehaviour("XmlDocument", asBEHAVE_RELEASEREFS, "void f(int&in)", asFUNCTION(BIND_CLASS XmlNode_ReleaseAllReferences), asCALL_CDECL_OBJFIRST));

	/* Methods and properties */

	/* XmlNode */
	RegisterNodeMethods_Native<TiXmlNode>(engine, "XmlNode");

	/* XmlText */
	RegisterNodeMethods_Native<TiXmlText>(engine, "XmlText");
	RegisterInheritance_Native<TiXmlNode, TiXmlText>(engine, "XmlNode", "XmlText");
	BIND_ASSERT(engine->RegisterObjectMethod("XmlText", "bool CDATA() const", asMETHOD(TiXmlText, CDATA), asCALL_THISCALL));

	/* XmlUnknown */
	RegisterNodeMethods_Native<TiXmlUnknown>(engine, "XmlUnknown");
	RegisterInheritance_Native<TiXmlNode, TiXmlUnknown>(engine, "XmlNode", "XmlUnknown");

	/* XmlAttribute */
	BIND_ASSERT(engine->RegisterObjectMethod("XmlAttribute", "string@ Name() const", asFUNCTION(BIND_CLASS XmlAttribute_Name), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlAttribute", "string@ Value() const", asFUNCTION(BIND_CLASS XmlAttribute_Value), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlAttribute", "int IntValue() const",  asMETHOD(TiXmlAttribute, IntValue), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlAttribute", "double DoubleValue() const", asMETHOD(TiXmlAttribute, DoubleValue), asCALL_THISCALL));
	
	BIND_ASSERT(engine->RegisterObjectMethod("XmlAttribute", "XmlAttribute@+ Next() const", asMETHODPR(TiXmlAttribute, Next, (void), TiXmlAttribute*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlAttribute", "XmlAttribute@+ Previous() const", asMETHODPR(TiXmlAttribute, Previous, (void), TiXmlAttribute*), asCALL_THISCALL));

	BIND_ASSERT(engine->RegisterObjectMethod("XmlAttribute", "bool opEquals(const XmlAttribute& in other) const", asMETHOD(TiXmlAttribute, operator==), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlAttribute", "int opCmp(const XmlAttribute& in other) const", asFUNCTION(BIND_CLASS XmlAttribute_Compare), asCALL_CDECL_OBJFIRST));

	/* XmlComment */
	RegisterNodeMethods_Native<TiXmlComment>(engine, "XmlComment");
	RegisterInheritance_Native<TiXmlNode, TiXmlComment>(engine, "XmlNode", "XmlComment");

	/* XmlDeclaration */
	RegisterNodeMethods_Native<TiXmlDeclaration>(engine, "XmlDeclaration");
	RegisterInheritance_Native<TiXmlNode, TiXmlDeclaration>(engine, "XmlNode", "XmlDeclaration");
	BIND_ASSERT(engine->RegisterObjectMethod("XmlDeclaration", "string@ Version()", asFUNCTION(BIND_CLASS XmlDeclaration_Version),asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlDeclaration", "string@ Encoding()", asFUNCTION(BIND_CLASS XmlDeclaration_Encoding),asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlDeclaration", "string@ Standalone()", asFUNCTION(BIND_CLASS XmlDeclaration_Standalone),asCALL_CDECL_OBJFIRST));

	/* XmlElement */
	RegisterNodeMethods_Native<TiXmlElement>(engine, "XmlElement");
	RegisterInheritance_Native<TiXmlNode, TiXmlElement>(engine, "XmlNode", "XmlElement");

	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "string@ Attribute(string& name) const", asFUNCTIONPR(BIND_CLASS XmlElement_Atribute, (TiXmlElement*, ScriptString&), ScriptString*), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "string@ Attribute(string& name, int& i) const", asFUNCTIONPR(BIND_CLASS XmlElement_Atribute, (TiXmlElement*, ScriptString&, int&), ScriptString*), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "string@ Attribute(string& name, double& d) const", asFUNCTIONPR(BIND_CLASS XmlElement_Atribute, (TiXmlElement*, ScriptString&, double&), ScriptString*), asCALL_CDECL_OBJFIRST));
	
	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "XmlAttributeQuery QueryIntAttribute(string& name, int& value)", asFUNCTION(BIND_CLASS XmlElement_QueryIntAttribute), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "XmlAttributeQuery QueryUnsignedAttribute(string& name, uint& value)", asFUNCTION(BIND_CLASS XmlElement_QueryUnsignedAttribute), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "XmlAttributeQuery QueryBoolAttribute(string& name, bool& value)", asFUNCTION(BIND_CLASS XmlElement_QueryBoolAttribute), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "XmlAttributeQuery QueryDoubleAttribute(string& name, double& value)", asFUNCTION(BIND_CLASS XmlElement_QueryDoubleAttribute), asCALL_CDECL_OBJFIRST));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "XmlAttributeQuery QueryFloatAttribute(string& name, float& value)", asFUNCTION(BIND_CLASS XmlElement_QueryFloatAttribute), asCALL_CDECL_OBJFIRST));

	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "XmlAttribute@+ FirstAttribute() const", asMETHODPR(TiXmlElement, FirstAttribute, (void), TiXmlAttribute*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "XmlAttribute@+ LastAttribute() const", asMETHODPR(TiXmlElement, LastAttribute, (void), TiXmlAttribute*), asCALL_THISCALL));

	BIND_ASSERT(engine->RegisterObjectMethod("XmlElement", "string@ GetText() const", asFUNCTION(BIND_CLASS XmlElement_GetText), asCALL_CDECL_OBJFIRST));

	/* XmlDocument */
	RegisterNodeMethods_Native<TiXmlDocument>(engine, "XmlDocument");
	RegisterInheritance_Native<TiXmlNode, TiXmlDocument>(engine, "XmlNode", "XmlDocument");
	BIND_ASSERT(engine->RegisterObjectMethod("XmlDocument", "bool LoadFile(XmlEncoding encoding)", asFUNCTION(BIND_CLASS XmlDocument_LoadFile), asCALL_CDECL_OBJFIRST));

	BIND_ASSERT(engine->RegisterObjectMethod("XmlDocument", "XmlElement@+ RootElement() const", asMETHODPR(TiXmlDocument, RootElement, (void), TiXmlElement*), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlDocument", "bool Error() const", asMETHOD(TiXmlDocument, Error), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlDocument", "string@ ErrorDesc() const", asFUNCTION(BIND_CLASS XmlDocument_ErrorDesc), asCALL_CDECL_OBJFIRST));

	BIND_ASSERT(engine->RegisterObjectMethod("XmlDocument", "int ErrorRow() const", asMETHOD(TiXmlDocument, ErrorRow), asCALL_THISCALL));
	BIND_ASSERT(engine->RegisterObjectMethod("XmlDocument", "int ErrorCol() const", asMETHOD(TiXmlDocument, ErrorCol), asCALL_THISCALL));

	/* Global functions */
	BIND_ASSERT(engine->RegisterGlobalFunction("XmlDocument@ NewXmlDocument(string& name)", asFUNCTION(BIND_CLASS Global_NewXmlDocument),asCALL_CDECL));
}
