// CodeGear C++Builder
// Copyright (c) 1995, 2017 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GIFImage.pas' rev: 32.00 (Windows)

#ifndef GifimageHPP
#define GifimageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gifimage
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS GIFException;
class DELPHICLASS TGIFItem;
class DELPHICLASS TGIFList;
struct TGIFColor;
struct TUsageCount;
class DELPHICLASS TGIFColorMap;
struct TLogicalScreenDescriptor;
class DELPHICLASS TGIFHeader;
class DELPHICLASS TGIFExtension;
class DELPHICLASS TGIFExtensionList;
struct TImageDescriptor;
class DELPHICLASS TGIFSubImage;
class DELPHICLASS TGIFTrailer;
struct TGIFGCERec;
class DELPHICLASS TGIFGraphicControlExtension;
struct TGIFPlainTextExtensionRec;
class DELPHICLASS TGIFTextExtension;
class DELPHICLASS TGIFCommentExtension;
struct TGIFApplicationRec;
class DELPHICLASS TGIFApplicationExtension;
class DELPHICLASS TGIFBlock;
class DELPHICLASS TGIFUnknownAppExtension;
class DELPHICLASS TGIFAppExtNSLoop;
class DELPHICLASS TGIFImageList;
class DELPHICLASS TGIFPainter;
class DELPHICLASS TGIFImage;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGIFVersion : unsigned char { gvUnknown, gv87a, gv89a };

typedef System::StaticArray<char, 3> TGIFVersionRec;

