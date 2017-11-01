// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cscript_signaturepseudomodel.h"

#include "fxjs/cfxjse_arguments.h"
#include "third_party/base/ptr_util.h"

CScript_SignaturePseudoModel::CScript_SignaturePseudoModel(
    CXFA_Document* pDocument)
    : CXFA_Object(pDocument,
                  XFA_ObjectType::Object,
                  XFA_Element::SignaturePseudoModel,
                  WideStringView(L"signaturePseudoModel"),
                  pdfium::MakeUnique<CJX_SignaturePseudoModel>(this)) {}

CScript_SignaturePseudoModel::~CScript_SignaturePseudoModel() {}

void CScript_SignaturePseudoModel::Verify(CFXJSE_Arguments* pArguments) {
  JSSignaturePseudoModel()->Verify(pArguments);
}

void CScript_SignaturePseudoModel::Sign(CFXJSE_Arguments* pArguments) {
  JSSignaturePseudoModel()->Sign(pArguments);
}

void CScript_SignaturePseudoModel::Enumerate(CFXJSE_Arguments* pArguments) {
  JSSignaturePseudoModel()->Enumerate(pArguments);
}

void CScript_SignaturePseudoModel::Clear(CFXJSE_Arguments* pArguments) {
  JSSignaturePseudoModel()->Clear(pArguments);
}
