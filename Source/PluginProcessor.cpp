#include "PluginProcessor.h"
#include "PluginEditor.h"

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GraceEnhancerAudioProcessor();
}

GraceEnhancerAudioProcessor::GraceEnhancerAudioProcessor()
    : AudioProcessor (BusesProperties()
                      .withInput ("Input", juce::AudioChannelSet::stereo(), true)
                      .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{}

void GraceEnhancerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec { sampleRate, static_cast<juce::uint32> (samplesPerBlock), getTotalNumInputChannels() };
    eq.prepare(spec);
    compressor.prepare(spec);
    limiter.prepare(spec);
    gain.prepare(spec);
    panner.prepare(spec);
}

void GraceEnhancerAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    juce::dsp::AudioBlock<float> block (buffer);

    gain.process(juce::dsp::ProcessContextReplacing<float>(block));
    eq.process(juce::dsp::ProcessContextReplacing<float>(block));
    compressor.process(juce::dsp::ProcessContextReplacing<float>(block));
    limiter.process(juce::dsp::ProcessContextReplacing<float>(block));
    panner.process(juce::dsp::ProcessContextReplacing<float>(block));

    checkForClipping(buffer);
}

void GraceEnhancerAudioProcessor::checkForClipping(const juce::AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* data = buffer.getReadPointer(ch);
        for (int i = 0; i < buffer.getNumSamples(); ++i)
        {
            if (std::abs(data[i]) > 0.99f)
            {
                juce::Logger::writeToLog("Clipping detected on channel " + juce::String(ch));
                break;
            }
        }
    }
}

juce::AudioProcessorEditor* GraceEnhancerAudioProcessor::createEditor()
{
    return new GraceEnhancerAudioProcessorEditor (*this);
}
