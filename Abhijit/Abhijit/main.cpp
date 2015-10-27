//
// In Project Properties add the following:
// Configuration Properties/ VC++ Directories/Include Directories:
// C:\code\fltkPractice\fltk-1.3.3
// Configuration Properties/ VC++ Directories/Library Directories:
// C:\code\fltkPractice\fltk-1.3.3\lib
//
// Linker/Input/Additional Dependencies:
//fltkd.lib
//wsock32.lib
//comctl32.lib
//fltkjpegd.lib
//fltkimagesd.lib
//
// In the above - 'd' stands for debug. So fltkd.lib is debug version. release version without the 'd'
//

#include "stdio.h"
#include <conio.h>
#include <iostream>

//#include "FL/Fl.h" // WINDOWS version. for linux, use Fl/fl.H instead of Fl/fl.h
//#include "FL/Fl_Window.h"
//#include "FL/Fl_Button.h"
//#include "FL/Fl_Output.h"

#include "FL/Fl.h"
#include "FL/Fl_Window.h"
#include "FL/Fl_Button.h"
#include "FL/Fl_Output.h"
#include "Fl/Fl_Slider.h"


struct Price
{
    int bid;
    int ask;
    int bidVolume;
    int askVolume;

    Price()
    {
        bidVolume=0;
        askVolume=0;
    }
};

struct Data
{
    Fl_Button *buttonData;
    Fl_Output *outputData;

};

void OnStartClick(Fl_Widget * button, void * pVoid)
{
    Price * pPrice = (Price *) pVoid;

    //std::cout << pPrice->ask << " " << button->label() <<std::endl;

    std::string strLbl = button->label();

    //const char * strLbl = button->label();
    //int nSize = strlen(strLbl);

    (pPrice->bid);

    Fl_Button *pButton = (Fl_Button *) button;	// all FLTK objects are derived from class Fl_Widget.
    // here, we are casting the pointer button of type Fl_Widget to
    // a pointer of class Fl_Button
    // button was pointing to the button that calls this function

    if (strcmp(pButton->label(),"Clicked") == 0)
    {
        pButton->label("again");
    }
    else
    {
        pButton->label("Clicked");
    }


    //pButton->label("mine!");
}

void OnUpClick(Fl_Widget * button, void * pVoid)
{
    Fl_Output * pOutput = (Fl_Output *) pVoid;

    //Fl_Button * pUpButton = (Fl_Button *) pButton;

    //std::cout << pPrice->ask << " " << button->label() <<std::endl;

    pOutput->label("Up Clicked");

    pOutput->value("500");

    Fl_Button *pButton = (Fl_Button *) button;

    if (strcmp(pButton->label(),"Clicked Up") == 0)
    {
        (*pButton).label("again Up");
    }
    else
    {
        pButton->label("Clicked Up");
    }

}

void OnUpClick2(Fl_Widget * button, void * pVoid)
{
    Data * data = (Data *) pVoid;			//void pointer cast as Data type
    Fl_Button * startBtn = data->buttonData;
    startBtn->label("up clicked");

    Fl_Output * pOutput = data->outputData;

    std::cout << button->label() <<std::endl;

    pOutput->label("Up Clicked");
    pOutput->value("500");

    Fl_Button *pButton = (Fl_Button *) button;

    if (strcmp(pButton->label(),"Clicked Up") == 0)
    {
        (*pButton).label("again Up");
    }
    else
    {
        pButton->label("Clicked Up");
    }

}

void OnSlider(Fl_Widget * slider, void * pVoid)
{
    //casting void pointers:
	Fl_Slider *pSlider= (Fl_Slider *) slider;
	Data *data = (Data *) pVoid;
	Fl_Output * pOutput = data->outputData;

	
	//assigning values from slider to where I want to show it:
	double dValue = pSlider->value();
	int value = (dValue);
    char label[12]="";
    sprintf(label, "%d", value); //casting int value as char * label
	
	std::cout << label << std::endl;
	pSlider->label(label);

	//int bid
	//sprintf(label, "%d", value);
	pOutput->value(label);
	
	Fl::check();
   
}

int main()
{

    Price myPrice;
    myPrice.bid = 45;
    myPrice.ask = 46;

    Price * secondPrice = new Price;
    int a = 50;

    Fl_Window win(500, 500, "Michael Window");

		///////////////////////////////////////////////////////
		//Window Construction
		win.begin();

		Fl_Button upBtn(200,10,100,20,"Up");
		Fl_Button startBtn(10,30,100,20,"Start");
		Fl_Button stopBtn(400,30,100,20,"Stop");
		Fl_Button downBtn(200,50,100,20,"Down");
		
		Fl_Slider slider (300, 30, 30, 450, "");

		Fl_Output output(200, 100, 100, 20, "Output1");
		Fl_Output output2(200, 130, 100, 20, "Output2");
		Fl_Output output3(200, 160, 100, 20, "Output3");

		win.end();
		/////////////////////////////////////////////////

    slider.bounds(300,50);
    slider.value(70);

    Data  data;
    data.buttonData = &startBtn;
    data.outputData = &output;
    

    startBtn.callback(OnStartClick, &myPrice);
    //upBtn.callback(OnUpClick, &output);
    upBtn.callback(OnUpClick2, &data);
    stopBtn.callback(OnStartClick, &myPrice);
    downBtn.callback(OnStartClick, &myPrice);

    slider.callback(OnSlider, &data);
    win.show();

    Fl::run();

    ++a;
}




/**************************************************
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main (int argc, char ** argv)
{
  Fl_Window *window;
  Fl_Box *box;

  window = new Fl_Window (300, 180);
  box = new Fl_Box (20, 40, 260, 100, "Hello World!");

  box->box (FL_UP_BOX);
  box->labelsize (36);
  box->labelfont (FL_BOLD+FL_ITALIC);
  box->labeltype (FL_SHADOW_LABEL);
  window->end ();
  window->show (argc, argv);

  return(Fl::run());
}
***************************************************/
