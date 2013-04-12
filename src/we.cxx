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

#include <libintl.h>
#include "we.h"
#include <FL/x.H>
#include "main.h"
#include "prozilla.h"
#include "string.h"

#    ifdef HAVE_LIBXPM
#      include <X11/xpm.h>
#    endif

/* XPM */
static const char *Prozgui2_xpm[] = {
"32 32 422 2",
"  	c None",
". 	c #ABAEAB",
"+ 	c #686968",
"@ 	c #232323",
"# 	c #181818",
"$ 	c #151515",
"% 	c #262625",
"& 	c #2E2E2E",
"* 	c #202020",
"= 	c #313130",
"- 	c #2D2C2C",
"; 	c #3C3B3B",
"> 	c #403F3F",
", 	c #4F4E4E",
"' 	c #4F4E4D",
") 	c #484747",
"! 	c #3F3E3E",
"~ 	c #464645",
"{ 	c #6A6867",
"] 	c #61605F",
"^ 	c #848280",
"/ 	c #8D8B88",
"( 	c #8F8D8A",
"_ 	c #444443",
": 	c #191818",
"< 	c #1A1A1A",
"[ 	c #0C0B0A",
"} 	c #201F1F",
"| 	c #343333",
"1 	c #252525",
"2 	c #393938",
"3 	c #363535",
"4 	c #333232",
"5 	c #474646",
"6 	c #373636",
"7 	c #383737",
"8 	c #4A4A4A",
"9 	c #454444",
"0 	c #525150",
"a 	c #5C5A5A",
"b 	c #7D7A78",
"c 	c #878582",
"d 	c #A0A19F",
"e 	c #31302F",
"f 	c #070605",
"g 	c #1C1B1A",
"h 	c #11100F",
"i 	c #1D1D1D",
"j 	c #212121",
"k 	c #414040",
"l 	c #4B4A49",
"m 	c #3E3D3D",
"n 	c #464545",
"o 	c #494847",
"p 	c #434242",
"q 	c #4E4D4D",
"r 	c #444343",
"s 	c #3A3939",
"t 	c #575655",
"u 	c #504F4F",
"v 	c #6C6A69",
"w 	c #92908C",
"x 	c #3A3A3A",
"y 	c #292828",
"z 	c #2D2D2D",
"A 	c #222221",
"B 	c #2F2F2E",
"C 	c #4A4949",
"D 	c #4B4B4A",
"E 	c #535252",
"F 	c #383837",
"G 	c #898785",
"H 	c #969491",
"I 	c #282727",
"J 	c #252424",
"K 	c #2D2D2C",
"L 	c #424141",
"M 	c #494848",
"N 	c #545352",
"O 	c #393838",
"P 	c #4D4C4B",
"Q 	c #3B3A3A",
"R 	c #323232",
"S 	c #696867",
"T 	c #7F7C7A",
"U 	c #868582",
"V 	c #969592",
"W 	c #A3A3A0",
"X 	c #302F2F",
"Y 	c #262626",
"Z 	c #292928",
"` 	c #4D4D4C",
" .	c #5A5959",
"..	c #5F5E5E",
"+.	c #575656",
"@.	c #676565",
"#.	c #686665",
"$.	c #757473",
"%.	c #84807E",
"&.	c #7E7C7A",
"*.	c #181717",
"=.	c #131212",
"-.	c #1B1A1A",
";.	c #313030",
">.	c #2B2A2A",
",.	c #6B6A69",
"'.	c #70625D",
").	c #66544D",
"!.	c #947569",
"~.	c #7B6D66",
"{.	c #685C58",
"].	c #83817E",
"^.	c #767371",
"/.	c #726E6D",
"(.	c #979796",
"_.	c #1B1B1A",
":.	c #161515",
"<.	c #282828",
"[.	c #1F1F1E",
"}.	c #282827",
"|.	c #3D3C3C",
"1.	c #2F2E2E",
"2.	c #353535",
"3.	c #544642",
"4.	c #915E4C",
"5.	c #C49C8D",
"6.	c #A08A7F",
"7.	c #936C5E",
"8.	c #A1948E",
"9.	c #51504E",
"0.	c #8B8986",
"a.	c #898784",
"b.	c #868280",
"c.	c #83807E",
"d.	c #767473",
"e.	c #323131",
"f.	c #1C1C1B",
"g.	c #1A1A19",
"h.	c #2B2B2A",
"i.	c #4C4B4B",
"j.	c #555454",
"k.	c #5D5C5C",
"l.	c #514F4E",
"m.	c #4A4948",
"n.	c #434241",
"o.	c #62493F",
"p.	c #B28F83",
"q.	c #8D7165",
"r.	c #443733",
"s.	c #A06854",
"t.	c #9C7061",
"u.	c #352722",
"v.	c #454443",
"w.	c #6F6D6B",
"x.	c #797775",
"y.	c #7E7A78",
"z.	c #110F0E",
"A.	c #252524",
"B.	c #504F4E",
"C.	c #616060",
"D.	c #595858",
"E.	c #535251",
"F.	c #674C44",
"G.	c #905C4C",
"H.	c #7B5548",
"I.	c #8B7166",
"J.	c #C28F7C",
"K.	c #A37867",
"L.	c #834F3F",
"M.	c #4E403C",
"N.	c #666564",
"O.	c #232222",
"P.	c #2E2D2D",
"Q.	c #323231",
"R.	c #4B4A4A",
"S.	c #5C5A59",
"T.	c #595857",
"U.	c #2C2B2B",
"V.	c #483B37",
"W.	c #754F42",
"X.	c #744F41",
"Y.	c #6A4437",
"Z.	c #474645",
"`.	c #625F5E",
" +	c #706E6D",
".+	c #5E5D5C",
"++	c #2A2A29",
"@+	c #5D5C5B",
"#+	c #676665",
"$+	c #373736",
"%+	c #5C5B5B",
"&+	c #666565",
"*+	c #5B5A59",
"=+	c #272626",
"-+	c #353434",
";+	c #605F5F",
">+	c #565554",
",+	c #646363",
"'+	c #565555",
")+	c #555453",
"!+	c #4C4B4A",
"~+	c #1E1E1D",
"{+	c #2C2C2C",
"]+	c #3C3C3B",
"^+	c #2C2C2B",
"/+	c #5B5A5A",
"(+	c #5E5D5D",
"_+	c #5F5D5C",
":+	c #605E5D",
"<+	c #515050",
"[+	c #343433",
"}+	c #222222",
"|+	c #232322",
"1+	c #272727",
"2+	c #454544",
"3+	c #5F5E5D",
"4+	c #8C8986",
"5+	c #8F8C89",
"6+	c #585655",
"7+	c #686767",
"8+	c #525151",
"9+	c #585757",
"0+	c #6D6B6B",
"a+	c #94928E",
"b+	c #A5A3A0",
"c+	c #B0B2AF",
"d+	c #B8B9B6",
"e+	c #C0C3BF",
"f+	c #BBBCB8",
"g+	c #A4A6A3",
"h+	c #989591",
"i+	c #8C8A87",
"j+	c #7B7977",
"k+	c #2E2E2D",
"l+	c #30302F",
"m+	c #333332",
"n+	c #7B7876",
"o+	c #9C9A97",
"p+	c #AAA9A6",
"q+	c #B3B4B1",
"r+	c #CACEC9",
"s+	c #D3D7D2",
"t+	c #D4DCD5",
"u+	c #C3CAC6",
"v+	c #BCBFBC",
"w+	c #E0E7DF",
"x+	c #B7B9B6",
"y+	c #BABFBB",
"z+	c #B4B6B3",
"A+	c #9A9997",
"B+	c #868583",
"C+	c #5D5B5B",
"D+	c #121111",
"E+	c #B2B5B1",
"F+	c #C0C3C0",
"G+	c #D1D3CE",
"H+	c #DDDFD7",
"I+	c #E5E7DE",
"J+	c #E4E6DD",
"K+	c #D9E4DC",
"L+	c #CFD7D2",
"M+	c #B3B5B3",
"N+	c #BABDBA",
"O+	c #CFDCD5",
"P+	c #B6BAB7",
"Q+	c #AFAFAC",
"R+	c #B9BAB7",
"S+	c #92918E",
"T+	c #636261",
"U+	c #636262",
"V+	c #181716",
"W+	c #3E3E3D",
"X+	c #AAAAA6",
"Y+	c #C6CBC6",
"Z+	c #D4D7D1",
"`+	c #E7E8DF",
" @	c #E4E5DD",
".@	c #E2EBE2",
"+@	c #E7F1E7",
"@@	c #E2F0E6",
"#@	c #DDEDE4",
"$@	c #999895",
"%@	c #918F8C",
"&@	c #BDC5C1",
"*@	c #DAECE3",
"=@	c #B8B8B5",
"-@	c #B6B8B5",
";@	c #A4A29F",
">@	c #878482",
",@	c #262525",
"'@	c #444342",
")@	c #626161",
"!@	c #9A9793",
"~@	c #B5B8B5",
"{@	c #CACECA",
"]@	c #EBEEE4",
"^@	c #DCECE3",
"/@	c #F3F8ED",
"(@	c #EDF5EB",
"_@	c #D9E9E1",
":@	c #CED6D0",
"<@	c #A7A8A6",
"[@	c #BBC0BD",
"}@	c #C0C6C0",
"|@	c #9D9C99",
"1@	c #C5CEC8",
"2@	c #CDD7D1",
"3@	c #4D4C4C",
"4@	c #817E7C",
"5@	c #AEB0AC",
"6@	c #CCD5CF",
"7@	c #DADFD8",
"8@	c #E1EAE1",
"9@	c #E8F3E9",
"0@	c #D1D9D3",
"a@	c #CBD2CD",
"b@	c #C1C5C1",
"c@	c #B9BDBA",
"d@	c #B5B6B2",
"e@	c #CAD3CE",
"f@	c #A5A4A2",
"g@	c #B5BAB5",
"h@	c #41403F",
"i@	c #797674",
"j@	c #B0B0AE",
"k@	c #CED0CB",
"l@	c #DDE1DA",
"m@	c #D6DED7",
"n@	c #DBE9E0",
"o@	c #DEECE3",
"p@	c #D6E4DC",
"q@	c #D9DBD4",
"r@	c #D6D7D1",
"s@	c #B9BBB7",
"t@	c #C5CDC7",
"u@	c #5E3B3F",
"v@	c #71454A",
"w@	c #866467",
"x@	c #786567",
"y@	c #616161",
"z@	c #5B5B5B",
"A@	c #6E6C6B",
"B@	c #9B9B99",
"C@	c #C6CEC9",
"D@	c #C0C6C2",
"E@	c #B0B2B0",
"F@	c #BBA9AB",
"G@	c #C9B8B8",
"H@	c #DDE4DC",
"I@	c #E4B4B8",
"J@	c #F3E4DE",
"K@	c #EEBABD",
"L@	c #E3E8DF",
"M@	c #CED4CE",
"N@	c #C2C9C4",
"O@	c #C6C7C2",
"P@	c #CDD5CF",
"Q@	c #B06C74",
"R@	c #BD898F",
"S@	c #AD989B",
"T@	c #A3A3A3",
"U@	c #959595",
"V@	c #7E7E7E",
"W@	c #767574",
"X@	c #959492",
"Y@	c #A9A9A8",
"Z@	c #A7A8A7",
"`@	c #AC9DA0",
" #	c #B4B9B6",
".#	c #CC7281",
"+#	c #D0B1B2",
"@#	c #C3ADAE",
"##	c #B58D94",
"$#	c #AAABAA",
"%#	c #A7A7A6",
"&#	c #B2B3B2",
"*#	c #606060",
"=#	c #A69193",
"-#	c #909090",
";#	c #747474",
">#	c #757575",
",#	c #6A6A6A",
"'#	c #7C7C7C",
")#	c #9C9B9B",
"!#	c #A69E9F",
"~#	c #A6A3A3",
"{#	c #858585",
"]#	c #14370C",
"^#	c #16390E",
"/#	c #4E6349",
"(#	c #9D999A",
"_#	c #989797",
":#	c #969696",
"<#	c #939793",
"[#	c #193A11",
"}#	c #334E2D",
"|#	c #5B6D57",
"1#	c #183A10",
"2#	c #5D6E59",
"3#	c #1B3C14",
"4#	c #4C6147",
"5#	c #375231",
"6#	c #4D6248",
"7#	c #8D928C",
"8#	c #1C3D15",
"9#	c #858C84",
"0#	c #41593C",
"a#	c #576953",
"b#	c #1A3C13",
"c#	c #717D6E",
"d#	c #969995",
"e#	c #173910",
"f#	c #888E86",
"g#	c #5C6E58",
"h#	c #1E3F17",
"i#	c #24431D",
"j#	c #193B11",
"k#	c #445B3F",
"l#	c #3C5536",
"m#	c #7B7B7B",
"n#	c #646464",
"o#	c #908F8F",
"    . + @ # $ % & * = - ; > , > ' ) ! ~ { ] ^ / (               ",
"    _ : < [ [ } | 1 2 3 > 4 > 5 > 6 7 8 9 0 a b c (             ",
"d e f $ g h i i 4 j k 3 ) l m n o ! p q r s t u v w             ",
"x f f $ < $ y z A B C > r 5 5 ) 0 D C q p 9 E F , G H           ",
"< < [ $ @ i I J K p ! L M N O P q 3 Q ; F R m S T U V W         ",
"h < h * < < X Y Z ` m Q k 9 ! , _ > 9  ...+.@.#.$.U %.&.%.      ",
"*.=.$ * -.$ 4 A ;.Q ! - >.- i 7 > ! ,.'.).!.~.{.Q L ].c ^./.(.  ",
"_.:.# <.= @ [.}.Q |.; 1.O |.X ~ 2.n 3.4.5.6.7.8.Q o 9.0.a.b.c.d.",
"e.f.g.4 % h.| ; r i.i.> j.q L k.l.m.n.o.p.q.r r.s.t.u.v.w.x.b y.",
"B g.z.A.} X e.I Q E i.B.C.D.5 k.E.j.k.m F.G.H.I.J.K.L.M.6 k N.  ",
"* < [.A O.P.Q.2 R.+.' R.j.q n S.p 5 T.9 h.U.V.W.X.Y.X Z.r `. +.+",
"< < j ++>.} I s q i.' R.@+q m.#+9 M T.q C ! 2.K $+s > ' ) %+&+*+",
"*.*.} =+Z @ z }.-+-+R.) ;+>+i.k.u i.,+'+)+T.E.!+j.q @+D.D.D.+.+.",
"~+~+{+1.]+^+A.3 5 5 k r ;+@+@+{ /+' ,+'+] ,+'+(+_+L @+C.' :+<+[+",
"}+}+|+U.4 i 1+@ 2+3+v.Q .+c.( V 4+4+H 5+U U v 6+7+8+@+n.0 8+9+L ",
"y z U.4 K % ++^+M *+v.l 0+c.a+b+c+d+e+f+g+g+h+h+i+j+;+, 0 8+(++.",
"P.@ k+Y l+g.% m+! l N +.n+o+p+q+r+s+t+u+v+w+x+c+y+z+A+B+N.C+, N ",
"D+f.;.|.- g.% ; r L /+..T E+F+G+H+I+J+K+G+L+M+N+O+P+Q+R+g+S+T+U+",
"V+B 6 -+<.>.;.W+l n t /+T X+Y+Z+`+ @.@+@@@#@O+P+$@%@&@*@=@-@;@>@",
",@|.6 L * P.}+'@m n )@R.{ !@~@{@ @]@^@+@/@(@_@:@v+<@[@}@|@1@2@X+",
"4 O | m i <.e.9 R.^+3@n 3+4@5@6@7@8@*@*@9@9@/@@@0@a@b@c@d@e@f@g@",
"p k+s k < * }+h@e.4 B.) 3+i@5+j@k@l@m@n@#@#@/@(@o@o@p@p@q@r@s@t@",
"m u@v@w@x@y@z@D |.s ! Q C A@b B@C@D@E@F@G@H@I@J@J@K@L@M@N@N@O@P@",
"9 Q@R@S@T@T@U@V@,+3@R.'+3@] W@X@Y@Z@T@T@`@ #.#+#@###$#%#T@T@$#&#",
"*#=#T@T@T@T@T@T@-#;#&+>#>#,#'#)#T@T@T@T@T@T@!#~#T@T@T@T@T@T@T@T@",
"{#T@T@]#^#/#T@T@T@(#(#T@T@_#(#T@T@T@T@T@T@T@T@T@T@T@]#T@T@T@T@T@",
":#T@T@]#<#[#T@]#}#T@|#1#2#T@]#]#3#T@4#5#]#T@]#T@]#T@]#T@T@T@T@T@",
"T@T@T@]#^#6#T@]#7#T@8#9#8#T@T@0#a#T@b#9#]#T@]#T@]#T@]#T@T@T@T@T@",
"T@T@T@]#T@T@T@]#T@T@8#9#8#T@c#[#d#T@b#9#]#T@e#f#]#T@]#T@T@T@T@T@",
"U@T@T@]#T@T@T@]#T@T@|#e#g#T@h#]#]#T@4#i#j#T@k#l#]#T@]#T@T@T@T@T@",
"m#T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@",
"n#o#T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@T@"};

Fl_Window *win_prefs=(Fl_Window *)0;

Fl_Tabs *tb_prefs=(Fl_Tabs *)0;

Fl_Group *gr_prefs_general=(Fl_Group *)0;

Fl_Input *retry_delay_in=(Fl_Input *)0;

Fl_Counter *threads_in=(Fl_Counter *)0;

Fl_Input *in_timeout=(Fl_Input *)0;

Fl_Check_Button *in_pasv_button=(Fl_Check_Button *)0;

Fl_Check_Button *in_no_cache_button=(Fl_Check_Button *)0;

Fl_Input *in_outputdir=(Fl_Input *)0;

Fl_Input *in_bps_per_dl=(Fl_Input *)0;

Fl_Group *gr_prefs_proxy=(Fl_Group *)0;

Fl_Group *gr_proxy_grp=(Fl_Group *)0;

Fl_Input *in_http_proxy_host=(Fl_Input *)0;

Fl_Input *in_http_proxy_port=(Fl_Input *)0;

Fl_Input *in_http_proxy_user=(Fl_Input *)0;

Fl_Input *in_http_proxy_passwd=(Fl_Input *)0;

Fl_Input *in_ftp_proxy_host=(Fl_Input *)0;

Fl_Input *in_ftp_proxy_port=(Fl_Input *)0;

Fl_Input *in_ftp_proxy_user=(Fl_Input *)0;

Fl_Input *in_ftp_proxy_passwd=(Fl_Input *)0;

Fl_Choice *in_ftp_proxy_type=(Fl_Choice *)0;

