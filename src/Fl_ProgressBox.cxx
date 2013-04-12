/******************************************************************************
 fltk prozilla - a front end for prozilla, a download accelerator library
 Copyright (C) 2001 Kalum Somaratna

 FLTK PROZGUI - a GUI download accelerator
 Copyright (C) 2011 Raviyanto Ahmad

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
******************************************************************************/

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif				/*
				 * HAVE_CONFIG_H 
				 */

#include "Fl_ProgressBox.H"
#include <stdio.h>

FL_EXPORT Fl_ProgressBox::Fl_ProgressBox(int x, int y, int w, int h, const char *lbl)
	: Fl_Box(x,y,w,h,lbl)
{
	mMin = mPresent = 0; 
	mMax = 100; 
	mShowPct = true; 
	box(FL_DOWN_BOX);
	selection_color(FL_BLUE);
	color(FL_WHITE);
	textcolor(FL_RED);
}					   
					   
FL_EXPORT void Fl_ProgressBox::draw()
{
	int bdx, bdy;
	double pct;
	if(damage() & FL_DAMAGE_ALL)
		draw_box();
	bdx = Fl::box_dx(box());
	bdy = Fl::box_dy(box());
	fl_color(selection_color());
	if(mPresent > mMax)
		mPresent = mMax;
	if(mPresent < mMin)
		mPresent = mMin;
	pct = (mPresent - mMin) / mMax;
	fl_rectf(x() + bdx, y() + bdy, (int)(((double)w() - 2*bdx) * pct), h() - 2*bdy);
	if(mShowPct)
	{
		char buffer[30];
		sprintf(buffer, "%d%%", (int) (pct * 100));
		fl_color(textcolor());
		fl_font(this->labelfont(), this->labelsize());
		fl_draw(buffer, x() + (w() - fl_width(buffer))/2, y() + fl_height() + (((h() - 2*bdy) - fl_height())/2));
	}
}

