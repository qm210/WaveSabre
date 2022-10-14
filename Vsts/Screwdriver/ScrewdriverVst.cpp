#include "ScrewdriverVst.h"
#include "ScrewdriverEditor.h"

#include <WaveSabreCore.h>
using namespace WaveSabreCore;

AudioEffect *createEffectInstance(audioMasterCallback audioMaster)
{
	Helpers::Init();
	return new ScrewdriverVst(audioMaster);
}

ScrewdriverVst::ScrewdriverVst(audioMasterCallback audioMaster)
	: VstPlug(audioMaster, (int)Screwdriver::ParamIndices::NumParams, 2, 2, 'Scrw', new Screwdriver())
{
	setEditor(new ScrewdriverEditor(this));
}

void ScrewdriverVst::getParameterName(VstInt32 index, char *text)
{
	switch ((Screwdriver::ParamIndices)index)
	{
	case Screwdriver::ParamIndices::X1: vst_strncpy(text, "X1", kVstMaxParamStrLen); break;
	case Screwdriver::ParamIndices::Y1: vst_strncpy(text, "Y1", kVstMaxParamStrLen); break;
	case Screwdriver::ParamIndices::X2: vst_strncpy(text, "X2", kVstMaxParamStrLen); break;
	case Screwdriver::ParamIndices::Y2: vst_strncpy(text, "Y2", kVstMaxParamStrLen); break;
	case Screwdriver::ParamIndices::LogPower0: vst_strncpy(text, "Shape0", kVstMaxParamStrLen); break;
	case Screwdriver::ParamIndices::LogPower1: vst_strncpy(text, "Shape1", kVstMaxParamStrLen); break;
	case Screwdriver::ParamIndices::LogPower2: vst_strncpy(text, "Shape2", kVstMaxParamStrLen); break;
	case Screwdriver::ParamIndices::DryWet: vst_strncpy(text, "Dry/Wet", kVstMaxParamStrLen); break;
	}
}

bool ScrewdriverVst::getEffectName(char *name)
{
	vst_strncpy(name, "WaveSabre - QM-Screwdriver", kVstMaxEffectNameLen);
	return true;
}

bool ScrewdriverVst::getProductString(char *text)
{
	vst_strncpy(text, "WaveSabre - QM-Screwdriver", kVstMaxProductStrLen);
	return true;
}
