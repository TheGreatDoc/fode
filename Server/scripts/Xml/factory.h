// Author: Grzegorz "Atom" Jagiella
// This file is public domain.

#include "../fonline_tla.h"
#include "tinyxml.h"

ScriptString*		NewString(const char* value);
TiXmlDeclaration*	NewTiXmlDeclaration();
TiXmlComment*		NewTiXmlComment();
TiXmlText*			NewTiXmlText(const char* value);
TiXmlUnknown*		NewTiXmlUnknown();
TiXmlElement*		NewTiXmlElement(const char* value);
TiXmlAttribute*		NewTiXmlAttribute();
TiXmlDocument*		NewTiXmlDocument();
TiXmlDocument*		NewTiXmlDocument(const char* value);
void				ReleaseAll();