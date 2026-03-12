cmake_minimum_required(VERSION 3.15)
project(GraceEnhancer VERSION 0.0.1)

set(JUCE_DIR "C:/JUCE")
add_subdirectory(${JUCE_DIR} JUCE)

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

target_compile_definitions(GraceEnhancer PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
)
