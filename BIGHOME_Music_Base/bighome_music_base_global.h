#ifndef BIGHOME_MUSIC_BASE_GLOBAL_H
#define BIGHOME_MUSIC_BASE_GLOBAL_H

#include <Qt/qglobal.h>

#ifdef BIGHOME_MUSIC_BASE_LIB
# define BIGHOME_MUSIC_BASE_EXPORT Q_DECL_EXPORT
#else
# define BIGHOME_MUSIC_BASE_EXPORT Q_DECL_IMPORT
#endif

#endif // BIGHOME_MUSIC_BASE_GLOBAL_H
