
#include <qapplication.h>
#include "mainfrm.h"

int main ( int argc, char ** argv)
{
	QApplication a( argc, argv );
	mainfrm w;
	w.show();
	a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
	return a.exec();

}
