#include "stdafx.h"
#pragma hdrstop

#include "SoundRender_CoreA.h"

XRSOUND_API xr_token* snd_devices_token = nullptr;
XRSOUND_API u32 snd_device_id = u32(-1);

void CSound_manager_interface::_create(int stage)
{
	if (!stage)
	{
		SoundRenderA = new CSoundRender_CoreA();
		SoundRender = SoundRenderA;
		Sound = SoundRender;

		if (!(strstr(Core.Params, "-nosound")))
		{
			SoundRender->bPresent = true;
			Sound->_initialize(stage);
		}
		else SoundRender->bPresent = false;
	}
}

void CSound_manager_interface::_destroy()
{
	Sound->_clear();
	xr_delete(SoundRender);
	Sound = nullptr;
}