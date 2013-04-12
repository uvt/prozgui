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
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <malloc.h>
#include <alloca.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <errno.h>
#include "main.h"
#include "savefile.h"
#include "download_win.h"
#include "dl_win.h"
#include "cstdlib"


void create_savefile(Fl_Browser *browser)
{
  FILE *fp;
  char file_name[PATH_MAX];
  snprintf(file_name, PATH_MAX, "%s/%s", rt.config_dir, "urls");
  int num_dls=browser->size();

  if ((fp = fopen(file_name, "wt")) == NULL)
  {
    perror("Could not save the list of URLS's");
    proz_debug("Could not save the list of URLS's :- %s", strerror(errno));
    return;
  }
  
  fprintf(fp, "%d\n", num_dls);
  
  if(num_dls>0)
    {
      for(int i=0; i<num_dls;i++)
	{
	  fprintf(fp, "%s\n", browser->text(i+1));
	}
    }
  fclose(fp);
  return;
}


void load_savefile(Fl_Browser *browser)
{
  FILE *fp;
  char file_name[PATH_MAX];
  snprintf(file_name, PATH_MAX, "%s/%s", rt.config_dir, "urls");
  int num_dls=0;
  int ret;

  if ((fp = fopen(file_name, "rt")) == NULL)
  {
    perror("Could not open the list of URLS's");
    proz_debug("Could not open the list of URLS's :- %s", strerror(errno));
    return;
   }

    ret = fscanf(fp, "%d\n", &num_dls);
    while (ret == EOF) {
        ret = fscanf(fp, "%d\n", &num_dls);
    }

char *line=(char *)malloc (20000);
if(line==0)
{
	printf("Could not allocalte memory");  
	proz_debug("Could not allocalte memory"); 
	exit(EXIT_FAILURE);
}

  if(num_dls>0)
    {
      for(int i=0; i<num_dls;i++)
	{
	  // fgets(line, sizeof(line) - 1, fp);
	  if(fscanf(fp,"%s\n", line)==EOF)
	    {
	      fclose(fp);
	      free(line);
	      proz_debug("Could not read the list of URLS from file!");
	      return;
	    }
	  browser->add(line);
	}
    }
 fclose(fp);
 free(line);
 return;

}
