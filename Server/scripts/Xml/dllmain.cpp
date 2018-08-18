// Author: Grzegorz "Atom" Jagiella
// This file is public domain.

#include "../fonline_tla.h"
#include "tinyxml.h"

EXPORT void Dummy() { }

int __stdcall DllMain(void* module, unsigned long reason, void* reserved)
{
	switch(reason)
	{
	case 1: // Process attach
		break;
	case 2: // Thread attach
		break;
	case 3: // Thread detach
		break;
	case 0: // Process detach
		break;
	}
	return 1;
}

extern void RegisterXml_Native(asIScriptEngine* engine, bool compiler);

FONLINE_DLL_ENTRY(compiler)
{
	RegisterXml_Native(ASEngine,compiler);
}