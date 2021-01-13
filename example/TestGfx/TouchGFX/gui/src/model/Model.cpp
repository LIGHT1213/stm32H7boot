#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui_generated/screen_screen/screenViewBase.hpp>
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	
	static int i;
	i=i+2;
	modelListener->UpDateHeartRateLine(i);
	modelListener->UpDateHeartNum(i);
	modelListener->UpDateTemNum(i);
	if(i==100)
	i=0;
}
