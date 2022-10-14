#ifndef __SCREWDRIVEREDITOR_H__
#define __SCREWDRIVEREDITOR_H__

#include <WaveSabreVstLib.h>
using namespace WaveSabreVstLib;

class ScrewdriverEditor : public VstEditor
{
public:
	ScrewdriverEditor(AudioEffect *audioEffect);
	virtual ~ScrewdriverEditor();

	virtual void Open();
};

#endif
