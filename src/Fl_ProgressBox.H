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
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>

class Fl_ProgressBox : public Fl_Box
{
protected:
	double mMin;
	double mMax;
	double mPresent;
	double mStep;
	bool mShowPct;
	Fl_Color mTextColor;
	FL_EXPORT void draw();
public:
	FL_EXPORT Fl_ProgressBox(int x, int y, int w, int h, const char *lbl);
	void range(double min, double max, double step = 1)  { mMin = min; mMax = max; mStep = step; };
	void step(double step)		{ mPresent += step; redraw(); };
	double min()	{ return mMin; }
	double max()	{ return mMax; }
	double position()	{ return mPresent; }
	double step()		{ return mStep; }
	void position(double pos) 	{ mPresent = pos; redraw(); }
	void showtext(bool st)	{ mShowPct = st; }
	bool showtext()		{ return mShowPct; }
	void textcolor(Fl_Color col)	{ mTextColor = col; }
	Fl_Color textcolor() 	{ return mTextColor; }
};


