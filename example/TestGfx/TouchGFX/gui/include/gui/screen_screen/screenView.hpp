#ifndef SCREENVIEW_HPP
#define SCREENVIEW_HPP

#include <gui_generated/screen_screen/screenViewBase.hpp>
#include <gui/screen_screen/screenPresenter.hpp>

class screenView : public screenViewBase
{
public:
    screenView();
    virtual ~screenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		//void UpDateHeartRateLine(int i);
		void UpDateHeartNum(int i);
		void UpDateTemNum(int i);
protected:
};

#endif // SCREENVIEW_HPP
