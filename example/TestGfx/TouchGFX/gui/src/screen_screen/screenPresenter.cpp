#include <gui/screen_screen/screenView.hpp>
#include <gui/screen_screen/screenPresenter.hpp>

screenPresenter::screenPresenter(screenView& v)
    : view(v)
{
}

void screenPresenter::activate()
{

}

void screenPresenter::deactivate()
{

}

void screenPresenter::UpDateHeartNum(int i)
{
	view.UpDateHeartNum(i);
}
void screenPresenter::UpDateTemNum(int i)
{
	view.UpDateTemNum(i);
}