Fl_Menu_Item menu_in_ftp_proxy_type[] = {
 {("USER@SITE"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("USER@ProxyUser@SITE"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("USER@SITE_PROXYUSER"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("ProxyUser@SITE"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("LOGIN_then_USER@SITE"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("OPENSITE"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("SITESITE"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("HTTP proxy"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Check_Button *in_use_http_proxy=(Fl_Check_Button *)0;

Fl_Check_Button *in_use_ftp_proxy=(Fl_Check_Button *)0;

Fl_Check_Button *in_direct_conn_button=(Fl_Check_Button *)0;

Fl_Check_Button *in_use_proxy_button=(Fl_Check_Button *)0;

Fl_Group *gr_prefs_ftpsearch=(Fl_Group *)0;

Fl_Counter *mirrors_in=(Fl_Counter *)0;

Fl_Input *in_ping_timeout=(Fl_Input *)0;

Fl_Counter *in_simul_pings=(Fl_Counter *)0;

Fl_Check_Button *in_use_ftpsearch_button=(Fl_Check_Button *)0;

Fl_Choice *ftps_server_choice=(Fl_Choice *)0;

Fl_Menu_Item menu_ftps_server_choice[] = {
 {("filesearching.com"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("getfile.us"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {("www.searchftps.com"), 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 12, 0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Button *ok_button=(Fl_Button *)0;

Fl_Button *cancel_button=(Fl_Button *)0;

Fl_Window* make_prefs_win() {
  Fl_Window* w;
  { Fl_Window* o = win_prefs = new Fl_Window(475, 410, gettext("Prozgui Preferences Panel"));
    w = o;
    
#ifdef HAVE_LIBXPM		// X11 w/Xpm library
  fl_open_display();
  Pixmap pixmap, mask;		// Icon pixmaps
  XpmAttributes attrs;		// Attributes of icon
    
  memset(&attrs, 0, sizeof(attrs));

  XpmCreatePixmapFromData(fl_display, DefaultRootWindow(fl_display),
			 const_cast<char **>(Prozgui2_xpm), &pixmap, &mask, &attrs);
  o->icon((char *) pixmap);

#endif

{ Fl_Tabs* o = tb_prefs = new Fl_Tabs(20, 5, 450, 370);
      o->box(FL_UP_BOX);
      o->callback((Fl_Callback*)cb_prefs_tab);
      { Fl_Group* o = gr_prefs_general = new Fl_Group(30, 30, 440, 340, gettext("General"));
        o->labelfont(1);
        o->labelsize(12);
        { Fl_Group* o = new Fl_Group(30, 35, 430, 330);
          o->box(FL_ENGRAVED_FRAME);
          { Fl_Input* o = retry_delay_in = new Fl_Input(305, 75, 95, 25);
            o->type(2);
            o->labelsize(12);
            o->textsize(12);
          }
          { Fl_Counter* o = threads_in = new Fl_Counter(305, 45, 95, 25);
            o->labelsize(12);
            o->minimum(1);
            o->maximum(30);
            o->step(1);
            o->value(4);
            o->textsize(12);
            o->type(FL_SIMPLE_COUNTER);
          }
          { Fl_Box* o = new Fl_Box(60, 45, 190, 25, gettext("Number of Threads:"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Input* o = in_timeout = new Fl_Input(305, 105, 95, 25);
            o->type(2);
            o->labelsize(12);
            o->textsize(12);
          }
          { Fl_Check_Button* o = in_pasv_button = new Fl_Check_Button(60, 195, 300, 30, gettext("Use PASV for FTP transfers (recommended)"));
            o->down_box(FL_DIAMOND_DOWN_BOX);
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Check_Button* o = in_no_cache_button = new Fl_Check_Button(60, 235, 340, 35, gettext("Ask the HTTP proxies not to cache requests between sessions (default is off)"));
            o->down_box(FL_DIAMOND_DOWN_BOX);
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Input* o = in_outputdir = new Fl_Input(60, 310, 340, 25);
            o->labelsize(12);
            o->textsize(12);
            o->align(FL_ALIGN_TOP);
          }
          { Fl_Input* o = in_bps_per_dl = new Fl_Input(305, 135, 95, 25);
            o->type(1);
            o->labelsize(11);
            o->textsize(12);
            o->align(FL_ALIGN_TOP);
          }
          { Fl_Box* o = new Fl_Box(60, 75, 210, 25, gettext("Retry Delay (Sec):"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Box* o = new Fl_Box(60, 105, 210, 25, gettext("Timeout Period (Sec):"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Box* o = new Fl_Box(60, 275, 340, 25, gettext("Directory to download the files:"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Box* o = new Fl_Box(60, 135, 240, 40, gettext("Limit bandwith usage PER download to (Kbps) (0 = unlimited):"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          o->end();
        }
        o->end();
      }
      { Fl_Group* o = gr_prefs_proxy = new Fl_Group(30, 35, 440, 335, gettext("Proxies"));
        o->labelfont(1);
        o->labelsize(12);
        o->hide();
        { Fl_Group* o = new Fl_Group(30, 35, 435, 325);
          o->box(FL_ENGRAVED_BOX);
          { Fl_Group* o = gr_proxy_grp = new Fl_Group(40, 80, 420, 270);
            o->box(FL_ENGRAVED_BOX);
            { Fl_Input* o = in_http_proxy_host = new Fl_Input(145, 115, 125, 25, gettext("Hostname:"));
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
            }
            { Fl_Input* o = in_http_proxy_port = new Fl_Input(325, 115, 115, 25, gettext("Port:"));
              o->type(2);
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
            }
            { Fl_Box* o = new Fl_Box(45, 90, 85, 25, gettext("HTTP Proxy:"));
              o->labelfont(1);
              o->labelsize(12);
              o->align(FL_ALIGN_WRAP);
            }
            { Fl_Input* o = in_http_proxy_user = new Fl_Input(145, 145, 125, 25, gettext("Username:"));
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
            }
            { Fl_Input* o = in_http_proxy_passwd = new Fl_Input(145, 175, 125, 25, gettext("Password:"));
              o->type(5);
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
            }
            { Fl_Input* o = in_ftp_proxy_host = new Fl_Input(145, 230, 125, 25, gettext("Hostname:"));
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
            }
            { Fl_Input* o = in_ftp_proxy_port = new Fl_Input(325, 230, 115, 25, gettext("Port:"));
              o->type(2);
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
            }
            { Fl_Input* o = in_ftp_proxy_user = new Fl_Input(145, 260, 125, 25, gettext("Username:"));
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
            }
            { Fl_Input* o = in_ftp_proxy_passwd = new Fl_Input(145, 290, 125, 25, gettext("Password:"));
              o->type(5);
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
            }
            { Fl_Box* o = new Fl_Box(45, 205, 85, 25, gettext("FTP Proxy:"));
              o->labelfont(1);
              o->labelsize(12);
              o->align(FL_ALIGN_WRAP);
            }
            { Fl_Choice* o = in_ftp_proxy_type = new Fl_Choice(145, 320, 125, 25, gettext("FTP Proxy Type:"));
              o->down_box(FL_BORDER_BOX);
              o->labelsize(12);
              o->textsize(12);
              o->align(132);
              o->menu(menu_in_ftp_proxy_type);
            }
            { Fl_Check_Button* o = in_use_http_proxy = new Fl_Check_Button(145, 90, 135, 20, gettext("Use HTTP Proxy"));
              o->down_box(FL_DIAMOND_DOWN_BOX);
              o->labelsize(12);
              o->align(132|FL_ALIGN_INSIDE);
            }
            { Fl_Check_Button* o = in_use_ftp_proxy = new Fl_Check_Button(145, 205, 135, 20, gettext("Use FTP Proxy"));
              o->down_box(FL_DIAMOND_DOWN_BOX);
              o->labelsize(12);
              o->align(132|FL_ALIGN_INSIDE);
            }
            o->end();
          }
          { Fl_Group* o = new Fl_Group(55, 40, 285, 45);
            { Fl_Check_Button* o = in_direct_conn_button = new Fl_Check_Button(55, 40, 265, 25, gettext("Direct Connection to the Internet"));
              o->type(102);
              o->down_box(FL_DIAMOND_DOWN_BOX);
              o->labelsize(12);
              o->callback((Fl_Callback*)cb_prefs_conn);
              o->align(132|FL_ALIGN_INSIDE);
            }
            { Fl_Check_Button* o = in_use_proxy_button = new Fl_Check_Button(55, 60, 235, 20, gettext("Use proxies"));
              o->type(102);
              o->down_box(FL_DIAMOND_DOWN_BOX);
              o->labelsize(12);
              o->callback((Fl_Callback*)cb_prefs_use_proxy);
              o->align(132|FL_ALIGN_INSIDE);
            }
            o->end();
          }
          o->end();
        }
        o->end();
      }
      { Fl_Group* o = gr_prefs_ftpsearch = new Fl_Group(30, 35, 440, 335, gettext("FTP Search"));
        o->labelfont(1);
        o->labelsize(12);
        o->hide();
        { Fl_Group* o = new Fl_Group(30, 35, 425, 325);
          o->box(FL_ENGRAVED_FRAME);
          { Fl_Box* o = new Fl_Box(55, 90, 210, 25, gettext("Number of mirrors to request:"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Counter* o = mirrors_in = new Fl_Counter(300, 90, 140, 25);
            o->labelsize(12);
            o->minimum(1);
            o->maximum(1000);
            o->step(1);
            o->value(40);
            o->textsize(12);
            o->type(FL_SIMPLE_COUNTER);
          }
          { Fl_Box* o = new Fl_Box(55, 125, 210, 25, gettext("Ping Timeout (Sec):"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Input* o = in_ping_timeout = new Fl_Input(300, 125, 140, 25);
            o->type(2);
            o->labelsize(12);
            o->textsize(12);
          }
          { Fl_Box* o = new Fl_Box(55, 160, 230, 25, gettext("Number of mirrors to ping at once:"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Counter* o = in_simul_pings = new Fl_Counter(300, 160, 140, 25);
            o->labelsize(12);
            o->minimum(1);
            o->maximum(30);
            o->step(1);
            o->value(5);
            o->textsize(12);
            o->type(FL_SIMPLE_COUNTER);
          }
          { Fl_Check_Button* o = in_use_ftpsearch_button = new Fl_Check_Button(55, 200, 295, 25, gettext("Do FTP Search automatically"));
            o->down_box(FL_DIAMOND_DOWN_BOX);
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          { Fl_Box* o = new Fl_Box(55, 55, 180, 25, gettext("FTP Search Server to use:"));
            o->labelsize(12);
            o->align(132|FL_ALIGN_INSIDE);
          }
          o->end();
        }
        { Fl_Choice* o = ftps_server_choice = new Fl_Choice(300, 55, 140, 25);
          o->down_box(FL_BORDER_BOX);
          o->labelsize(12);
          o->textsize(12);
          o->align(132);
          o->menu(menu_ftps_server_choice);
        }
        o->end();
      }
      o->end();
    }
    { Fl_Button* o = ok_button = new Fl_Button(265, 385, 70, 20, gettext("Ok"));
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_prefs_ok);
    }
    { Fl_Button* o = cancel_button = new Fl_Button(365, 385, 70, 20, gettext("Cancel"));
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_prefs_cancel);
    }
    o->end();
  }
  return w;
}

Fl_Window *win_about=(Fl_Window *)0;

#include <FL/Fl_Pixmap.H>
static const char *idata_Prozgui1[] = {
"130 130 1567 2",
"  \tc None",
". \tc #838C83",
"+ \tc #858C84",
"@ \tc #868E84",
"# \tc #868D84",
"$ \tc #878E86",
"% \tc #898E86",
"& \tc #888D86",
"* \tc #8A8F86",
"= \tc #8A8E86",
"- \tc #8A8E87",
"; \tc #8C8E87",
"> \tc #8C8F87",
", \tc #8C8E88",
"\' \tc #8A8D86",
") \tc #8B8D87",
"! \tc #8B8D86",
"~ \tc #8C8F88",
"{ \tc #8B8E88",
"] \tc #8B8E87",
"^ \tc #8B8F88",
"/ \tc #8A8F88",
"( \tc #8C8F89",
"_ \tc #8B8F89",
": \tc #8B8F8A",
"< \tc #8C8E8A",
"[ \tc #8A8F89",
"} \tc #8B8E89",
"| \tc #8A8E89",
"1 \tc #8A8E88",
"2 \tc #898E88",
"3 \tc #898F88",
"4 \tc #888E88",
"5 \tc #888D88",
"6 \tc #878E88",
"7 \tc #868D88",
"8 \tc #878D88",
"9 \tc #868C88",
"0 \tc #858C87",
"a \tc #848C88",
"b \tc #848C87",
"c \tc #848C86",
"d \tc #838B86",
"e \tc #828B86",
"f \tc #828A86",
"g \tc #808A86",
"h \tc #7F8A86",
"i \tc #7E8986",
"j \tc #7E8985",
"k \tc #7E8A85",
"l \tc #808A87",
"m \tc #818A86",
"n \tc #828B87",
"o \tc #828C87",
"p \tc #828C88",
"q \tc #838C87",
"r \tc #848D88",
"s \tc #848E88",
"t \tc #868D89",
"u \tc #868E89",
"v \tc #868E88",
"w \tc #878F8A",
"x \tc #878E8B",
"y \tc #868E8B",
"z \tc #858D8A",
"A \tc #838C8B",
"B \tc #828B88",
"C \tc #7E8783",
"D \tc #899189",
"E \tc #8A9289",
"F \tc #8B928A",
"G \tc #8B9189",
"H \tc #8C918A",
"I \tc #8A9088",
"J \tc #8C9087",
"K \tc #8C9088",
"L \tc #8B9087",
"M \tc #8B8F87",
"N \tc #8B8E86",
"O \tc #8A8C86",
"P \tc #8B8C86",
"Q \tc #8D8E88",
"R \tc #8C8E89",
"S \tc #8C9089",
"T \tc #8B9089",
"U \tc #8B908A",
"V \tc #8A8E8A",
"W \tc #898E89",
"X \tc #888F89",
"Y \tc #888E8A",
"Z \tc #888E89",
"` \tc #878E8A",
" .\tc #878E89",
"..\tc #868E8A",
"+.\tc #858E89",
"@.\tc #848E8A",
"#.\tc #858E8A",
"$.\tc #848F8A",
"%.\tc #878F88",
"&.\tc #868F8A",
"*.\tc #878F89",
"=.\tc #888F8A",
"-.\tc #88908B",
";.\tc #888F8C",
">.\tc #878F8C",
",.\tc #868E8C",
"\'.\tc #8A9288",
").\tc #8A928A",
"!.\tc #8B9289",
"~.\tc #8C9189",
"{.\tc #8B8F86",
"].\tc #8C8D88",
"^.\tc #8C8D87",
"/.\tc #898F8A",
"(.\tc #898F89",
"_.\tc #8A8F8A",
":.\tc #89908A",
"<.\tc #88908A",
"[.\tc #89908B",
"}.\tc #878F8B",
"|.\tc #87908B",
"1.\tc #868F8B",
"2.\tc #86908A",
"3.\tc #87908A",
"4.\tc #889089",
"5.\tc #879089",
"6.\tc #888F88",
"7.\tc #888F8B",
"8.\tc #88908C",
"9.\tc #838C88",
"0.\tc #899089",
"a.\tc #8A908A",
"b.\tc #8B918A",
"c.\tc #8C8E86",
"d.\tc #8B8D88",
"e.\tc #8B8C87",
"f.\tc #898B85",
"g.\tc #8C8C87",
"h.\tc #8B9088",
"i.\tc #898E8A",
"j.\tc #899088",
"k.\tc #888F87",
"l.\tc #898E87",
"m.\tc #898F8B",
"n.\tc #889088",
"o.\tc #8A9089",
"p.\tc #8A8F87",
"q.\tc #898B86",
"r.\tc #898A84",
"s.\tc #8A8C87",
"t.\tc #8D8D88",
"u.\tc #848580",
"v.\tc #8D8E89",
"w.\tc #898A86",
"x.\tc #848681",
"y.\tc #898D86",
"z.\tc #868F88",
"A.\tc #898F87",
"B.\tc #868D8A",
"C.\tc #858C88",
"D.\tc #889087",
"E.\tc #899087",
"F.\tc #8D8E87",
"G.\tc #898A85",
"H.\tc #898A82",
"I.\tc #868682",
"J.\tc #848581",
"K.\tc #666764",
"L.\tc #6E6E6D",
"M.\tc #848484",
"N.\tc #696969",
"O.\tc #8C8C8C",
"P.\tc #656565",
"Q.\tc #888888",
"R.\tc #636362",
"S.\tc #808080",
"T.\tc #868785",
"U.\tc #858683",
"V.\tc #91948F",
"W.\tc #888A85",
"X.\tc #898C87",
"Y.\tc #888B86",
"Z.\tc #888B85",
"`.\tc #8A8E85",
" +\tc #878E8C",
".+\tc #898F86",
"++\tc #8E8E88",
"@+\tc #898984",
"#+\tc #757874",
"$+\tc #525350",
"%+\tc #464645",
"&+\tc #262626",
"*+\tc #5D5D5D",
"=+\tc #444444",
"-+\tc #616161",
";+\tc #666666",
">+\tc #636363",
",+\tc #747474",
"\'+\tc #818181",
")+\tc #606060",
"!+\tc #7C7C7C",
"~+\tc #6F6F6F",
"{+\tc #7B7B7B",
"]+\tc #6D6D6D",
"^+\tc #8A8A8A",
"/+\tc #757575",
"(+\tc #767676",
"_+\tc #858585",
":+\tc #7C7C7B",
"<+\tc #868885",
"[+\tc #828480",
"}+\tc #868D87",
"|+\tc #858C86",
"1+\tc #848D87",
"2+\tc #878C87",
"3+\tc #878D87",
"4+\tc #878E87",
"5+\tc #878D86",
"6+\tc #888E85",
"7+\tc #8B8E85",
"8+\tc #8A8E84",
"9+\tc #8B8C84",
"0+\tc #8A8C83",
"a+\tc #8B8E84",
"b+\tc #898E8C",
"c+\tc #7C7E78",
"d+\tc #494A48",
"e+\tc #383838",
"f+\tc #222222",
"g+\tc #3D3D3D",
"h+\tc #3B3B3B",
"i+\tc #181818",
"j+\tc #535353",
"k+\tc #5A5A5A",
"l+\tc #777777",
"m+\tc #8D8D8D",
"n+\tc #727272",
"o+\tc #909090",
"p+\tc #9C9C9C",
"q+\tc #939393",
"r+\tc #828282",
"s+\tc #959595",
"t+\tc #8F8F8F",
"u+\tc #979797",
"v+\tc #989898",
"w+\tc #929292",
"x+\tc #969696",
"y+\tc #9B9C9A",
"z+\tc #888B87",
"A+\tc #8B8C82",
"B+\tc #8A8D83",
"C+\tc #8A8F84",
"D+\tc #898F8C",
"E+\tc #888E8C",
"F+\tc #5F605C",
"G+\tc #50504E",
"H+\tc #000000",
"I+\tc #131313",
"J+\tc #1F1F1F",
"K+\tc #363636",
"L+\tc #2E2E2E",
"M+\tc #101010",
"N+\tc #555555",
"O+\tc #353535",
"P+\tc #393939",
"Q+\tc #333333",
"R+\tc #2B2B2B",
"S+\tc #272727",
"T+\tc #141414",
"U+\tc #4D4D4D",
"V+\tc #7E7E7E",
"W+\tc #3F3F3F",
"X+\tc #585858",
"Y+\tc #8E8E8E",
"Z+\tc #797979",
"`+\tc #7A7A7A",
" @\tc #8E908C",
".@\tc #858E88",
"+@\tc #858D86",
"@@\tc #868C86",
"#@\tc #868C87",
"$@\tc #888C86",
"%@\tc #8A9085",
"&@\tc #8C8F86",
"*@\tc #868982",
"=@\tc #545652",
"-@\tc #3E3E3D",
";@\tc #050505",
">@\tc #0D0D0D",
",@\tc #323232",
"\'@\tc #202020",
")@\tc #3C3C3C",
"!@\tc #4E4E4E",
"~@\tc #474747",
"{@\tc #4A4A4A",
"]@\tc #525252",
"^@\tc #3E3E3E",
"/@\tc #6C6C6C",
"(@\tc #5F5F5F",
"_@\tc #424242",
":@\tc #5E5E5E",
"<@\tc #404040",
"[@\tc #717171",
"}@\tc #949694",
"|@\tc #888E87",
"1@\tc #888E8B",
"2@\tc #8B8F84",
"3@\tc #8C9086",
"4@\tc #898C85",
"5@\tc #595B57",
"6@\tc #121212",
"7@\tc #1A1A1A",
"8@\tc #1C1C1C",
"9@\tc #313131",
"0@\tc #2C2C2C",
"a@\tc #070707",
"b@\tc #212121",
"c@\tc #373737",
"d@\tc #3A3A3A",
"e@\tc #0C0C0C",
"f@\tc #4C4C4C",
"g@\tc #4F4F4F",
"h@\tc #6E6E6E",
"i@\tc #5B5B5B",
"j@\tc #787878",
"k@\tc #6A6A6A",
"l@\tc #626262",
"m@\tc #868686",
"n@\tc #6B6B6B",
"o@\tc #8B8B8B",
"p@\tc #7E807C",
"q@\tc #8C8E84",
"r@\tc #8C9085",
"s@\tc #8D9086",
"t@\tc #8A8D85",
"u@\tc #7F827C",
"v@\tc #363836",
"w@\tc #0A0A0A",
"x@\tc #171717",
"y@\tc #161616",
"z@\tc #080808",
"A@\tc #292929",
"B@\tc #1B1B1B",
"C@\tc #494949",
"D@\tc #5C5C5C",
"E@\tc #343434",
"F@\tc #454545",
"G@\tc #7F7F7F",
"H@\tc #9E9E9E",
"I@\tc #949792",
"J@\tc #89908C",
"K@\tc #8B9086",
"L@\tc #656863",
"M@\tc #0D0E0D",
"N@\tc #1E1E1E",
"O@\tc #434343",
"P@\tc #242424",
"Q@\tc #2A2A2A",
"R@\tc #464646",
"S@\tc #737373",
"T@\tc #7D7D7D",
"U@\tc #8A8C82",
"V@\tc #8C8F84",
"W@\tc #8A8F85",
"X@\tc #585955",
"Y@\tc #545454",
"Z@\tc #707070",
"`@\tc #646464",
" #\tc #505050",
".#\tc #878787",
"+#\tc #9A9A9A",
"@#\tc #A3A3A3",
"##\tc #8D908A",
"$#\tc #858D88",
"%#\tc #858D87",
"&#\tc #878D89",
"*#\tc #888B82",
"=#\tc #696A66",
"-#\tc #2D2D2D",
";#\tc #303030",
">#\tc #111111",
",#\tc #232323",
"\'#\tc #414141",
")#\tc #2F2F2F",
"!#\tc #575757",
"~#\tc #7E7F7E",
"{#\tc #898B80",
"]#\tc #8D8F84",
"^#\tc #8D9084",
"/#\tc #8B8D84",
"(#\tc #0F0F0F",
"_#\tc #282828",
":#\tc #676767",
"<#\tc #191919",
"[#\tc #4B4B4B",
"}#\tc #898D88",
"|#\tc #878C88",
"1#\tc #888A7E",
"2#\tc #8D8E84",
"3#\tc #8D9085",
"4#\tc #8D8F86",
"5#\tc #8D8F88",
"6#\tc #8B8C85",
"7#\tc #222220",
"8#\tc #686868",
"9#\tc #949494",
"0#\tc #787978",
"a#\tc #878B85",
"b#\tc #868E87",
"c#\tc #86877B",
"d#\tc #8E8F85",
"e#\tc #8D8F87",
"f#\tc #585A56",
"g#\tc #1D1D1D",
"h#\tc #484848",
"i#\tc #515151",
"j#\tc #252525",
"k#\tc #151515",
"l#\tc #0E0E0E",
"m#\tc #7B7C7B",
"n#\tc #888C87",
"o#\tc #888D87",
"p#\tc #888D82",
"q#\tc #8A8C85",
"r#\tc #141413",
"s#\tc #898989",
"t#\tc #838383",
"u#\tc #767876",
"v#\tc #8D9088",
"w#\tc #6E6F6A",
"x#\tc #7E807E",
"y#\tc #8A8D87",
"z#\tc #8D9087",
"A#\tc #444544",
"B#\tc #565656",
"C#\tc #575452",
"D#\tc #564A47",
"E#\tc #4E423D",
"F#\tc #6A6261",
"G#\tc #535251",
"H#\tc #595959",
"I#\tc #AAAAAA",
"J#\tc #474847",
"K#\tc #8A8D89",
"L#\tc #898D84",
"M#\tc #767872",
"N#\tc #232020",
"O#\tc #5F3D2C",
"P#\tc #5C2412",
"Q#\tc #A98C76",
"R#\tc #8A725E",
"S#\tc #675042",
"T#\tc #5E3028",
"U#\tc #402920",
"V#\tc #383030",
"W#\tc #7F807F",
"X#\tc #747673",
"Y#\tc #868A86",
"Z#\tc #8C8F8A",
"`#\tc #8A8D84",
" $\tc #3A3B39",
".$\tc #5E4C4C",
"+$\tc #795A51",
"@$\tc #825846",
"#$\tc #A57B66",
"$$\tc #C0A288",
"%$\tc #BEA78C",
"&$\tc #8D7A65",
"*$\tc #796554",
"=$\tc #8A7771",
"-$\tc #A39A95",
";$\tc #4C2923",
">$\tc #706160",
",$\tc #3A393A",
"\'$\tc #9B9B9B",
")$\tc #9D9D9D",
"!$\tc #5B5C5B",
"~$\tc #7A7E7A",
"{$\tc #878D8A",
"]$\tc #898D83",
"^$\tc #888C85",
"/$\tc #8E605A",
"($\tc #C27C64",
"_$\tc #BF9377",
":$\tc #BD9F83",
"<$\tc #C1AA8F",
"[$\tc #766655",
"}$\tc #85715D",
"|$\tc #AA9C8E",
"1$\tc #E3D9CE",
"2$\tc #AE9C90",
"3$\tc #3B180E",
"4$\tc #401D1B",
"5$\tc #584136",
"6$\tc #403E3C",
"7$\tc #7C807C",
"8$\tc #898D87",
"9$\tc #898D89",
"0$\tc #878C83",
"a$\tc #70726D",
"b$\tc #98564A",
"c$\tc #BC7C62",
"d$\tc #BE997C",
"e$\tc #BEA488",
"f$\tc #AE9A81",
"g$\tc #867260",
"h$\tc #7E6856",
"i$\tc #3A2926",
"j$\tc #867A68",
"k$\tc #482E27",
"l$\tc #594132",
"m$\tc #674C3F",
"n$\tc #755B49",
"o$\tc #3F2829",
"p$\tc #362320",
"q$\tc #A0A0A0",
"r$\tc #919191",
"s$\tc #8E8F8E",
"t$\tc #878B83",
"u$\tc #373936",
"v$\tc #727271",
"w$\tc #130E0E",
"x$\tc #754434",
"y$\tc #9A593B",
"z$\tc #CE9D81",
"A$\tc #C0A68A",
"B$\tc #8E7A66",
"C$\tc #867160",
"D$\tc #725645",
"E$\tc #3C2919",
"F$\tc #2E221E",
"G$\tc #5D4439",
"H$\tc #735947",
"I$\tc #806752",
"J$\tc #A17E60",
"K$\tc #391C15",
"L$\tc #320A07",
"M$\tc #5F5552",
"N$\tc #A6A6A6",
"O$\tc #8A8D88",
"P$\tc #898C84",
"Q$\tc #0F0F0E",
"R$\tc #0B0B0B",
"S$\tc #443937",
"T$\tc #9B6049",
"U$\tc #AD856B",
"V$\tc #86705F",
"W$\tc #6E5340",
"X$\tc #523A2C",
"Y$\tc #543C33",
"Z$\tc #654C3E",
"`$\tc #785E4B",
" %\tc #927760",
".%\tc #C9A68A",
"+%\tc #D2A688",
"@%\tc #B37F5D",
"#%\tc #4F1E0B",
"$%\tc #3C1405",
"%%\tc #342C29",
"&%\tc #A5A5A5",
"*%\tc #878B86",
"=%\tc #898C88",
"-%\tc #8B8D85",
";%\tc #7B7E78",
">%\tc #2A1C1C",
",%\tc #905746",
"\'%\tc #966551",
")%\tc #6F4F3E",
"!%\tc #60473E",
"~%\tc #5A4036",
"{%\tc #866D55",
"]%\tc #9C8069",
"^%\tc #DCB4A1",
"/%\tc #D4A694",
"(%\tc #B7846C",
"_%\tc #9B5E42",
":%\tc #965A3E",
"<%\tc #58382F",
"[%\tc #522E16",
"}%\tc #5A5C5A",
"|%\tc #8E918D",
"1%\tc #8E8F87",
"2%\tc #8E9088",
"3%\tc #3C3D3A",
"4%\tc #3A302E",
"5%\tc #775644",
"6%\tc #9F6E5D",
"7%\tc #AD8570",
"8%\tc #B7957D",
"9%\tc #C69784",
"0%\tc #C48F7F",
"a%\tc #AC725F",
"b%\tc #A05F4C",
"c%\tc #8C4F3D",
"d%\tc #4E3223",
"e%\tc #787676",
"f%\tc #7B7F79",
"g%\tc #8A8C88",
"h%\tc #8B8D89",
"i%\tc #8C8D85",
"j%\tc #2F2F2E",
"k%\tc #3E3636",
"l%\tc #5C4C45",
"m%\tc #796359",
"n%\tc #6E4B3A",
"o%\tc #816155",
"p%\tc #7D5445",
"q%\tc #582E20",
"r%\tc #726665",
"s%\tc #8C8D86",
"t%\tc #757872",
"u%\tc #7A7C78",
"v%\tc #8B8C88",
"w%\tc #8D8D86",
"x%\tc #454543",
"y%\tc #818280",
"z%\tc #121312",
"A%\tc #787977",
"B%\tc #808280",
"C%\tc #363634",
"D%\tc #6C6E6B",
"E%\tc #82847E",
"F%\tc #676866",
"G%\tc #8D8E86",
"H%\tc #4B4C49",
"I%\tc #828280",
"J%\tc #82837C",
"K%\tc #303130",
"L%\tc #A9A9A9",
"M%\tc #999999",
"N%\tc #858782",
"O%\tc #3F423D",
"P%\tc #ACACAC",
"Q%\tc #BCBCBC",
"R%\tc #AEAEAE",
"S%\tc #ACAEAE",
"T%\tc #B7B8B8",
"U%\tc #BDBDBD",
"V%\tc #A7A7A7",
"W%\tc #B1B1B1",
"X%\tc #A2A2A2",
"Y%\tc #82847F",
"Z%\tc #767675",
"`%\tc #8C8D8B",
" &\tc #92938E",
".&\tc #9E9D9A",
"+&\tc #A3A29E",
"@&\tc #B0AEAB",
"#&\tc #BDBEBB",
"$&\tc #CED6D4",
"%&\tc #CFD8D6",
"&&\tc #BCBDBB",
"*&\tc #BFCBCB",
"=&\tc #BCC9C8",
"-&\tc #A8ADAB",
";&\tc #ACADAA",
">&\tc #BAC5C5",
",&\tc #B8BCBC",
"\'&\tc #B0B0B0",
")&\tc #B6B6B6",
"!&\tc #5C5C5A",
"~&\tc #8C8C88",
"{&\tc #9E9E9B",
"]&\tc #9A9A97",
"^&\tc #9E9E9A",
"/&\tc #A5A4A0",
"(&\tc #B0AEAA",
"_&\tc #BCB8B4",
":&\tc #C9C6C1",
"<&\tc #D0CDC8",
"[&\tc #D5D3CD",
"}&\tc #D5D4CE",
"|&\tc #B8BAB8",
"1&\tc #B1B2AE",
"2&\tc #A8AAA5",
"3&\tc #A2A4A0",
"4&\tc #DBF7F7",
"5&\tc #CCE2E0",
"6&\tc #A9ACA9",
"7&\tc #A4A4A4",
"8&\tc #A3A5A2",
"9&\tc #A8A9A6",
"0&\tc #AEACA8",
"a&\tc #B5B3AE",
"b&\tc #BDBBB6",
"c&\tc #C7C5BE",
"d&\tc #D3D1C8",
"e&\tc #DAD9CE",
"f&\tc #CAC9C3",
"g&\tc #BBBBB7",
"h&\tc #C1C2BD",
"i&\tc #D2D4CE",
"j&\tc #C6C8C3",
"k&\tc #BDC0BB",
"l&\tc #B6BAB4",
"m&\tc #D8ECEA",
"n&\tc #DFF8F6",
"o&\tc #A4ABA6",
"p&\tc #949790",
"q&\tc #D4F0F0",
"r&\tc #D0E0E0",
"s&\tc #B6BBBB",
"t&\tc #C4C4C4",
"u&\tc #C0C0C0",
"v&\tc #B7B7B7",
"w&\tc #7D7E7D",
"x&\tc #BCC2C3",
"y&\tc #BABEBC",
"z&\tc #C0BEB9",
"A&\tc #CCC8C2",
"B&\tc #D3D1C7",
"C&\tc #D8D6C9",
"D&\tc #DEDDCD",
"E&\tc #C6C5BD",
"F&\tc #A7A7A6",
"G&\tc #C1C3BD",
"H&\tc #D4D8CD",
"I&\tc #CCD2C8",
"J&\tc #CDD4CB",
"K&\tc #C0C5BC",
"L&\tc #ADB4AB",
"M&\tc #A1A69E",
"N&\tc #939590",
"O&\tc #D8F8F8",
"P&\tc #CEE7E7",
"Q&\tc #ACB1B0",
"R&\tc #ACADAD",
"S&\tc #BBBBBB",
"T&\tc #A8A8A8",
"U&\tc #A1A1A1",
"V&\tc #8A8B87",
"W&\tc #A8A9A9",
"X&\tc #D4E6E6",
"Y&\tc #C9CBC6",
"Z&\tc #D3D2CA",
"`&\tc #DDDDD0",
" *\tc #DBDDCD",
".*\tc #E0E2CE",
"+*\tc #E3E4D0",
"@*\tc #C6C7BD",
"#*\tc #D1D8CD",
"$*\tc #C4CCC0",
"%*\tc #B3B8AE",
"&*\tc #A3A79F",
"**\tc #BED2D0",
"=*\tc #B3C5C2",
"-*\tc #929894",
";*\tc #AFBEBB",
">*\tc #CBDEDE",
",*\tc #B9BEBE",
"\'*\tc #BFBFBF",
")*\tc #8A8B86",
"!*\tc #CED6D6",
"~*\tc #C2C4BF",
"{*\tc #CACDC4",
"]*\tc #DADBCC",
"^*\tc #D5D6C8",
"/*\tc #DFE2CD",
"(*\tc #E1E5CD",
"_*\tc #E2E7CE",
":*\tc #BDC0B7",
"<*\tc #C8CDC3",
"[*\tc #C8CDC0",
"}*\tc #B6BAAF",
"|*\tc #A6A8A2",
"1*\tc #8E908B",
"2*\tc #B2C3C0",
"3*\tc #D8F7F7",
"4*\tc #CCE3E3",
"5*\tc #B2B8B8",
"6*\tc #C3C3C3",
"7*\tc #AFAFAF",
"8*\tc #BCBEB9",
"9*\tc #C4C7BF",
"0*\tc #D1D6C7",
"a*\tc #DCE2D0",
"b*\tc #BEBFB7",
"c*\tc #D8DBC8",
"d*\tc #E3E8CE",
"e*\tc #DFEBD0",
"f*\tc #D8DACD",
"g*\tc #CCCEC3",
"h*\tc #BABCB6",
"i*\tc #ACAEA8",
"j*\tc #9B9C98",
"k*\tc #91928D",
"l*\tc #B1C2C0",
"m*\tc #CDE9E9",
"n*\tc #939994",
"o*\tc #A4A5A2",
"p*\tc #BFC5C5",
"q*\tc #CACACA",
"r*\tc #949592",
"s*\tc #9F9F9F",
"t*\tc #B0B1B0",
"u*\tc #BFC5BC",
"v*\tc #CCD2C6",
"w*\tc #D8DED0",
"x*\tc #BEC0B7",
"y*\tc #CDD4C3",
"z*\tc #CFD0C8",
"A*\tc #CECEC8",
"B*\tc #BEC0BB",
"C*\tc #B4B5B2",
"D*\tc #9E9F9A",
"E*\tc #B3C4C1",
"F*\tc #BACECC",
"G*\tc #939894",
"H*\tc #B1C2BF",
"I*\tc #D7F7F7",
"J*\tc #CDE0E0",
"K*\tc #B5B6B6",
"L*\tc #888886",
"M*\tc #B5B5B5",
"N*\tc #C6C6C6",
"O*\tc #C7CEC9",
"P*\tc #D8E6DC",
"Q*\tc #D4DDD0",
"R*\tc #BFC0BD",
"S*\tc #CDCDCA",
"T*\tc #C4C5C2",
"U*\tc #B6B7B4",
"V*\tc #B6BBB7",
"W*\tc #A6A8A3",
"X*\tc #9A9C96",
"Y*\tc #8D8F89",
"Z*\tc #B2C2C0",
"`*\tc #D0EAEA",
" =\tc #C8CBCB",
".=\tc #8C8D8C",
"+=\tc #B3B6B6",
"@=\tc #E4FAF3",
"#=\tc #D2D9CC",
"$=\tc #D4D4D2",
"%=\tc #CFD0CE",
"&=\tc #C9CAC8",
"*=\tc #C0C2BF",
"==\tc #BBBDBA",
"-=\tc #B6B8B4",
";=\tc #B9CAC7",
">=\tc #949994",
",=\tc #969894",
"\'=\tc #BEC3C3",
")=\tc #B2B2B2",
"!=\tc #8B8C8B",
"~=\tc #7C7E79",
"{=\tc #BFC6C2",
"]=\tc #C5CAC0",
"^=\tc #CBD1C9",
"/=\tc #B8BEB8",
"(=\tc #BFBFBE",
"_=\tc #D1D1D0",
":=\tc #D3D3D2",
"<=\tc #D1D2D0",
"[=\tc #CED0CE",
"}=\tc #CCCDCA",
"|=\tc #D1D9D8",
"1=\tc #B4BAB6",
"2=\tc #999B96",
"3=\tc #A0AAA6",
"4=\tc #D4F2F2",
"5=\tc #AFB4B4",
"6=\tc #B4B4B4",
"7=\tc #9C9C9A",
"8=\tc #B2B3B2",
"9=\tc #B1B5AD",
"0=\tc #C3CAC0",
"a=\tc #CFD6CD",
"b=\tc #D4DDD3",
"c=\tc #CBD3C9",
"d=\tc #D4E2D4",
"e=\tc #C5D0C6",
"f=\tc #D2D3D1",
"g=\tc #C1C2BE",
"h=\tc #C3D1CF",
"i=\tc #B1B9B9",
"j=\tc #BCBEBD",
"k=\tc #9B9C99",
"l=\tc #8D8F8A",
"m=\tc #8E8F8A",
"n=\tc #BEBEBE",
"o=\tc #BCC2BF",
"p=\tc #CBDBD7",
"q=\tc #CBD7D0",
"r=\tc #C7CFC6",
"s=\tc #CAD2C8",
"t=\tc #CCD7CC",
"u=\tc #D0E0D2",
"v=\tc #BFC6BD",
"w=\tc #D1D1CE",
"x=\tc #B8BCBB",
"y=\tc #BDC5C5",
"z=\tc #CEDEDD",
"A=\tc #A7A8A3",
"B=\tc #A6A7A5",
"C=\tc #9D9E9A",
"D=\tc #91928E",
"E=\tc #90918C",
"F=\tc #8F908C",
"G=\tc #8F908B",
"H=\tc #8E8E89",
"I=\tc #B4B5B5",
"J=\tc #D4EBE9",
"K=\tc #CBDBD3",
"L=\tc #BAC1B8",
"M=\tc #BEC4BC",
"N=\tc #C2CAC1",
"O=\tc #C9D5C9",
"P=\tc #D3DECE",
"Q=\tc #C2C7C0",
"R=\tc #C3C7C1",
"S=\tc #C5C7C4",
"T=\tc #D1D2D1",
"U=\tc #D1D1D1",
"V=\tc #CBCFCD",
"W=\tc #D0D7D4",
"X=\tc #BABBB6",
"Y=\tc #B3B3AF",
"Z=\tc #AAABA6",
"`=\tc #A4A59E",
" -\tc #A0A09B",
".-\tc #9C9D98",
"+-\tc #989893",
"@-\tc #959691",
"#-\tc #92948F",
"$-\tc #C2C7C7",
"%-\tc #B8C4C3",
"&-\tc #C2D4CE",
"*-\tc #ADB3AB",
"=-\tc #B3B9B2",
"--\tc #B9C0B8",
";-\tc #C4CCC3",
">-\tc #D0D9CA",
",-\tc #B8BDB7",
"\'-\tc #C3C7C0",
")-\tc #D0D3CD",
"!-\tc #D1D3D0",
"~-\tc #C5C5C5",
"{-\tc #C5C6C4",
"]-\tc #CBCCC8",
"^-\tc #BEBFBA",
"/-\tc #BDBDB7",
"(-\tc #BABAB4",
"_-\tc #B6B6B0",
":-\tc #B2B2AB",
"<-\tc #AAAAA3",
"[-\tc #A2A19C",
"}-\tc #9D9E98",
"|-\tc #92928E",
"1-\tc #CEDCDC",
"2-\tc #BBCCC8",
"3-\tc #A4A8A2",
"4-\tc #ACB1AB",
"5-\tc #B5BAB3",
"6-\tc #C0C7BF",
"7-\tc #CFD6CA",
"8-\tc #C6CDC3",
"9-\tc #CFD3CB",
"0-\tc #D1D3CE",
"a-\tc #D2D3D0",
"b-\tc #D2D2D1",
"c-\tc #CBCBCA",
"d-\tc #CECFCC",
"e-\tc #CBCBC8",
"f-\tc #CBCCC6",
"g-\tc #CCCDC6",
"h-\tc #CCCDC5",
"i-\tc #CBCBC4",
"j-\tc #C5C4BE",
"k-\tc #BCBBB4",
"l-\tc #B1B0AA",
"m-\tc #A7A6A0",
"n-\tc #9B9C95",
"o-\tc #969690",
"p-\tc #8F908A",
"q-\tc #8E908A",
"r-\tc #989999",
"s-\tc #AEB6B3",
"t-\tc #9CA09A",
"u-\tc #A6ABA4",
"v-\tc #BEC7C2",
"w-\tc #D2E0DA",
"x-\tc #AAACAB",
"y-\tc #CCD3C8",
"z-\tc #C5C7C2",
"A-\tc #D1D3CF",
"B-\tc #D3D3D0",
"C-\tc #D3D3D1",
"D-\tc #B3B3B3",
"E-\tc #C0C0BD",
"F-\tc #C1C1BD",
"G-\tc #D9D8D0",
"H-\tc #D1D0C8",
"I-\tc #C5C3BC",
"J-\tc #B8B7B0",
"K-\tc #ABA9A3",
"L-\tc #A1A19B",
"M-\tc #989993",
"N-\tc #94948F",
"O-\tc #90908B",
"P-\tc #8E8E8A",
"Q-\tc #B9BAB9",
"R-\tc #B2BFBC",
"S-\tc #C0D1CE",
"T-\tc #E0FAF8",
"U-\tc #E4FAF4",
"V-\tc #CDD6CA",
"W-\tc #B9BAB8",
"X-\tc #DEE0DB",
"Y-\tc #DEDEDD",
"Z-\tc #C5C6C5",
"`-\tc #D6D5CD",
" ;\tc #CDCAC3",
".;\tc #BDBBB4",
"+;\tc #B1AFA9",
"@;\tc #A6A6A0",
"#;\tc #9E9E98",
"$;\tc #C6CBCA",
"%;\tc #D9F5F3",
"&;\tc #DFFAF8",
"*;\tc #DEF2EC",
"=;\tc #CAD0C5",
"-;\tc #B8BAB7",
";;\tc #D2D3CE",
">;\tc #DFE0DB",
",;\tc #DFE0DA",
"\';\tc #D3D3CD",
");\tc #D3D3CE",
"!;\tc #C7C7C5",
"~;\tc #C6C6C5",
"{;\tc #C1C0BD",
"];\tc #D0CEC7",
"^;\tc #C3C0BA",
"/;\tc #B6B4AE",
"(;\tc #ABAAA5",
"_;\tc #9C9B97",
":;\tc #969691",
"<;\tc #BCC5C4",
"[;\tc #DCF8F6",
"};\tc #C8D3CC",
"|;\tc #C8CBC2",
"1;\tc #C5C7C3",
"2;\tc #D3D3CF",
"3;\tc #E0E0D9",
"4;\tc #E0E0D7",
"5;\tc #E0E0D8",
"6;\tc #BABAB9",
"7;\tc #D0CEC8",
"8;\tc #D2CFC8",
"9;\tc #C4C2BB",
"0;\tc #B8B6AF",
"a;\tc #ACAAA6",
"b;\tc #A5A39E",
"c;\tc #A09F9B",
"d;\tc #9A9A95",
"e;\tc #959690",
"f;\tc #C8D2D2",
"g;\tc #B0B1A8",
"h;\tc #C2C3B8",
"i;\tc #CECFC6",
"j;\tc #E0E0DA",
"k;\tc #D9D8CE",
"l;\tc #CDCAC4",
"m;\tc #C1BEB8",
"n;\tc #B5B4AE",
"o;\tc #AEACA7",
"p;\tc #AAA9A4",
"q;\tc #A6A4A0",
"r;\tc #9F9F9A",
"s;\tc #9A9994",
"t;\tc #92948E",
"u;\tc #A3A49F",
"v;\tc #B2B4A8",
"w;\tc #D0D1C7",
"x;\tc #BABAB7",
"y;\tc #D3D3CC",
"z;\tc #E0E0D6",
"A;\tc #E0E0D5",
"B;\tc #DFDFDD",
"C;\tc #CBCAC3",
"D;\tc #C1C0BA",
"E;\tc #B8B6B2",
"F;\tc #B2B2AC",
"G;\tc #B0B0AA",
"H;\tc #AEADA8",
"I;\tc #A7A7A1",
"J;\tc #A0A09C",
"K;\tc #9B9C96",
"L;\tc #989892",
"M;\tc #949590",
"N;\tc #90928C",
"O;\tc #BCC1BE",
"P;\tc #B7BAB9",
"Q;\tc #C2C7C5",
"R;\tc #BABAB6",
"S;\tc #D3D3CA",
"T;\tc #DFE0D5",
"U;\tc #A5A5A4",
"V;\tc #D6D6CD",
"W;\tc #CECDC5",
"X;\tc #C6C5BE",
"Y;\tc #C0BFBA",
"Z;\tc #BEBCB7",
"`;\tc #BFBDB7",
" >\tc #BABAB2",
".>\tc #A2A49E",
"+>\tc #9C9C98",
"@>\tc #969893",
"#>\tc #929490",
"$>\tc #90928D",
"%>\tc #8F918C",
"&>\tc #C2D0CE",
"*>\tc #ABAEAE",
"=>\tc #C1C6C5",
"->\tc #C7C7C0",
";>\tc #D3D3C9",
">>\tc #E0E0DC",
",>\tc #D4D4CB",
"\'>\tc #CFCFC6",
")>\tc #CDCDC5",
"!>\tc #CFCEC6",
"~>\tc #CDCCC4",
"{>\tc #C7C6BE",
"]>\tc #C0C0BA",
"^>\tc #B3B4AE",
"/>\tc #A8A8A3",
"(>\tc #9DA09A",
"_>\tc #9A9B96",
":>\tc #969993",
"<>\tc #949690",
"[>\tc #8F918B",
"}>\tc #8C908A",
"|>\tc #8C908B",
"1>\tc #D3DDDD",
"2>\tc #B5BAB9",
"3>\tc #E0E0DB",
"4>\tc #D0D0C8",
"5>\tc #D8D6CD",
"6>\tc #D8D8D0",
"7>\tc #D4D4CC",
"8>\tc #B8BAB3",
"9>\tc #AEAFA9",
"0>\tc #A7A8A2",
"a>\tc #A1A29D",
"b>\tc #9B9D96",
"c>\tc #989A94",
"d>\tc #90938C",
"e>\tc #8E918C",
"f>\tc #BEC2C1",
"g>\tc #B5BCBB",
"h>\tc #B9BBB5",
"i>\tc #C5C5C4",
"j>\tc #C6C7BF",
"k>\tc #D3D3CB",
"l>\tc #C7C7C4",
"m>\tc #C7C6C5",
"n>\tc #D4D4CD",
"o>\tc #C8C9C2",
"p>\tc #BDBEB7",
"q>\tc #B4B5AF",
"r>\tc #AEB0A9",
"s>\tc #A8A9A3",
"t>\tc #A4A69E",
"u>\tc #9E9F99",
"v>\tc #989A93",
"w>\tc #929590",
"x>\tc #90928E",
"y>\tc #8F928C",
"z>\tc #8E918B",
"A>\tc #B6BAB9",
"B>\tc #BABAB5",
"C>\tc #C7C6C0",
"D>\tc #C7C6C1",
"E>\tc #C7C7C3",
"F>\tc #D5D6D0",
"G>\tc #C5C5BE",
"H>\tc #BBBCB5",
"I>\tc #B4B6B0",
"J>\tc #ABACA6",
"K>\tc #9B9E98",
"L>\tc #979A94",
"M>\tc #90948E",
"N>\tc #8D918C",
"O>\tc #595956",
"P>\tc #484846",
"Q>\tc #CCD2D1",
"R>\tc #BABAB8",
"S>\tc #D4D4CE",
"T>\tc #D1D1C9",
"U>\tc #CACCC4",
"V>\tc #C4C6BD",
"W>\tc #BABBB5",
"X>\tc #B0B3AD",
"Y>\tc #A1A29C",
"Z>\tc #9B9E97",
"`>\tc #8D908B",
" ,\tc #757574",
".,\tc #474745",
"+,\tc #B7B7B5",
"@,\tc #D6D7CF",
"#,\tc #D1D2CB",
"$,\tc #CACCC5",
"%,\tc #C2C3BF",
"&,\tc #BDBEB9",
"*,\tc #B8B9B4",
"=,\tc #B4B6AF",
"-,\tc #B2B3AC",
";,\tc #ADAEA8",
">,\tc #A2A29D",
",,\tc #90938F",
"\',\tc #8B8E8A",
"),\tc #797976",
"!,\tc #555553",
"~,\tc #D4D5D2",
"{,\tc #CED0CC",
"],\tc #C9CAC6",
"^,\tc #C6C7BE",
"/,\tc #C2C2BC",
"(,\tc #B7B7B1",
"_,\tc #999C96",
":,\tc #8E928C",
"<,\tc #90908C",
"[,\tc #444542",
"},\tc #B6B7B5",
"|,\tc #CDCEC8",
"1,\tc #D8D8CF",
"2,\tc #D3D4CC",
"3,\tc #C9C8C2",
"4,\tc #B9B8B3",
"5,\tc #A8A9A4",
"6,\tc #9C9E98",
"7,\tc #949791",
"8,\tc #90948F",
"9,\tc #93938F",
"0,\tc #575855",
"a,\tc #C7C6C3",
"b,\tc #D4D5CC",
"c,\tc #C5C6BE",
"d,\tc #B5B6B0",
"e,\tc #A5A6A0",
"f,\tc #9B9D97",
"g,\tc #90938E",
"h,\tc #8F928D",
"i,\tc #989995",
"j,\tc #8B8B86",
"k,\tc #747471",
"l,\tc #2D2D2C",
"m,\tc #BDBDBC",
"n,\tc #C1C1BE",
"o,\tc #AFB1A9",
"p,\tc #A3A49E",
"q,\tc #989A95",
"r,\tc #959891",
"s,\tc #919590",
"t,\tc #91948E",
"u,\tc #8C8F8B",
"v,\tc #939490",
"w,\tc #7F807C",
"x,\tc #5B5B5A",
"y,\tc #D3D4CE",
"z,\tc #C4C6BE",
"A,\tc #B7B9B1",
"B,\tc #ACACA5",
"C,\tc #9EA19A",
"D,\tc #999B95",
"E,\tc #919490",
"F,\tc #6B6C68",
"G,\tc #4D4D4B",
"H,\tc #EBEBEA",
"I,\tc #CCCDC7",
"J,\tc #C0C1B9",
"K,\tc #B2B5AD",
"L,\tc #A6A7A2",
"M,\tc #A6A7A0",
"N,\tc #A4A5A0",
"O,\tc #A1A29E",
"P,\tc #9C9F99",
"Q,\tc #989B95",
"R,\tc #8E928D",
"S,\tc #939390",
"T,\tc #8B8A86",
"U,\tc #80817D",
"V,\tc #575755",
"W,\tc #BFBFBA",
"X,\tc #C7C6C4",
"Y,\tc #C9CAC4",
"Z,\tc #BCBEB8",
"`,\tc #B3B3AC",
" \'\tc #B2B4AC",
".\'\tc #B4B4AD",
"+\'\tc #B7B6B0",
"@\'\tc #BAB9B3",
"#\'\tc #B0B0AB",
"$\'\tc #A8AAA4",
"%\'\tc #9DA099",
"&\'\tc #8F928E",
"*\'\tc #8D908C",
"=\'\tc #8C8C86",
"-\'\tc #888883",
";\'\tc #7A7A76",
">\'\tc #4A4A48",
",\'\tc #91928C",
"\'\'\tc #BDBDBB",
")\'\tc #DDDDDD",
"!\'\tc #D2D3CD",
"~\'\tc #C4C6BF",
"{\'\tc #C1C2BA",
"]\'\tc #C4C3BC",
"^\'\tc #C6C6BE",
"/\'\tc #CACAC2",
"(\'\tc #CCCBC3",
"_\'\tc #C8C8C0",
":\'\tc #BFBFB7",
"<\'\tc #AEB1A9",
"[\'\tc #9FA29C",
"}\'\tc #949893",
"|\'\tc #8B908B",
"1\'\tc #8C8B86",
"2\'\tc #8A8A86",
"3\'\tc #747571",
"4\'\tc #61625E",
"5\'\tc #636462",
"6\'\tc #838381",
"7\'\tc #C0C0BC",
"8\'\tc #EAEAEA",
"9\'\tc #D2D3CB",
"0\'\tc #D1D2CA",
"a\'\tc #D7D8CE",
"b\'\tc #D9D9CF",
"c\'\tc #D4D5CD",
"d\'\tc #CECEC7",
"e\'\tc #C2C3BD",
"f\'\tc #B5B5B1",
"g\'\tc #A9AAA6",
"h\'\tc #A1A39F",
"i\'\tc #959794",
"j\'\tc #909390",
"k\'\tc #8C918B",
"l\'\tc #8B8F8B",
"m\'\tc #989895",
"n\'\tc #8B8B87",
"o\'\tc #8D8D87",
"p\'\tc #BBBCB6",
"q\'\tc #BEBFBB",
"r\'\tc #ACADAB",
"s\'\tc #ACACAA",
"t\'\tc #A0A09F",
"u\'\tc #9D9D9C",
"v\'\tc #979896",
"w\'\tc #8E928E",
"x\'\tc #8B8B88",
"y\'\tc #8D8C88",
"z\'\tc #C2C2BD",
"A\'\tc #BCBCBB",
"B\'\tc #D3D2D1",
"C\'\tc #919491",
"D\'\tc #8C908C",
"E\'\tc #929290",
"F\'\tc #9E9F9E",
"G\'\tc #989896",
"H\'\tc #969694",
"I\'\tc #91918B",
"J\'\tc #BEBEB7",
"K\'\tc #B8B8B7",
"L\'\tc #8A8B89",
"M\'\tc #C0C0BE",
"N\'\tc #B2B1B1",
"O\'\tc #A6A6A5",
"P\'\tc #91918C",
"Q\'\tc #BEBEB8",
"R\'\tc #B2B2B1",
"S\'\tc #8F8F8E",
"T\'\tc #8A8A85",
"U\'\tc #8B8B85",
"V\'\tc #8F8F8A",
"W\'\tc #8C8B87",
"X\'\tc #BAB9B2",
"Y\'\tc #BFBFBB",
"Z\'\tc #8D8D89",
"`\'\tc #8B8A85",
" )\tc #8D8C87",
".)\tc #C3C1BB",
"+)\tc #8A8B88",
"@)\tc #8A8B85",
"#)\tc #90918B",
"$)\tc #BBB9B5",
"%)\tc #8D8D8B",
"&)\tc #8E8F89",
"*)\tc #C2BFBA",
"=)\tc #BAB8B2",
"-)\tc #C9C9C4",
";)\tc #8D8C86",
">)\tc #C4C0BA",
",)\tc #BBBAB7",
"\')\tc #C3BFBA",
"))\tc #C6C1BD",
"!)\tc #ABABA9",
"~)\tc #BDB8B4",
"{)\tc #8D8C89",
"])\tc #90908A",
"^)\tc #C4BFBA",
"/)\tc #ABABAB",
"()\tc #959594",
"_)\tc #8F8E88",
":)\tc #BCB9B4",
"<)\tc #8E8D88",
"[)\tc #868681",
"})\tc #BEB9B5",
"|)\tc #BFBCB7",
"1)\tc #6D6D6C",
"2)\tc #BDB9B4",
"3)\tc #C1BCB7",
"4)\tc #C3BFB9",
"5)\tc #C8C8C4",
"6)\tc #BAB7B1",
"7)\tc #C0BBB5",
"8)\tc #BBB9B3",
"9)\tc #C4C0B8",
"0)\tc #817271",
"a)\tc #7E7776",
"b)\tc #787876",
"c)\tc #C4C1B8",
"d)\tc #89596A",
"e)\tc #957B84",
"f)\tc #B3B2B0",
"g)\tc #B6B3AD",
"h)\tc #9F989A",
"i)\tc #AFAFAD",
"j)\tc #C2C1BE",
"k)\tc #C7C5C0",
"l)\tc #BAB9B5",
"m)\tc #BEBEBB",
"n)\tc #CECECA",
"o)\tc #D3D2CE",
"p)\tc #D3D1CD",
"q)\tc #8F8E8A",
"r)\tc #14370C",
"s)\tc #CECDC9",
"t)\tc #DDDCD8",
"u)\tc #C7C6C2",
"v)\tc #BAB9B6",
"w)\tc #1A3C13",
"x)\tc #365030",
"y)\tc #788275",
"z)\tc #999996",
"A)\tc #CECECB",
"B)\tc #D6D6D3",
"C)\tc #D1D1CD",
"D)\tc #D1D0CD",
"E)\tc #C6C6C3",
"F)\tc #778174",
"G)\tc #B0B0AF",
"H)\tc #969995",
"I)\tc #475D42",
"J)\tc #324E2C",
"K)\tc #989B98",
"L)\tc #193A11",
"M)\tc #9C9D9B",
"N)\tc #4D6248",
"O)\tc #1E3E16",
"P)\tc #15380D",
"Q)\tc #9FA09F",
"R)\tc #25411B",
"S)\tc #2E4A27",
"T)\tc #61715D",
"U)\tc #8F948E",
"V)\tc #3F5739",
"W)\tc #1A3B12",
"X)\tc #1B3C14",
"Y)\tc #4A6046",
"Z)\tc #9B9D9B",
"`)\tc #999B98",
" !\tc #3F583A",
".!\tc #9FA09E",
"+!\tc #365130",
"@!\tc #385232",
"#!\tc #274520",
"$!\tc #979A97",
"%!\tc #22411A",
"&!\tc #979A96",
"*!\tc #495F44",
"=!\tc #24431D",
"-!\tc #7D877B",
";!\tc #60705C",
">!\tc #1D3E16",
",!\tc #717D6E",
"\'!\tc #1C3D15",
")!\tc #788376",
"!!\tc #16380E",
"~!\tc #848B82",
"{!\tc #556850",
"]!\tc #284621",
"^!\tc #848C83",
"/!\tc #768174",
"(!\tc #7A8477",
"_!\tc #2D4A27",
":!\tc #727E6F",
"<!\tc #707C6D",
"[!\tc #2E4B28",
"}!\tc #5D6E59",
"|!\tc #294723",
"1!\tc #7C857A",
"2!\tc #7B8579",
"3!\tc #35502F",
"4!\tc #9D9E9D",
"5!\tc #183A10",
"6!\tc #9C9E9C",
"7!\tc #304C2A",
"8!\tc #173910",
"9!\tc #9D9F9D",
"0!\tc #1C3D14",
"a!\tc #B1B1B0",
"b!\tc #B0B0AE",
"c!\tc #737F70",
"d!\tc #6E7B6B",
"e!\tc #7C867A",
"f!\tc #193B11",
"g!\tc #878E85",
"h!\tc #C8C8C5",
"i!\tc #1E3F17",
"j!\tc #546750",
"k!\tc #51654D",
"l!\tc #8E938D",
"m!\tc #C5C5C2",
"n!\tc #375231",
"o!\tc #294722",
"p!\tc #21411A",
"q!\tc #3E5739",
"r!\tc #667563",
"s!\tc #40583A",
"t!\tc #CACBC8",
"u!\tc #60715D",
"v!\tc #3E5638",
"w!\tc #4A6045",
"x!\tc #1F3F18",
"y!\tc #566952",
"z!\tc #1B3C13",
"A!\tc #485E43",
"B!\tc #C1C1BF",
"C!\tc #B9BAB7",
"D!\tc #6C7969",
"E!\tc #D1D3CD",
"F!\tc #828A80",
"G!\tc #9A9C9A",
"H!\tc #6F7C6D",
"I!\tc #798377",
"J!\tc #3A5434",
"K!\tc #17390F",
"L!\tc #556851",
"M!\tc #9B9D9A",
"N!\tc #C7C7C2",
"O!\tc #C6C7C2",
"P!\tc #A4A3A3",
"Q!\tc #A8A3A3",
"R!\tc #9E9E9D",
"S!\tc #9A9A98",
"T!\tc #9B9B9A",
"U!\tc #969693",
"V!\tc #8F908D",
"W!\tc #A2A2A1",
"X!\tc #C8C9C4",
"Y!\tc #989997",
"Z!\tc #989996",
"`!\tc #C0C2BC",
" ~\tc #CFCEC7",
".~\tc #D2D4CA",
"+~\tc #D8D9D0",
". + @ # $ % & % * = = = = - ; > ; ; , ; ; ; , \' \' ) ! , , , , , , ~ , ~ ~ {\
 { ~ ~ ~ { ] ^ ^ ^ ^ { / , ^ ^ ( ~ _ : ( < _ [ } | / 1 / 2 2 3 2 4 2 4 5 4 5 6\
 7 8 7 9 0 a b 0 b c d d e f g g g h i j j h g k h g g l m n o p q a r r s t u\
 u v v 7 7 u u w x y z A B C ",
"D E F F G H I J K L L M N M ~ ~ , , ; , , ] , O O O P , ; ] Q , R , , ~ ~ { ,\
 ^ ~ , ^ { ^ ( ^ ^ ( ^ , S ( ~ ~ S S ~ ( T U [ _ ^ [ [ V [ / [ W 1 W | W W V X\
 X Y Z Y X Z w `  .u  .u ..u u +.@.#.#.@.$.#.@.+.@...+.#.u u %.` &.*.*...*.=. \
.X X 4 4 =.=.-.;.>.>.,.@.e ",
"\'.).F !.~.H {.J J > {.M > , ~ ~ , > , , Q ].{ \' O ! ^.; ]., ]., Q ~ ~ , ~ ,\
 ~ , ( ^ ~ ^ _ ^ ^ ( ^ ^ ~ ( ( R ^ ( ~ } U _ [ _ _ : [ [ _ [ [ [ [ [ /.(._.V /\
./._./.:./.<./.=./.[.Y <.w =.<.w }.|.1.|.2.w w <.3.}.<.=.w <.X X X X 4.5.6.X X\
 4 3 4 4 4 2 X /.7.8.;.,.#.9.",
"0.a.b.U b.~.= {.> > ~ > > c.> , ; ; , ~ Q d.e.O f.P g., , ) , , , , , ^ ~ , ,\
 ~ ~ ~ , { , ~ ^ ( _ ^ ^ ( T _ : h.( : ( _ _ _ { _ } [ [ [ [ [ [ [ [ _._.[ [ i\
.V /.Y /./././././.=././.<.=.<.-.-.7.-.<.=.=.<.<.<.:././.X 6.:.3 j.3 6./ / j.3\
 k.- l.l.- 2 _.m.7.;.>.z q ",
"n.o.o.o.T I p.] M ^ ^ ~ { , ] , ; ]., , Q , ) q.r.s.e.t.c.^., , u.v.w.x.R y.,\
 ~ M ~ , K , ^ { K ( ~ ^ S ( _ { ( ( ^ ^ ^ ^ ^ ^ ^ ^ / , _ ^ ( ~ _ : _ ( T _.|\
 [ [ W | 2 Z Z Z 4 Z  .*.z.*.z.&.Z  . .6 X  .X 6.n.(.3 6.3 3 / / 3 3 3 l.p.p.A\
.- = = = - - [ :.[.;.>.B.C.",
"$ D.6.6.p.E.- L ~ K h.~ { , , > , ].; , Q F.].G.H.O P I.J.K.L.M.N.M.O.P.Q.R.S\
.T.U.V.W.X.Y.Z.{ ( } _ ~ ~ T ^ ( ^ ^ { ^ | ^ K ^ _ T ^ { S ~ ( ~ S S ~ S T a.[\
 | [ (.W W W =.(.Z Z Z Z Y X X  .Z X Z 4 6.6.2 6.4 2 2 A.* p.A.3 2 p.1 % - p.=\
 = `.= `.`.= p.[ _.m. +z a ",
".+j.I I h.I { L K K ^ K ~ M ; , ; ^.Q , ++, ^.@+#+$+%+&+*+=+-+;+>+,+\'+)+!+~+\
{+,+]+^+>+/+(+]+!+_+:+<+[+~ S _ ( ( } ^ ^ { _ ^ ^ ( / ^ ^ _ _ ( _ _ : [ ^ | 1 \
[ W 2 3 Z 6.W 4 4 4 4 6 6  .7 7 v 7 7 7 }+}+|+b 0 b b b c 1+b }+2+3+4+3+5+6+% \
.+N 7+8+9+0+a+N [ :.m.b+B.C.",
"j.j.I I T h.= ~ ^ ~ ^ > ~ c.; , ; ; , , Q c+d+e+f+g+h+i+)+j+k+N.]+l+{+_+m+n+_\
+o+(+p+{+q+r+s+t+u+v+w+x+y+z+( ( ( ( _ ( } _ ^ _ ( ~ ~ ^ S ( ( : o._ : _ [ o.[\
 [ [ / | [ (.| 3 Z (.W =.=./.Z X Z =.X X  .Z u  .Y Z  .%.%.Z 4 6.3 2 4 4 p.* =\
 N `.a+A+B+C+N / V D+E+..7 ",
"* * L p.I L = > ~ M > ^ ] ; ; ; N ^.G.F+G+H+H+I+J+K+L+M+N+O+P+K+O+Q+R+H+S+T+U\
+e+K+V+W+r+X+P.Y+Z+,+`+n+O.V+ @~ ~ ( K ~ ~ ~ ^ ~ S ( ~ ^ ~ ( : _ _ _ / V [ [ [\
 _.[ [ [ (.Y W (.i.(.X (./.:.<.Z 4 Y 4 Z 4 6 6 6 6 t .@C.a b c b b a 0 b +@@@@\
@#@& $@& $@& 4 4 Y =.x y u ",
"%@J K K J J {.J &@; ; , , , ] , *@=@-@;@;@T+>@,@\'@)@)@L+!@M+~@,@{@]@^@L+,+&+\
/@,@]@(@Q+_@:@<@[@!+Z+/@n+Q.{+Y+}@, ~ ~ ~ , ~ _ _ _ _ _ ^ [ _ [ _ ^ [ [ [ | (.\
_.(.[ W [ | [ /.W [ 3 i.| /.(.Z W 3 [ X X Z (.Z 4 w X 6 X Z `  .u u =.6 6 4 6 \
A.|@|@|@l.- 1 2 Z /.-.1@y 6 ",
"2@3@J J J 3@= &@> ; ^ > M = 4@5@6@7@8@9@0@a@b@<@c@9@d@e@~@6@f@d@g@h@;+i@/+9@j\
@g+:@,+-+;+(@i@h@k@l@m@n@^+\'+o@v+p@~ ( ~ ^ ~ ~ ( _ ~ ^ ~ K ( [ ^ 1 | ^ [ [ / \
1 1 / / 1 [ (.2 / W 4 Z 4 5 5 4 8 8 v 6 8 Z 6 6 6.4 4 X w Z 6 `  .Z w  .u 6 4+\
#@4 2 / 2 2 / 4 /.=.7.7.,.8 ",
"q@r@s@&@7+&@t@c.^ ~ ; , , u@v@L+w@8@i+H+x@;@y@0@,@x@8@z@A@\'@K+Q+0@^@x@B@C@&+\
D@E@S+)+x@^@K+L+H+^@<@>+F@l+,+G@H@M.I@K K ^ ~ ^ ( _ / _ _ [ | [ | 1 ^ [ [ / (.\
1 / | 1 / [ [ / [ | (.W W Z Z Y Y Z Z 4 X X Z Z 6.(.X Y 6.X 6.X =.=.=.7.7.Y  .\
7 3 / 3 3 2 1 W /.7.J@;.y 8 ",
"B+r@s@r@{.K@N &@> M ] ; L@M@H+;@;@N@e@H+M+H+z@T+c@P+c@&+O@y@X+=+E@c@9@i+)+J+)\
+)@P@0@7@)@Q@<@,+i+,@i@R@)@N+{+S@T@^+Y.^ ^ ~ ^ K T _ ~ ^ } ^ / _ _ [ [ I [ [ ^\
 [ [ [ [ [ | | | 3 2 2 4 Z 4  .4 5 4 4 4 4 6 6 4 4 4 Z 4 4 4 Z Z =.Z Y Y ` v #\
@|@4 2 4 4 W X Y =.E+7. +}+",
"U@V@r@7+2@W@N > > ; ; X@I+N@N@8@\'@)@7@6@_@;@L+\'@P+Y@S+6@h@;@Z@g+l+~+;+f@:@E\
@,+P+h@{+F@M.>+`@Q.!+l@]@S.`+ #O..#!++#@###| [ / ^ o.[ ^ } ^ _ } [ } [ _ [ [ _\
 [ [ [ [ | [ 2 (.W W 4 4 Z 4 6 6 8 7 $#$#r 7 $#$#%#v $#9 $#C.7 7 7 7 7 &#u  .t\
 t u 6 6 4 4 Z *.Y 7.;.7.,.7 ",
"*#2@r@8+8+8+t@> > ~ =#H+y@;@H+9@H+\'@>@H+-#e@;#>#H+j+;#J+!@H+j+,#i+Y@d@B@\'#d\
@*+,@)#(@>#k+L+E@Y@e+-#)#a@(+0@K+!#)+n+O.~#$@( _ ( [ [ [ / / _ _ } [ { [ [ [ |\
 1 1 1 [ W W W 1 W 2 W 4 6.4 Z Z Z 4 u v  .w *. . . .6 6 Z Z Z 4 4 4 Z W =.Y  \
. . . .6 8 |@Z Y =.=.-.;. +2+",
"{#]#^#a+/#a+t@> > c+w@H+H+y@;@R+H+6@(#z@-#;@g+)#H+c@I+L+;+H+l+K+9@Z@0@d@9@_#,\
+S+ #:#H+)#<#E@L+!#^@_#^@[#g@d@e+d@`@Q.m@-+}#I { [ | } / } ^ / ~ | | | [ 1 | 1\
 W Z W W W W 2 2 4 Z (./ X X (.2 X X 6.=.Z Y Y Y X Z 6.X 6.6.2 4 2 4 (.X =.Y Y\
 Z Z 4 4 X =.=.Y :.[.;.>.|#",
"1#2#3#2#q@4#N 5#6#7#H+H+z@z@,#P@;@f+I+Q@K+T+K+O+R+O@\'@<@(+I+S@f@)@k@P@N+:#\'\
#:@d@{@n@*+j@{@8#>+<#8#R@:@h@\'#O@S+{@h@V+9#Q.0#a#o._.| _ | _ _ / _ } | V | [ \
(.2 | 2 2 2 l.2 2 4 Z 2 4 2 2 Z 2 4 Z X Z Z =.W Z Z X 6.4 2 A.4 6.2 6.2 2 3 (.\
X Z Z 6 8 b#6 6  .w Y 1@>.,.9 ",
"c#U@]#V@d#s@c.e#f#(#M+T+e+M+x@f+T+`@g#L+T+H+h#T+>#\'#Q@_#X+>@i#<@=+)+Q+!@)#0@\
)+,@g+g@;@h#j#Q@Y@8@S+k#M+l#k#=+(@l@N.\'+m@V+~+m#n#_ _ _._ | [ | [ [ / V | W W\
 4 Z 4 4 4 Z 4 4 6 4 4 4 o#6 6 4 6 4 Z 4 4 4 4 6 4 2 4 4 4 6.4 2 2 l.2 2 3 W (\
.Z Z Y 4 Z 4 Z X =.1@-.;. +9 ",
"p#8+= * M ~ ] q#r#d@w@;@6@e@;@H+H+g#;@)@e+H+W+i+T+R+O+U+P+H+X+_@,#E@&+O@_@P@Q\
+&+k+/+)#n@P+R+;#g+h+[#^@N+ #Y+s#q+,+r+t#q+r+n+u#1 : ( | / _ 1 | | 1 | 1 (.4 2\
 4 4 4 5 4 4 6 Z 6 4 4 5 6 6 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 l.|@4 |@l.2 4 Z 4 W\
 Z Z 4 4 4 W W /.m.[.J@7.&#",
"`.v#v#K K K ] w#H+H+;@8@e@w@,#<#\'@Q+e@\'@O+;@)+T+\'@X+6@n+!@`@V+P+!+W+:#l@-+\
*+!+U+;+T@6@\'#;#Y@-+h@S@8#T@Q.h@v+M.Q.m@o+Y+G@S.!@^+x#}#_ [ / | 1 1 1 | 2 [ 2\
 2 2 | 2 4 2 2 2 2 2 4 Z 4 4 4 4 4 4 4 4 4 4 4 2 4 4 4 4 5 4 4 |@2 l.l.% y#2 4\
 3 4 (.W 4 4 W 2 2 /.=.:.7.7.&#",
"8+z#v#J ^ S - A#H+T+w@&+7@;@)@H+,@8@w@f+_@>@]@e@7@`@&+l+h+H+k+g#)@O@0@\'#<@B#\
~@P+)#`@&+j+X+l+n+/+C#D#E#F#G#)+U+H#Z@k@I#m@u+Z+:@`@J#n#| 1 K#| 1 2 [ 2 1 1 1 \
2 2 2 | 2 W 2 (.2 W W 4 2 2 4 2 1 3 4 2 2 2 2 3 2 Z 4 2 W |@2 2 l.y#l.2 1 1 W \
2 2 4 4 2 2 4 Z Z X Y m.1@&#",
"L#J J M ^ K M#-#H+f+a@<#,#6@k#(#;#x@H+y@;#0@Q@;@_#!@H+f@ #x@X+H+,#;@H+e@;@M+h\
#6@:@D@k#S.]@Q.k+N#O#P#Q#R#S#T#U#V#O+6@Y+[@V+_+B#[@_@W#X#Y#Z#| 1 1 1 2 W 2 2 2\
 2 W 2 1 2 W Z 2 W 2 2 2 }#2 2 2 2 1 W 2 2 4 2 4 4 4 4 4 4 4 o#4 |@|@l.}#2 4 4\
 4 4 4 4 2 4 W X =.=.7.Y  .",
"`#&@J J ~ K  $B@H+e@H+i+H+i+P@H+x@h+6@,@R+,@^@f+0@l@T+*+Y@L+:#g#g+,+i#Y@e+K+U\
+\'@g@`@-#r+ #.$+$@$#$$$%$&$*$=$-$;$>$,$G@m@\'$u+.#)$)+N+/+e+S.!$~$2 2 2 2 4 2\
 4 4 W | 1 2 2 2 Z 4 4 2 4 2 l.4 2 2 2 2 2 2 2 2 4 2 4 4 2 4 4 2 4 4 l.2 2 2 2\
 4 2 4 4 4 4 Z Z Y Y =.Y Y {$",
"]$N {.{.L ^$r#<#6@E@b@B@f+H+[#0@K+h#j#g@j#a@W+e+Y@Z@N@)@c@K+U+P@f@c@\'@;+h#9@\
g+E@E@Z@d@f@)#/$($_$:$<$[$}$|$1$2$3$4$5$6$P+Y+w+T@H@Z+w+r+k@M.8#:#7$4 W 2 4 4 \
4 4 2 }#2 W 1 2 5 2 2 }#2 5 5 8$2 4 2 5 2 l.l.l.8$2 2 2 |@2 4 2 2 2 2 2 1 1 1 \
1 9$4 2 4 2 X Z =.Y 7.-.}.` ",
"0$`.N > M a$T+g#;@_#L+_#b@z@)#6@E@h+>#e@a@l#f+l#O+R@-#K+Q@P@B#;@R+R@>@y@T+;#P\
+K+M+l@g#X+H+b$c$d$e$f$g$h$i$j$k$l$m$n$o$p$/@,+G@9#S.q$q$r$@#n+n@s$2 2 2 2 }#4\
 }#2 2 1 8$}#1 2 l.2 2 2 2 4 1 1 2 2 y#1 }#l.2 2 1 4 4 }#5 4 2 2 2 1 2 1 2 4 2\
 2 1 2 2 2 2 Z Y Y =.Y Y ..",
"t$N > > { u$i+M+;@L+;#,#\'@H+_#8@B#\'@K+F@y@h+d@,@Y@i#,@*+c@Q+~+b@h@`@W+/@^@*\
+i#-+!#Q.Q+v$w$x$y$z$A$B$C$D$E$F$G$H$I$J$K$L$M$h#,+N$~+9#Z+,+M.~+{+`@2 O$1 1 1\
 O$O$1 1 1 | 1 - 2 }#}#2 1 }#1 1 l.1 1 8$y#1 1 1 2 1 2 1 }#4 l.2 2 1 O$}#2 2 2\
 1 2 2 }#2 2 Z Z Z Y =./.=.` ",
"P$&@J ; \' Q$g#8@w@g+R+b@k#H+g+;@&+0@R$[#,#9@X+e+!#h#e+P.:@{@/@<@N+,+E@T@h#g@\
X+<@{@f@)@j@N@P+S$T$U$V$W$X$Y$Z$`$ %.%+%@%#%$%%%,#n+e+n+i@]+&%h@y+*%2 O$y#1 O$\
8$l.1 1 1 - 1 1 O$y#2 2 }#l.2 y#=%8$- l.}#8$1 2 1 2 }#}#2 }#}#2 5 }#2 2 8$2 l.\
2 2 2 5 }#2 Z Z Z Y Y Y Y B.",
"-%&@J > ;%\'@>#e@b@=+J+c@P@;@!@f+P@8@y@R@Q@P@w@l#i@d@7@B#E@=+(+Q@!@(@6@>+j#k@\
R@B#,+]@^@n+0@h#T+>%,%\'%)%!%~%{%]%^%/%(%_%:%<%[%k#d@j#h@R@}%|%1 }#5 - 8$1 - y\
#O$y#O$O$1 y#O$y#y#l.O$O$1 }#O$O$- y#y#- 1 1 1 1 O$1 1 }#2 }#}#}#O$}#y#1 - { {\
 O$1 2 1 2 1 2 Y Y W =.Y 1@{$",
"-%1%2%> 3%H+>@H+;@0@H+M+>@H+;@H+g#J+P@Q+P@;#K+H+f@l@_#`+]@)#Z+K+8#k@:@N.)+R@h\
#k+L+/+{@!+c@Z+)@h+<@4%5%6%7%8%9%0%a%b%c%d%l@e%,@n@A@<@f%Y.8$- O$}#}#1 - O$=%8\
$O$O$1 - 1 1 g%y#- y#O$}#1 g%y#O$- O$d.y#O$1 1 8$O$1 2 9$O$O$1 }#1 O$1 1 } h%O\
$| 1 1 1 2 W W i.Z Z =.Y {$",
"i%5#2%! j%(#^@M+_#<@H+Q@,@H+D@;@^@L+N@B#d@T+!@0@{@h@y@r+(@N+`+U+]+Y@)#!+<@k@!\
@X+N.]@]@S@R@8#,@P@R@w@)@k%l%m%n%o%p%q%r%H+i#K+[@{@^@S.~+B#[@u#{ O$g%y#y#1 g%y\
#y#y#d.y#y#O$) - O$O$1 O$O$O$g%1 O${ O$O$1 y#y#- O$1 O$O$O$1 O$1 O$O$O$1 - 1 1\
 1 { 1 4 2 | W 2 Y Y =.1@` ",
"s%5#2%t%M+H+,@H+&+N@;@_#A@H+e+<#B@R@e@h#&+8@;+e+N.Z+)# #P+=+D@Q@k@F@M+j@N@D@f\
@)@{@E@d@i@&+(+O@^@=+S+i+(#;@c@;@f+&+a@<@6@k@>#,@~@W+R@k@>+`+U+x+u%y#1 1 y#8$8\
$O$g%y#y#y#O$- y#y#O$O$O$y#O$O$O$] - g%y#) d.O$y#1 O$O$O$O$O$O$O$1 g%d.y#v%d.O\
${ O$O$1 1 1 W W /.i.i.Y  .",
"w%; 5#x%8@H+Q@a@y@w@H+H+y@H+E@;@\'@&+e@w@6@e@,@b@Y@P+)#X+K+i#]+ #i#T@&+Z+B#r+\
j+D@l@{+B#;+h#`+Y@D@`+L+>+;+g+R@x@H#{@L+/@_#k+B#`+D@(+Z@ #:@{+~@M.!@y%- O$- }#\
g%y#) y#- y#d.s.O$O$y#O$O$O$y#g%].O$v%) 1 d.O$y#O$O$1 O$O$O$O$y#O$y#s.1 =%]., \
g%1 1 O$1 1 1 2 1 W /.Y i.Y ",
"c.5#P z%;@;@H+a@l#f+i+9@7@x@]@H+^@g@K+A@&+E@h#Q@;+<@!@!@)+~@(@_@Z@,+~@l@A@*+h\
#B# #n@!@l+f@N.B#]@Y+e@N.f@g+k@e+j+)+_#^+&+S.E@n+P+6@n+c@P.B#i#h+Q+Y@A%y#O$s.y\
#y#) y#) d.d.O$y#O$y#O$s.O$y#e.- g%].d.s.y#y#) 1 O$O$- O$O$O$O$v%O$- ) d.O$e.d\
.d.s.2 K#1 }#1 1 i.i.i.Y Z ",
"c.2%a$P+H+y@)#x@7@Q@a@Q+^@;@-+,#)@d@B#c@0@W+L+K+ #^@Q+<@\'#k+:@R+B#K+!@:#O@~+\
h+`@B#h#Q+8#C@/@c@;#Y+;#X+_@`@n@(#k@:@P+S.R+`+h+h@G@i#N. #^+C@(+o@T@`@j@B%d.O$\
y#v%s.y#^.d.v%d.) O$O$O$O$v%) ) d.d.y#s.) d.s.] d.O$d.y#1 1 y#- d.^.e.) v%O$) \
O${ y#l.O$1 2 2 1 W W Z i.Y ",
"c.5#C%\'@H+z@8@H+H+i+;@;@i+T+H+;@F@M+;@H+H+w@J+H+&+\'#M+F@E@<@i#g+Z@l@-+)+h#S\
.7@l@&+)+=+F@,@n+_#=+,+(#T@Q+=+n+f+C@)@<@:#A@n+;#;#,+)#k@,@:@N@_#!@~@)+>+=+D%s\
.O$y#d.y#y#y#) ) ) d.O$) ) d.^.e.d.v%g%e.) ^.y#y#O$1 O$- O$O$O$O$- O$d.s.y#d.s\
.g%d.O$O$d.1 O$2 1 W Z W Z Z ",
"F.E%a@I+H+6@x@H+&+_#T+d@\'@)@X+(# #`@c@\'#P@j#)@j+]+B#\'@8#P@B#<@_@]@h@_@`+f@\
Z+)+o@Z@h#8#8#\'#_+j+)+o+{@j@:#8#9#:#T@g@K+V+h+G@n+ #t#N@T@ #h@;#8@e+ #G@(+)+j\
@F%y#e.].y#e.) d.d.y#{ O$) d.] d.d.e.s.g%s.s.v%) e.d.- ) O$] - 1 O$O$O$y#) y#O\
$d.d.1 O$1 O$1 O$O$W | W Y Y Y ",
"G%H%l#S+7@w@\'@H+6@8@y@0@f+y@d@7@_@*+B@f+H+]@_#>@(+!#!@Z@O@c@8#;@B#i@r+t#[@t+\
:@^+t#T@,+\'+l+Y+j@n+Q.k+^+]@_#{+f+_+ #X+H#d@G@y@]+F@ #!#i@:@H#K+0@e@]@8#n@,+!\
@I%s.d.O$d.v%y#) ) ) ) O$O$- d.) ) y#s.d.d.) s.) ) e.) y#d.O$O$O$) d.v%d.O$y#s\
.O$y#d.1 1 1 1 1 | | W Y W Z ",
"J%K%H+P@8@e@B@\'@6@_#P@L+M+y@6@;@&+R+y@k#H+N@L+8@8@=+f+N+;#,@\'@-#i@B#(+\'+`+\
L%x+H@o@^+M%Y+o+)$G@s#v+;+S.j@i@r+9@]@B#g+n@0@ #N@i#d@B#r+ #;+/@F@K+M+w@e+U+l@\
R@!#N%) ) ) e.g.^.e.; ) d.d.) ].v%d.) y#s.e.s.) y#d.y#) ) y#O$O$O$O$O$O$O$) X.\
% d.O$O$1 O$1 1 1 W W W W 4 Z ",
"O%H+H+H+e@;@H+H+(#y@f+,@\'@8@)@_#Q+ #N@g#y@)@&+f+`@,@i#(+<@N.j+(+V+^+M.N$M.P%\
+#Q%R%S%T%P%I#U%V%W%W%^+N$O.s#X%Y+s#)+n@k@h#_+h#t#h@e+:@L+F@O+Q@,@I+e@;@i+j+;+\
X+!+Y%v%d.e.e.^.e.) O$d.d.) d.O$d.e.O - ) y#y#1 d.e.s.y#d.O$O$O$y#O$d.O$O$s.O$\
O$y#O$1 O$1 1 1 1 1 W W W Z ",
";@k#H+j#\'@B@O+H+E@_@P@P@F@Q@R@e@k+Q@P+c@-#&+e+6@[@d@B#h@h#i@f+ #~+(+Z%`% &.&\
+&@&#&$&%&&&@#*&=&-&;&>&,&P%\'&I#v+)&o+X%O.h#V+9@h@R@ #N+f@[@l+!+O.{@W+M+H+>@/\
@h@Z+!&) e.e.s.e.e.~&) O$d.) { ) ) O$y#) s.e.O$d.O$s.d.y#d.g%1 y#O$d.O$O$y#O$1\
 O$y#O$O$1 1 }#1 2 1 | 1 W W ",
"H+H+H+k#H+b@M+6@_#&+f@&+;@e+N@Q@;#0@>#H+H+P@O+6@ #&+)+;#L+j@_#)+(+,+{&]&^&/&(\
&_&:&<&[&}&|&$&1&2&3&4&4&5&6&N$7&R%X%R%N$l+S.Y@C@,@k@;#Q@h@&+>+f@~@^@k#x@H+x@(\
@{@H#u%d.d.e.) e.d.e.) ) d.] ) ) y#y#y#O$) s.) O$y#O$) y#y#v%d.O$y#d.d.y#=%s.s\
.O$O$O$O$O$O$O$2 2 W W W 2 ",
"S+H+;@w@w@H+a@f+Q+;@h+\'@H+!@M+K+&+R@[#b@8@_@K+;+O@H+S.H#k@h#/@l+[@t+8&9&0&a&\
b&c&d&e&f&g&h&i&j&k&l&m&n&o&p&{ q&r&s&t&u&L%v&.#N$w+Q.*+k+*+O+\'#~@U+!@I+M+;@;\
@\'+)+_+w&s.e.e.) ) ) ) ~&) O$] ].d.y#s.s.s.y#s.O$s.) y#v%y#O$y#O$O$O$d.O$1 - \
- y#O$O$y#O$O$1 1 1 2 W W 2 W ",
"A@P@_#7@\'@l#;@F@A@>@k+R+R+R@Y@S.C@y@h#M+;@N.;#d@:@d@M.^@_+b@D@o@]+&%x&y&z&A&\
B&C&D&E&F&@#@#@#G&H&I&J&K&L&M&N&O&O&O&P&Q&R&S&\'&T&x+U&V+n+[@s#`+)@!+)+L+{@&+<\
@S.O.R%r$V&\' e.) ) ) d.) d.^.d.d.) O$\' y#y#y#s.y#O$s.y#O$s.O$d.O$y#d.{ d.O$d\
.O$O$1 O$}#O$O$O$y#O$2 | 1 W W ",
"i+T+w@;@H+N@H+H+;#H+;@H+x@R+;@P+P@7@B@6@a@T+y@W+Q@l#X+y@(+;#{@i#N.\'+W&X&Y&Z&\
`& *.*+*@*@#@#@#@#@#@#@##*$*%*&***=*-*} ) ;*>*,*\'*&%u&)$Q.H#K+!+0@i+N.7@g@9@(\
@h@`@s#G@)*y#s.s.O$s.v%d.v%d.) ^.) y#) y#s.y#O$y#s.g%y#) g%s.d.O$O$O$O$O$O$O$O\
$O$y#O$- - y#y#O$1 1 1 W Z 4 ",
"H+;@x@H+H+;#H+Q+,@H+h#;@i#g+f+-+S+,@b@b@<@[@z@N+C@-#k@g@{+h+S@Z+`+N$N$!*~*{*]\
*^*/*(*_*:*@#@#@#@#@#@#@#<*[*}*|*1*s.O ) 2*O&3*4*5*6*7*W%^+n+V+!@h@:@e+r+)+x+.\
#{+p+U.O ) v%) ) d.e.) ) ) O$] ) O$y#O$y#s.s.s.) y#y#y#y#O$O$O$O$O$1 O$O$O$O$O\
$O$y#d.O$O$O$O$1 1 1 K#| W ",
"g#w@J+H+R+A@>#<@e+_#;#l#C@O@_@/@,#e+,@\'@_#!@=+n@)#)+,+d@D@;#f@!#P.m@+#P%8*9*\
0*a*b*c*d*e*@#@#@#@#@#@#@#@#f*g*h*i*j*k*g%l*O&O&m*n*o*p*q*I#v&9#Z+M.n+i#[@[@9#\
q+o+r*) s.e.e.y#y#) s.e.y#) d.d.) y#v%y#d.y#e.{ O$) d.^.) y#d.d.y#y#d.O$O$s.O$\
s.O$- g%d.O$O$y#1 1 1 2 | O$",
"w@w@I+H+8@l#6@P+A@8@U+i+]@i+d@h+j#B@,#w@-#O+H+)+8@H+N.;#r$Q@k+[#H#Z+M.s*t*u*v\
*w*@#@#x*y*@#@#@#@#@#@#@#@#@#z*A*B*C*;&D*E*O&F*G*) H*I*J*K*Q%s*r+m+/@D@Y+Z@s+`\
+L*y#d.) y#y#y#v%) ) e.) ) ) d.d.y#s.s.O O$) ) ) s.y#e.O$s.) y#{ s.d.d.y#y#O$O\
$s.) ) e.O$O$y#O$O$1 | }#| ",
";@;@H+H+Q+H+H+;@6@w@A@J+h+y@<@E@k#e@8@w@)@,@x@e+<@Q@O@&+!+Q@_+A@N+M.Y+M*N*O*P\
*Q*@#@#@#@#@#@#@#@#@#@#@#@#@#@#R*S*T*#&U*V*W*X*Y*P Z*O&O&`* =T&s+`+Z@]@~+l+.=w\
.~&) v%) ) ) ) ! y#s.) s.) e.v%) v%O$O$y#s.) ) v%) s.s.O$y#g%s.O$O$d.O$O$O$O$y\
#s.s.s.y#y#s.O$O$O$1 1 | | ",
"_#6@&+H+X+T+{@ #k#h#L+=+Z+O@D@]+O@f+d@b@D@f@`@]+:@n+!#,@!@_#M.{@n+h@N.v+W%+=@\
=#=@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#$=%=&=T**===-=i*;=O&>=, ,=\'=N*)=(+!=~=s.) \
) ) ) ].) v%) y#g.) ) y#e.y#d.d.O$y#- y#y#s.y#e.s.) e.) e.y#s.y#O$d.1 1 g%y#y#\
s.O$s.s.s.g%s.y#O$1 1 | 2 | ",
"i+N@M+N@N@z@I+_#y@{@A@b@Q@f+f+j#N@w@,#H+i+f+6@A@;@R+e+6@S.a@>+&+R@t#*+m@s*X%{\
=]=^=@#@#@#@#/=@#@#@#@#@#@#@#@#@#@#@#@#(=_=:=<=[=}=|=1=2=) 3=4=5=6=O.7=d.].].)\
 ) ) e.d.O ) s.) v%y#y#y#y#) O$) v%s.s.s.y#g%) s.y#d.s.O y#g%y#y#d.O$O$- ) d.O\
$y#y#e.O ! O v%g%O$}#| 2 | ",
"i+M+;@P+>#b@h+d@H+U+Q@Q@_@8@g@_@P@M+>#M+g#;#O@[@R${@!@;#j+;@h@)+i#h@:#\'+^+H@\
8=9=0=a=#*b=c=d=e=@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#f=g=h=i=4=j=9#k=l=m=Q \
Q ].~&) s.e.e.g%^.e.y#) e.y#) ) ) ) ] y#y#) e.e.s.O O ) e.e.y#y#g%O$y#1 O$- d.\
{ O$s.g%P e.O ) O$O$1 K#| | ",
"H+(#H+\'@Q+;@A@9@f+B#g+P+=+A@]@_@~@L+w@,@j+0@_#i#f+;+^@<@P.=+D@i+!+(+Q.x+9#x+\
n=o=p=@#q=r=s=t=u=v=@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#w=x=y=z=A=B=C=N&D=E=\
F=G=H=, d.d.) ) ) ^.) y#y#s.y#e.y#g%O$- ) d.) s.v%P e.) P s.y#y#O$O$y#y#1 y#) \
d.O$e.s.s.e.d.d.d.O$1 | K#1 ",
"w@!#W+9@K+l#h+)@<#!@&+Q+_#0@F@,# #E@&+T+=+P@=+\'#I+B#d@<@~@g#f@^@I+f@U+;+8#l+\
t+I=J=@#K=L=M=N=O=P=@#@#@#@#@#@#Q=R=S=T=U=U=v&@#@#@#@#@#@#@#V=W=X=Y=Z=`= -.-+-\
@-#-F=m=R ].) s.y#e.y#y#e.e.e.d.y#y#s.e.) y#d.O$e.s.s.s.e.s.s.) O$g%d.O$O$O$O$\
O$s.d.) v%e.d.e.O$1 1 K#W | ",
"H+i+y@H+j+H+a@F@L+]@>#*+O+_#!@K+e+,@&+x@P@w@y@8@Q@K+N@C@H#P+_@\'#E@\'#g@!+;+O\
.S@v+$-%-&-*-=---;->-,-@#@#@#@#@#@#\'-)-!-T=T=U=~-v&@#@#@#@#@#{-]-h&^-/-(-_-:-\
<-[-}-+-|-1*< Y*, v%e.e.) ) e.s.) O$g%y#s.s.e.{ \' y#e.v%v%].y#s.d.) g%y#O$O$1\
 y#O$v%s.e.s.y#O$v%{ { | | 1 W ",
"w@6@K+_#_@>@C@y@-#^@f+;+8@;#>+\'#D@^@0@e+k+=+H#e+~@!+K+(+U+k@l@Z@~+N.~+S.N.q$\
s#+#S&1-2-3-4-5-6-7-8-@#@#@#@#@#@#@#9-0-a-f=b-b-U=~-v&@#@#@#@#c-d-e-f-g-h-i-j-\
k-l-m-n-o-|-p-q-Y*, ) e.s.s.s.e.y#d.O$s.g%d.e.v%e.s.s.s.s.e.d.y#y#s.O$O$O$y#O$\
y#g%y#O$O$d.y#O$1 | | 1 K#W ",
"y@h+e@_#K+w@`@]@=+:#>#H#<#x@g@8@g+^@l#d@-#f+8#S+g#g@&+&+i+X+S+7@f+0@i+*+e+T@P\
.S.+#r-s-t-u-v-w-x-y-@#@#@#@#@#@#@#@#z-A-B-C-C-C-b-U=U=@#@#@#@#@#@#D-E-E-F-G-H\
-I-J-K-L-M-N-k*O-G=P-R e.d.e.) y#e.d.) y#y#y#g%y#s.y#y#y#v%\' s.) - O$- 1 O$y#\
1 d.O$O$O$O$y#O$1 K#| | | | ",
"y@N@8@L+P@f+C@9@B@R+T+X+\'@g+&+(#U+g+)#T+i+M+e+w@O+~@,#V+R$!#j+W+D@Q@g@k+P+G@\
k@`+9#+#Q-R-S-T-U-V-y-@#@#@#@#@#@#@#@#@#W-0-X-B-B-a-b-Y-Z-@#@#@#@#@#@#@#@#@#@#\
@#`- ;.;+;@;#;+-N-E=p-m=, ].s.e.O s.y#s.y#s.O$O$y#v%g%v%y#s.O$y#O$y#O$g%O$1 O$\
O$O$O$1 1 O$1 K#| 1 | | W | ",
">#M+H+P@b@7@_#9@{@g@_#i@j#B#>+O@:#F@k+R@(#,@l@P@k+D@N@P.!#O+Y@h@O.i@)+N+]@Q.Z\
@t+9#M%\'*$;%;&;*;=;-;@#@#@#@#@#@#@#@#@#@#z-;;>;,;\';);B-!;~;@#@#@#@#@#@#@#@#@\
#@#@#{;];^;/;(;[-_;:;|-O-P-Q , , ) y#y#y#y#O$y#g%O$d.1 O$y#O$d.y#O$g%1 O$g%O$O\
$1 1 1 - O$2 { W | V | | V i.",
"z@<@L+{@P+Q+8#a@i#=+0@-+f+R@=+;#S@B# #8#J+T+~@>#\'#~@x@{@K+k+7@<#Y@g+P+W+0@)#\
]@(+n+]+O.T&<;[;};|;1;@#@#@#@#@#@#@#@#@#@#@#1;2;,;3;4;5;2;C-C-6;@#@#@#@#@#@#@#\
@#@#@#7;8;9;0;a;b;c;d;e;k*G=p-H=Y*R d.g%O$s.1 O$d.- O$X.{ O$1 1 O$O$O$O$O$1 1 \
1 } O$1 1 1 1 } | V | [ i.W ",
")@e+e@\'#d@L+D@R+0@_@M+ #;@-#_#&+*+,@j+Y@&+a@f+;@,@^@B@k+(#j@,@K+>+R@Z@C@Q@:@\
h+]+Q.(+S.x+R%f;g;h;i;R*@#@#@#@#@#@#@#@#@#@#@#1;);\';4;4;4;j;B-C-b-b-6;@#@#@#@\
#@#@#@#@#k;l;m;n;o;p;q;r;s;@-t;G=p-q-p-, 1 O$O$O$O$y#y#O$O$O$O$O$1 O$1 2 O$1 1\
 K#d.1 1 1 | 1 | | V | [ | /.",
"w@Q@H+_@>@B@L+f+c@j+7@n@0@-+]@h#/@f@-+(+d@R@B@;@_@d@0@k+8@;+P@k@_@n@l+V+h+M.9\
@D@/+k@+#r+T&u&u;v;h;w;@#@#@#@#@#@#@#@#@#@#@#@#x;y;y;z;A;z;5;2;B-B;~;6;@#@#@#@\
#@#@#@#@#`-C;D;E;F;G;H;I;J;K;L;M;t;N;####( d.d.O$] O$O$y#1 1 1 O${ O$O$1 }#1 1\
 1 | 1 1 1 | 1 V V V [ V V ",
"B@P@w@E@ #E@g+h+)#O+0@n+w@!@<@\'#`+;#l@n+`@]@<@M+L+;#e+^@;@Y@H+f@w@l#Y@i#i@^@\
;# #F@i#,+(+n+P%H@O;@#S%P;Q;@#@#@#@#@#@#@#@#@#@#@#@#R;S;S;T;A;4;j;B-C-~;6;@#@#\
@#@#@#@#@#U;V;W;X;Y;Z;`; >:-Z=.>+>@>#>$>%> @q-R { O$O$O$1 O$O$K#O$1 O$1 1 1 1 \
1 K#1 1 | | | | V | V | V V ",
"g#;#F@R@K+i@&+e+Y@J+_#~@H+d@Q+=+[@!@]@(@!@L+P@J+g#a@(#`@f+R@R$,@n+>#h+^@P+V+c\
@Y@L+i+*+)+`+O.v+N$&>*>S%=>@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#->;>;>A;5;>>B;Y-6;@#@\
#@#@#@#@#@#@#V;,>\'>)>!>~>{>]>^>/>(>_>:><>k*[>}>|>: 1 1 1 1 1 1 1 1 { O$1 O$O$\
1 1 1 1 1 1 { | | _.| V V V ",
"_#)#B@,@R$[#j#j#_@)#Q+)+H+k@B@_@k+=+!#8#i#!#=+)#)@7@;@Q@;@h#S+i@;#_@N.]@(@V+E\
@m@!+j+,+_+j@9#s*S&@#1>@#2>@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#R;;>T;4;3>C-6;6;@\
#@#@#@#@#@#@#@#@#@#F-4>5>6>7>->8>9>0>a>b>c>N&d>e>##q-< O$1 { O$1 1 1 1 1 K#1 1\
 1 1 1 1 1 | 1 [ V | | _.V ",
"M+N@K+ #M+H#\'@)# #H+A@Y@P@ #O+O@]@R@h@k@k@`+;+)@[@!#i@P+>@e+z@ #y@K+e+e+Q+f@\
O+>+,@A@!#f@n+Z+-+@#@#@#f>g>h>@#@#i>@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#j>k>y;););l>\
m>@#@#@#@#@#@#@#@#@#@#@#@#@#@#n>o>p>q>r>s>t>u>v>w>x>y>z>1*{ { 1 1 1 1 | | 1 1 \
1 1 { 1 [ / | V | V } | V V ",
"]+<@h#j@y@]+c@!#l@g@[#h#8@[#7@D@h+f+i@f@g#h@N+B#[#7@_@;#i+e+(#L+j#e@b@W+\'#P+\
J+;+;+K+j@=+h@Q.*+@#M.@#@#@#@#@#A>=>@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#B>R;C>D>\
E>6;6;@#@#@#@#@#@#@#@#@#@#@#@#@#F>g-G>]>H>I>J>.>K>L>@><>M>N>}>1 { 1 1 | 1 1 | \
} | | 1 1 | | [ [ V | _._._.",
",@j#a@R+(#)@>#L+B@X+-#E@9@H#f+8#]+<@f@S.d@,+-+P.]@C@Y@:@!#`@i@]+S@O>P>b@f@;+h\
#~+~+P.[@h@[@m@l+^+,+@#@#@#@#@#@#A>Q>@#@#@#@#v&@#@#@#@#@#@#@#@#@#@#@#@#@#@#B>B\
>x;R>6;6;@#@#@#@#@#@#@#@#@#@#@#@#E>S>T>U>V>W>X>i*|*u;Y>Z>p&y>`>( 1 O$1 { 1 1 1\
 } 1 1 1 / | | _ V _.| V _.",
"w@>@0@{@H+]@8@O@I+H+Q@>@Q@=+k#\'@^@!#:@;+A@X+h+X+Z+)@F@A@d@ #i@P. ,~&)*.,&+Q+\
i+B#O@c@R@(@`@!+j@t#l+S.^+@#@#@#@#@#@#@#@#@#@#@#v&@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#x;E>6;R>@#@#@#@#@#@#@#@#@#@#@#@#+,@,#,$,%,&,*,=,-,;,>,L>,,`>}>}>_./ 1 1 \
| } | \',| | V [ | V V | _._.",
"8#R@B#/@C@j@H+B#g+O@*+R+,@P.9@8#W+!#R@S@V+!+^@Z@/@N+S.^@~@!@`+Z+),^.^.v%!,y@A\
@^@Q+{@,@,@:@X+T@t#N.x+/+@#@#@#@#@#@#@#@#@#@#@#@#v&@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#x;R>R>@#@#@#@#@#@#@#@#@#@#@#@#@#@#R*~,{,],o>^,/,(,0>_,w>:,e>##U { { {\
 { | _ | | { ^ V V [ _.V _.",
"Q+y@e+,#y@h@N@j#0@]@P+d@0@Y@w@X+7@U+_@T+i@F@L+{@^@0@R@w@`@d@Z@x+<,g.g.^.e.[,y\
@Q+d@j@:@k+B#&+Y@-+Z@_+N.@#@#@#u&@#@#@#@#@#@#@#@#@#v&@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#R>6;6;6;@#@#@#@#@#@#@#@#@#@#@#@#@#},|,1,2,3,4,5,6,7,8,$>e>e>}>}\
 } | } | } | _.V V [ V V _.",
"P+i+ #_#;@P.6@i@H+~@N@L+Q@[#k#h@>+{@Z@^@K+(@{@n@E@j+H#A@H#O+j@q+9,g.].g.g.e.0\
,8@J+`@i+h#{@;#<@ #H#r+n+@#@#@#n=@#@#@#@#},@#@#@#@#@#v&~-6;@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#a,6;6;R>@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#b,c,d,e,f,@>w>g,h,|%1\
*|>} } _ _._ : _.\',V V _./.",
"h#;#N+X+_#!#H+)+f+P+=+N+U+l@J+D@N+O@B#T@P.<@[#n+`@i@X+_#>+k+r+7&i,g.g.^.].^.j\
,k,l,h@H#!+P.!+)+S@l+j@s#@#@#@#q*@#m,n,@#i>@#@#@#@#@#@#v&~-@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#a,l>E>6;6;6;~-v&@#@#@#@#@#@#@#@#@#E-f-p>o,p,6,q,r,s,t,h\
,e>`>u,\',\',_.: : : _.V i.V ",
"Y@N@d@c@W+Y@P@=+k#[#J+8@!@R@e+\'#!@<@f@z@M.F@O+U+<@:@O+I+N+W+T@x+v,].g.~&g.].\
e.O w,x,l#P.Q@,@h@W+L+\'#h#!+O.@#@#@#@#X=@#@#@#@#@#@#@#@#@#v&@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#R>a,2;B-!;b-T=6;@#@#@#@#@#@#@#@#@#@#y,z,A,B,p,C,K>_,D\
,:><>E,h, @}>_._ V : _.: _./.",
"(@7@i@K+R+h#w@(+H+!@,@I+A@9@P+{+)@\'#/+R+_@D@g+/@F@k@f@O+k@d@_+o+v,~&g.g.s%~&\
V&)*j,j,F,G,R@K+l@:@!@;#,@:#:#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#x;a,B-C-H,H,~;6;@#@#@#@#@#@#@#@#@#+,I,J,K,J>s>L,M,L,\
N,O,P,Q,w>R,|>U _._.V \',_._.",
"g+I+c@6@y@P@T+C@>@\'#E@;#i@_@)@P.j+f@]@!+!+N+f@n+8#=+k@j#S@B#Q._+S,e.g.g.e.~&\
j,)*j,s.j,T,U,V,!@g@\'#S@i#Z@!#@#@#@#@#@#W,@#@#@#D-@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#R>X,!;B-!;l>6;6;~-~-v&@#@#@#@#@#F>Y,Z,=,`, \'.\
\'+\'@\'+\'#\'$\'%\'I@&\'*\'U V V V /.V ",
"D@K+*+d@/@N+d@[#w@~+=+\'#:@e+{@P.C@!#O@-#X+h+Y@)+X+g+R@f+D@D@!+Z+P-g.=\'g.g.e\
.)*)*j,e.j,=\'~&=\'-\';\'>\'~@0@)+ #S.@#,\'@#@#@#@#@#@#@#@#\'\'D-@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#R>6;~;Y-)\'U=~-@#@#@#@#@#!\'g\
-~\'{\'{\']\'^\'/\'(\'_\':\'<\'[\'}\'&\'|>|\': _.i.V ",
"_@L+h#H+U+c@M+,@g#_#;@;@O+P@^@)@P+k@=+A@l+R+^@<@k@8#i@N+/@D@r$m@E==\'O =\'P e\
.P =\'j,1\'s%=\'g.e.j,P e.2\'3\'4\'5\'6\'g.].@#@#@#7\'@#@#@#@#@#@#i>@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#x;6;C-H,8\')\'U=v&@#@#@#@#\
@#!\'9\'0\'b,a\'b\'c\'d\'e\'f\'g\'h\'k=i\'j\'k\'|>l\'_.",
"[#K+:#;@P+~@;#Z@_@{@]@;+!@*+*+i@n@t+]+:#_+;#h@l@h@r+g+{@o+;+U&m+m\'P P P j,n\
\'e.P =\'g.g.].g.=\'n\'j,=\'g.g.=\'g.o\'^.^.].@#@#@#p\'q\'%,@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#R>C-H,8\')\'U=6;@#@#@#\
@#@#@#@#@#@#@#@#r\'s\'&%@#@#X%t\'u\'v\'w\'_.a.",
"N+7@]@E@)@C@H+~@P@^@O+E@C@\'#^@S@H+V+R@0@,+d@Y@0@P@M.]@<@!+;+9#\'+x\'V&1\'=\'\
j,)*e.g.P g.g.y\'t.g.P =\'^.g.e.P g.~&^.^.g.Q @#@#@#@#@#@#R;z\'@#@#A\'@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#X,B\'B\'~;6;~;@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#U&y+C\'D\'",
"l@*+U+W+N+-+=+0@H+N.7@0@Q@j+<#Z+>#S@Y@R@n+K+D@Y@0@~+d@B#Q.`@T&^+E\'j,V&=\'j,j\
,P =\'P g.^.].Q o\'=\'e.e.e.e.j,e.^.^.].g.) Y*@#@#@#@#@#@#@#e\'@#@#},@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#6;l>~;~;@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#X%F\'}@",
"O+i+;@H+H+M+O@R@i+C@b@;#Q+;#!@h@g@j@c@R@j@)+!#R@H#l+X+k@Y+]+7&q+G\')*2\'P P P\
 j,1\'V&g.^.y\'++g.g.g.g.e.s.P =\'d.g.^.g.^.s.E=@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#x;6;6;6;6;@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#X%t\'",
"7@!@ #=+k@g+)#X+L+k+)@8#N.9@]@i@)@q+B#C@k+L+Z+d@L+)+)@K+n+N.9#O.H\'2\'P =\'g.\
1\'j,j,T,e.g.~&t.^.^.~&^.g.e.O n\'e.~&g.e.e.e.=\'I\'@#@#@#@#@#@#J\'@#@#l>@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#R>l>m>K\
\'7*@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#X%",
"P.k+f@y@,#E@)@<@w@(+E@0@N+^@ #{@_#k@_#;+`+H+`+K+^@:@]@n@>+:@s+O.L\')*j,g.g.2\
\'T,j,T,g.g.g.y\'^.~&^.^.g.)*O O ) e.^.e.g.P s.O [>@#@#@#@#@#@#@#@#@#q\'@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#x;X,M\'N\
\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"-#W+)@P@!@f+Q+8#;@)@K+]@K+E@(+Y@ #Z@P+N+l@e+m@=+k+{+J+S.l@Y+I#^+O\'2\'j,e.P j\
,j,j,j,j,=\'1\'g.g.g.].].g.j,j,=\'g.g.=\'P P P P e.e.Q P\'@#@#@#@#Q\'@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#R\
\'L%@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"E@g@ #\'@f+R@,@f@-#*+)@S@,+h#t#e+:#]@k+Z@l+B@T@,@[#\'+,@M.]@k+s+!+S\'T\'U\'=\
\'j,j,j,j,j,j,=\'P =\'=\'=\'y\'].g.P e.e.g.=\'e.e.V&j,e.e.P g., V\'<,@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"h#)+[#)+:@d@`@P.S+Z@C@ #;+W+/@P+i@H#g#!@{@<@:#S+]@/@e@P.:@(@s*~+o+G.T,j,)*j,j\
,=\'W\'j,)*2\'=\'=\'g.].].t.g.e.e.^.=\'e.=\'P j,e.=\'g.g.=\'].m=<,@#@#X\'@#@#@\
#@#Y\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"7@g#Y@J+N.I+y@!#P@(@;@^@Q+N+-+i+O+[@d@)+X+,+!+U+_@l+P@,+Z+n@V%Y+x+Z\'U\'j,1\'\
j,1\'=\'n\'2\'1\'`\'=\'=\'~& )o\'~&g.g.g.^.g.P n\')*j,j,P e.e.e.e.t.p-@#@#@#.)\
@#@#@#@#Y\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"Q@H#,@<#l@Y@U+(@B#S.:@Z@r+A@m@!+H#)+f@{+]@0@r+`@Z@V+<@Y@g@k@9#r++#+)j,g.P =\'\
^.1\'e.T\'U\'T,=\'g.g.o\'^.t.g.g.g.^.e.e.2\'@)j,j,e.=\'=\'e.g.^.Q #)@#@#@#$)@#\
@#@#@#Y\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
":@Z+l+)+V+D@:@n+R+Z@F@N+N+h#S@[#]@_@,#U+g#Q+l@J+N+*+K+N+{@i@q+(+.#%)s%~&].=\'\
^.g.P T\')*j,=\'g.g. )g. )^.P g.].g.P )*P =\'j,g.P j,P v%g.=\'&)@#@#@#@#*)@#@#\
@#@#@#\';@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"=+k@K+&+]@&+k@)@K+{+H+;+]+7@)+=+.#N+h@r+B#n@`@{@)+D@h#,+!@)+\'$!+&%q$g.g.^.; \
o\'g.V&@)2\'j,1\'=\'g.g.=\'g.~&=\'g.t.O g.j,P e.P 1\'P e.e.g.=\'=\'].V\'@#@#@#\
@#=)$)@#@#@#@#-)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"f+~+h#B#m@>@M.j+d@!+Q@8#`@L+T@(#~+8#!@!+<@Y@!+U+l@B#!#j@Z@-+o@V+o+P%<,g.~&].Q\
 o\'j,2\'2\'2\'n\'=\'e.;)g.g.g.=\'=\'^.j,e.j,P P s%=\'P g.g.P P P ^.g.m=<,@#@#\
@#@#>)@#@#@#@#Y\',)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"N.m@:@[#S.*+`+H#k+S.[#h@D@<@M.Y@ #g@^@]+!@)@R@_#S@h#_#)+E@f@.#:#S.v+S,=\'~&g.\
Q  )j,T\'2\'2\'P =\'=\'g.1\'j,e.P =\'g.T,P P g.g.=\'=\'=\'e.e.e.P P ) e.].R m=\
@#@#@#@#\')@#@#@#@#Y\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"K+O@e+_#{@&+P.H+,@[@H+ #:#b@)+A@h#f@H# #!@h@h@z@)+n+0@`+]@E@t#`@.#u+L%<,=\'t.\
t.g.n\'T\'j,2\'P P j,=\'1\'P e.=\'=\'g.j,j,j,j,P =\'g.e.~&g.)*P g.g.g.e.].].H=\
P\'@#@#@#))@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"C@G@:#,@:@h#Q.*+n+S.L+k@:@h+O.{@Z+;+Y@j@k@)+,+g@]@Z@y@r+(@N+S.~+s#r+x+!)g. )+\
+g.=\'T\')*j,j,j,P =\'P j,P j,=\'^.n\'e.=\'P g.g.g.g.g.1\'j,g.P e.g.^.e.g.Q &)\
@#@#@#~)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"{@^@N.:@/+_@.#(#i@H#W+n+Z@!@r+!@h#,+K+Z@B# #M._@h@T@;# #P+=+;+i@_+[@j@M*{)t.t\
.t.g.2\'P j,j,j,1\'=\'n\'j,P W\'g.g.n\'j,n\'=\'P 1\'~&=\'~&=\'=\'g.P g.g.g.e.e\
.^.++])@#@#@#^)@#@#@#@#@#Y\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"n+k@_@N+l+R+_+i@h@,+`@;+!+l@t#g@)+i@L+_@O@e+f@A@N.<@K+D@K+i#(+(+T@x+Z@/)()_)o\
\'y\'g.2\'j,j,j,j,=\'=\'g.j,j,g.1\'g.g.g.g.g.g.P g.g.g.g.P g.e.g.e.P e.) e.].O\
-@#@#@#:)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"&+n+Q+B#O+N+~+s#v+U&@#@#q$p+s*t#m@/+H#)+]@l@S.e+!+j+/@`@P.~@:#;+o@r$\'+r$r+@#\
<)t.o\'e.P ) e.g.g.g.g.j,j,P e.=\'g.P 1\'j,=\'=\'g.^.g.^.g.e.^.^.e.e.=\'P g.e.\
m=@#@#@#@#>)@#@#@#@#@#@#Y\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"[@(+k+o@(@u+X%@#@#@#@#@#@#@#@#X%s*s+Y+Z+/@l@;+i#(@X+!#B#g@*+;+k+T@/+.#9#_+@#[\
) )F.n\'g.o\'g.g.g.g.s%j,U\'P 1\'g.g.=\'1\'j,g.j,g.g.^.g.g.P ^.^.g.P g.P g.^.e\
.@#@#@#@#})|)@#@#@#@#@#@#Y\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"T@Y+;+m+s+U&@#@#@#@#@#@#@#@#@#@#@#@#H@t+Y@e+l@H+,@]@\'@:#[#]@N+D@^+M.t+Y+Q.@#\
1)t.~&j,=\'o\'P g.g.~&~&V&@)j,P g.g.P j,1\'g.=\'g.g.^.g.g.e.g.g.e.P e.^.^.^.g.\
^.@#@#@#@#2)3)4)@#@#@#@#@#5)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"`@r${+)$X%@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#    ]+S.n@0@{+,@l@ #X+j@Q.h@s+V+@#M\
.@# )P g.s%j,v%=\'g.^.=\'j,P =\'g.=\'j,P j,=\'e.              g.e.^.g.g.=\'g.g\
.e.) @#@#@#@#@#6)7)8)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
";+Z@x+X%@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#  .#k@Y@V+(@U+!+7@[@Z@r+^+S.@#,\
+@#2\'j,j,g.j,g.=\'g.g.j,2\'j,1\'=\'e.P j,    @#@#@#@#@#@#@#@#    ~&e.].].^.^.\
g.^.v%@#@#@#@#@#@#@#9)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"k@s+U&@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#    0)@#a))@<@c@;+l@j@T@n+@#.\
#@#b))*1\'s%j,P W\'=\'g.j,g.g.~&g.g.    @#@#@#@#@#@#@#@#@#@#@#@#    ^.^.^.g.g.\
e.e.].@#@#@#@#@#@#@#c)@#d)e)@#@#@#@#@#@#@#@#@#@#f)@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"N.\'$@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#  @#T@T@^+S.M%;+@#\
`+@#  @#@#@#@#    g.=\'j,g.g.~&~&  @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#  ^.g.^.g.e\
.e.g.].@#@#@#@#@#@#g)@#h)@#@#@#@#@#@#@#@#@#@#@#i)j)k)l)@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"G@@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#  `@S@k@t#l@@# \
 @#@#@#@#@#@#@#@#    j, ) )t.  @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#g.g.^.e.e.)\
 ^.e.@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#m)n)o)p)x;@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"w+@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#  D@s+`+  @#@\
#@#@#@#@#@#@#@#@#@#@#  g. )o\'  @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#        \
      g.g.q)O-@#@#@#@#@#@#@#@#r)r)@#@#@#@#@#@#@#@#s)t)B-2;);u)v)@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"s*@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)r)r)w)x)y\
)@#@#@#@#@#@#@#@#@#@#@#  t.  @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#    ^.p-z)@#@#@#@#@#@#@#r)r)@#@#@#@#@#@#@#@#@#A)B)B-C)D)E)F&@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)r)r)r)r)r\
)F)@#@#@#@#@#@#@#@#@#@#    @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#   &s*@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#G)@#@#@#@#  @#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)q$@#H)I)r\
)J)@#@#@#@#@#@#@#@#@#@#@#  @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#  @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#  @#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"p+@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)@#@#@#K)r\
)L)@#@#@#r)r)M)N)O)P)@#Q)R)S)L)L)S)T)q$@#@#r)r)r)r)r)r)r)r)@#@#U)V)W)X)Y)Z)r)r\
)@#@#@#r)r)@#@#@#@#r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"s+@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)@#@#@#`)r\
)L)@#@#@#r)r) !r)r)r).!+!r)r)r)r)r)r)@!q$@#r)r)r)r)r)r)r)#!@#$!%!r)r)r)r)V)r)r\
)@#@#@#r)r)@#@#@#@#r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"T@@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)@#@#&!*!r\
)J)@#@#@#r)r)=!-!Q)@#;!r)>!,!M)M),!\'!r)T)@#@#@#@#@#)!r)!!~!@#{!r)]!^!Q)^!#!r)\
r)@#@#@#r)r)@#@#@#@#r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"X++#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)r)r)r)r)r\
)/!@#@#@#r)r)(!@#@#@#_!r):!@#@#@#@#<!r)[!@#@#@#@#s,>!r)}!@#@#|!r)1!@#@#@#2!r)r\
)@#@#@#r)r)@#@#@#@#r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"\'+p+@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)r)r)W)3!\
y)@#@#@#@#r)r)4!@#@#@#5!r)6!@#@#@#@#M)r)L)@#@#@#.!7!r)3!U&@#@#8!r)9!@#@#@#4!r)\
r)@#@#@#r)r)@#@#@#@#r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"V+@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)@#@#@#@#@\
#@#@#@#@#r)r)@#@#@#@#5!r)6!@#@#@#@#M)r)L)@#@#@#N)r)0!s,@#@#@#8!r)9!@#@#@#4!r)r\
)@#@#@#r)r)@#@#@#U&r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#a!b!@#@#@#@#@#@#@#@#@#@#",
"Y+@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)@#@#@#@#@\
#@#@#@#@#r)r)@#@#@#@#_!r)c!@#@#@#@#,!r)[!@#@#d!r)r),!@#@#@#@#|!r)e!@#@#@#1!r)r\
)@#@#@#f!r)H)@#@#g!r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#h!@#@#@#@#@#@#@#@#@#@#",
"+#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)@#@#@#@#@\
#@#@#@#@#r)r)@#@#@#@#;!r)i!c!6!6!:!>!r)T)@#I f!r)I)@#@#@#@#@#j!r)]!+ q$+ ]!r)r\
)@#@#@#7!r)k!9!l!J)r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#  m!@#@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)@#@#@#@#@\
#@#@#@#@#r)r)@#@#@#@#.!x)r)r)r)r)r)r)n!Q)@#o!r)r)r)r)r)r)r)@#H)p!r)r)r)r)q!r)!\
!@#@#@#r!r)r)r)r)s!r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#t!@#@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)@#@#@#@#@\
#@#@#@#@#r)r)@#@#@#@#@#.!;!_!5!L)_!u!Q)@#@#r)r)r)r)r)r)r)r)@#@#l!v!f!X)w!U)r)x\
!@#@#@#X%y!i!z!A!Z)r)r)@#@#@#r)r)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#B!C!@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#D!r)n\
!@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#&%E!@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#s!F!.!G!H!\'!r)\
r!@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#);z-@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#r)r)r)r)r)r)7!Q\
)@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#E>);x;@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#I!J!0!K!#!L!M!@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#x;E>\';@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#x;N!O!@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#P!Q!@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#x;x;x;@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#R!S!@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#T!v\'U&@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#Q)U!S,R!@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#U&G\'P-O-T!@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#@#",
"M%@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@\
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#U&S!V!g.].U!t\'@#\
@#@#@#@#@#@#@#@#@#@#@#@#@#W!@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#    \
X!z*@#@#@#@#@#@#@#@#@#@#@#@#",
"_+\'$@#@#@#@#@#@#@#@#@#@#U&U&@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#\
@#X%@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#X%q$@#@#@#@#@#@#@#@#t\'Y!E=~&d.d.m=Z!U\
&@#@#@#@#@#@#@#@#@#@#@#@#U&p+t\'@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#`!\
3, ~.~+~@#@#@#@#@#@#@#@#@#@#@#"
};
static Fl_Pixmap image_Prozgui1(idata_Prozgui1);

Fl_Window* make_about_win() {
  Fl_Window* w;
  { Fl_Window* o = win_about = new Fl_Window(510, 370);
    w = o;
    o->labeltype(FL_NORMAL_LABEL);
  
#ifdef HAVE_LIBXPM		// X11 w/Xpm library
  fl_open_display();
  Pixmap pixmap, mask;		// Icon pixmaps
  XpmAttributes attrs;		// Attributes of icon
    
  memset(&attrs, 0, sizeof(attrs));

  XpmCreatePixmapFromData(fl_display, DefaultRootWindow(fl_display),
			 const_cast<char **>(Prozgui2_xpm), &pixmap, &mask, &attrs);
  o->icon((char *) pixmap);

#endif
  

    { Fl_Box* o = new Fl_Box(10, 25, 190, 30, gettext("Prozgui Download Accelerator 2.0.7"));
      o->labelfont(1);
      o->labelsize(12);
      o->labelcolor(4);
      o->align(FL_ALIGN_WRAP);
    }
    { Fl_Box* o = new Fl_Box(15, 55, 185, 20, gettext("GUI Version 2.0.7"));
      o->labelsize(12);
    }
    { Fl_Box* o = new Fl_Box(20, 80, 185, 20, gettext("libprozgui version 1.2.2"));
      o->labelsize(12);
    }
    { Fl_Button* o = new Fl_Button(60, 315, 85, 20, gettext("Ok"));
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_about_ok);
    }
    { Fl_Box* o = new Fl_Box(40, 115, 130, 130);
      o->box(FL_SHADOW_FRAME);
      o->image(image_Prozgui1);
      o->labelsize(12);
    }
    { Fl_Tabs* o = new Fl_Tabs(225, 25, 265, 315);
      o->labelfont(1);
      o->labelcolor(4);
      { Fl_Group* o = new Fl_Group(230, 45, 260, 290, gettext("Credits"));
        o->labelsize(12);
        o->labelcolor(4);
        { Fl_Scroll* o = new Fl_Scroll(235, 55, 245, 275);
          o->box(FL_ENGRAVED_BOX);
          o->color(28);
          o->labelfont(1);
          o->labelsize(12);
          o->labelcolor(4);
          { Fl_Box* o = new Fl_Box(260, 70, 180, 20, gettext("Kalum Somaratna"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 95, 180, 20, gettext("Uwe Hermann"));
            o->labelsize(10);
          }
          { Fl_Box* o = new Fl_Box(260, 120, 180, 20, gettext("Gustavo Noronha Silva"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 145, 180, 20, gettext("Ralph Slooten"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 170, 180, 20, gettext("Raviyanto"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 195, 180, 20, gettext("Silviu Marin-Caea"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 220, 180, 20, gettext("Pablo Iranzo Gomez"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 245, 180, 20, gettext("Krogg"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 270, 180, 20, gettext("David L. Matthews"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          o->end();
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(230, 55, 250, 280, gettext("Translations"));
        o->labelsize(12);
        o->labelcolor(4);
        o->hide();
        { Fl_Scroll* o = new Fl_Scroll(235, 55, 245, 275);
          o->box(FL_ENGRAVED_BOX);
          o->color(28);
          o->when(FL_WHEN_RELEASE_ALWAYS);
          { Fl_Box* o = new Fl_Box(260, 70, 180, 20, gettext("Ruben Boer - Dutch"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 100, 180, 20, gettext("Ralph Slooten - Dutch"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 130, 180, 20, gettext("Flower - Romanian"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 160, 180, 20, gettext("Gustavo Noronha Silva - Portuguese"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 190, 180, 20, gettext("Emanuele Tatti - Italian"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 220, 180, 20, gettext("Alberto Zanoni - Italian"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          { Fl_Box* o = new Fl_Box(260, 250, 180, 20, gettext("Eric Lassauge - French"));
            o->labelsize(10);
            o->align(FL_ALIGN_WRAP);
          }
          o->end();
        }
        o->end();
      }
      o->end();
    }
    { Fl_Box* o = new Fl_Box(10, 260, 210, 30, ("code.google.com/p/project-linux-software"));
      o->color(29);
      o->labelsize(10);
      o->labelcolor(1);
      o->align(FL_ALIGN_WRAP);
    }
    o->end();
  }
  return w;
}

Fl_Return_Button *url_input_ok_button=(Fl_Return_Button *)0;

Fl_Input *in_url=(Fl_Input *)0;

static const char *idata_Prozgui3[] = {
"48 48 301 2",
"  \tc None",
". \tc #D6D6CE",
"+ \tc #6B6B6B",
"@ \tc #292929",
"# \tc #212121",
"$ \tc #181818",
"% \tc #393939",
"& \tc #313131",
"* \tc #424242",
"= \tc #636363",
"- \tc #4A4A4A",
"; \tc #525252",
"> \tc #5A5A5A",
", \tc #737373",
"\' \tc #848484",
") \tc #8C8C8C",
"! \tc #8C8C84",
"~ \tc #C6C6C6",
"{ \tc #000000",
"] \tc #7B7B7B",
"^ \tc #8C948C",
"/ \tc #182118",
"( \tc #94948C",
"_ \tc #9C9C9C",
": \tc #A5A5A5",
"< \tc #949494",
"[ \tc #4A4242",
"} \tc #5A5252",
"| \tc #6B6363",
"1 \tc #423131",
"2 \tc #6B3921",
"3 \tc #9C7B63",
"4 \tc #8C7363",
"5 \tc #634239",
"6 \tc #4A3129",
"7 \tc #B5B5B5",
"8 \tc #6B5A52",
"9 \tc #945A4A",
"0 \tc #A5735A",
"a \tc #BD9C84",
"b \tc #BDA584",
"c \tc #947B73",
"d \tc #C6BDBD",
"e \tc #5A3931",
"f \tc #5A4242",
"g \tc #423939",
"h \tc #6B4A42",
"i \tc #BD7B5A",
"j \tc #BD9C7B",
"k \tc #BDA58C",
"l \tc #7B6B5A",
"m \tc #7B6352",
"n \tc #9C8C7B",
"o \tc #948473",
"p \tc #4A2118",
"q \tc #635242",
"r \tc #392929",
"s \tc #9C6342",
"t \tc #CEA584",
"u \tc #AD947B",
"v \tc #6B5242",
"w \tc #291810",
"x \tc #423121",
"y \tc #846B52",
"z \tc #6B5239",
"A \tc #290000",
"B \tc #524A42",
"C \tc #735A42",
"D \tc #523929",
"E \tc #5A4239",
"F \tc #7B634A",
"G \tc #CEA58C",
"H \tc #C69473",
"I \tc #734221",
"J \tc #391000",
"K \tc #393129",
"L \tc #7B5A52",
"M \tc #7B5242",
"N \tc #8C6352",
"O \tc #846352",
"P \tc #A5846B",
"Q \tc #DEAD9C",
"R \tc #C68C7B",
"S \tc #A56352",
"T \tc #8C5239",
"U \tc #524239",
"V \tc #84635A",
"W \tc #946B5A",
"X \tc #845242",
"Y \tc #734A39",
"Z \tc #292921",
"` \tc #312929",
" .\tc #ADADAD",
"..\tc #B5B5AD",
"+.\tc #C6CECE",
"@.\tc #CEDEDE",
"#.\tc #BDC6C6",
"$.\tc #ADB5B5",
"%.\tc #C6C6BD",
"&.\tc #CECEC6",
"*.\tc #D6DED6",
"=.\tc #A5ADA5",
"-.\tc #BDCECE",
";.\tc #DEF7F7",
">.\tc #9CA59C",
",.\tc #BDBDB5",
"\'.\tc #DEDECE",
").\tc #DEDED6",
"!.\tc #C6CEC6",
"~.\tc #D6E7DE",
"{.\tc #BDCEC6",
"].\tc #D6EFEF",
"^.\tc #C6D6D6",
"/.\tc #BDBDBD",
"(.\tc #D6D6C6",
"_.\tc #E7E7CE",
":.\tc #E7E7D6",
"<.\tc #E7EFDE",
"[.\tc #E7E7DE",
"}.\tc #D6DECE",
"|.\tc #CED6CE",
"1.\tc #BDC6B5",
"2.\tc #C6DEDE",
"3.\tc #ADBDB5",
"4.\tc #9CADA5",
"5.\tc #E7EFD6",
"6.\tc #EFEFE7",
"7.\tc #E7EFE7",
"8.\tc #ADADA5",
"9.\tc #D6F7F7",
"0.\tc #CEE7E7",
"a.\tc #DEEFD6",
"b.\tc #EFF7E7",
"c.\tc #A5ADAD",
"d.\tc #B5BDBD",
"e.\tc #DEE7D6",
"f.\tc #E7F7DE",
"g.\tc #E7F7E7",
"h.\tc #F7F7E7",
"i.\tc #B5BDB5",
"j.\tc #DEEFE7",
"k.\tc #DEE7DE",
"l.\tc #DEEFDE",
"m.\tc #EFEFDE",
"n.\tc #D6D6D6",
"o.\tc #CECECE",
"p.\tc #BDC6BD",
"q.\tc #D6E7D6",
"r.\tc #E7E7E7",
"s.\tc #DEDEDE",
"t.\tc #CED6D6",
"u.\tc #949C94",
"v.\tc #CEDECE",
"w.\tc #EFEFEF",
"x.\tc #1E1E1E",
"y.\tc #343434",
"z.\tc #4C4C4C",
"A.\tc #5F5F5F",
"B.\tc #535353",
"C.\tc #414141",
"D.\tc #363636",
"E.\tc #3D3D3D",
"F.\tc #5B5B5B",
"G.\tc #747474",
"H.\tc #7F7F7F",
"I.\tc #C6D6CE",
"J.\tc #B9C1B9",
"K.\tc #B8BFB8",
"L.\tc #AFB4AF",
"M.\tc #A8AFA8",
"N.\tc #A9B0A6",
"O.\tc #B6BEB2",
"P.\tc #C9D4C9",
"Q.\tc #E1E7DA",
"R.\tc #ECF4E4",
"S.\tc #F7F7EF",
"T.\tc #F7F7F7",
"U.\tc #DDDDDD",
"V.\tc #B4B4B4",
"W.\tc #9B9B9B",
"X.\tc #868686",
"Y.\tc #AFAFAF",
"Z.\tc #CCDAD3",
"`.\tc #4D4D4D",
" +\tc #CC6575",
".+\tc #A9757D",
"++\tc #947F82",
"@+\tc #666666",
"#+\tc #474747",
"$+\tc #272727",
"%+\tc #707070",
"&+\tc #686868",
"*+\tc #818181",
"=+\tc #7D7D7D",
"-+\tc #8B8B8B",
";+\tc #B9C9C1",
">+\tc #A2A29D",
",+\tc #919391",
"\'+\tc #8D8183",
")+\tc #A9707B",
"!+\tc #CDD2C7",
"~+\tc #D9E5D2",
"{+\tc #CC5B70",
"]+\tc #BA6575",
"^+\tc #A7A7A7",
"/+\tc #929292",
"(+\tc #8E8E8D",
"_+\tc #555555",
":+\tc #9B7C80",
"<+\tc #7A7A7A",
"[+\tc #606060",
"}+\tc #464646",
"|+\tc #656565",
"1+\tc #888888",
"2+\tc #9A9A9A",
"3+\tc #C1C9C9",
"4+\tc #A2A7A7",
"5+\tc #8A8B8A",
"6+\tc #909290",
"7+\tc #989A97",
"8+\tc #8D8082",
"9+\tc #717171",
"0+\tc #3A3A3A",
"a+\tc #898989",
"b+\tc #9F9F9F",
"c+\tc #8E9090",
"d+\tc #7C7C7C",
"e+\tc #4F4F4F",
"f+\tc #5E5E5E",
"g+\tc #828282",
"h+\tc #8A8A8A",
"i+\tc #A6767A",
"j+\tc #C76771",
"k+\tc #977D80",
"l+\tc #908082",
"m+\tc #14370C",
"n+\tc #1A3B12",
"o+\tc #4B5D47",
"p+\tc #888484",
"q+\tc #6D746B",
"r+\tc #17390F",
"s+\tc #6E6E6E",
"t+\tc #193B12",
"u+\tc #4A5C46",
"v+\tc #445840",
"w+\tc #16380E",
"x+\tc #5A6757",
"y+\tc #1B3C14",
"z+\tc #1D3D16",
"A+\tc #556451",
"B+\tc #183A10",
"C+\tc #3D5338",
"D+\tc #646F62",
"E+\tc #858585",
"F+\tc #6E756D",
"G+\tc #6E756C",
"H+\tc #737972",
"I+\tc #1E3E17",
"J+\tc #656F63",
"K+\tc #1C3C15",
"L+\tc #757A74",
"M+\tc #1F3E17",
"N+\tc #465A42",
"O+\tc #183A11",
"P+\tc #6B7369",
"Q+\tc #8A8384",
"R+\tc #596756",
"S+\tc #203F19",
"T+\tc #546351",
"U+\tc #183910",
"V+\tc #3B5236",
"W+\tc #15380D",
"X+\tc #43583F",
"Y+\tc #9B7B7F",
"Z+\tc #626D5F",
"`+\tc #25431E",
" @\tc #8A8B8B",
".@\tc #8B8284",
"+@\tc #838383",
"@@\tc #5D5D5D",
"#@\tc #898984",
"$@\tc #727272",
"%@\tc #193A11",
"&@\tc #5E6A5B",
"*@\tc #8E8E8E",
"=@\tc #989898",
"-@\tc #A9ADA9",
";@\tc #AFAFAA",
">@\tc #AEAEAE",
",@\tc #B6B6B6",
"\'@\tc #676767",
")@\tc #8C8C8A",
"!@\tc #7A7A75",
"~@\tc #7E7E7E",
"{@\tc #777777",
"]@\tc #808080",
"^@\tc #919191",
"/@\tc #9E9E9E",
"(@\tc #B2B2B2",
"_@\tc #C1C1C1",
":@\tc #DBDBD4",
"        . + @ # $ $ $ @ % $ @ & & # % * * = % - ; > * % ; > , + + \' ) ) !   \
                    ",
"      ~ % $ $ $ { { $ & % $ $ @ * # * % & - & - & ; & & * $ ; * > , ] ) \' ^ \
                    ",
"    ~ / { $ $ $ { { $ $ - $ & % * % * % & * & ; - & % & - + % * > - + , ] ) (\
                   ",
"  ~ { { { $ @ { $ $ $ $ * $ $ * & & - > - * & * & > % - - > - @ * = % = + \' \
)                   ",
"~ $ { { $ $ $ $ { # % # @ @ % - % % % * - & - > > = $ & - * = @ % > > % ; , _\
 :                 ",
"$ { { { $ $ $ $ $ # & & # # & > % - * - * ; % * * ; ; * > - % % ; ; * @ * + )\
 )                 ",
"$ $ $ { { $ & @ $ $ & $ @ % * % % - * > ; % % ; - ; # * % % @ $ $ $ % + , , )\
 \' ~               ",
"$ $ $ $ $ $ # $ # @ * $ & $ ; - - % - % ; * % ; - , & & * * = ; + , ] \' < \'\
 < ] \' <             ",
"{ $ $ { $ # $ $ $ @ * $ @ & = & * & - % - % - > @ > @ * + + , [ } | > ; = + <\
 \' ) = , )         ",
"$ $ $ $ $ @ $ { $ - @ $ & @ - - & @ @ $ $ $ $ * % > & = \' > 1 2 3 4 5 6 1 % \
- \' \' \' , - , 7     ",
"$ $ { { # $ & $ $ # @ @ & & % - @ & & - > @ $ - @ ; & ; 8 9 0 a b 4 c d e f g\
 = \' ) ) ] , ] = ) ",
"$ @ $ $ @ & * @ @ $ # @ * * % % % @ % & & & % ; $ = % % h i j k l m n o p e q\
 r ] ) ) \' ) ) \' + ",
"& & $ $ @ * @ & @ & & % * - - * * & > > * % - = - , % [ 6 s t u 4 v w x v y z\
 A B > ) ] ) \' ] ] ",
"& @ { { & $ $ $ & % % * & ; ; > > - - = - - - = * * * ; @ 1 9 3 C D E F 3 G H\
 I J K % * = > ]   ",
"% # $ { @ @ $ & & * $ $ % - ; - - - = + ; - - = > , ; + = & 1 L M N O P Q R S\
 T 8 U % @ * +     ",
"@ $ $ $ @ # # @ & @ * @ % - = > * ; ; - ; - - > * - * = ; & @ $ & E V W N X Y\
 Z % > * ; , ] +   ",
"$ $ $ $ @ # & $ & @ - * = ; - ; * ; = - - % > + & - * ; = - * % @ $ $ & @ ` @\
 @ > @ * * - + > > ",
"$ $ $ $ & @ & # $ # & % % > - ; % > - + % - = = % + * > ; - > - - - % @ * * *\
 % ; > * > + = > > ",
"$ $ $ $ % $ @ % $ % @ @ @ & @ > & - > + * % > + - > - + = ; > - > ; > * > + -\
 > + ; = - + = ; = ",
"$ { # $ $ % # # $ $ # @ * * - - ; > + = > > = - * > & ; = % ; - = % = % * - *\
 ; = * > * ; - & * ",
"@ $ @ & % @ > & & @ @ - * * - % % % - + ; ; + , + ; > = = > = = , > + = , - %\
 > = = ; * , = * @ ",
"$ $ $ $ @ # % # $ @ # $ - > = ; & & ; ] \' \' < ) ] ) ] < ) ] \' , \' = ; * +\
 = - > > % ; ; ; = % * ",
"& % & @ & & * $ $ & @ % @ > ; * & ; = , ] \' _  ._ _ : : : _ _ ) ) \' ] ] + =\
 - = = * - * = = % - ",
"& $ & @ & & @ & @ @ @ # - > > > & ; + ] \' ( _ : ..+.~ +.@.#. .$.7 : _ : : ) \
\' > + - ; > ; = > + ",
"& % $ & @ $ * # $ $ % @ % > * * = - ] \' _ _ : ..%.&.. . *.7 =.-.;.-.>. .$.: \
 .< \' = * = % % - ; ",
"$ @ # % % & @ & { @ @ * % - - ; > = + <  ...,.%.&.\'.).).*.&.%.!.~.=.( {.].^.\
/.7 7 _ < _ ] = , - ",
"{ $ $ @ & * & # $ $ % * * * * = - = , < +.~ (.\'.\'._.:.:.<.[.).}.|.1.=.#.2.3\
.4.: +./. . .\' > = + ",
"{ & & % & % & $ & * # * ; % - > ; = ] < #.!.&.\'._._._.5.<.6.7.<.[.}.1.8.( ! \
! 4.9.0.#./.7 _ \' , ",
"$ @ @ & % % @ $ & # * ; % > - ; ; - + ) : 7 %.(.:.:._.a.<.7.b.b.6.[.}.%...>.(\
 4.9.].c.>.+.d.7 < ",
"$ - * & * * $ @ @ # @ - % % * , = % > ] _ 7 %.|.e.:.5.a.a.f.g.b.h.6.[.. ~ i. \
.$.-._ ! c.9.0.+.: ",
"@ % * & * - $ @ & & - - = * @ * * - > + )  .!.j.*.k.<.l.l.l.f.f.b.b.m.[.n.o.~\
 p.,...: $.].c.: 7 ",
"% % # & @ % $ # $ $ & & & @ & = % * ; ] ] < : p.|.*.e.k.q.l.l.<.<.g.b.6.r.s.*\
.n.. o.o.t./.u.u.0.",
"- - @ % * - $ $ @ $ & > & & % ; % ; > = ] ] _ 7 1.*.*.|.v.q.e.a.<.f.b.b.w.w.r\
.r.r.[.s.s.s.|.~   ",
"& * x.y.z.A.B.C.y.D.* % % & * E.y.F.= G.H.\' \' 7 ^.;.I.J.K.L.M.N.O.P.Q.R.S.T\
.T.w.U.V.W.X.X.) Y.Z.",
"- `. +.+++X.X.] @+#+$+@ % # `.%+&+H.X.X.*+=+H.-+7 ].;+>+,+\'+X.X.X.\'+)+!+~+{\
+]+^+/+X.X.X.X.X.X.(+",
"E._+:+X.X.X.X.X.X.<+[+D.* }+|+<+X.X.X.X.X.X.X.1+2+3+4+5+X.X.X.X.X.X.X.6+7+8+X\
.X.X.X.X.X.X.X.X.X.",
"C.&+X.X.X.X.X.X.X.X.9+0+& _+, X.X.X.X.X.X.X.X.X.a+b+c+X.X.X.X.X.X.X.X.X.X.X.X\
.X.X.X.X.X.X.X.X.X.",
"|+d+X.X.X.X.X.X.X.X.*+e+E.f+g+X.X.X.X.X.X.X.X.X.X.h+1+X.X.X.X.X.X.X.X.X.X.X.X\
.X.X.X.X.X.X.X.X.X.",
"= X.X.X.X.X.X.X.X.X.X.i+j+k+X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X\
.X.X.X.X.X.X.X.X.X.",
"= X.X.X.X.X.X.X.X.X.X.l+k+m+m+n+o+X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X\
.X.m+X.X.X.X.X.X.X.",
"f+*+X.X.X.X.X.X.X.X.X.p+X.m+X.q+r+X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X\
.X.X.X.X.X.X.X.X.X.",
"s+\' X.X.X.X.X.X.X.X.X.X.X.m+m+t+u+X.m+v+w+x+y+y+x+X.m+m+m+z+A+B+C+m+X.m+X.X.\
m+X.m+X.X.X.X.X.X.X.",
"X.X.X.X.X.X.X.X.X.X.X.X.X.m+X.X.X.X.m+D+E+y+F+G+y+X.X.H+I+J+K+F+F+m+X.m+X.X.m\
+X.m+X.X.X.X.X.X.X.",
"X.X.X.X.X.X.X.X.X.X.X.X.X.m+X.X.X.X.m+X.X.y+F+F+y+X.L+M+N+X.K+F+F+m+X.O+L+P+m\
+X.m+X.X.X.X.X.X.X.",
"X.X.X.X.X.X.X.X.X.X.X.Q+X.m+X.X.X.X.m+X.X.R+y+y+x+X.S+m+m+m+T+U+V+W+X.u+B+X+m\
+X.m+X.X.X.X.X.X.X.",
"X.X.X.X.X.X.X.X.X.X.k+Y+X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.Z+`+X.X. @.@X\
.X.a+X.X.X.X.X.X.X.",
"X.X.X.X.X.X.X.X.+@=+@@+ =+X.X.X.X.X.X.X.  #@$@X.X.X.X.X.X.+@+@m+%@&@*@=@-@;@>\
@,@ .(+X.X.X.X.X.X.",
"X.X.X.X.X.X.X.+@\'@F._+`.%+%+] X.X.E+)@      !@= ~@X.X.~@%+\'@{@<+]@^@/@(@_@~\
 o.[.:@: X.X.X.X.X.X."
};
static Fl_Pixmap image_Prozgui3(idata_Prozgui3);

Fl_Check_Button *do_ftpsearch_button=(Fl_Check_Button *)0;

Fl_Window* make_url_input_win() {
  Fl_Window* w;
  { Fl_Window* o = new Fl_Window(440, 140, gettext("Please enter the  URL"));
    w = o;

#ifdef HAVE_LIBXPM		// X11 w/Xpm library
  fl_open_display();
  Pixmap pixmap, mask;		// Icon pixmaps
  XpmAttributes attrs;		// Attributes of icon
    
  memset(&attrs, 0, sizeof(attrs));

  XpmCreatePixmapFromData(fl_display, DefaultRootWindow(fl_display),
			 const_cast<char **>(Prozgui2_xpm), &pixmap, &mask, &attrs);
  o->icon((char *) pixmap);

#endif

    { Fl_Return_Button* o = url_input_ok_button = new Fl_Return_Button(235, 110, 90, 25, gettext("Ok"));
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_url_input_ok);
    }
    { Fl_Input* o = in_url = new Fl_Input(65, 55, 360, 30);
      o->labelsize(12);
      o->textsize(12);
      o->align(133);
    }
    { Fl_Box* o = new Fl_Box(60, 25, 335, 25, gettext("Enter URL (CTRL+V to paste from clipboard)"));
      o->labelsize(12);
      o->align(132|FL_ALIGN_INSIDE);
    }
    { Fl_Box* o = new Fl_Box(5, 30, 55, 60);
      o->image(image_Prozgui3);
    }
    { Fl_Button* o = new Fl_Button(340, 110, 90, 25, gettext("Cancel"));
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_url_input_cancel);
    }
    { Fl_Check_Button* o = do_ftpsearch_button = new Fl_Check_Button(60, 90, 245, 20, gettext("FTP Search for mirrors (Experimental)"));
      o->down_box(FL_DIAMOND_DOWN_BOX);
      o->labelsize(12);
    }
    o->hide();
    o->end();
  }
  return w;
}
