#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class GraceEnhancerAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    GraceEnhancerAudioProcessorEditor (GraceEnhancerAudioProcessor&);
    ~GraceEnhancerAudioProcessorEditor() override = default;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    GraceEnhancerAudioProcessor& processorRef;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GraceEnhancerAudioProcessorEditor)
};
