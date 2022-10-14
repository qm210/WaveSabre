#ifndef __SCREWDRIVERVST_H__
#define __SCREWDRIVERVST_H__

#include <WaveSabreVstLib.h>
using namespace WaveSabreVstLib;

class ScrewdriverVst : public VstPlug
{
public:
	ScrewdriverVst(audioMasterCallback audioMaster);

	virtual void getParameterName(VstInt32 index, char *text);

	virtual bool getEffectName(char *name);
	virtual bool getProductString(char *text);
};

#endif