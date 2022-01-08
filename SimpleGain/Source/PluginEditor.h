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
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

public:
    SimpleGainAudioProcessorEditor (SimpleGainAudioProcessor&, AudioProcessorValueTreeState&);
    ~SimpleGainAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleGainAudioProcessor& audioProcessor;

    // Value Tree
    AudioProcessorValueTreeState& valueTreeState;

    // Slider, Label, and Attachment for Gain
    Slider gainSlider;
    Label gainLabel;
    std::unique_ptr<SliderAttachment> gainSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleGainAudioProcessorEditor)
};
