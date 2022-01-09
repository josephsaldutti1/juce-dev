/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleGainAudioProcessorEditor::SimpleGainAudioProcessorEditor (SimpleGainAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState(vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);

    // Gain Slider and Label settings
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 80, 20);
    gainSlider.setTextValueSuffix(" dB");
    gainLabel.setText("Gain In", juce::dontSendNotification);
    gainLabel.setJustificationType(juce::Justification::centred);

    // Add and make visible
    addAndMakeVisible(gainSlider);
    addAndMakeVisible(gainLabel);

    // Atttach Gain Slider to the value tree
    gainSliderAttachment.reset(new SliderAttachment(valueTreeState, "gainIn", gainSlider));
}

SimpleGainAudioProcessorEditor::~SimpleGainAudioProcessorEditor()
{
}

//==============================================================================
void SimpleGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colour::Colour(0xff4287f5));
    g.setColour(juce::Colours::white);
    g.setFont(18.0f);
}

void SimpleGainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    // Reused
    int gainSliderWidth = 100;
    int gainSliderHeight = 100;
    int gainLabelWidth = 80;
    int gainLabelHeight = 40;

    // Place Gain Slider in the middle of the window
    gainSlider.setBounds(   ((getWidth() - gainSliderWidth) / 2),
                            ((getHeight() - (gainSliderHeight + gainLabelHeight)) / 2),
                            gainSliderWidth,
                            gainSliderHeight);
    // Place Gain Label directly below
    gainLabel.setBounds(    ((getWidth() - gainLabelWidth) / 2),
                            (getHeight() - gainSliderWidth - gainLabelHeight),
                            gainLabelWidth,
                            gainLabelHeight);
}
