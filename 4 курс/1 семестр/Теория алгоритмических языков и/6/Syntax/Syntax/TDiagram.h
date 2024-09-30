#pragma once
#ifndef __DIAGRAM
#define __DIAGRAM
#include "TScaner.h"
#include "Errs.h"



class TDiagram
{
private:
	TScaner* ts;
public:
	TDiagram(TScaner* ts) { this->ts = ts; };
	~TDiagram() {};

	void S(); // опнцпюллю
	void F(); // тсмйжхъ

	// ноепюрнпш
	void O(); // ноепюрнп
	void G(); // ноепюрнп: бшгнб тсмйжхх
	void I(); // ноепюрнп: IF
	void W(); // ноепюрнп: янярюбмни
	void J(); // ноепюрнп: опхябюхбюмхе

	// ноепюжхх
	void Q(); // ноепюжхъ: кнц. пюбемярбн
	void M(); // ноепюжхъ: кнц. лмнфеярбн
	void A(); // ноепюжхъ: юддхрхбмше
	void X(); // ноепюжхъ: лскэрхокхйюрхбмше
	void L(); // опняреиьее бшпюемхе 

	// ноепюмдш х йнмярюмрш
	void D(); // дюммше 
	void N(); // рхо дюммшу (я яоежхтхйюрнпюлх)
	void C(); // яохянй
	void H(); // оепелеммюъ
	void Z(); // бшпюфемхе

};

#endif //__DIAGRAM

