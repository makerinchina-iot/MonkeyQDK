
CONFIG += c++17 c++1z

# app.exe and lib dll path
APP_OUT_PATH = $$PWD/build/bin

# lib*.a path
APP_LIBS_PATH = $$PWD/build/libs

# plugin dll path
APP_PLUGIN_PATH = $$PWD/build/bin/plugins

#lib include
INCLUDEPATH += $$PWD/src/libs
DEPENDPATH  += $$PWD/src/libs

#coreplugin
INCLUDEPATH += $$PWD/src/plugins
DEPENDPATH  += $$PWD/src/plugins

#library name
#defineReplace(replaceLibName) {
#   unset(LIBRARY_NAME)
#   LIBRARY_NAME = $$1
#   CONFIG(debug, debug|release) {
#      !debug_and_release|build_pass {
#          mac:RET = $$member(LIBRARY_NAME, 0)_debug
#              else:win32:RET = $$member(LIBRARY_NAME, 0)d
#      }
#   }
#   isEmpty(RET):RET = $$LIBRARY_NAME
#   return($$RET)
#}
