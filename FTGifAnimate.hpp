// CodeGear C++Builder
// Copyright (c) 1995, 2017 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'FTGifAnimate.pas' rev: 32.00 (Windows)

#ifndef FtgifanimateHPP
#define FtgifanimateHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Graphics.hpp>
#include <GIFImage.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ftgifanimate
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall GifAnimateAddImage(Vcl::Graphics::TGraphic* Source, bool Transparent, System::Word DelayMS)/* overload */;
extern DELPHI_PACKAGE int __fastcall GetColorIndex(Gifimage::TGIFSubImage* GIF, System::Uitypes::TColor Color);
extern DELPHI_PACKAGE int __fastcall GifAnimateAddImage(Vcl::Graphics::TGraphic* Source, System::Uitypes::TColor TransparentColor, System::Word DelayMS)/* overload */;
extern DELPHI_PACKAGE int __fastcall GifAnimateAddImage(Vcl::Graphics::TGraphic* Source, System::Word pLeft, System::Word pTop, bool NSLoop, bool GCExt, System::Word Loops, System::Uitypes::TColor TransparentColor, System::Word DelayMS, Gifimage::TDisposalMethod Disposal)/* overload */;
extern DELPHI_PACKAGE int __fastcall GifAnimateAddImage(Vcl::Graphics::TGraphic* pSource, System::Word pLeft, System::Word pTop, System::Uitypes::TColor TransparentColor, Gifimage::TGIFAppExtNSLoop* pLoopExt, Gifimage::TGIFGraphicControlExtension* pGCExt)/* overload */;
extern DELPHI_PACKAGE void __fastcall GifAnimateBegin(void)/* overload */;
extern DELPHI_PACKAGE void __fastcall GifAnimateBegin(int Width, int Height)/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TPicture* __fastcall GifAnimateEndPicture(void);
extern DELPHI_PACKAGE Gifimage::TGIFImage* __fastcall GifAnimateEndGif(void);
}	/* namespace Ftgifanimate */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FTGIFANIMATE)
using namespace Ftgifanimate;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FtgifanimateHPP
