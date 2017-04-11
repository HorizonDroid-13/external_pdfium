// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FGAS_CRT_IFGAS_STREAM_H_
#define XFA_FGAS_CRT_IFGAS_STREAM_H_

#include "core/fxcrt/cfx_retain_ptr.h"
#include "core/fxcrt/fx_stream.h"
#include "core/fxcrt/fx_system.h"

enum FX_STREAMACCESS {
  FX_STREAMACCESS_Binary = 0x00,
  FX_STREAMACCESS_Read = 0x02,
  FX_STREAMACCESS_Write = 0x04,
  FX_STREAMACCESS_Truncate = 0x10,
  FX_STREAMACCESS_Append = 0x20,
  FX_STREAMACCESS_Create = 0x80,
};

enum FX_STREAMSEEK {
  FX_STREAMSEEK_Begin = 0,
  FX_STREAMSEEK_Current,
  FX_STREAMSEEK_End,
};

class IFGAS_Stream : public CFX_Retainable {
 public:
  static CFX_RetainPtr<IFGAS_Stream> CreateReadStream(
      const CFX_RetainPtr<IFX_SeekableReadStream>& pFileRead);
  static CFX_RetainPtr<IFGAS_Stream> CreateWriteStream(
      const CFX_RetainPtr<IFX_SeekableWriteStream>& pFileWrite);
  static CFX_RetainPtr<IFGAS_Stream> CreateStream(uint8_t* pData,
                                                  int32_t length);

  virtual uint32_t GetAccessModes() const = 0;
  virtual int32_t GetLength() const = 0;
  virtual int32_t Seek(FX_STREAMSEEK eSeek, int32_t iOffset) = 0;
  virtual int32_t GetPosition() = 0;
  virtual bool IsEOF() const = 0;
  virtual int32_t ReadData(uint8_t* pBuffer, int32_t iBufferSize) = 0;
  virtual int32_t ReadString(wchar_t* pStr, int32_t iMaxLength, bool& bEOS) = 0;
  virtual int32_t WriteData(const uint8_t* pBuffer, int32_t iBufferSize) = 0;
  virtual int32_t WriteString(const wchar_t* pStr, int32_t iLength) = 0;
  virtual void Flush() = 0;
  virtual bool SetLength(int32_t iLength) = 0;
  virtual int32_t GetBOM(uint8_t bom[4]) const = 0;
  virtual uint16_t GetCodePage() const = 0;
  virtual uint16_t SetCodePage(uint16_t wCodePage) = 0;

  CFX_RetainPtr<IFX_SeekableReadStream> MakeSeekableReadStream();
};

#endif  // XFA_FGAS_CRT_IFGAS_STREAM_H_
