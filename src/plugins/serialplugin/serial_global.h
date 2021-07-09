#pragma once

#if defined(SERIALPLUGIN_LIBRARY)
#  define SERIALPLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define SERIALPLUGIN_EXPORT Q_DECL_IMPORT
#endif
