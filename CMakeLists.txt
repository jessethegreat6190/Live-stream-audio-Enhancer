cmake_minimum_required(VERSION 3.15)
project(GraceEnhancer VERSION 0.0.1)

set(JUCE_DIR "C:/JUCE")
add_subdirectory(${JUCE_DIR} JUCE)

set(JucePlugin_Build_VST 0)

juce_add_plugin(GraceEnhancer
    COMPANY_NAME "GraceOnline"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE GrOn
    PLUGIN_CODE GrEn
    FORMATS VST3
    PRODUCT_NAME "GraceEnhancer"
)

target_sources(GraceEnhancer PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

target_link_libraries(GraceEnhancer PRIVATE
    juce::juce_dsp
)

target_compile_definitions(GraceEnhancer PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_IGNORE_VST3_MISMATCHED_PARAMETER_WARNING=1
    JUCE_VST3_CAN_REPLACE_VST2=0
)
