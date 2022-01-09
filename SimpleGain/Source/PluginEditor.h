/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SimpleGainAudioProcessorEditor  : public juce::AudioProcessorEditor
{

    // Typedefs
    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

public:
    SimpleGainAudioProcessorEditor (SimpleGainAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~SimpleGainAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleGainAudioProcessor& audioProcessor;

    // Value Tree
    juce::AudioProcessorValueTreeState& valueTreeState;

    // Slider, Label, and Attachment for Gain
    juce::Slider gainSlider;
    juce::Label gainLabel;
    std::unique_ptr<SliderAttachment> gainSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleGainAudioProcessorEditor)
};
