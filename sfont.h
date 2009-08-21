#ifndef _SFONT_H
#define _SFONT_H

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup SFont

	Functions to manage SFonts
	@{
*/

/**Struct describing a signle SFont letter
	\param letter
        The image representing the letter
	\param width
        The letter's width
*/
typedef struct
{
      OSL_IMAGE *letter;
      unsigned int width;
} OSL_SFLETTER;

/**Struct describing a SFont
	\param letters
        Single letters
	\param lettersCount
        Total number of letters
*/
typedef struct
{
	OSL_SFLETTER *letters[256];
	int height;
	int lettersCount;
} OSL_SFONT;

/** Load an SFont
	\param filename
        file name
	\param pixelFormat 
		pixel format
	Returns a pointer to the loaded OSL_SFONT or NULL
*/
OSL_SFONT *oslLoadSFontFile(char *filename, int pixelFormat);

/** Delete a loaded SFont
	\param sfont
        SFont to delete
*/
void oslDeleteSFont(OSL_SFONT *sfont);

/** Get the text width using a SFont
	\param sfont
        SFont
	\param text
        Text to measure
	Returns width in pixel of the string rendered with the given SFont
*/
int oslGetSFontTextWidth(OSL_SFONT *sfont, char *text);

/** Print a string using SFont
	\param sfont
        SFont to use
	\param text
        Text to print
	Returns the string end position
*/
int oslSFontDrawText(OSL_SFONT *sfont, int x, int y, char *text);

/** @} */ // end of SFont

#ifdef __cplusplus
}
#endif

#endif