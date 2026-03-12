#include "PluginEditor.h"

GraceEnhancerAudioProcessorEditor::GraceEnhancerAudioProcessorEditor (GraceEnhancerAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    setSize (400, 300);
}

void GraceEnhancerAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (20.0f);
    g.drawFittedText ("GraceEnhancer", getLocalBounds(), juce::Justification::centred, 1);
}

void GraceEnhancerAudioProcessorEditor::resized()
{
}
