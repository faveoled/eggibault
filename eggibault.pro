TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}

SOURCES	+= main.cpp

FORMS   = mainfrm.ui
