// Copyright (c) 2007-2009 Google Inc.
// Copyright (c) 2006-2007 Jaiku Ltd.
// Copyright (c) 2002-2006 Mika Raento and Renaud Petit
//
// This software is licensed at your choice under either 1 or 2 below.
//
// 1. MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// 2. Gnu General Public license 2.0
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//
// This file is part of the JaikuEngine mobile client.

#include "csd_idle.h"

EXPORT_C const TTypeName& TBBUserActive::Type() const
{
	return KIdleType;
}

EXPORT_C TBool TBBUserActive::Equals(const MBBData* aRhs) const
{
	const TBBUserActive* rhs=bb_cast<TBBUserActive>(aRhs);
	return (rhs && *this==*rhs);
}

EXPORT_C const TTypeName& TBBUserActive::StaticType()
{
	return KIdleType;
}

EXPORT_C const MBBData* TBBUserActive::Part(TUint aPartNo) const
{
	if (aPartNo==0) return &iActive;
	if (aPartNo==1) return &iSince;
	return 0;
}

EXPORT_C MBBData* TBBUserActive::CloneL(const TDesC&) const
{
	TBBUserActive* ret=new (ELeave) TBBUserActive;
	*ret=*this;
	return ret;
}

EXPORT_C void TBBUserActive::IntoStringL(TDes& aString) const
{
	CheckStringSpaceL(aString, 6);
	if (iActive()) aString.Append(_L("active"));
	else aString.Append(_L("idle"));
}

_LIT(KActive, "active");
_LIT(KSince, "since");

EXPORT_C TBBUserActive::TBBUserActive() :  TBBCompoundData(KIdle), iActive(KActive), iSince(KSince) { }

EXPORT_C const TDesC& TBBUserActive::StringSep(TUint) const
{
	return KNullDesC;
}

EXPORT_C bool TBBUserActive::operator==(const TBBUserActive& rhs) const
{
	return (iActive==rhs.iActive && iSince==rhs.iSince);
}

EXPORT_C TBBUserActive& TBBUserActive::operator=(const TBBUserActive& aRhs)
{
	iActive()=aRhs.iActive();
	iSince()=aRhs.iSince();
	return *this;
}

