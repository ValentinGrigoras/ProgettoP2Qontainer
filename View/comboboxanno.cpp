#include "comboboxanno.h"

ComboBoxAnno::ComboBoxAnno(QWidget* parent):
    QComboBox (parent)
{

    addItem("2005"); addItem("2006"); addItem("2007"); addItem("2008"); addItem("2009");
     addItem("2010"); addItem("2011"); addItem("2012"); addItem("2013"); addItem("2014");
     addItem("2015"); addItem("2016"); addItem("2017"); addItem("2018"); addItem("2019");
}

void ComboBoxAnno::CreateComboBox(std::string p)
{
                clear();
                if(p == "Ps3")
                {
                  addItem("2006"); addItem("2007"); addItem("2008"); addItem("2009");
                     addItem("2010"); addItem("2011"); addItem("2012"); addItem("2013"); addItem("2014");
                     addItem("2015"); addItem("2016"); addItem("2017"); addItem("2018"); addItem("2019");
                }
              else  if(p == "Ps4")
                {
                     addItem("2013"); addItem("2014");
                     addItem("2015"); addItem("2016"); addItem("2017"); addItem("2018"); addItem("2019");
                }

            else if(p == "Xbox360")
            {
                addItem("2005"); addItem("2006"); addItem("2007"); addItem("2008"); addItem("2009");
                 addItem("2010"); addItem("2011"); addItem("2012"); addItem("2013"); addItem("2014");
                 addItem("2015"); addItem("2016"); addItem("2017"); addItem("2018"); addItem("2019");
            }
            else if(p == "XboxOne")
            {
                addItem("2005"); addItem("2006"); addItem("2007"); addItem("2008"); addItem("2009");
                 addItem("2010"); addItem("2011"); addItem("2012"); addItem("2013"); addItem("2014");
                 addItem("2015"); addItem("2016"); addItem("2017"); addItem("2018"); addItem("2019");
            }

}