#pragma pack(push,4)
class PASCALIMPLEMENTATION GIFException : public Vcl::Graphics::EInvalidGraphic
{
	typedef Vcl::Graphics::EInvalidGraphic inherited;
	
public:
	/* Exception.Create */ inline __fastcall GIFException(const System::UnicodeString Msg) : Vcl::Graphics::EInvalidGraphic(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall GIFException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : Vcl::Graphics::EInvalidGraphic(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall GIFException(NativeUInt Ident)/* overload */ : Vcl::Graphics::EInvalidGraphic(Ident) { }
	/* Exception.CreateRes */ inline __fastcall GIFException(System::PResStringRec ResStringRec)/* overload */ : Vcl::Graphics::EInvalidGraphic(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall GIFException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : Vcl::Graphics::EInvalidGraphic(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall GIFException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : Vcl::Graphics::EInvalidGraphic(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall GIFException(const System::UnicodeString Msg, int AHelpContext) : Vcl::Graphics::EInvalidGraphic(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall GIFException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : Vcl::Graphics::EInvalidGraphic(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall GIFException(NativeUInt Ident, int AHelpContext)/* overload */ : Vcl::Graphics::EInvalidGraphic(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall GIFException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Vcl::Graphics::EInvalidGraphic(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall GIFException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Vcl::Graphics::EInvalidGraphic(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall GIFException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : Vcl::Graphics::EInvalidGraphic(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~GIFException(void) { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGIFSeverity : unsigned char { gsInfo, gsWarning, gsError };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFItem : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TGIFImage* FGIFImage;
	
protected:
	virtual TGIFVersion __fastcall GetVersion(void);
	virtual void __fastcall Warning(TGIFSeverity Severity, System::UnicodeString Message);
	
public:
	__fastcall virtual TGIFItem(TGIFImage* GIFImage);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream) = 0 ;
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream) = 0 ;
	virtual void __fastcall SaveToFile(const System::UnicodeString Filename);
	virtual void __fastcall LoadFromFile(const System::UnicodeString Filename);
	__property TGIFVersion Version = {read=GetVersion, nodefault};
	__property TGIFImage* Image = {read=FGIFImage};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGIFItem(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFList : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TGIFItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	TGIFImage* FImage;
	
protected:
	TGIFItem* __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, TGIFItem* Item);
	int __fastcall GetCount(void);
	virtual void __fastcall Warning(TGIFSeverity Severity, System::UnicodeString Message);
	
public:
	__fastcall TGIFList(TGIFImage* Image);
	__fastcall virtual ~TGIFList(void);
	int __fastcall Add(TGIFItem* Item);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall Exchange(int Index1, int Index2);
	TGIFItem* __fastcall First(void);
	int __fastcall IndexOf(TGIFItem* Item);
	void __fastcall Insert(int Index, TGIFItem* Item);
	TGIFItem* __fastcall Last(void);
	void __fastcall Move(int CurIndex, int NewIndex);
	int __fastcall Remove(TGIFItem* Item);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream, System::TObject* Parent) = 0 ;
	__property TGIFItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
	__property System::Classes::TList* List = {read=FItems};
	__property TGIFImage* Image = {read=FImage};
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGIFColor
{
public:
	System::Byte Red;
	System::Byte Green;
	System::Byte Blue;
};
#pragma pack(pop)


typedef System::StaticArray<TGIFColor, 256> TColorMap;

typedef TColorMap *PColorMap;

struct DECLSPEC_DRECORD TUsageCount
{
public:
	int Count;
	int Index;
};


typedef System::StaticArray<TUsageCount, 256> TColormapHistogram;

typedef System::StaticArray<System::Byte, 256> TColormapReverse;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFColorMap : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	System::Uitypes::TColor operator[](int Index) { return this->Colors[Index]; }
	
private:
	TColorMap *FColorMap;
	int FCount;
	int FCapacity;
	bool FOptimized;
	
protected:
	System::Uitypes::TColor __fastcall GetColor(int Index);
	void __fastcall SetColor(int Index, System::Uitypes::TColor Value);
	int __fastcall GetBitsPerPixel(void);
	bool __fastcall DoOptimize(void);
	void __fastcall SetCapacity(int Size);
	virtual void __fastcall Warning(TGIFSeverity Severity, System::UnicodeString Message) = 0 ;
	virtual void __fastcall BuildHistogram(TColormapHistogram &Histogram) = 0 ;
	virtual void __fastcall MapImages(TColormapReverse &Map) = 0 ;
	
public:
	__fastcall TGIFColorMap(void);
	__fastcall virtual ~TGIFColorMap(void);
	__classmethod TGIFColor __fastcall Color2RGB(System::Uitypes::TColor Color);
	__classmethod System::Uitypes::TColor __fastcall RGB2Color(TGIFColor Color);
	void __fastcall SaveToStream(System::Classes::TStream* Stream);
	void __fastcall LoadFromStream(System::Classes::TStream* Stream, int Count);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	int __fastcall IndexOf(System::Uitypes::TColor Color);
	int __fastcall Add(System::Uitypes::TColor Color);
	int __fastcall AddUnique(System::Uitypes::TColor Color);
	void __fastcall Delete(int Index);
	void __fastcall Clear(void);
	virtual bool __fastcall Optimize(void) = 0 ;
	virtual void __fastcall Changed(void) = 0 ;
	void __fastcall ImportPalette(HPALETTE Palette);
	void __fastcall ImportColorTable(void * Pal, int Count);
	void __fastcall ImportDIBColors(HDC Handle);
	void __fastcall ImportColorMap(const TColorMap &Map, int Count);
	HPALETTE __fastcall ExportPalette(void);
	__property System::Uitypes::TColor Colors[int Index] = {read=GetColor, write=SetColor/*, default*/};
	__property PColorMap Data = {read=FColorMap};
	__property int Count = {read=FCount, nodefault};
	__property bool Optimized = {read=FOptimized, write=FOptimized, nodefault};
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TLogicalScreenDescriptor
{
public:
	System::Word ScreenWidth;
	System::Word ScreenHeight;
	System::Byte PackedFields;
	System::Byte BackgroundColorIndex;
	System::Byte AspectRatio;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFHeader : public TGIFItem
{
	typedef TGIFItem inherited;
	
private:
	TLogicalScreenDescriptor FLogicalScreenDescriptor;
	TGIFColorMap* FColorMap;
	void __fastcall Prepare(void);
	
protected:
	virtual TGIFVersion __fastcall GetVersion(void);
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	void __fastcall SetBackgroundColor(System::Uitypes::TColor Color);
	void __fastcall SetBackgroundColorIndex(System::Byte Index);
	int __fastcall GetBitsPerPixel(void);
	int __fastcall GetColorResolution(void);
	
public:
	__fastcall virtual TGIFHeader(TGIFImage* GIFImage);
	__fastcall virtual ~TGIFHeader(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	void __fastcall Clear(void);
	__property TGIFVersion Version = {read=GetVersion, nodefault};
	__property System::Word Width = {read=FLogicalScreenDescriptor.ScreenWidth, write=FLogicalScreenDescriptor.ScreenWidth, nodefault};
	__property System::Word Height = {read=FLogicalScreenDescriptor.ScreenHeight, write=FLogicalScreenDescriptor.ScreenHeight, nodefault};
	__property System::Byte BackgroundColorIndex = {read=FLogicalScreenDescriptor.BackgroundColorIndex, write=SetBackgroundColorIndex, nodefault};
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, write=SetBackgroundColor, nodefault};
	__property System::Byte AspectRatio = {read=FLogicalScreenDescriptor.AspectRatio, write=FLogicalScreenDescriptor.AspectRatio, nodefault};
	__property TGIFColorMap* ColorMap = {read=FColorMap};
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
	__property int ColorResolution = {read=GetColorResolution, nodefault};
};

#pragma pack(pop)

typedef System::Byte TGIFExtensionType;

typedef System::TMetaClass* TGIFExtensionClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFExtension : public TGIFItem
{
	typedef TGIFItem inherited;
	
private:
	TGIFSubImage* FSubImage;
	
protected:
	virtual System::Byte __fastcall GetExtensionType(void) = 0 ;
	virtual TGIFVersion __fastcall GetVersion(void);
	System::Byte __fastcall DoReadFromStream(System::Classes::TStream* Stream);
	__classmethod void __fastcall RegisterExtension(System::Byte elabel, TGIFExtensionClass eClass);
	__classmethod TGIFExtensionClass __fastcall FindExtension(System::Classes::TStream* Stream);
	__classmethod virtual TGIFExtensionClass __fastcall FindSubExtension(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TGIFExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFExtension(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	__property System::Byte ExtensionType = {read=GetExtensionType, nodefault};
	__property TGIFSubImage* SubImage = {read=FSubImage};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFExtensionList : public TGIFList
{
	typedef TGIFList inherited;
	
public:
	TGIFExtension* operator[](int Index) { return this->Extensions[Index]; }
	
protected:
	TGIFExtension* __fastcall GetExtension(int Index);
	void __fastcall SetExtension(int Index, TGIFExtension* Extension);
	
public:
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream, System::TObject* Parent);
	__property TGIFExtension* Extensions[int Index] = {read=GetExtension, write=SetExtension/*, default*/};
public:
	/* TGIFList.Create */ inline __fastcall TGIFExtensionList(TGIFImage* Image) : TGIFList(Image) { }
	/* TGIFList.Destroy */ inline __fastcall virtual ~TGIFExtensionList(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TImageDescriptor
{
public:
	System::Byte Separator;
	System::Word Left;
	System::Word Top;
	System::Word Width;
	System::Word Height;
	System::Byte PackedFields;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFSubImage : public TGIFItem
{
	typedef TGIFItem inherited;
	
private:
	Vcl::Graphics::TBitmap* FBitmap;
	HBITMAP FMask;
	bool FNeedMask;
	HPALETTE FLocalPalette;
	char *FData;
	int FDataSize;
	TGIFColorMap* FColorMap;
	TImageDescriptor FImageDescriptor;
	TGIFExtensionList* FExtensions;
	bool FTransparent;
	TGIFGraphicControlExtension* FGCE;
	void __fastcall Prepare(void);
	void __fastcall Compress(System::Classes::TStream* Stream);
	void __fastcall Decompress(System::Classes::TStream* Stream);
	
protected:
	virtual TGIFVersion __fastcall GetVersion(void);
	bool __fastcall GetInterlaced(void);
	void __fastcall SetInterlaced(bool Value);
	int __fastcall GetColorResolution(void);
	int __fastcall GetBitsPerPixel(void);
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	Vcl::Graphics::TBitmap* __fastcall DoGetBitmap(void);
	Vcl::Graphics::TBitmap* __fastcall DoGetDitherBitmap(void);
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(void);
	void __fastcall SetBitmap(Vcl::Graphics::TBitmap* Value);
	void __fastcall FreeMask(void);
	bool __fastcall GetEmpty(void);
	HPALETTE __fastcall GetPalette(void);
	void __fastcall SetPalette(HPALETTE Value);
	TGIFColorMap* __fastcall GetActiveColorMap(void);
	System::Types::TRect __fastcall GetBoundsRect(void);
	void __fastcall SetBoundsRect(const System::Types::TRect &Value);
	void __fastcall DoSetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	System::Types::TRect __fastcall GetClientRect(void);
	System::Byte __fastcall GetPixel(int x, int y);
	void __fastcall SetPixel(int x, int y, System::Byte Value);
	void * __fastcall GetScanline(int y);
	void __fastcall NewBitmap(void);
	void __fastcall FreeBitmap(void);
	void __fastcall NewImage(void);
	void __fastcall FreeImage(void);
	void __fastcall NeedImage(void);
	System::Types::TRect __fastcall ScaleRect(const System::Types::TRect &DestRect);
	bool __fastcall HasMask(void);
	System::Word __fastcall GetBounds(int Index);
	void __fastcall SetBounds(int Index, System::Word Value);
	bool __fastcall GetHasBitmap(void);
	void __fastcall SetHasBitmap(bool Value);
	
public:
	__fastcall virtual TGIFSubImage(TGIFImage* GIFImage);
	__fastcall virtual ~TGIFSubImage(void);
	void __fastcall Clear(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Rect, bool DoTransparent, bool DoTile);
	void __fastcall StretchDraw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Rect, bool DoTransparent, bool DoTile);
	void __fastcall Crop(void);
	void __fastcall Merge(TGIFSubImage* Previous);
	__property bool HasBitmap = {read=GetHasBitmap, write=SetHasBitmap, nodefault};
	__property System::Word Left = {read=GetBounds, write=SetBounds, index=1, nodefault};
	__property System::Word Top = {read=GetBounds, write=SetBounds, index=2, nodefault};
	__property System::Word Width = {read=GetBounds, write=SetBounds, index=3, nodefault};
	__property System::Word Height = {read=GetBounds, write=SetBounds, index=4, nodefault};
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property bool Interlaced = {read=GetInterlaced, write=SetInterlaced, nodefault};
	__property TGIFColorMap* ColorMap = {read=FColorMap};
	__property TGIFColorMap* ActiveColorMap = {read=GetActiveColorMap};
	__property char * Data = {read=FData};
	__property int DataSize = {read=FDataSize, nodefault};
	__property TGIFExtensionList* Extensions = {read=FExtensions};
	__property TGIFVersion Version = {read=GetVersion, nodefault};
	__property int ColorResolution = {read=GetColorResolution, nodefault};
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
	__property Vcl::Graphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property HBITMAP Mask = {read=FMask, nodefault};
	__property HPALETTE Palette = {read=GetPalette, write=SetPalette, nodefault};
	__property bool Empty = {read=GetEmpty, nodefault};
	__property bool Transparent = {read=FTransparent, nodefault};
	__property TGIFGraphicControlExtension* GraphicControlExtension = {read=FGCE};
	__property System::Byte Pixels[int x][int y] = {read=GetPixel, write=SetPixel};
	__property void * Scanline[int y] = {read=GetScanline};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFTrailer : public TGIFItem
{
	typedef TGIFItem inherited;
	
__published:
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
public:
	/* TGIFItem.Create */ inline __fastcall virtual TGIFTrailer(TGIFImage* GIFImage) : TGIFItem(GIFImage) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGIFTrailer(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGIFGCERec
{
public:
	System::Byte BlockSize;
	System::Byte PackedFields;
	System::Word DelayTime;
	System::Byte TransparentColorIndex;
	System::Byte Terminator;
};
#pragma pack(pop)


enum DECLSPEC_DENUM TDisposalMethod : unsigned char { dmNone, dmNoDisposal, dmBackground, dmPrevious };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFGraphicControlExtension : public TGIFExtension
{
	typedef TGIFExtension inherited;
	
private:
	TGIFGCERec FGCExtension;
	
protected:
	virtual System::Byte __fastcall GetExtensionType(void);
	bool __fastcall GetTransparent(void);
	void __fastcall SetTransparent(bool Value);
	System::Uitypes::TColor __fastcall GetTransparentColor(void);
	void __fastcall SetTransparentColor(System::Uitypes::TColor Color);
	System::Byte __fastcall GetTransparentColorIndex(void);
	void __fastcall SetTransparentColorIndex(System::Byte Value);
	System::Word __fastcall GetDelay(void);
	void __fastcall SetDelay(System::Word Value);
	bool __fastcall GetUserInput(void);
	void __fastcall SetUserInput(bool Value);
	TDisposalMethod __fastcall GetDisposal(void);
	void __fastcall SetDisposal(TDisposalMethod Value);
	
public:
	__fastcall virtual TGIFGraphicControlExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFGraphicControlExtension(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	__property System::Word Delay = {read=GetDelay, write=SetDelay, nodefault};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, nodefault};
	__property System::Byte TransparentColorIndex = {read=GetTransparentColorIndex, write=SetTransparentColorIndex, nodefault};
	__property System::Uitypes::TColor TransparentColor = {read=GetTransparentColor, write=SetTransparentColor, nodefault};
	__property bool UserInput = {read=GetUserInput, write=SetUserInput, nodefault};
	__property TDisposalMethod Disposal = {read=GetDisposal, write=SetDisposal, nodefault};
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGIFPlainTextExtensionRec
{
public:
	System::Byte BlockSize;
	System::Word Left;
	System::Word Top;
	System::Word Width;
	System::Word Height;
	System::Byte CellWidth;
	System::Byte CellHeight;
	System::Byte TextFGColorIndex;
	System::Byte TextBGColorIndex;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFTextExtension : public TGIFExtension
{
	typedef TGIFExtension inherited;
	
private:
	System::Classes::TStrings* FText;
	TGIFPlainTextExtensionRec FPlainTextExtension;
	
protected:
	virtual System::Byte __fastcall GetExtensionType(void);
	System::Uitypes::TColor __fastcall GetForegroundColor(void);
	void __fastcall SetForegroundColor(System::Uitypes::TColor Color);
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	void __fastcall SetBackgroundColor(System::Uitypes::TColor Color);
	System::Word __fastcall GetBounds(int Index);
	void __fastcall SetBounds(int Index, System::Word Value);
	System::Byte __fastcall GetCharWidthHeight(int Index);
	void __fastcall SetCharWidthHeight(int Index, System::Byte Value);
	System::Byte __fastcall GetColorIndex(int Index);
	void __fastcall SetColorIndex(int Index, System::Byte Value);
	
public:
	__fastcall virtual TGIFTextExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFTextExtension(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	__property System::Word Left = {read=GetBounds, write=SetBounds, index=1, nodefault};
	__property System::Word Top = {read=GetBounds, write=SetBounds, index=2, nodefault};
	__property System::Word GridWidth = {read=GetBounds, write=SetBounds, index=3, nodefault};
	__property System::Word GridHeight = {read=GetBounds, write=SetBounds, index=4, nodefault};
	__property System::Byte CharWidth = {read=GetCharWidthHeight, write=SetCharWidthHeight, index=1, nodefault};
	__property System::Byte CharHeight = {read=GetCharWidthHeight, write=SetCharWidthHeight, index=2, nodefault};
	__property System::Byte ForegroundColorIndex = {read=GetColorIndex, write=SetColorIndex, index=1, nodefault};
	__property System::Uitypes::TColor ForegroundColor = {read=GetForegroundColor, nodefault};
	__property System::Byte BackgroundColorIndex = {read=GetColorIndex, write=SetColorIndex, index=2, nodefault};
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	__property System::Classes::TStrings* Text = {read=FText, write=FText};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFCommentExtension : public TGIFExtension
{
	typedef TGIFExtension inherited;
	
private:
	System::Classes::TStrings* FText;
	
protected:
	virtual System::Byte __fastcall GetExtensionType(void);
	
public:
	__fastcall virtual TGIFCommentExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFCommentExtension(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	__property System::Classes::TStrings* Text = {read=FText};
};

#pragma pack(pop)

typedef System::StaticArray<char, 8> TGIFIdentifierCode;

typedef System::StaticArray<char, 3> TGIFAuthenticationCode;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGIFApplicationRec
{
public:
	TGIFIdentifierCode Identifier;
	TGIFAuthenticationCode Authentication;
};
#pragma pack(pop)


typedef System::TMetaClass* TGIFAppExtensionClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFApplicationExtension : public TGIFExtension
{
	typedef TGIFExtension inherited;
	
private:
	TGIFApplicationRec FIdent;
	System::AnsiString __fastcall GetAuthentication(void);
	System::AnsiString __fastcall GetIdentifier(void);
	
protected:
	virtual System::Byte __fastcall GetExtensionType(void);
	void __fastcall SetAuthentication(const System::AnsiString Value);
	void __fastcall SetIdentifier(const System::AnsiString Value);
	virtual void __fastcall SaveData(System::Classes::TStream* Stream) = 0 ;
	virtual void __fastcall LoadData(System::Classes::TStream* Stream) = 0 ;
	
public:
	__fastcall virtual TGIFApplicationExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFApplicationExtension(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	__classmethod void __fastcall RegisterExtension(const TGIFApplicationRec &eIdent, TGIFAppExtensionClass eClass);
	__classmethod virtual TGIFExtensionClass __fastcall FindSubExtension(System::Classes::TStream* Stream);
	__property System::AnsiString Identifier = {read=GetIdentifier, write=SetIdentifier};
	__property System::AnsiString Authentication = {read=GetAuthentication, write=SetAuthentication};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFBlock : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Byte FSize;
	void *FData;
	
public:
	__fastcall TGIFBlock(int ASize);
	__fastcall virtual ~TGIFBlock(void);
	void __fastcall SaveToStream(System::Classes::TStream* Stream);
	void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	__property System::Byte Size = {read=FSize, nodefault};
	__property void * Data = {read=FData};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFUnknownAppExtension : public TGIFApplicationExtension
{
	typedef TGIFApplicationExtension inherited;
	
private:
	System::Classes::TList* FBlocks;
	
protected:
	virtual void __fastcall SaveData(System::Classes::TStream* Stream);
	virtual void __fastcall LoadData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TGIFUnknownAppExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFUnknownAppExtension(void);
	__property System::Classes::TList* Blocks = {read=FBlocks};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFAppExtNSLoop : public TGIFApplicationExtension
{
	typedef TGIFApplicationExtension inherited;
	
private:
	System::Word FLoops;
	unsigned FBufferSize;
	
protected:
	virtual void __fastcall SaveData(System::Classes::TStream* Stream);
	virtual void __fastcall LoadData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TGIFAppExtNSLoop(TGIFSubImage* ASubImage);
	__property System::Word Loops = {read=FLoops, write=FLoops, nodefault};
	__property unsigned BufferSize = {read=FBufferSize, write=FBufferSize, nodefault};
public:
	/* TGIFApplicationExtension.Destroy */ inline __fastcall virtual ~TGIFAppExtNSLoop(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGIFImageList : public TGIFList
{
	typedef TGIFList inherited;
	
public:
	TGIFSubImage* operator[](int Index) { return this->SubImages[Index]; }
	
protected:
	TGIFSubImage* __fastcall GetImage(int Index);
	void __fastcall SetImage(int Index, TGIFSubImage* SubImage);
	
public:
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream, System::TObject* Parent);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	__property TGIFSubImage* SubImages[int Index] = {read=GetImage, write=SetImage/*, default*/};
public:
	/* TGIFList.Create */ inline __fastcall TGIFImageList(TGIFImage* Image) : TGIFList(Image) { }
	/* TGIFList.Destroy */ inline __fastcall virtual ~TGIFImageList(void) { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TGIFCompression : unsigned char { gcLZW, gcRLE };

enum DECLSPEC_DENUM TColorReduction : unsigned char { rmNone, rmWindows20, rmWindows256, rmWindowsGray, rmMonochrome, rmGrayScale, rmNetscape, rmQuantize, rmQuantizeWindows, rmPalette };

enum DECLSPEC_DENUM TDitherMode : unsigned char { dmNearest, dmFloydSteinberg, dmStucki, dmSierra, dmJaJuNI, dmSteveArche, dmBurkes };

enum DECLSPEC_DENUM TGIFOptimizeOption : unsigned char { ooCrop, ooMerge, ooCleanup, ooColorMap, ooReduceColors };

typedef System::Set<TGIFOptimizeOption, TGIFOptimizeOption::ooCrop, TGIFOptimizeOption::ooReduceColors> TGIFOptimizeOptions;

enum DECLSPEC_DENUM TGIFDrawOption : unsigned char { goAsync, goTransparent, goAnimate, goLoop, goLoopContinously, goValidateCanvas, goDirectDraw, goClearOnLoop, goTile, goDither, goAutoDither };

typedef System::Set<TGIFDrawOption, TGIFDrawOption::goAsync, TGIFDrawOption::goAutoDither> TGIFDrawOptions;

typedef TGIFPainter* *PGIFPainter;

class PASCALIMPLEMENTATION TGIFPainter : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	TGIFImage* FImage;
	Vcl::Graphics::TCanvas* FCanvas;
	System::Types::TRect FRect;
	TGIFDrawOptions FDrawOptions;
	int FAnimationSpeed;
	int FActiveImage;
	TDisposalMethod Disposal;
	TDisposalMethod OldDisposal;
	Vcl::Graphics::TBitmap* BackupBuffer;
	Vcl::Graphics::TBitmap* FrameBuffer;
	Vcl::Graphics::TBitmap* Background;
	HDC ValidateDC;
	bool DoRestart;
	bool FStarted;
	TGIFPainter* *PainterRef;
	NativeUInt FEventHandle;
	System::Sysutils::Exception* ExceptObject;
	void *ExceptAddress;
	System::Classes::TNotifyEvent FEvent;
	System::Classes::TNotifyEvent FOnStartPaint;
	System::Classes::TNotifyEvent FOnPaint;
	System::Classes::TNotifyEvent FOnAfterPaint;
	System::Classes::TNotifyEvent FOnLoop;
	System::Classes::TNotifyEvent FOnEndPaint;
	void __fastcall DoOnTerminate(System::TObject* Sender);
	void __fastcall DoSynchronize(System::Classes::TThreadMethod Method);
	void __fastcall DoPaintFrame(void);
	void __fastcall DoPaint(void);
	void __fastcall DoEvent(void);
	void __fastcall SetActiveImage(const int Value);
	
protected:
	virtual void __fastcall Execute(void);
	void __fastcall SetAnimationSpeed(int Value);
	
public:
	__fastcall TGIFPainter(TGIFImage* AImage, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, TGIFDrawOptions Options);
	__fastcall TGIFPainter(PGIFPainter Painter, TGIFImage* AImage, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, TGIFDrawOptions Options);
	__fastcall virtual ~TGIFPainter(void);
	HIDESBASE void __fastcall Start(void);
	void __fastcall Stop(void);
	void __fastcall Restart(void);
	__property TGIFImage* Image = {read=FImage};
	__property Vcl::Graphics::TCanvas* Canvas = {read=FCanvas};
	__property System::Types::TRect Rect = {read=FRect, write=FRect};
	__property TGIFDrawOptions DrawOptions = {read=FDrawOptions, write=FDrawOptions, nodefault};
	__property int AnimationSpeed = {read=FAnimationSpeed, write=SetAnimationSpeed, nodefault};
	__property bool Started = {read=FStarted, nodefault};
	__property int ActiveImage = {read=FActiveImage, write=SetActiveImage, nodefault};
	__property System::Classes::TNotifyEvent OnStartPaint = {read=FOnStartPaint, write=FOnStartPaint};
	__property System::Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property System::Classes::TNotifyEvent OnAfterPaint = {read=FOnAfterPaint, write=FOnAfterPaint};
	__property System::Classes::TNotifyEvent OnLoop = {read=FOnLoop, write=FOnLoop};
	__property System::Classes::TNotifyEvent OnEndPaint = {read=FOnEndPaint, write=FOnEndPaint};
	__property NativeUInt EventHandle = {read=FEventHandle, nodefault};
};


typedef void __fastcall (__closure *TGIFWarning)(System::TObject* Sender, TGIFSeverity Severity, System::UnicodeString Message);

class PASCALIMPLEMENTATION TGIFImage : public Vcl::Graphics::TGraphic
{
	typedef Vcl::Graphics::TGraphic inherited;
	
private:
	bool IsDrawing;
	bool IsInsideGetPalette;
	TGIFImageList* FImages;
	TGIFHeader* FHeader;
	HPALETTE FGlobalPalette;
	System::Classes::TThreadList* FPainters;
	TGIFDrawOptions FDrawOptions;
	TColorReduction FColorReduction;
	int FReductionBits;
	TDitherMode FDitherMode;
	TGIFCompression FCompression;
	TGIFWarning FOnWarning;
	Vcl::Graphics::TBitmap* FBitmap;
	TGIFPainter* FDrawPainter;
	System::Classes::TThreadPriority FThreadPriority;
	int FAnimationSpeed;
	int FForceFrame;
	System::Uitypes::TColor FDrawBackgroundColor;
	System::Classes::TNotifyEvent FOnStartPaint;
	System::Classes::TNotifyEvent FOnPaint;
	System::Classes::TNotifyEvent FOnAfterPaint;
	System::Classes::TNotifyEvent FOnLoop;
	System::Classes::TNotifyEvent FOnEndPaint;
	bool __fastcall GetAnimate(void);
	void __fastcall SetAnimate(const bool Value);
	void __fastcall SetForceFrame(const int Value);
	
protected:
	virtual int __fastcall GetHeight(void);
	virtual void __fastcall SetHeight(int Value);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	TGIFPainter* __fastcall InternalPaint(PGIFPainter Painter, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Rect, TGIFDrawOptions Options);
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Rect);
	virtual bool __fastcall Equals(Vcl::Graphics::TGraphic* Graphic)/* overload */;
	virtual HPALETTE __fastcall GetPalette(void);
	virtual void __fastcall SetPalette(HPALETTE Value);
	virtual bool __fastcall GetEmpty(void);
	virtual void __fastcall WriteData(System::Classes::TStream* Stream);
	bool __fastcall GetIsTransparent(void);
	TGIFVersion __fastcall GetVersion(void);
	int __fastcall GetColorResolution(void);
	int __fastcall GetBitsPerPixel(void);
	System::Byte __fastcall GetBackgroundColorIndex(void);
	void __fastcall SetBackgroundColorIndex(const System::Byte Value);
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	void __fastcall SetBackgroundColor(const System::Uitypes::TColor Value);
	System::Byte __fastcall GetAspectRatio(void);
	void __fastcall SetAspectRatio(const System::Byte Value);
	void __fastcall SetDrawOptions(TGIFDrawOptions Value);
	void __fastcall SetAnimationSpeed(int Value);
	void __fastcall SetReductionBits(int Value);
	void __fastcall NewImage(void);
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(void);
	Vcl::Graphics::TBitmap* __fastcall NewBitmap(void);
	void __fastcall FreeBitmap(void);
	TGIFColorMap* __fastcall GetColorMap(void);
	bool __fastcall GetDoDither(void);
	__property TGIFPainter* DrawPainter = {read=FDrawPainter};
	__property bool DoDither = {read=GetDoDither, nodefault};
	void __fastcall FixHeaderWidthHeight(void);
	
public:
	__fastcall virtual TGIFImage(void);
	__fastcall virtual ~TGIFImage(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	void __fastcall LoadFromResourceName(NativeUInt Instance, const System::UnicodeString ResName);
	int __fastcall Add(System::Classes::TPersistent* Source);
	void __fastcall Pack(void);
	void __fastcall OptimizeColorMap(void);
	void __fastcall Optimize(TGIFOptimizeOptions Options, TColorReduction ColorReduction, TDitherMode DitherMode, int ReductionBits);
	void __fastcall Clear(void);
	void __fastcall StopDraw(void);
	TGIFPainter* __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Rect, TGIFDrawOptions Options);
	void __fastcall PaintStart(void);
	void __fastcall PaintPause(void);
	void __fastcall PaintStop(void);
	void __fastcall PaintResume(void);
	void __fastcall PaintRestart(void);
	virtual void __fastcall Warning(System::TObject* Sender, TGIFSeverity Severity, System::UnicodeString Message);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall LoadFromClipboardFormat(System::Word AFormat, NativeUInt AData, HPALETTE APalette);
	virtual void __fastcall SaveToClipboardFormat(System::Word &AFormat, NativeUInt &AData, HPALETTE &APalette);
	__property TGIFColorMap* GlobalColorMap = {read=GetColorMap};
	__property TGIFVersion Version = {read=GetVersion, nodefault};
	__property TGIFImageList* Images = {read=FImages};
	__property int ColorResolution = {read=GetColorResolution, nodefault};
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
	__property System::Byte BackgroundColorIndex = {read=GetBackgroundColorIndex, write=SetBackgroundColorIndex, nodefault};
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, write=SetBackgroundColor, nodefault};
	__property System::Byte AspectRatio = {read=GetAspectRatio, write=SetAspectRatio, nodefault};
	__property TGIFHeader* Header = {read=FHeader};
	__property bool IsTransparent = {read=GetIsTransparent, nodefault};
	__property TGIFDrawOptions DrawOptions = {read=FDrawOptions, write=SetDrawOptions, nodefault};
	__property System::Uitypes::TColor DrawBackgroundColor = {read=FDrawBackgroundColor, write=FDrawBackgroundColor, nodefault};
	__property TColorReduction ColorReduction = {read=FColorReduction, write=FColorReduction, nodefault};
	__property int ReductionBits = {read=FReductionBits, write=SetReductionBits, nodefault};
	__property TDitherMode DitherMode = {read=FDitherMode, write=FDitherMode, nodefault};
	__property TGIFCompression Compression = {read=FCompression, write=FCompression, nodefault};
	__property int AnimationSpeed = {read=FAnimationSpeed, write=SetAnimationSpeed, nodefault};
	__property bool Animate = {read=GetAnimate, write=SetAnimate, nodefault};
	__property int ForceFrame = {read=FForceFrame, write=SetForceFrame, nodefault};
	__property System::Classes::TThreadList* Painters = {read=FPainters};
	__property System::Classes::TThreadPriority ThreadPriority = {read=FThreadPriority, write=FThreadPriority, nodefault};
	__property Vcl::Graphics::TBitmap* Bitmap = {read=GetBitmap};
	__property TGIFWarning OnWarning = {read=FOnWarning, write=FOnWarning};
	__property System::Classes::TNotifyEvent OnStartPaint = {read=FOnStartPaint, write=FOnStartPaint};
	__property System::Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property System::Classes::TNotifyEvent OnAfterPaint = {read=FOnAfterPaint, write=FOnAfterPaint};
	__property System::Classes::TNotifyEvent OnLoop = {read=FOnLoop, write=FOnLoop};
	__property System::Classes::TNotifyEvent OnEndPaint = {read=FOnEndPaint, write=FOnEndPaint};
	/* Hoisted overloads: */
	
public:
	inline bool __fastcall  Equals(System::TObject* Obj){ return Vcl::Graphics::TGraphic::Equals(Obj); }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Word GIFVersion = System::Word(0x202);
static const System::Int8 GIFVersionMajor = System::Int8(0x2);
static const System::Int8 GIFVersionMinor = System::Int8(0x2);
static const System::Int8 GIFVersionRelease = System::Int8(0x5);
static const System::Word GIFMaxColors = System::Word(0x100);
static const int BitmapAllocationThreshold = int(0x7a120);
extern DELPHI_PACKAGE int GIFDelayExp;
extern DELPHI_PACKAGE int GIFDefaultDelay;
extern DELPHI_PACKAGE int GIFMinimumDelay;
extern DELPHI_PACKAGE int GIFMaximumDelay;
extern DELPHI_PACKAGE System::StaticArray<System::StaticArray<char, 3>, 2> GIFVersions;
extern DELPHI_PACKAGE System::Word CF_GIF;
extern DELPHI_PACKAGE TGIFDrawOptions GIFImageDefaultDrawOptions;
extern DELPHI_PACKAGE TColorReduction GIFImageDefaultColorReduction;
extern DELPHI_PACKAGE int GIFImageDefaultColorReductionBits;
extern DELPHI_PACKAGE TDitherMode GIFImageDefaultDitherMode;
extern DELPHI_PACKAGE TGIFCompression GIFImageDefaultCompression;
extern DELPHI_PACKAGE System::Classes::TThreadPriority GIFImageDefaultThreadPriority;
extern DELPHI_PACKAGE int GIFImageDefaultAnimationSpeed;
extern DELPHI_PACKAGE bool DoAutoDither;
extern DELPHI_PACKAGE bool PaletteDevice;
extern DELPHI_PACKAGE bool GIFImageRenderOnLoad;
extern DELPHI_PACKAGE bool GIFImageOptimizeOnStream;
extern DELPHI_PACKAGE System::ResourceString _sOutOfData;
#define Gifimage_sOutOfData System::LoadResourceString(&Gifimage::_sOutOfData)
extern DELPHI_PACKAGE System::ResourceString _sTooManyColors;
#define Gifimage_sTooManyColors System::LoadResourceString(&Gifimage::_sTooManyColors)
extern DELPHI_PACKAGE System::ResourceString _sBadColorIndex;
#define Gifimage_sBadColorIndex System::LoadResourceString(&Gifimage::_sBadColorIndex)
extern DELPHI_PACKAGE System::ResourceString _sBadVersion;
#define Gifimage_sBadVersion System::LoadResourceString(&Gifimage::_sBadVersion)
extern DELPHI_PACKAGE System::ResourceString _sBadSignature;
#define Gifimage_sBadSignature System::LoadResourceString(&Gifimage::_sBadSignature)
extern DELPHI_PACKAGE System::ResourceString _sScreenBadColorSize;
#define Gifimage_sScreenBadColorSize System::LoadResourceString(&Gifimage::_sScreenBadColorSize)
extern DELPHI_PACKAGE System::ResourceString _sImageBadColorSize;
#define Gifimage_sImageBadColorSize System::LoadResourceString(&Gifimage::_sImageBadColorSize)
extern DELPHI_PACKAGE System::ResourceString _sUnknownExtension;
#define Gifimage_sUnknownExtension System::LoadResourceString(&Gifimage::_sUnknownExtension)
extern DELPHI_PACKAGE System::ResourceString _sBadExtensionLabel;
#define Gifimage_sBadExtensionLabel System::LoadResourceString(&Gifimage::_sBadExtensionLabel)
extern DELPHI_PACKAGE System::ResourceString _sOutOfMemDIB;
#define Gifimage_sOutOfMemDIB System::LoadResourceString(&Gifimage::_sOutOfMemDIB)
extern DELPHI_PACKAGE System::ResourceString _sDIBCreate;
#define Gifimage_sDIBCreate System::LoadResourceString(&Gifimage::_sDIBCreate)
extern DELPHI_PACKAGE System::ResourceString _sDecodeTooFewBits;
#define Gifimage_sDecodeTooFewBits System::LoadResourceString(&Gifimage::_sDecodeTooFewBits)
extern DELPHI_PACKAGE System::ResourceString _sDecodeCircular;
#define Gifimage_sDecodeCircular System::LoadResourceString(&Gifimage::_sDecodeCircular)
extern DELPHI_PACKAGE System::ResourceString _sBadTrailer;
#define Gifimage_sBadTrailer System::LoadResourceString(&Gifimage::_sBadTrailer)
extern DELPHI_PACKAGE System::ResourceString _sBadExtensionInstance;
#define Gifimage_sBadExtensionInstance System::LoadResourceString(&Gifimage::_sBadExtensionInstance)
extern DELPHI_PACKAGE System::ResourceString _sBadBlockSize;
#define Gifimage_sBadBlockSize System::LoadResourceString(&Gifimage::_sBadBlockSize)
extern DELPHI_PACKAGE System::ResourceString _sBadBlock;
#define Gifimage_sBadBlock System::LoadResourceString(&Gifimage::_sBadBlock)
extern DELPHI_PACKAGE System::ResourceString _sUnsupportedClass;
#define Gifimage_sUnsupportedClass System::LoadResourceString(&Gifimage::_sUnsupportedClass)
extern DELPHI_PACKAGE System::ResourceString _sInvalidData;
#define Gifimage_sInvalidData System::LoadResourceString(&Gifimage::_sInvalidData)
extern DELPHI_PACKAGE System::ResourceString _sBadHeight;
#define Gifimage_sBadHeight System::LoadResourceString(&Gifimage::_sBadHeight)
extern DELPHI_PACKAGE System::ResourceString _sBadWidth;
#define Gifimage_sBadWidth System::LoadResourceString(&Gifimage::_sBadWidth)
extern DELPHI_PACKAGE System::ResourceString _sFailedPaste;
#define Gifimage_sFailedPaste System::LoadResourceString(&Gifimage::_sFailedPaste)
extern DELPHI_PACKAGE System::ResourceString _sScreenSizeExceeded;
#define Gifimage_sScreenSizeExceeded System::LoadResourceString(&Gifimage::_sScreenSizeExceeded)
extern DELPHI_PACKAGE System::ResourceString _sNoColorTable;
#define Gifimage_sNoColorTable System::LoadResourceString(&Gifimage::_sNoColorTable)
extern DELPHI_PACKAGE System::ResourceString _sBadPixelCoordinates;
#define Gifimage_sBadPixelCoordinates System::LoadResourceString(&Gifimage::_sBadPixelCoordinates)
extern DELPHI_PACKAGE System::ResourceString _sUnsupportedBitmap;
#define Gifimage_sUnsupportedBitmap System::LoadResourceString(&Gifimage::_sUnsupportedBitmap)
extern DELPHI_PACKAGE System::ResourceString _sInvalidPixelFormat;
#define Gifimage_sInvalidPixelFormat System::LoadResourceString(&Gifimage::_sInvalidPixelFormat)
extern DELPHI_PACKAGE System::ResourceString _sBadDimension;
#define Gifimage_sBadDimension System::LoadResourceString(&Gifimage::_sBadDimension)
extern DELPHI_PACKAGE System::ResourceString _sNoDIB;
#define Gifimage_sNoDIB System::LoadResourceString(&Gifimage::_sNoDIB)
extern DELPHI_PACKAGE System::ResourceString _sInvalidStream;
#define Gifimage_sInvalidStream System::LoadResourceString(&Gifimage::_sInvalidStream)
extern DELPHI_PACKAGE System::ResourceString _sInvalidColor;
#define Gifimage_sInvalidColor System::LoadResourceString(&Gifimage::_sInvalidColor)
extern DELPHI_PACKAGE System::ResourceString _sInvalidBitSize;
#define Gifimage_sInvalidBitSize System::LoadResourceString(&Gifimage::_sInvalidBitSize)
extern DELPHI_PACKAGE System::ResourceString _sEmptyColorMap;
#define Gifimage_sEmptyColorMap System::LoadResourceString(&Gifimage::_sEmptyColorMap)
extern DELPHI_PACKAGE System::ResourceString _sEmptyImage;
#define Gifimage_sEmptyImage System::LoadResourceString(&Gifimage::_sEmptyImage)
extern DELPHI_PACKAGE System::ResourceString _sInvalidBitmapList;
#define Gifimage_sInvalidBitmapList System::LoadResourceString(&Gifimage::_sInvalidBitmapList)
extern DELPHI_PACKAGE System::ResourceString _sInvalidReduction;
#define Gifimage_sInvalidReduction System::LoadResourceString(&Gifimage::_sInvalidReduction)
extern DELPHI_PACKAGE System::ResourceString _sGIFImageFile;
#define Gifimage_sGIFImageFile System::LoadResourceString(&Gifimage::_sGIFImageFile)
extern DELPHI_PACKAGE System::ResourceString _sProgressLoading;
#define Gifimage_sProgressLoading System::LoadResourceString(&Gifimage::_sProgressLoading)
extern DELPHI_PACKAGE System::ResourceString _sProgressSaving;
#define Gifimage_sProgressSaving System::LoadResourceString(&Gifimage::_sProgressSaving)
extern DELPHI_PACKAGE System::ResourceString _sProgressConverting;
#define Gifimage_sProgressConverting System::LoadResourceString(&Gifimage::_sProgressConverting)
extern DELPHI_PACKAGE System::ResourceString _sProgressRendering;
#define Gifimage_sProgressRendering System::LoadResourceString(&Gifimage::_sProgressRendering)
extern DELPHI_PACKAGE System::ResourceString _sProgressCopying;
#define Gifimage_sProgressCopying System::LoadResourceString(&Gifimage::_sProgressCopying)
extern DELPHI_PACKAGE System::ResourceString _sProgressOptimizing;
#define Gifimage_sProgressOptimizing System::LoadResourceString(&Gifimage::_sProgressOptimizing)
extern DELPHI_PACKAGE void __fastcall Register(void);
extern DELPHI_PACKAGE HPALETTE __fastcall WebPalette(void);
extern DELPHI_PACKAGE void __fastcall InternalGetDIBSizes(HBITMAP Bitmap, int &InfoHeaderSize, int &ImageSize, Vcl::Graphics::TPixelFormat PixelFormat);
extern DELPHI_PACKAGE bool __fastcall InternalGetDIB(HBITMAP Bitmap, HPALETTE Palette, void *BitmapInfo, void *Bits, Vcl::Graphics::TPixelFormat PixelFormat);
extern DELPHI_PACKAGE HPALETTE __fastcall CreateOptimizedPaletteFromManyBitmaps(System::Classes::TList* Bitmaps, int Colors, int ColorBits, bool Windows);
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall ReduceColors(Vcl::Graphics::TBitmap* Bitmap, TColorReduction ColorReduction, TDitherMode DitherMode, int ReductionBits, HPALETTE CustomPalette);
}	/* namespace Gifimage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GIFIMAGE)
using namespace Gifimage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GifimageHPP
