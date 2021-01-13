#include <gui/screen_screen/screenView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

extern int TemIn; 
screenView::screenView()
{

}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}

void screenView::UpDateHeartNum(int i)
{
	HeartRateNum.setValue(i);
}
void screenView::UpDateTemNum(int i)
{
	//char  buffer[20];
	
	float Temp=0.01f+i+0.1*i;
	TemNum.setValue(Temp);
//	if(Temp>38)
//	{
//		TemNumText.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
//	}
//	else
//	{
//		TemNumText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
//	}
	Unicode::snprintfFloat(TemNumTextBuffer,TEMNUMTEXT_SIZE,"%3.1f",float(Temp) );
	TemNumText.setWildcard(TemNumTextBuffer);
	TemNumText.invalidate();

}
#ifdef __cplusplus
}
#endif
