#pragma once

#include "../xrCore/xrCore.h"
#include "../xrEngine/stdafx.h"
#include "../Include/xrRender/RenderFactory.h"
#include "../Include/xrRender/RenderDeviceRender.h"
#include <vcclr.h>


#ifdef	MANAGED_RENDER_BUILD
#define MANAGED_RENDER_API		__declspec(dllexport)
#else
#define MANAGED_RENDER_API		__declspec(dllimport)
#endif