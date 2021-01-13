#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
	
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::UpDateHeartRateLine(int i)
{
	HeartRateLine.addDataPoint(i);
	HeartRateLine.setGraphRangeY(0,10*slider1.getValue());
}
