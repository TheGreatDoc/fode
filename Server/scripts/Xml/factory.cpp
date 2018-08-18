// Author: Grzegorz "Atom" Jagiella
// This file is public domain.

#include "factory.h"
#include <vector>

int XmlTextId=-1;
int XmlNodeId=-1;
int XmlUnknownId=-1;
int XmlAttributeId=-1;
int XmlCommentId=-1;
int XmlDeclarationId=-1;
int XmlElementId=-1;
int XmlDocumentId=-1;

vector<RefCount*> ToRelease;

ScriptString* NewString(const char* value)
{
	if(!value) return NULL;
	return &(ScriptString::Create(value));
}

TiXmlDeclaration* NewTiXmlDeclaration()
{
#ifdef XML_DEBUG
	printf("factory: TiXmlDeclaration...\n");
#endif
    TiXmlDeclaration* obj = new TiXmlDeclaration();
#ifdef XML_DEBUG
	obj->TypeId=ASEngine->GetObjectTypeById(XmlDeclarationId)->GetName();
	printf("factory created %s\n", obj->TypeId.c_str());
#endif
	ToRelease.push_back(obj);
	ASEngine->NotifyGarbageCollectorOfNewObject(obj, ASEngine->GetObjectTypeById(XmlDeclarationId));
#ifdef XML_DEBUG
	printf("GC notified\n");
#endif
    return obj;
}

TiXmlComment* NewTiXmlComment()
{
#ifdef XML_DEBUG
	printf("factory: TiXmlComment...\n");
#endif
    TiXmlComment* obj = new TiXmlComment();
#ifdef XML_DEBUG
	obj->TypeId=ASEngine->GetObjectTypeById(XmlCommentId)->GetName();
	printf("factory created %s\n", obj->TypeId.c_str());
#endif
	ToRelease.push_back(obj);
    ASEngine->NotifyGarbageCollectorOfNewObject(obj, ASEngine->GetObjectTypeById(XmlCommentId));
#ifdef XML_DEBUG
	printf("GC notified\n");
#endif
    return obj;
}


TiXmlText* NewTiXmlText(const char* value)
{
#ifdef XML_DEBUG
	printf("factory: TiXmlText...\n");
#endif
    TiXmlText* obj = new TiXmlText(value);
#ifdef XML_DEBUG
	obj->TypeId=ASEngine->GetObjectTypeById(XmlTextId)->GetName();
	printf("factory created %s\n", obj->TypeId.c_str());
#endif
	ToRelease.push_back(obj);
    ASEngine->NotifyGarbageCollectorOfNewObject(obj, ASEngine->GetObjectTypeById(XmlTextId));
#ifdef XML_DEBUG
	printf("GC notified\n");
#endif
    return obj;
}

TiXmlUnknown* NewTiXmlUnknown()
{
#ifdef XML_DEBUG
	printf("factory: TiXmlUnknown...\n");
#endif
    TiXmlUnknown* obj = new TiXmlUnknown();
#ifdef XML_DEBUG
	obj->TypeId=ASEngine->GetObjectTypeById(XmlUnknownId)->GetName();
	printf("factory created %s(%d)\n", obj->TypeId.c_str(), (int)obj);
#endif
	ToRelease.push_back(obj);
    ASEngine->NotifyGarbageCollectorOfNewObject(obj, ASEngine->GetObjectTypeById(XmlUnknownId));
#ifdef XML_DEBUG
	printf("GC notified\n");
#endif
    return obj;
}


TiXmlElement* NewTiXmlElement(const char* value)
{
#ifdef XML_DEBUG
	printf("factory: TiXmlElement...\n");
#endif
    TiXmlElement* obj = new TiXmlElement(value);
#ifdef XML_DEBUG
	obj->TypeId=ASEngine->GetObjectTypeById(XmlElementId)->GetName();
	printf("factory created %s(%d)\n", obj->TypeId.c_str(), (int)obj);
#endif
	ToRelease.push_back(obj);
    ASEngine->NotifyGarbageCollectorOfNewObject(obj, ASEngine->GetObjectTypeById(XmlElementId));
#ifdef XML_DEBUG
	printf("GC notified\n");
#endif
    return obj;
}


TiXmlAttribute* NewTiXmlAttribute()
{
#ifdef XML_DEBUG
	printf("factory: TiXmlAttribute...\n");
#endif
    TiXmlAttribute* obj = new TiXmlAttribute();
#ifdef XML_DEBUG
	obj->TypeId=ASEngine->GetObjectTypeById(XmlAttributeId)->GetName();
	printf("factory created %s\n", obj->TypeId.c_str());
#endif
	ToRelease.push_back(obj);
    ASEngine->NotifyGarbageCollectorOfNewObject(obj, ASEngine->GetObjectTypeById(XmlAttributeId));
#ifdef XML_DEBUG
	printf("GC notified\n");
#endif
    return obj;
}

TiXmlDocument* NewTiXmlDocument()
{
#ifdef XML_DEBUG
	printf("factory: TiXmlDocument...\n");
#endif
    TiXmlDocument* obj = new TiXmlDocument();
#ifdef XML_DEBUG
	obj->TypeId=ASEngine->GetObjectTypeById(XmlDocumentId)->GetName();
	printf("factory created %s(%d)\n", obj->TypeId.c_str(), (int)obj);
#endif
	ToRelease.push_back(obj);
    ASEngine->NotifyGarbageCollectorOfNewObject(obj, ASEngine->GetObjectTypeById(XmlDocumentId));
#ifdef XML_DEBUG
	printf("GC notified\n");
#endif
    return obj;
}

TiXmlDocument* NewTiXmlDocument(const char* value)
{
#ifdef XML_DEBUG
	printf("factory: TiXmlDocument...\n");
#endif
    TiXmlDocument* obj = new TiXmlDocument(value);
#ifdef XML_DEBUG
	obj->TypeId=ASEngine->GetObjectTypeById(XmlDocumentId)->GetName();
	printf("factory created %s(%d)\n", obj->TypeId.c_str(), (int)obj);
#endif
	ToRelease.push_back(obj);
    ASEngine->NotifyGarbageCollectorOfNewObject(obj, ASEngine->GetObjectTypeById(XmlDocumentId));
#ifdef XML_DEBUG
	printf("GC notified\n");
#endif
    return obj;
}


void ReleaseAll()
{
#ifdef XML_DEBUG
	printf("releaseall begin\n");
#endif
	for(vector<RefCount*>::iterator it=ToRelease.begin(),end=ToRelease.end();it!=end;it++)
		(*it)->Release();
	ToRelease.clear();
#ifdef XML_DEBUG
	printf("releaseall end\n");
#endif
}