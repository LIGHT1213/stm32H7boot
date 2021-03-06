/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    container1.setPosition(0, 0, 480, 272);

    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    container1.add(box1);

    slider1.setXY(15, 0);
    slider1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_INDICATORS_SLIDER_HORIZONTAL_SMALL_ROUND_KNOB_ID));
    slider1.setupHorizontalSlider(3, 7, 0, 0, 125);
    slider1.setValueRange(1, 20);
    slider1.setValue(1);
    container1.add(slider1);

    buttonWithLabel1.setXY(292, -3);
    buttonWithLabel1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel1.setLabelText(touchgfx::TypedText(T_SINGLEUSEID12));
    buttonWithLabel1.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel1.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel1.setAction(buttonCallback);
    container1.add(buttonWithLabel1);

    HeartRateLine.setScale(1);
    HeartRateLine.setPosition(0, 57, 480, 215);
    HeartRateLine.setGraphAreaMargin(0, 0, 0, 0);
    HeartRateLine.setGraphAreaPadding(0, 0, 0, 0);
    HeartRateLine.setGraphRangeY(0, 100);

    HeartRateLineLine1.setScale(1);
    HeartRateLineLine1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(1, 0, 0));
    HeartRateLineLine1.setPainter(HeartRateLineLine1Painter);
    HeartRateLineLine1.setLineWidth(1);
    HeartRateLine.addGraphElement(HeartRateLineLine1);

    HeartRateLineHistogram1.setScale(1);
    HeartRateLineHistogram1.setColor(touchgfx::Color::getColorFrom24BitRGB(104, 74, 177));
    HeartRateLineHistogram1.setBarWidth(1);
    HeartRateLineHistogram1.setBaseline(0);
    HeartRateLineHistogram1.setAlpha(175);
    HeartRateLine.addGraphElement(HeartRateLineHistogram1);

    HeartRateLineDots1.setScale(1);
    HeartRateLineDots1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(20, 151, 197));
    HeartRateLineDots1.setPainter(HeartRateLineDots1Painter);
    HeartRateLineDots1.setDotWidth(4);
    HeartRateLine.addGraphElement(HeartRateLineDots1);

    HeartRateLine.addDataPoint(49.6754373254205f);
    HeartRateLine.addDataPoint(51.4453867210524f);
    HeartRateLine.addDataPoint(49.9149393407297f);
    HeartRateLine.addDataPoint(45.1694118910658f);
    HeartRateLine.addDataPoint(37.8841855138815f);
    HeartRateLine.addDataPoint(29.2199616220125f);
    HeartRateLine.addDataPoint(20.6392502611767f);
    HeartRateLine.addDataPoint(13.6730453169078f);
    HeartRateLine.addDataPoint(9.67462112463248f);
    HeartRateLine.addDataPoint(9.59939633950965f);
    HeartRateLine.addDataPoint(13.8458195474722f);
    HeartRateLine.addDataPoint(22.182585983884f);
    HeartRateLine.addDataPoint(33.7739376565764f);
    HeartRateLine.addDataPoint(47.2993372329955f);
    HeartRateLine.addDataPoint(61.1489409519001f);
    HeartRateLine.addDataPoint(73.6643305217846f);
    HeartRateLine.addDataPoint(83.3868457958382f);
    HeartRateLine.addDataPoint(89.2746694751367f);
    HeartRateLine.addDataPoint(90.8547031245925f);
    HeartRateLine.addDataPoint(88.2856025449888f);
    HeartRateLine.addDataPoint(82.3222990539257f);
    HeartRateLine.addDataPoint(74.1878972398445f);
    HeartRateLine.addDataPoint(65.3733688712415f);
    HeartRateLine.addDataPoint(57.3968908191254f);
    HeartRateLine.addDataPoint(51.5609158267952f);
    HeartRateLine.addDataPoint(48.7454476232477f);
    HeartRateLine.addDataPoint(49.2701635012222f);
    HeartRateLine.addDataPoint(52.8471324119213f);
    HeartRateLine.addDataPoint(58.6315093813318f);
    HeartRateLine.addDataPoint(65.362080107857f);
    HeartRateLine.addDataPoint(71.5692641835866f);
    HeartRateLine.addDataPoint(75.8175226507261f);
    HeartRateLine.addDataPoint(76.943643999522f);
    HeartRateLine.addDataPoint(74.2529627064843f);
    HeartRateLine.addDataPoint(67.6422413375371f);
    HeartRateLine.addDataPoint(57.62945381306f);
    HeartRateLine.addDataPoint(45.2854427047708f);
    HeartRateLine.addDataPoint(32.0778794928453f);
    HeartRateLine.addDataPoint(19.651848524646f);
    HeartRateLine.addDataPoint(9.58136025009954f);
    HeartRateLine.addDataPoint(3.13076039368765f);
    HeartRateLine.addDataPoint(1.06343492986291f);
    HeartRateLine.addDataPoint(3.52779967240961f);
    HeartRateLine.addDataPoint(10.0384157328846f);
    HeartRateLine.addDataPoint(19.5550934735762f);
    HeartRateLine.addDataPoint(30.647429601027f);
    HeartRateLine.addDataPoint(41.7187902309396f);
    HeartRateLine.addDataPoint(51.2544441284251f);
    HeartRateLine.addDataPoint(58.0547388693816f);
    HeartRateLine.addDataPoint(61.4166950832187f);
    HeartRateLine.addDataPoint(61.2355178834617f);
    HeartRateLine.addDataPoint(58.0102637185363f);
    HeartRateLine.addDataPoint(52.7530276948838f);
    HeartRateLine.addDataPoint(46.8163172567359f);
    HeartRateLine.addDataPoint(41.6661622151174f);
    HeartRateLine.addDataPoint(38.6371622511117f);
    HeartRateLine.addDataPoint(38.7084604232494f);
    HeartRateLine.addDataPoint(42.3363566800971f);
    HeartRateLine.addDataPoint(49.3703277784108f);
    HeartRateLine.addDataPoint(59.0660044081617f);
    HeartRateLine.addDataPoint(70.1933393294586f);
    HeartRateLine.addDataPoint(81.2231178253898f);
    HeartRateLine.addDataPoint(90.5625829734795f);
    HeartRateLine.addDataPoint(96.8030917775117f);
    HeartRateLine.addDataPoint(98.9408347673785f);
    HeartRateLine.addDataPoint(96.5357842036582f);
    HeartRateLine.addDataPoint(89.7837864336104f);
    HeartRateLine.addDataPoint(79.4903365823057f);
    HeartRateLine.addDataPoint(66.950068029918f);
    HeartRateLine.addDataPoint(53.7507931105068f);
    HeartRateLine.addDataPoint(41.5328423473907f);
    HeartRateLine.addDataPoint(31.7414231009213f);
    HeartRateLine.addDataPoint(25.4108052181624f);
    HeartRateLine.addDataPoint(23.0141066273274f);
    HeartRateLine.addDataPoint(24.4020407313516f);
    HeartRateLine.addDataPoint(28.8399684093948f);
    HeartRateLine.addDataPoint(35.1370446911773f);
    HeartRateLine.addDataPoint(41.846757684556f);
    HeartRateLine.addDataPoint(47.5068457964833f);
    HeartRateLine.addDataPoint(50.880461405669f);
    HeartRateLine.addDataPoint(51.1602016269981f);
    HeartRateLine.addDataPoint(48.1026018723642f);
    HeartRateLine.addDataPoint(42.0716646956255f);
    HeartRateLine.addDataPoint(33.9844269117777f);
    HeartRateLine.addDataPoint(25.1670722150877f);
    HeartRateLine.addDataPoint(17.1442959010444f);
    HeartRateLine.addDataPoint(11.3952062954851f);
    HeartRateLine.addDataPoint(9.11436745590467f);
    HeartRateLine.addDataPoint(11.01588502214f);
    HeartRateLine.addDataPoint(17.2116139980986f);
    HeartRateLine.addDataPoint(27.1829778880616f);
    HeartRateLine.addDataPoint(39.8510949378729f);
    HeartRateLine.addDataPoint(53.7344621261955f);
    HeartRateLine.addDataPoint(67.1695972103843f);
    HeartRateLine.addDataPoint(78.5601778949555f);
    HeartRateLine.addDataPoint(86.615651962774f);
    HeartRateLine.addDataPoint(90.5420192763072f);
    HeartRateLine.addDataPoint(90.1549821356937f);
    HeartRateLine.addDataPoint(85.8979145887325f);
    HeartRateLine.addDataPoint(78.7620962421345f);
    HeartRateLine.addDataPoint(70.1220572683373f);
    HeartRateLine.addDataPoint(61.5122421864962f);
    HeartRateLine.addDataPoint(54.3803930707724f);
    HeartRateLine.addDataPoint(49.856733044535f);
    HeartRateLine.addDataPoint(48.5754128953595f);
    HeartRateLine.addDataPoint(50.5764419512384f);
    HeartRateLine.addDataPoint(55.3035133704671f);
    HeartRateLine.addDataPoint(61.6979783271463f);
    HeartRateLine.addDataPoint(68.3739551311923f);
    HeartRateLine.addDataPoint(73.8467514923179f);
    HeartRateLine.addDataPoint(76.7782628322203f);
    HeartRateLine.addDataPoint(76.2003368756313f);
    HeartRateLine.addDataPoint(71.6805408634486f);
    HeartRateLine.addDataPoint(63.4038029981294f);
    HeartRateLine.addDataPoint(52.1567244561521f);
    HeartRateLine.addDataPoint(39.2166764150328f);
    HeartRateLine.addDataPoint(26.1628663310586f);
    HeartRateLine.addDataPoint(14.6388528991897f);
    HeartRateLine.addDataPoint(6.10373590946393f);
    HeartRateLine.addDataPoint(1.61099097326398f);
    HeartRateLine.addDataPoint(1.64966702934856f);
    HeartRateLine.addDataPoint(6.07279841397706f);
    HeartRateLine.addDataPoint(14.1242094121172f);
    HeartRateLine.addDataPoint(24.5593704638102f);
    HeartRateLine.addDataPoint(35.8412089369013f);
    container1.add(HeartRateLine);

    textArea2.setXY(220, 0);
    textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3));
    container1.add(textArea2);

    add(__background);
    add(container1);
}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel1)
    {
        //Interaction1
        //When buttonWithLabel1 clicked change screen to screen
        //Go to screen with screen transition towards East
        application().gotoscreenScreenWipeTransitionEast();
    }
}
