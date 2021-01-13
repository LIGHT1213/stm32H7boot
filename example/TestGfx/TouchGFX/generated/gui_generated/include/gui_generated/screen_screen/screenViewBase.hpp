/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREENVIEWBASE_HPP
#define SCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen_screen/screenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/progress_indicators/CircleProgress.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565Bitmap.hpp>

class screenViewBase : public touchgfx::View<screenPresenter>
{
public:
    screenViewBase();
    virtual ~screenViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea3;
    touchgfx::TextAreaWithOneWildcard TemNumText;
    touchgfx::TextAreaWithOneWildcard HeartRateText;
    touchgfx::ButtonWithLabel buttonWithLabel1;
    touchgfx::Container container1;
    touchgfx::CircleProgress TemNum;
    touchgfx::PainterRGB565Bitmap TemNumPainter;
    touchgfx::CircleProgress HeartRateNum;
    touchgfx::PainterRGB565Bitmap HeartRateNumPainter;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEMNUMTEXT_SIZE = 5;
    touchgfx::Unicode::UnicodeChar TemNumTextBuffer[TEMNUMTEXT_SIZE];
    static const uint16_t HEARTRATETEXT_SIZE = 5;
    touchgfx::Unicode::UnicodeChar HeartRateTextBuffer[HEARTRATETEXT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<screenViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SCREENVIEWBASE_HPP
