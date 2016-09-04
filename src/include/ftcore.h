#ifndef __FT_CORE_H__
#define __FT_CORE_H__

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H

/* Define some fixed size types. */
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;

/* Public APIs. */
extern FT_Library
ftcore_CreateFtLibrary(void);

extern FT_Error
ftcore_DestroyFtLibrary(FT_Library *pft_library);

extern FT_Face
ftcore_CreateFace(FT_Library ft_library, const char *ft_fontpath, FT_Long ft_index);

extern FT_Error
ftcore_DestroyFace(FT_Face *pft_face);

#endif /* __FT_CORE_H__ */

// Local Variables: 
// coding: utf-8
// End: 
