#include "ScrewdriverEditor.h"

#include <WaveSabreCore.h>
using namespace WaveSabreCore;

ScrewdriverEditor::ScrewdriverEditor(AudioEffect *audioEffect)
	: VstEditor(audioEffect, 300, 160, "QM's SCREWDRIVER")
{
}

ScrewdriverEditor::~ScrewdriverEditor()
{
}

void ScrewdriverEditor::Open()
{
	addKnob((VstInt32)Screwdriver::ParamIndices::X1, "X1");
	addKnob((VstInt32)Screwdriver::ParamIndices::Y1, "Y1");
	addSpacer();
	addSpacer();
	addKnob((VstInt32)Screwdriver::ParamIndices::X2, "X2");
	addKnob((VstInt32)Screwdriver::ParamIndices::Y2, "Y2");
    startNextRow();
	addKnob((VstInt32)Screwdriver::ParamIndices::LogPower0, "Shape0");
	addKnob((VstInt32)Screwdriver::ParamIndices::LogPower1, "Shape1");
	addKnob((VstInt32)Screwdriver::ParamIndices::LogPower2, "Shape2");
	addSpacer();
	addSpacer();
	addKnob((VstInt32)Screwdriver::ParamIndices::DryWet, "DRY/WET");

	VstEditor::Open();
}
